/*
 * control.c
 *
 *  Created on: Jun 9, 2014
 *  Template: Callen Fisher
 *  Author: Roberto Aldera
 *
 */

#include "control.h"

void getEncoder(float *shaft_revs) {

	int rawEncoder = TIM_GetCounter(TIM3);
	if (rawEncoder > 32768) {
		rawEncoder = -(65536 - rawEncoder);
	}
	*shaft_revs = (rawEncoder) * 0.1;

}

void controlMethod(float*acc, float*mag, float*gyro, uint8_t*temp, float*angles,
		float*PWMval) //perform all control in this method
{
	//debugging code
	//3 floats sent in angles (12 bytes total)
	angles[0] = 1.11;
	angles[1] = 2.22;
	angles[2] = 3.33;

	//to wind up dragline manually after jumping
	if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_9) == 0) {
		*PWMval = 35;
		setPWM(PWMval);
	} else {
		*PWMval = 0;
		setPWM(PWMval);
	}

}
