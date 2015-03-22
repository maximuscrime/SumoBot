/*
 * ADC.h
 *
 * Created: 11/8/2014 7:11:30 PM
 *  Author: Jacob
 */ 


#ifndef ADC_H_
#define ADC_H_

#define ADC0 PINC0
#define ADC1 PINC1
#define ADC2 PINC2
#define ADC3 PINC3
#define ADC4 PINC4
#define ADC5 PINC5

#include <stdint.h>
#include <avr/io.h>

void initADC(void);
void startConversion(void);
void changeADCSource(uint8_t);
uint8_t getADCConverted(void);
uint16_t getADCResult(void);

#endif /* ADC_H_ */