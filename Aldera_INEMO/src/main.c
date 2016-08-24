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
uint8_t MiscPayload8[10];	//temperature=2 (excluded for now),PWM=4,Encoder=4
uint8_t a8[] = { 65, 66, 67, 68, 69, 70, 74, 75, 76, 77, 78, 79 };	//debugging
uint8_t b8[] = { 106, 107, 108, 109, 110, 111 };	//debugging
uint8_t c8[] = { 74, 75, 76, 77, 78, 79 };			//debugging
uint8_t d8[] = { 97, 98, 99, 100, 101, 102 };		//debugging
float angles[3];
float PWMval;
float shaft_angle = 0;
float shaft_revs = 0;
uint8_t last_encoderA_state = 0;
uint8_t last_encoderB_state = 0;
uint8_t temperature[2];

void convertDataToBytes(void);

int main(void) {
	serialTerminal_Init();
	setUpLoopTimer();
	setUpGPIO();
	setUpEcompass();
	setUpGyro();
	setUpADC();
	setUpXbee();
	setUpLoggerSDcard();
	setUpPWM();
	float acc[3];
	float mag[3];
	float gyro[3];

	uint8_t status = 0;
	uint8_t XBee_waiting = 0;
	int p = 0;

	while (1) {

		//get data
		getAcc(acc8, acc); //send the floats as well
		getGyro(gyro8, gyro);
		//getMag(mag8, mag);	//mag is taking too long, loop drops from 100Hz to 85Hz
		getTemp(temperature); //fix this, keeps saying temperature is 19 in GUI

		getEncoder(&shaft_angle, &shaft_revs, &last_encoderA_state,
				&last_encoderB_state);
		//perform control on data
		controlMethod(acc, mag, gyro, temperature, angles, &PWMval);

		convertDataToBytes();
		for (p = 0; p < sizeof(TxBuff); p++) {
			TxBuff[p] = 0;
		}
		DMA_Cmd(DMA1_Channel7, DISABLE);
		DMA_SetCurrDataCounter(DMA1_Channel7, sizeof(TxBuff));
		DMA_Cmd(DMA1_Channel4, DISABLE);
		DMA_SetCurrDataCounter(DMA1_Channel4, sizeof(TxBuff));
		//Four payloads, gyro/acc/angles/MiscPayload
		serialTerminal_packetize(gyro8, acc8, angles8, MiscPayload8,
				sizeof(gyro8), sizeof(acc8), sizeof(angles8),
				sizeof(MiscPayload8));
		//debugging purposes
//		serialTerminal_packetize(a8, b8, c8, d8, sizeof(a8), sizeof(b8),
//			sizeof(c8), sizeof(d8));

		DMA_Cmd(DMA1_Channel4, ENABLE);
		USART_DMACmd(USART1, USART_DMAReq_Tx, ENABLE);
		USART_Cmd(USART1, ENABLE);

		if (XBee_waiting == 4) {
			DMA_Cmd(DMA1_Channel7, ENABLE);
			USART_DMACmd(USART2, USART_DMAReq_Tx, ENABLE);
			USART_Cmd(USART2, ENABLE);
			XBee_waiting = 0;
		}

		//Toggle PA11 to test loop frequency
		if (status == 0) {
			GPIO_SetBits(GPIOA, GPIO_Pin_11);
			status = 1;
		} else {
			GPIO_ResetBits(GPIOA, GPIO_Pin_11);
			status = 0;
		}
		wait();
		XBee_waiting++;

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
	//int i;
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
	for (int i = 0; i < 2; i++) {
		MiscPayload8[i] = temperature[i];
	}

	union {
		char temp_char[4];
		float temp_int_buffer;
	} buffer_to_char_union3;
	buffer_to_char_union3.temp_int_buffer = PWMval;
	for (int i = 2; i < 6; i++) {
		MiscPayload8[i] = buffer_to_char_union3.temp_char[i - 2];
	}

	union {
		char temp_char[4];
		float temp_int_buffer;
	} buffer_to_char_union4;
	buffer_to_char_union4.temp_int_buffer = shaft_revs;
	for (int i = 6; i < 10; i++) {
		MiscPayload8[i] = buffer_to_char_union4.temp_char[i - 6];
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
