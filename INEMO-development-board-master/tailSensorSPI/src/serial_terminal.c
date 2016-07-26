#include "serial_terminal.h"
#include "CRC.h"


void serialTerminal_Init(void)
{
  initCRC();
}


void serialTerminal_packetize(uint8_t* payload_to_packS1,uint8_t* payload_to_packS2,uint8_t* payload_to_packS3,uint8_t* payload_to_packS4, uint16_t length_of_payloadS1,uint16_t length_of_payloadS2,uint16_t length_of_payloadS3,uint16_t length_of_payloadS4)
{
  CommsTask_TransmitPacketStruct pkt_to_tx;
  uint16_t raw_data_pointer = 0;
  uint16_t packet_data_pointer = 4;
  uint16_t crcCalculated;
  uint8_t char_to_pack;
  uint8_t a=4;
  //put data
  for (raw_data_pointer = 0; raw_data_pointer < length_of_payloadS1; raw_data_pointer++, packet_data_pointer++,a++)
  { //for both bytes of the pkt_code,
    char_to_pack = payload_to_packS1[raw_data_pointer];
    t[a]=char_to_pack;
    if (char_to_pack == 0x7E)
    {
      pkt_to_tx.data[packet_data_pointer++] = 0x7D;
      pkt_to_tx.data[packet_data_pointer] = 0x5E;
    }
    else if (char_to_pack == 0x7D)
    {
      pkt_to_tx.data[packet_data_pointer++] = 0x7D;
      pkt_to_tx.data[packet_data_pointer] = 0x5D;
    }
    else
    {
      pkt_to_tx.data[packet_data_pointer] = char_to_pack;
    }
  }
  for (raw_data_pointer = 0; raw_data_pointer < length_of_payloadS2; raw_data_pointer++, packet_data_pointer++,a++)
  { //for both bytes of the pkt_code,
    char_to_pack = payload_to_packS2[raw_data_pointer];
    t[a]=char_to_pack;
    if (char_to_pack == 0x7E)
    {
      pkt_to_tx.data[packet_data_pointer++] = 0x7D;
      pkt_to_tx.data[packet_data_pointer] = 0x5E;
    }
    else if (char_to_pack == 0x7D)
    {
      pkt_to_tx.data[packet_data_pointer++] = 0x7D;
      pkt_to_tx.data[packet_data_pointer] = 0x5D;
    }
    else
    {
      pkt_to_tx.data[packet_data_pointer] = char_to_pack;
    }
  }
  for (raw_data_pointer = 0; raw_data_pointer < length_of_payloadS3; raw_data_pointer++, packet_data_pointer++,a++)
  { //for both bytes of the pkt_code,
    char_to_pack = payload_to_packS3[raw_data_pointer];
    t[a]=char_to_pack;
    if (char_to_pack == 0x7E)
    {
      pkt_to_tx.data[packet_data_pointer++] = 0x7D;
      pkt_to_tx.data[packet_data_pointer] = 0x5E;
    }
    else if (char_to_pack == 0x7D)
    {
      pkt_to_tx.data[packet_data_pointer++] = 0x7D;
      pkt_to_tx.data[packet_data_pointer] = 0x5D;
    }
    else
    {
      pkt_to_tx.data[packet_data_pointer] = char_to_pack;
    }
  }
  for (raw_data_pointer = 0; raw_data_pointer < length_of_payloadS4; raw_data_pointer++, packet_data_pointer++,a++)
  { //for both bytes of the pkt_code,
    char_to_pack = payload_to_packS4[raw_data_pointer];
    t[a]=char_to_pack;
    if (char_to_pack == 0x7E)
    {
      pkt_to_tx.data[packet_data_pointer++] = 0x7D;
      pkt_to_tx.data[packet_data_pointer] = 0x5E;
    }
    else if (char_to_pack == 0x7D)
    {
      pkt_to_tx.data[packet_data_pointer++] = 0x7D;
      pkt_to_tx.data[packet_data_pointer] = 0x5D;
    }
    else
    {
      pkt_to_tx.data[packet_data_pointer] = char_to_pack;
    }
  }
 uint16_t l=a-4;

 	 union
 	  {
 	  	char temp_char[2];
 	  	uint16_t temp_16;
 	  }buffer_to_char_union1;
 	  buffer_to_char_union1.temp_16=0x0101;




 pkt_to_tx.data[0]=buffer_to_char_union1.temp_char[0];
  pkt_to_tx.data[1]=buffer_to_char_union1.temp_char[1];
  t[0]=buffer_to_char_union1.temp_char[0];
  t[1]=buffer_to_char_union1.temp_char[1];
  	  union
   	  {
   	  	char temp_char[2];
   	  	uint16_t temp_16;
   	  }buffer_to_char_union2;
   	  buffer_to_char_union2.temp_16=l;

  pkt_to_tx.data[2]=buffer_to_char_union2.temp_char[0];
  pkt_to_tx.data[3]=buffer_to_char_union2.temp_char[1];
  t[2]=buffer_to_char_union2.temp_char[0];
  t[3]=buffer_to_char_union2.temp_char[1];
  //calculate CRC
  crcCalculated = (uint16_t) crcCalc(t, 0,a);////////////////////COULD BE ERROR HERE

  //put CRC
  for (raw_data_pointer = 0; raw_data_pointer < 2; raw_data_pointer++, packet_data_pointer++)
  {
    char_to_pack = (uint8_t) ((crcCalculated >> 8 * (1 - raw_data_pointer)) & 0x00FF);
    if (char_to_pack == 0x7E)
    {
      pkt_to_tx.data[packet_data_pointer++] = 0x7D;
      pkt_to_tx.data[packet_data_pointer] = 0x5E;
    }
    else if (char_to_pack == 0x7D)
    {
      pkt_to_tx.data[packet_data_pointer++] = 0x7D;
      pkt_to_tx.data[packet_data_pointer] = 0x5D;
    }
    else
    {
      pkt_to_tx.data[packet_data_pointer] = char_to_pack;
    }
  }

  //set pkt length
  pkt_to_tx.bytes_to_tx = packet_data_pointer+2;//add 2 for the two 7E's

  //add 7E
  TxBuff[0]=0x7E;//start character
  //add type

  int i;
  for(i=1;i<pkt_to_tx.bytes_to_tx-1;i++)
  {
	  TxBuff[i]=pkt_to_tx.data[i-1];
  }
  //add 7E
  TxBuff[pkt_to_tx.bytes_to_tx-1]=0x7E;
  //set number of characters to tx
  Tx_chars=pkt_to_tx.bytes_to_tx;
  int p=0;

  for(p=0;p<sizeof(pkt_to_tx.data);p++)
  		  {
  			  pkt_to_tx.data[p]=0;
  			  t[p]=0;
  		  }
}































/*

void serialTerminal_packetize(uint8_t* payload_to_pack, uint16_t length_of_payload)
{
  CommsTask_TransmitPacketStruct pkt_to_tx;
  uint16_t raw_data_pointer = 0;
  uint16_t packet_data_pointer = 0;
  uint16_t crcCalculated;
  uint8_t char_to_pack;
  //portBASE_TYPE xStatus;

  //put start char
  pkt_to_tx.data[packet_data_pointer++] = 0x7E;

  //put data
  for (raw_data_pointer = 0; raw_data_pointer < length_of_payload; raw_data_pointer++, packet_data_pointer++)
  { //for both bytes of the pkt_code,
    char_to_pack = payload_to_pack[raw_data_pointer];
    if (char_to_pack == 0x7E)
    {
      pkt_to_tx.data[packet_data_pointer++] = 0x7D;
      pkt_to_tx.data[packet_data_pointer] = 0x5E;
    }
    else if (char_to_pack == 0x7D)
    {
      pkt_to_tx.data[packet_data_pointer++] = 0x7D;
      pkt_to_tx.data[packet_data_pointer] = 0x5D;
    }
    else
    {
      pkt_to_tx.data[packet_data_pointer] = char_to_pack;
    }
  }

  //calculate CRC
  crcCalculated = (uint16_t) crcCalc(payload_to_pack, 0, length_of_payload);

  //put CRC
  for (raw_data_pointer = 0; raw_data_pointer < 2; raw_data_pointer++, packet_data_pointer++)
  {
    char_to_pack = (uint8_t) ((crcCalculated >> 8 * (1 - raw_data_pointer)) & 0x00FF);
    if (char_to_pack == 0x7E)
    {
      pkt_to_tx.data[packet_data_pointer++] = 0x7D;
      pkt_to_tx.data[packet_data_pointer] = 0x5E;
    }
    else if (char_to_pack == 0x7D)
    {
      pkt_to_tx.data[packet_data_pointer++] = 0x7D;
      pkt_to_tx.data[packet_data_pointer] = 0x5D;
    }
    else
    {
      pkt_to_tx.data[packet_data_pointer] = char_to_pack;
    }
  }

  //put end char
  pkt_to_tx.data[packet_data_pointer++] = 0x7E;

  //set pkt length
  pkt_to_tx.bytes_to_tx = packet_data_pointer;


  int i;
    for(i=0;i<pkt_to_tx.bytes_to_tx;i++)
    {
  	  TxBuff[i]=pkt_to_tx.data[i];
    }
    Tx_chars=pkt_to_tx.bytes_to_tx;
}*/
