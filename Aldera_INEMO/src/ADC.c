/*
 * ADC.c
 *
 *  Created on: Jun 6, 2014
 *      Author: Callen Fisher
 */

//note this is code i found, it links the ADC to the DMA, this is set up for the ADC that
//is linked to the gyro, it needs to be changed for external ADC. This code has not been tested
//the DMA has been set up in the DMA.c file.
#include "ADC.h"

void setUpADC() {
	V25 = 1750;    // when V25=1.41V at ref 3.3V
	Avg_Slope = 5; //when avg_slope=4.3mV/C at ref 3.3V

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
	ADC_InitTypeDef ADC_InitStructure;
	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
	ADC_InitStructure.ADC_ScanConvMode = DISABLE;
	ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
	ADC_InitStructure.ADC_NbrOfChannel = 1;
	ADC_Init(ADC1, &ADC_InitStructure);
	ADC_TempSensorVrefintCmd(ENABLE);
	ADC_RegularChannelConfig(ADC1, ADC_Channel_16, 1, ADC_SampleTime_41Cycles5); // ADC_SampleTime_7Cycles5);
	ADC_Cmd(ADC1, ENABLE);
	ADC_ResetCalibration(ADC1);
	while (ADC_GetResetCalibrationStatus(ADC1))
		;

	ADC_StartCalibration(ADC1);
	while (ADC_GetCalibrationStatus(ADC1))
		;
}
uint8_t readADCtempValue() {
	ADC_SoftwareStartConvCmd(ADC1, ENABLE);
	while (!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC)) {
	}
	AD_value = ADC_GetConversionValue(ADC1);
	ADC_ClearFlag(ADC1, ADC_FLAG_EOC);
	TemperatureC = (uint8_t) ((V25 - AD_value) / Avg_Slope + 25);
	return TemperatureC;
}

//u16 ADC_ConvertedValue[BufferSize]; //BufferSize
//
//void setUpADC(void) {
//	GPIO_InitTypeDef GPIO_InitStructure;
//	ADC_InitTypeDef ADC_InitStructure;
//
//	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOC | RCC_APB2Periph_ADC1, ENABLE);
//
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_0 | GPIO_Pin_2
//			| GPIO_Pin_4 | GPIO_Pin_5;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
//	GPIO_Init(GPIOC, &GPIO_InitStructure);
//
//	/* ADC configuration*/
//	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
//	ADC_InitStructure.ADC_ScanConvMode = ENABLE;
//	ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
//	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
//	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
//	ADC_InitStructure.ADC_NbrOfChannel = 5;
//
//	/* ADC regular channel configuration */
//	ADC_RegularChannelConfig(ADC1, ADC_Channel_10, 1,
//			ADC_SampleTime_239Cycles5);
//	ADC_RegularChannelConfig(ADC1, ADC_Channel_11, 2,
//			ADC_SampleTime_239Cycles5);
//	ADC_RegularChannelConfig(ADC1, ADC_Channel_15, 3,
//			ADC_SampleTime_239Cycles5);
//	ADC_RegularChannelConfig(ADC1, ADC_Channel_14, 4,
//			ADC_SampleTime_239Cycles5);
//	ADC_RegularChannelConfig(ADC1, ADC_Channel_15, 5,
//			ADC_SampleTime_239Cycles5);
//
//	ADC_Init(ADC1, &ADC_InitStructure);
//
//	/* Enable ADC */
//	ADC_Cmd(ADC1, ENABLE);
//
//	/* Enable ADC reset calibration register */
//	ADC_ResetCalibration(ADC1);
//	/* Check the end of ADC reset calibration register */
//	while (ADC_GetResetCalibrationStatus(ADC1))
//		;
//
//	/* Start ADC calibration */
//	ADC_StartCalibration(ADC1);
//	/* Check the end of ADC calibration */
//	while (ADC_GetCalibrationStatus(ADC1))
//		;
//
//	//set up the DMA
//	setUpDMA((&ADC_ConvertedValue[0]));
//}
//void readADCdma(u16* out) {
//	/* Enable ADC DMA */
//	ADC_DMACmd(ADC1, ENABLE);
//	ADC_Cmd(ADC1, ENABLE);
//	DMA_Cmd(DMA1_Channel1, ENABLE);
//	ADC_SoftwareStartConvCmd(ADC1, ENABLE);
//	while (!(DMA_GetFlagStatus(DMA1_FLAG_TC1)))
//		;
//	ADC_Cmd(ADC1, DISABLE);
//	ADC_SoftwareStartConvCmd(ADC1, DISABLE);
//	DMA_ClearFlag(DMA1_FLAG_TC1);
//	int i = 0;
//	for (i = 0; i < BufferSize; i++) {
//		*out = ADC_ConvertedValue[i];
//		out++;
//	}
//}
