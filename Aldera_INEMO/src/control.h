/*
 * control.h
 *
 *  Created on: Jun 9, 2014
 *      Author: Callen Fisher
 */

#ifndef CONTROL_H_
#define CONTROL_H_

#include "stm32f10x.h"
#include <stddef.h>
#include "AccMag.h"
#include "gyro.h"
#include "pwm.h"

void getEncoder(float*shaft_revs,float*shaft_speed,uint16_t *rawEncoderOld, uint16_t *countSinceEncoderTick);
void readEncoder(float *shaft_revs, float *shaft_speed,int16_t leftCount, int16_t rightCount, int16_t fwdCount,
		int16_t rotCount, int32_t leftTotal, int32_t rightTotal,
		int32_t fwdTotal, int32_t rotTotal);
void waitForEnd500Hz(void);
void controlMethod(float*acc,float*mag,float*gyro,uint8_t*temp,float*angles,float*PWMval);

#endif /* CONTROL_H_ */
