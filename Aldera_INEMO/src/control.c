/*
 * control.c
 *
 *  Created on: Jun 9, 2014
 *  Template: Callen Fisher
 *  Author: Roberto Aldera
 *
 */

#include "control.h"

void readEncoder(float *shaft_revs, float *shaft_speed) {

	static volatile int16_t oldShaftEncoder;
	static volatile int16_t shaftEncoder;
	static float position = 0;

	oldShaftEncoder = shaftEncoder;
	shaftEncoder = TIM_GetCounter(TIM3);
	*shaft_speed = shaftEncoder - oldShaftEncoder;
	position += *shaft_speed;
	*shaft_revs = position;
//	if (shaftEncoder > 32768) {
//		shaftEncoder = -(65536 - shaftEncoder);
//	}
//	*shaft_revs = (position) ;//(1/(3*2));	//3 teeth on encoder wheel
	//*shaft_speed = *shaft_speed / 0.01;

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
		*PWMval = *PWMval+0.2;	//was 20
		setPWM(PWMval);
	} else {
		*PWMval = 0;
		setPWM(PWMval);
	}

}
