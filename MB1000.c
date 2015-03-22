/*
 * MB1000.c
 *
 * Created: 12/22/2014 6:04:01 PM
 *  Author: Jacob
 */ 

#include "USART.h"
#include <stdint.h>

initMB1000()
{
	initUSART(USART_UBBR);
}

uint8_t getData()
{
	uint8_t sonicData = RecieveByte();
	return sonicData;
}

uint8_t convertUltraSonicData(uint8_t firstByte, uint8_t secondByte, uint8_t thirdByte)
{
	uint8_t answer = 0;
	
	firstByte -= 48;
	secondByte -= 48;
	thirdByte -= 48;
	
	firstByte *= 100;
	secondByte *= 10;
	
	answer = firstByte + secondByte + thirdByte;
	return answer;
}