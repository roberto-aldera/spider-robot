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
void waitForEnd500Hz(void);
void controlMethod(float*acc,float*mag,float*gyro,uint8_t*temp,float*angles,float*PWMval);

#endif /* CONTROL_H_ */
