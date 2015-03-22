/*
 * MotorDrive.h
 *
 * Created: 11/8/2014 7:16:08 PM
 *  Author: Jacob
 */ 


#ifndef MOTORDRIVE_H_
#define MOTORDRIVE_H_

enum Direction
{
	RIGHT,
	LEFT,
	FORWARD,
	BACKWARD	
};

enum Speed
{
	NORMAL,
	FAST
};

void initMotorDriver(void);
void driveDirection(enum Direction, enum Speed);
void forwards(void);
void backwards(void);
void turnLeft(void);
void turnRight(void);

#endif /* MOTORDRIVE_H_ */