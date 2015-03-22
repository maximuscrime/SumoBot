/*
 * MB1000.h
 *
 * Created: 12/22/2014 6:04:16 PM
 *  Author: Jacob
 */ 


#ifndef MB1000_H_
#define MB1000_H_

#define USART_UBBR 129 // for a baud rate of 9600 for Atmega168

initMB1000();
uint8_t convertUltraSonicData(uint8_t,uint8_t,uint8_t);
uint8_t getData();


#endif /* MB1000_H_ */