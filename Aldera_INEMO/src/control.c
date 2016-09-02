/*
 * control.c
 *
 *  Created on: Jun 9, 2014
 *  Template: Callen Fisher
 *  Author: Roberto Aldera
 *
 */

#include "control.h"

void getEncoder(float *shaft_revs, float *shaft_speed, uint16_t *rawEncoderOld,
		uint16_t *countSinceEncoderTick) {

	//uint16_t rawEncoder = 0;
	//uint16_t temp = 0;

	//*rawEncoderOld = TIM_GetCounter(TIM3);
//	int16_t temp = TIM_GetCounter(TIM3);
//	waitForEnd500Hz();
//	int16_t rawEncoder = TIM_GetCounter(TIM3);

//	if (temp != rawEncoder) {
//		//encoder has moved in this cycle
//		//*rawEncoderOld = temp;
//		*shaft_speed = (float) (rawEncoder - *rawEncoderOld)
//				/ (0.002 * (*countSinceEncoderTick));
//		*rawEncoderOld = rawEncoder;
//		*countSinceEncoderTick = 1;
//
//	} else {
//
//		*shaft_speed = (float) (rawEncoder - *rawEncoderOld)
//				/ (0.002 * (*countSinceEncoderTick));
////		*rawEncoderOld = rawEncoder;
//		*countSinceEncoderTick = *countSinceEncoderTick + 1;
////		if (*countSinceEncoderTick > 1000) {
////			//going too slowly to read
////			*shaft_speed = 0;
////		}
//
//	}

//	if (rawEncoder > 32768) {
//		rawEncoder = -(65536 - rawEncoder);
//	}
//	*shaft_revs = (rawEncoder) * 0.1;
	//check the encoder, then check again 2ms later, do this every 100Hz
	//*shaft_speed = (float) (rawEncoder - *rawEncoderOld) / 0.01;
	//*rawEncoderOld = rawEncoder;

}

void readEncoder(float *shaft_revs, float *shaft_speed, int16_t leftCount,
		int16_t rightCount, int16_t fwdCount, int16_t rotCount,
		int32_t leftTotal, int32_t rightTotal, int32_t fwdTotal,
		int32_t rotTotal) {
	// local variables - most are residual
	static volatile int16_t oldLeftEncoder;
	static volatile int16_t oldRightEncoder;
	static volatile int16_t leftEncoder;
	static volatile int16_t rightEncoder;
//	static volatile int16_t encoderSum;
//	static volatile int16_t encoderDiff;

	oldLeftEncoder = leftEncoder;
	leftEncoder = TIM_GetCounter(TIM3);
	oldRightEncoder = rightEncoder;
	rightEncoder = -TIM_GetCounter(TIM4);
	leftCount = leftEncoder - oldLeftEncoder;
	rightCount = rightEncoder - oldRightEncoder;
	fwdCount = leftCount + rightCount;
	rotCount = -(leftCount - rightCount);
	fwdTotal += fwdCount;
	rotTotal += rotCount;
	leftTotal += leftCount;
	rightTotal += rightCount;

	if (leftEncoder > 32768) {
		leftEncoder = -(65536 - leftEncoder);
	}
	*shaft_revs = (leftEncoder) * 0.1;
	*shaft_speed = (float) (leftCount);

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
