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

void calibrateMEMS(float* acc, float* accCalib, float* gyro, float* gyroCalib, u8* temperature){
	accCalib[0] = 0.9922*acc[0] - 0.0247*acc[1] + 0.0225*acc[2] + 0.0468;
	accCalib[1] = 0.0453*acc[0] + 0.9574*acc[1] + 0.0072*acc[2] + 0.022;
	accCalib[2] = -0.0141*acc[0] -0.0037*acc[1] + 0.9971*acc[2] + 0.0053;

	gyroCalib[0] = gyro[0] + (0.060394*temperature[1] - 3.0843);
	gyroCalib[1] = gyro[1] + (0.025522*temperature[1] - 0.40084);
	gyroCalib[2] = gyro[2] + (-0.32248*temperature[1] + 11.3496);
}

void controlMethod(float*accCalib, float*gyroCalib, uint8_t*temp, float*angles, float*velocities,
		float*positions,float*PWMval) //perform all control in this method
{
//3 floats sent in angles (12 bytes total)
	angles[0] = angles[0] + gyroCalib[0]*0.01;
	angles[1] = angles[1] + gyroCalib[1]*0.01;
	angles[2] = angles[2] + gyroCalib[2]*0.01;

//Velocities from acc data
	velocities[0] = velocities[0] + 9.81*accCalib[0]*0.01;
	velocities[1] = velocities[1] + 9.81*accCalib[1]*0.01;
	velocities[2] = velocities[2] + 9.81*accCalib[2]*0.01;

//Positions from velocity from acc data
	positions[0] = positions[0] + velocities[0]*0.01;
	positions[1] = positions[1] + velocities[1]*0.01;
	positions[2] = positions[2] + velocities[2]*0.01;

	//do PFL

	//turn off motor PWM control after 0.5 s

//to wind up dragline manually after jumping
	if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_9) != 0) {
		*PWMval = *PWMval+0.2;	//was 20
		setPWM(PWMval);
	} else {
		*PWMval = 0;
		setPWM(PWMval);
	}

}
