/*
 * UART.h
 *
 * Created: 11/8/2014 7:10:50 PM
 *  Author: Jacob
 */ 


#ifndef USART_H_
#define USART_H_
#define F_CPU 20000000UL
#define BAUD_RATE 9600

#include <stdint.h>

void initUSART(uint16_t); // want a ubbr of 129 for 20MHz 9600 Baud rate
uint8_t RecieveByte();
void TransmitByte(uint8_t);
uint8_t reverseByte(uint8_t);

#endif /* UART_H_ */