/*
 * Sensors.h
 *
 * Created: 11/8/2014 7:20:38 PM
 *  Author: Jacob
 */ 


#ifndef SENSORS_H_
#define SENSORS_H_

#include "ADC.h"
#include "USART.h"
#include <stdint.h>

#define FRONT_FLOOR_SENSOR_1 ADC1
#define FRONT_FLOOR_SENSOR_2 ADC3
#define REAR_FLOOR_SENSOR ADC2
#define RIGHT_IR_SENSOR ADC5
#define LEFT_IR_SENSOR ADC4
#define IR_PROXIMITY_SENSOR ADC0

struct ADCResult  
{
	uint8_t Source;
	uint16_t Result;
};

void initSensors(void);
uint8_t USARTInfo(void);
struct ADCResult ADCInfo(void);
void startNewADCConversion(void);
void changeToIR_PROXIMITY();

#endif /* SENSORS_H_ */