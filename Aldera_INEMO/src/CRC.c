/*
 * CRC.c
 *
 *  Created on: 03 Dec 2012
 *      Author: james
 */

#include "CRC.h"

#define CRCDATA_DATAWIDTH 16
#define CRCDATA_POLYNOMIAL 0x1021
#define CRCDATA_INITIALVAL 0xFFFF
#define CRCDATA_REFLECT_DATA 0
#define CRCDATA_REFLECT_REMAIN 0
#define CRCDATA_FINAL_VAL 0
#define CRCDATA_MASK 65535

static uint32_t crcTable[256];
static uint32_t currentCRC;

static void buildTable();

void initCRC() {

  buildTable();
  currentCRC = CRCDATA_INITIALVAL;

}

uint32_t crcCalc(const uint8_t* data, uint16_t startIndex, uint16_t length) {
  uint16_t index;
  uint32_t lookup;
  uint32_t remainder = CRCDATA_INITIALVAL;

  for (index = startIndex; index < length + startIndex; index++) {
    lookup = ((uint32_t) data[index] ^ (uint32_t) (remainder >> (CRCDATA_DATAWIDTH - (uint8_t) 8))) & (uint32_t) 0xFF;
    remainder = (uint32_t) (crcTable[lookup] ^ (uint32_t) (remainder << (uint32_t) 8));
  }
  /* CRC result */
  return (uint32_t) (remainder ^ CRCDATA_FINAL_VAL) & CRCDATA_MASK;
}

/*****************************************************************************/
/*******                                                               *******/
/*******                   Private Functions/Procedures                 *******/
/*******                                                               *******/
/*****************************************************************************/
/**
 * This function build the lookup table.
 * @param sCRCdata - CRC data struct
 * @return void.
 * @throws  none
 */
static void buildTable() {
  uint32_t topbit;
  uint32_t dividend;
  uint32_t bit;
  uint32_t remainder;

  topbit = (uint32_t) 1U << (CRCDATA_DATAWIDTH - (uint8_t) 1);

  //Compute the remainder of each possible dividend.
  for (dividend = 0U; dividend < 256U; dividend++) {
    //Start with the dividend followed by zeros.
    remainder = (dividend << (CRCDATA_DATAWIDTH - (uint8_t) 8)) & CRCDATA_MASK;

    //Perform modulo-2 division, a bit at a time.
    for (bit = 8U; bit > 0U; bit--) {
      //Try to divide the current data bit.
      if ((remainder & topbit) > 0U) {
        remainder = ((remainder << 1U) ^ CRCDATA_POLYNOMIAL) & CRCDATA_MASK;
      } else {
        remainder = (remainder << 1U) & CRCDATA_MASK;
      }
    }
    //Store the result into table.
    crcTable[dividend] = remainder;
  }
}
