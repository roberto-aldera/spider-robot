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

void getEncoder(float*shaft_angle,float*shaft_revs,uint8_t*last_encoderA_state,uint8_t*last_encoderB_state);
void controlMethod(float*acc,float*mag,float*gyro,s8*temp,float*angles,float*PWMval);

#endif /* CONTROL_H_ */
