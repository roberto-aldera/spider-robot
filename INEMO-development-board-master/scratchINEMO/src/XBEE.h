/*
 * XBEE.h
 *
 *  Created on: Jun 6, 2014
 *      Author: Callen Fisher
 */

#ifndef XBEE_H_
#define XBEE_H_

#include "stm32f10x.h"
#include <stddef.h>
#include "serial_terminal.h"
void setUpXbee(void);
uint16_t receiveXBEE(void);
void sendXBEE(float Data);
void S_DMA();

#endif /* XBEE_H_ */
