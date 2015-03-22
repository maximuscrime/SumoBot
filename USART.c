/*
 * UART.c
 *
 * Created: 11/8/2014 7:10:37 PM
 *  Author: Jacob
 */ 

#include "USART.h"
#include <stdint.h>
#include <avr/io.h>

void initUSART(uint16_t ubbr)
{
	/*Set baud rate */
	UBRR0H = ubbr>>8;
	UBRR0L = ubbr;
	
	/*Enable receiver and transmitter */
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	
	/*Enable Rx Interrupt */
	UCSR0B |= (1<<RXCIE0); 
	
	/* Set frame format: 8 data bits, 1 stop bit */
	UCSR0C = (3<<UCSZ00); //Equivalent to (1 << UCSZ1) | (1 << UCSZ0)
}

uint8_t RecieveByte(void)
{
	/* Wait for data to be received */
	while (!(UCSR0A & (1<<RXC0)));
	
	/* Get and return received data from buffer */
	return UDR0;
}

void TransmitByte(uint8_t data)
{
	/* Wait for empty transmit buffer */
	while ( !( UCSR0A & (1<<UDRE0)) );
	
	/* Put data into buffer, sends the data */
	UDR0 = data;
}

uint8_t reverseByte(uint8_t byte) //Test
{
	
	uint8_t output = 0;
	uint8_t bit = 0;

	for(int count = 1; count <= 8; count++)
	{
		bit = byte & 0x01;
		byte = byte>>1;
		output = output<<1;
		if(bit==1)
			output  = output+1;
	}
	
	return output;
}