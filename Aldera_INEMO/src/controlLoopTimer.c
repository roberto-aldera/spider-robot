/*
 * controlLoopTimer.c
 *
 *  Created on: Jun 6, 2014
 *      Author: Callen Fisher
 */

#include "controlLoopTimer.h"

int proceed10ms = 0;
int proceed2ms = 0;
///////////////////////////////////////////////////////////////////////////
////////////////main loop timer ///////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
void setUpLoopTimer(void) {
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

	NVIC_InitTypeDef NVIC_InitStructure;
	/* Enable the TIM2 global Interrupt */
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn; //set up the interrupt handler for TIM2
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;

	NVIC_Init(&NVIC_InitStructure);

	TIM_TimeBaseInitTypeDef TIM_TimeBaseStruct;

	TIM_TimeBaseStruct.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseStruct.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseStruct.TIM_Period = (7200 / 4 - 1); //makes it 100Hz - confirmed on scope.
	//TIM_TimeBaseStruct.TIM_Period = (3600 / 4 - 1); //experimenting
	TIM_TimeBaseStruct.TIM_Prescaler = 400 - 1;
	TIM_TimeBaseStruct.TIM_RepetitionCounter = 0x0000;

	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStruct);

	TIM_Cmd(TIM2, ENABLE);

	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);

}

void setUpDelayTimer(void) {
	//Timer for 2ms delay, use TIM4
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);

	NVIC_InitTypeDef NVIC_InitStructure;
	/* Enable the TIM2 global Interrupt */
	NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn; //set up the interrupt handler for TIM2
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;

	NVIC_Init(&NVIC_InitStructure);

	TIM_TimeBaseInitTypeDef TIM_TimeBaseStruct;

	TIM_TimeBaseStruct.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseStruct.TIM_CounterMode = TIM_CounterMode_Up;
	//TIM_TimeBaseStruct.TIM_Period = (1440 / 4 - 1); //makes it 2ms
	TIM_TimeBaseStruct.TIM_Period = (3600 / 4 - 1); //experimenting
	TIM_TimeBaseStruct.TIM_Prescaler = 400 - 1;
	TIM_TimeBaseStruct.TIM_RepetitionCounter = 0x0000;

	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStruct);

	TIM_Cmd(TIM4, ENABLE);

	TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE);
}

void TIM2_IRQHandler(void) {
	if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET) {
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);

		proceed10ms = 1;
	}
}
void TIM4_IRQHandler(void) {
	if (TIM_GetITStatus(TIM4, TIM_IT_Update) != RESET) {
		TIM_ClearITPendingBit(TIM4, TIM_IT_Update);

		proceed2ms = 1;
	}
}
void setUpEncoder(void) {
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);

	// set both inputs to rising polarity to let it use both edges
	TIM_EncoderInterfaceConfig(TIM3, TIM_EncoderMode_TI12,
	TIM_ICPolarity_Rising,
	TIM_ICPolarity_Rising);
	TIM_SetAutoreload(TIM3, 0xffff);

	TIM_Cmd(TIM3, ENABLE);

	__disable_irq();
	TIM_SetCounter(TIM3, 0);
	__enable_irq();

}

void waitForEnd100Hz(void) {
	while (proceed10ms == 0) //interrupt will set proceed to 1;
	{

	}
	proceed10ms = 0;
}
void waitForEnd500Hz(void) {
	while (proceed2ms == 0) //interrupt will set proceed to 1;
	{

	}
	proceed2ms = 0;
}
