/*
 * Sensors.c
 *
 * Created: 11/8/2014 7:20:26 PM
 *  Author: Jacob
 */ 

#include "Sensors.h"
#include "MB1000.h"
#include <stdint.h>

void initSensors(void)
{
	/* Initialize all of the sensors and set USART */
	initAnalogSensors();
	initMB1000();
}

uint8_t USARTInfo(void)
{
	return getData();
}

struct ADCResult ADCInfo(void)
{
	struct ADCResult Info; 
	
	switch(getADCConverted())
	{
		case IR_PROXIMITY_SENSOR :
			Info.Source = IR_PROXIMITY_SENSOR;
			changeADCSource(REAR_FLOOR_SENSOR);
			break;
		case REAR_FLOOR_SENSOR :
			Info.Source = REAR_FLOOR_SENSOR;
			changeADCSource(IR_PROXIMITY_SENSOR); //Should be Right_IR_Sensor if using
			break;
	}
	
	Info.Result = getADCResult();
	return Info;
}

void startNewADCConversion(void)
{	startConversion();	}
	


void changeToIR_PROXIMITY()
{
	changeADCSource(IR_PROXIMITY_SENSOR);
}