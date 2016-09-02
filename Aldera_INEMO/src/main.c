/*
 * main.c
 *
 *  Created on: May 25, 2014
 *  Original author: Callen Fisher
 *  Current author: Roberto Aldera, Thesis 2016
 */
//Include all the relevant (header) files
//#include <stddef.h>
#include "stm32f10x.h"
#include "AccMag.h"
#include "controlLoopTimer.h"
#include "gpioPorts.h"
#include "gyro.h"
#include "testPorts.h"
#include "XBEE.h"
#include "USART.h"
#include "DMA.h"
#include "ADC.h"
#include "control.h"
#include "send.h"
#include "serial_terminal.h"
#include "CRC.h"
#include "pwm.h"

uint8_t acc8[6];		//3 axes, each returning uint16_t, 3x2=6
uint8_t mag8[6];
uint8_t gyro8[6];
uint8_t angles8[12];
uint8_t MiscPayload8[13];	//temperature=1 (just ADCtemp),PWM=4,Encoder=4+4
uint16_t encoderPosition = 0;
uint8_t temperature[2];
uint8_t status = 0;
uint8_t XBee_waiting = 0;
float acc[3];
float mag[3];
float gyro[3];
float angles[3];
float PWMval;
float shaft_revs = 0;
float shaft_speed = 0;
uint16_t rawEncoderOld = 0;
uint16_t countSinceEncoderTick = 1;

//speeds
volatile int16_t leftCount;
volatile int16_t rightCount;
volatile int16_t fwdCount;
volatile int16_t rotCount;
//distances
volatile int32_t leftTotal;
volatile int32_t rightTotal;
volatile int32_t fwdTotal;
volatile int32_t rotTotal;

void setUpEncoder();
void convertDataToBytes(void);
void toggleGPIOpin(uint8_t *status);

uint8_t a8[] = { 65, 66, 67, 68, 69, 70 };	//debugging
uint8_t b8[] = { 106, 107, 108, 109, 110, 111 };	//debugging
uint8_t c8[] = { 74, 75, 76, 77, 78, 79, 74, 75, 76, 77, 78, 79 };	//debugging
uint8_t d8[] = { 97, 98, 99, 100, 101, 102, 103, 102, 101, 100, 99, 98, 97 };//debugging

int main(void) {
	serialTerminal_Init();
	setUpLoopTimer();
	//setUpDelayTimer();
	setUpEncoder();
	setUpGPIO();
	setUpEcompass();
	setUpGyro();
	setUpADC();
	setUpXbee();
	setUpLoggerSDcard();
	setUpPWM();

	while (1) {
		getAcc(acc8, acc);
		getGyro(gyro8, gyro);
		//getMag(mag8, mag);
		getTempCelsius(temperature);
//		getEncoder(&shaft_revs, &shaft_speed, &rawEncoderOld,
//				&countSinceEncoderTick);
		readEncoder(&shaft_revs, &shaft_speed,leftCount, rightCount, fwdCount, rotCount, leftTotal,
				rightTotal, fwdTotal, rotTotal);

		controlMethod(acc, mag, gyro, temperature, angles, &PWMval);

		for (int p = 0; p < sizeof(TxBuff); p++) {
			TxBuff[p] = 0;
		}

		DMA_Cmd(DMA1_Channel7, DISABLE);
		DMA_SetCurrDataCounter(DMA1_Channel7, sizeof(TxBuff));
		DMA_Cmd(DMA1_Channel4, DISABLE);
		DMA_SetCurrDataCounter(DMA1_Channel4, sizeof(TxBuff));

		//Four payloads, gyro/acc/angles/MiscPayload
		convertDataToBytes();
		serialTerminal_packetize(gyro8, acc8, angles8, MiscPayload8,
				sizeof(gyro8), sizeof(acc8), sizeof(angles8),
				sizeof(MiscPayload8));

		//debugging purposes
//		serialTerminal_packetize(a8, b8, c8, d8, sizeof(a8), sizeof(b8),
//				sizeof(c8), sizeof(d8));

		//SD card data
		DMA_Cmd(DMA1_Channel4, ENABLE);
		USART_DMACmd(USART1, USART_DMAReq_Tx, ENABLE);
		USART_Cmd(USART1, ENABLE);

		//XBee data, slower
		if (XBee_waiting == 10) {
			DMA_Cmd(DMA1_Channel7, ENABLE);
			USART_DMACmd(USART2, USART_DMAReq_Tx, ENABLE);
			USART_Cmd(USART2, ENABLE);
			XBee_waiting = 0;
		}
		XBee_waiting++;
		//Toggle PA11 to test loop frequency
		toggleGPIOpin(&status);
		//wait until next run, to maintain 100Hz sync
		waitForEnd100Hz();
	}
}

void toggleGPIOpin(uint8_t *status) {
	if (*status == 0) {
		GPIO_SetBits(GPIOA, GPIO_Pin_11);
		*status = 1;
	} else {
		GPIO_ResetBits(GPIOA, GPIO_Pin_11);
		*status = 0;
	}
}

void convertDataToBytes() {
	union {
		char temp_char[12];
		float temp_int_buffer[3];
	} buffer_to_char_union1;
	buffer_to_char_union1.temp_int_buffer[0] = angles[0];
	buffer_to_char_union1.temp_int_buffer[1] = angles[1];
	buffer_to_char_union1.temp_int_buffer[2] = angles[2];
	for (int i = 0; i < 12; i++) {
		angles8[i] = buffer_to_char_union1.temp_char[i];
	}

//	union {
//		uint8_t temp_signed[2];
//		uint8_t temp_unsigned[2];
//	} buffer_to_char_union2;
//	//temperatureToPack[1] = 30;
//	buffer_to_char_union2.temp_signed[0] = temperature[0];
//	buffer_to_char_union2.temp_signed[1] = temperature[1];
//	for (int i = 0; i < 2; i++) {
//		MiscPayload8[i] = buffer_to_char_union2.temp_unsigned[i];
//	}
	for (int i = 0; i < 1; i++) {
//		MiscPayload8[i] = temperature[i];
		MiscPayload8[0] = temperature[1];
	}

	union {
		char temp_char[4];
		float temp_int_buffer;
	} buffer_to_char_union3;
	buffer_to_char_union3.temp_int_buffer = PWMval;
	for (int i = 1; i < 5; i++) {
		MiscPayload8[i] = buffer_to_char_union3.temp_char[i - 1];
	}

	union {
		char temp_char[4];
		float temp_int_buffer;
	} buffer_to_char_union4;
	buffer_to_char_union4.temp_int_buffer = shaft_revs;
	for (int i = 5; i < 9; i++) {
		MiscPayload8[i] = buffer_to_char_union4.temp_char[i - 5];
	}

	union {
		char temp_char[4];
		float temp_int_buffer;
	} buffer_to_char_union5;
	buffer_to_char_union5.temp_int_buffer = shaft_speed;
	for (int i = 9; i < 13; i++) {
		MiscPayload8[i] = buffer_to_char_union5.temp_char[i - 9];
	}
}

///////////////////////////////////////////////////////////////////////////
/////don't delete the following functions//////////////////////////////////
///////////////////////////////////////////////////////////////////////////
void __assert_func(const char *file, int line, const char *func,
		const char *failedexpr) {
	while (1) {
	}
}
void __assert(const char *file, int line, const char *failedexpr) {
	__assert_func(file, line, NULL, failedexpr);
}
