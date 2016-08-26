/*
 * controlLoopTimer.h
 *
 *  Created on: Jun 6, 2014
 *      Author: Callen Fisher
 */

#ifndef CONTROLLOOPTIMER_H_
#define CONTROLLOOPTIMER_H_

#include "stm32f10x.h"
#include <stddef.h>

void setUpLoopTimer(void);
void setUpDelayTimer(void);
void setUpEncoder(void);
void waitForEnd100Hz(void);
void waitForEnd500Hz(void);

#endif /* CONTROLLOOPTIMER_H_ */
