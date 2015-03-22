/*
 * PWM.c
 *
 * Created: 11/10/2014 12:08:42 AM
 *  Author: Jacob
 */ 

#include "PWM.h"
#include <avr/io.h>
#include <stdint.h>

void initPWM(void)
{
	/* Set direction of pins B1 and B2 to output */
	DDRB |= (1<<PINB1) | (1<<PINB2);
	
	/* Set clear on OC1A compare match and select Fast PWM with top at OCR1A */
	TCCR1A = (1<<COM1A1) | (1<<COM1B1) | (1<<WGM11);
	
	/* Set the clock prescaler to clk/1*/
	TCCR1B |= (1<<CS10) | (1<<WGM13) | (1<<WGM12);
	
	ICR1 = 39999;
	
	OCR1A = DUTY_CYCLE_50;	
	OCR1B = DUTY_CYCLE_50;
}

void changeDutyCycleOCR1A(uint16_t dutyCycle) //0 - 100%
{
    OCR1A = compareValue-dutyCycle;	
}

void changeDutyCycleOCR1B(uint16_t dutyCycle) //0 - 100%
{
	OCR1B = compareValue-dutyCycle;	 
}