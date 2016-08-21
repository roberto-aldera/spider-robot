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
#include "DMA.h"
#include "ADC.h"
#include "control.h"
#include "send.h"
#include "serial_terminal.h"
#include "CRC.h"
#include "pwm.h"

//uint32_t temp = 0;
//uint16_t temperature16 = 24;
uint16_t recVal;

float PWMval;

//uint8_t temperatureArray8[2]; //returns 2 bytes for temperature
uint8_t acc8[6];		//3 axes, each returning uint16_t, 3x2=6
uint8_t mag8[6];
uint8_t gyro8[6];
uint8_t angles8[12];
uint8_t MiscPayload8[8];	//temperature=2 (excluded for now),PWM=4,Encoder=4
uint8_t a8[] = { 65, 66, 67, 68, 69, 70 };			//debugging
uint8_t b8[] = { 106, 107, 108, 109, 110, 111 };	//debugging
uint8_t c8[] = { 74, 75, 76, 77, 78, 79 };			//debugging
uint8_t d8[] = { 97, 98, 99, 100, 101, 102 };		//debugging
float angles[3];

float shaft_angle = 0;
float shaft_revs = 0;
uint8_t last_encoderA_state = 0;
uint8_t last_encoderB_state = 0;

s8 temperatureToPack;

void convertAnglesToBytes(void);

int main(void) {
	serialTerminal_Init();
	setUpLoopTimer();
	setUpGPIO();
	setUpEcompass();
	setUpGyro();
	setUpXbee();
	setUpPWM();
	float acc[3];
	float mag[3];
	float gyro[3];
	s8 temperature;

	USART_Cmd(USART2, ENABLE);
	uint8_t status = 0;
	int p = 0;
	/*
	 for (int i = 0; i < 1000; i++){
	 for (int j = 0; j < 1000; j++){
	 //do nothing
	 }
	 }
	 */
	while (1) {

		//get data
		getAcc(acc8, acc); //send the floats as well
		getGyro(gyro8, gyro);
		//getMag(mag8, mag);	//mag is taking too long, loop drops from 100Hz to 85Hz
		//getTemp(temperature);//fix this, keeps saying temperature is 19 in GUI
		temperatureToPack = temperature;

		getEncoder(&shaft_angle,&shaft_revs,&last_encoderA_state,&last_encoderB_state);
		//perform control on data
		controlMethod(acc, mag, gyro, &temperature, angles, &PWMval);

		convertAnglesToBytes();
		for (p = 0; p < sizeof(TxBuff); p++) {
			TxBuff[p] = 0;
		}
		DMA_Cmd(DMA1_Channel7, DISABLE);
		DMA_SetCurrDataCounter(DMA1_Channel7, sizeof(TxBuff));
		//Four payloads, gyro/acc/angles/MiscPayload
		serialTerminal_packetize(gyro8, acc8, angles8, MiscPayload8,
				sizeof(gyro8), sizeof(acc8), sizeof(angles8),
				sizeof(MiscPayload8));
		//debugging purposes
//		serialTerminal_packetize(a8, b8, c8, d8, sizeof(a8), sizeof(b8),
//			sizeof(c8), sizeof(d8));

		DMA_Cmd(DMA1_Channel7, ENABLE);
		USART_DMACmd(USART2, USART_DMAReq_Tx, ENABLE);
		USART_Cmd(USART2, ENABLE);
/*
		for (int i = 0; i < 1000; i++) {
			for (int j = 0; j < 5; j++) {
				//do nothing, give Xbees a chance to send packet.
			}
		}
*/
		//Toggle PA11 to test loop frequency
		if (status == 0) {
			GPIO_SetBits(GPIOA, GPIO_Pin_11);
			status = 1;
		} else {
			GPIO_ResetBits(GPIOA, GPIO_Pin_11);
			status = 0;
		}
		wait();

		/*recVal=0;
		 recVal=USART_ReceiveData(USART2);
		 if(recVal==0x7E&&USART_GetFlagStatus(USART2,USART_IT_RXNE))
		 {
		 USART_ClearFlag(USART2,USART_IT_RXNE);
		 TIM_SetCounter(TIM2,0x00);//TODO: This could force an interrupt, not sure, double check

		 USART_Cmd(USART2,DISABLE);
		 DMA_DeInit(DMA1_Channel7);
		 controlMethod(&acc[0],&mag[0],&gyro[0],&temp);//get the data


		 union
		 {
		 char temp_char[12];
		 float temp_float_buffer[3];
		 }buffer_to_char_union1;
		 buffer_to_char_union1.temp_float_buffer[0]=acc[0];
		 buffer_to_char_union1.temp_float_buffer[1]=acc[1];
		 buffer_to_char_union1.temp_float_buffer[2]=acc[2];
		 int i;
		 for(i=0;i<12;i++)
		 {
		 acc8[i]=buffer_to_char_union1.temp_char[i];
		 }

		 union
		 {
		 char temp_char[12];
		 float temp_float_buffer[3];
		 }buffer_to_char_union2;
		 buffer_to_char_union2.temp_float_buffer[0]=mag[0];
		 buffer_to_char_union2.temp_float_buffer[1]=mag[1];
		 buffer_to_char_union2.temp_float_buffer[2]=mag[2];
		 for(i=0;i<12;i++)
		 {
		 mag8[i]=buffer_to_char_union2.temp_char[i];
		 }
		 union
		 {
		 char temp_char[12];
		 float temp_float_buffer[3];
		 }buffer_to_char_union3;
		 buffer_to_char_union3.temp_float_buffer[0]=gyro[0];
		 buffer_to_char_union3.temp_float_buffer[1]=gyro[1];
		 buffer_to_char_union3.temp_float_buffer[2]=gyro[2];
		 for(i=0;i<12;i++)
		 {
		 gyro8[i]=buffer_to_char_union3.temp_char[i];
		 }
		 union
		 {
		 s8 temp_signed;
		 uint8_t temp_unsigned;
		 }buffer_to_char_union4;
		 buffer_to_char_union4.temp_signed=temp;
		 temperature8=buffer_to_char_union4.temp_unsigned;

		 serialTerminal_packetize(gyro8,acc8,mag8,&temperature8,12,12,12,1);
		 USART_Cmd(USART2,ENABLE);
		 S_DMA();//re init the DMA and then it will send

		 wait();
		 }*/
	}
}

void convertAnglesToBytes() {
	union {
		char temp_char[12];
		float temp_int_buffer[3];
	} buffer_to_char_union1;
	buffer_to_char_union1.temp_int_buffer[0] = angles[0];
	buffer_to_char_union1.temp_int_buffer[1] = angles[1];
	buffer_to_char_union1.temp_int_buffer[2] = angles[2];
	int i;
	for (i = 0; i < 12; i++) {
		angles8[i] = buffer_to_char_union1.temp_char[i];
	}

	/*union {
	 char temp_char[2];
	 uint16_t temp_int_buffer;
	 } buffer_to_char_union2;
	 buffer_to_char_union2.temp_int_buffer = temperature16;
	 for (i = 0; i < 2; i++) {
	 MiscPayload8[i] = buffer_to_char_union2.temp_char[i];
	 }*/
/*	union {
		s8 temp_signed;
		uint8_t temp_unsigned;
	} buffer_to_char_union4;
	buffer_to_char_union4.temp_signed = temperatureToPack;
	MiscPayload8[0] = buffer_to_char_union4.temp_unsigned;
*/
	union {
		char temp_char[4];
		float temp_int_buffer;
	} buffer_to_char_union3;
	buffer_to_char_union3.temp_int_buffer = PWMval;
	for (i = 0; i < 4; i++) {
		MiscPayload8[i] = buffer_to_char_union3.temp_char[i];
	}
	union {
		char temp_char[4];
		float temp_int_buffer;
	} buffer_to_char_union5;
	buffer_to_char_union5.temp_int_buffer = shaft_revs;
	for (i = 4; i < 8; i++) {
		MiscPayload8[i] = buffer_to_char_union5.temp_char[i - 4];
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
