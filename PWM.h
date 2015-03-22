/*
 * PWM.h
 *
 * Created: 11/10/2014 12:08:53 AM
 *  Author: Jacob
 */ 


#ifndef PWM_H_
#define PWM_H_
#define compareValue 39999
#define DUTY_CYCLE_0 compareValue
#define DUTY_CYCLE_5 38000
#define DUTY_CYCLE_10 36000
#define DUTY_CYCLE_11 35600
#define DUTY_CYCLE_12 35200
#define DUTY_CYCLE_13 34800
#define DUTY_CYCLE_14 34400
#define DUTY_CYCLE_15 34000
#define DUTY_CYCLE_16 33600
#define DUTY_CYCLE_17 33200
#define DUTY_CYCLE_18 32800
#define DUTY_CYCLE_19 32400
#define DUTY_CYCLE_20 32000
#define DUTY_CYCLE_21 31600
#define DUTY_CYCLE_22 31200
#define DUTY_CYCLE_23 30800
#define DUTY_CYCLE_24 30400
#define DUTY_CYCLE_25 30000
#define DUTY_CYCLE_30 28000
#define DUTY_CYCLE_35 26000
#define DUTY_CYCLE_40 24000
#define DUTY_CYCLE_45 22000
#define DUTY_CYCLE_50 20000
#define DUTY_CYCLE_55 18000
#define DUTY_CYCLE_60 16000
#define DUTY_CYCLE_65 14000
#define DUTY_CYCLE_70 12000 
#define DUTY_CYCLE_75 10000
#define DUTY_CYCLE_80 8000
#define DUTY_CYCLE_85 6000
#define DUTY_CYCLE_90 4000
#define DUTY_CYCLE_95 2000
#define DUTY_CYCLE_100 0

#include <stdint.h>

void initPWM(void);
void changeDutyCycleOCR1A(uint16_t);
void changeDutyCycleOCR1B(uint16_t);

#endif /* PWM_H_ */