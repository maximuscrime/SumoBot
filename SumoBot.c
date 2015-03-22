/*
 * SumoBot.c
 *
 * Created: 11/8/2014 7:08:39 PM
 *  Author: Jacob
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include "MotorDrive.h"
#include "Sensors.h"
#include "USART.h"
#define F_CPU 20000000UL //Make sure you change the fuses to 20MHz
#include <util/delay.h>
#include <stdbool.h>

enum DriveState 
{
	SEARCHING,
	REVERSING,
	ATTACKING	
};

enum DriveState state = SEARCHING;
uint16_t count = 0; 
volatile bool ADCFlag = false;
volatile bool UARTFlag = false;
uint8_t data;
uint16_t ultraSonic[3];	

int main(void)
{	
	sei();
	_delay_ms(1000);	
	initSensors();
	initMotorDriver();	
	
    while(1)
    {
        if(UARTFlag == true)
	{
		if (state == SEARCHING)
		{
			count = 0;
			//Read data and load it into Sensors or find some way to deal with it
			data = USARTInfo();
		
			if(data == 'R')
			{
				for(int i = 0; i < 3; i++)
				{
					ultraSonic[i] = USARTInfo();
				}
				data = convertUltraSonicData(ultraSonic[0], ultraSonic[1], ultraSonic[2]);
				if (data < 8)
				{
					state = ATTACKING;
					driveDirection(BACKWARD, FAST);
					do
					{
						data = USARTInfo();
						if(data == 'R')
						{
							for(int i = 0; i < 3; i++)
							{
								ultraSonic[i] = USARTInfo();
							}
							data = convertUltraSonicData(ultraSonic[0], ultraSonic[1], ultraSonic[2]);
							if (data < 8)
							{
								state = ATTACKING;
							}
							else
							{
								driveDirection(LEFT, NORMAL);
								state = SEARCHING;
							}
						}
					} while (state == ATTACKING);
				}
				else
				{
					driveDirection(LEFT, NORMAL);
				}
			}
		}
		else if(state == REVERSING)
		{
			count++;
			if (count == 20)
			{
				driveDirection(LEFT, NORMAL);
				state = SEARCHING;
				count = 0;
			}
		}
		UARTFlag = false;
	}
	else if(ADCFlag == true)
	{
		//Read data and load it into Sensors or find some way to deal with it
		struct ADCResult data = ADCInfo(); 
	
		if (state == SEARCHING)
		{
			count = 0;
		} 
		else
		{
			count++;
			if (count == 20)
			{
				driveDirection(LEFT, NORMAL);
				state = SEARCHING;
				count = 0;
			}
		}
		
		switch(data.Source)
		{
			case IR_PROXIMITY_SENSOR :
			if ((data.Result > 600))
			{
				driveDirection(FORWARD, FAST);
				state = ATTACKING;
				do
				{
					_delay_ms(75);
					changeToIR_PROXIMITY();
					startNewADCConversion();
					data = ADCInfo();
					if (data.Result > 600)
					{
						state = ATTACKING;
					}
					else
					{
						state = SEARCHING;
					}
				} while (state == ATTACKING);
			}
			else
			{
				if (state == REVERSING)
				{} 
				else
				{
					driveDirection(LEFT, NORMAL);
				}	
			}
			break;
		
		case REAR_FLOOR_SENSOR :
			if (data.Result < 675)
			{
				driveDirection(BACKWARD, FAST);
				state = REVERSING;
				_delay_ms(750);
			}
			else
			{
				if (state == REVERSING)
				{}
				else
				{
					driveDirection(LEFT, NORMAL);
				}
			}
			break;
		}	
		startNewADCConversion();		//Change
		ADCFlag = false;
	}
    }
}

ISR(USART_RX_vect)
{
	UARTFlag = true;
}

ISR(ADC_vect)
{
	ADCFlag = true;
}