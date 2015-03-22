/*
 * ADC.c
 *
 * Created: 11/8/2014 7:11:12 PM
 *  Author: Jacob
 */ 

#include "ADC.h"
#include <avr/io.h>
#include <stdint.h>

//ADCSRA |= 1<<ADSC; for interrupt
void initADC()
{
	/* Enable ADC (ADEN) and ADC interrupt (ADIE)  */
	ADCSRA = (1<<ADEN)|(1<<ADIE);
	
	/* Set reference voltage */
	ADMUX |= (1<<REFS0);
	
	/* Set ADC prescalar to 128 */
	ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); //Get a value of 20,000,000/128 = 156,250 < 200,000 KsPs, keeps 10 bit resolution  
	
	/* Start Conversions */
	ADCSRA |= (1<<ADSC);
}

void startConversion(void)
{
	/* Start the conversion again */
	ADCSRA |= (1<<ADSC);
}

uint8_t getADCConverted(void)
{
	/* Go into ADC ADMUX and pull bits 0-3 with bit mask */
	uint8_t channel = ADMUX; 
	channel &= 0x0F;
	return channel;	
}

void changeADCSource(uint8_t channel)
{
	/* Mask channel with 00001111 or 0x0F and add channel selection */
	//ADMUX |= (channel & 0x0F);
	ADMUX = (ADMUX & 0xf0) | channel;
	
}

uint16_t getADCResult()
{
	uint8_t theLowADC = ADCL;
	uint16_t tenBitResult = ADCH<<8 | theLowADC;	
	return tenBitResult;
}