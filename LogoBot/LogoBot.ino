/********************************************************************
  Code to allow the MRK-1 sumo robot to be operated using simple Logo commands

  This code was built off of the Lesson 8, Competitive Sumo Robot
  http://github.com/SumoRobotLeague/MRK-1/

  For more information about the Logo programming language visit
  http://el.media.mit.edu/logo-foundation/what_is_logo/index.html

  
  ********************************************************************/

#include "Motor.h"
#include "Pitches.h"

/************************/
/** PIN CONFIGURATIONS **/
/************************/
// LED pin
#define led 7

// IR Sensor pins
#define leftSensor  A1
#define rightSensor A2
#define IREmitter   6

// Hardware pins
#define button 2
#define buzzer 5

// Ultrasonic sensor pins
#define echoPin A0
#define pingPin 3

// Motor pins
#define rightMotorSpeed     10
#define rightMotorDirection 8
#define leftMotorSpeed      9
#define leftMotorDirection  4

/*************************************************/
/** Global Variables and Configuration Settings **/
/*************************************************/
// Competition configuration settings
int moveSpeed = 200;  //speed can vary from 0, stopped, to 255, full speed
int moveTime = 200;  //duration in ms of movement in command such as forward

// Create our motor object
Motor motor;


void setup() {
	Serial.begin(9600);

	// pin setup
	pinMode(button, INPUT_PULLUP);
	pinMode(buzzer, OUTPUT);

	// IR sensors
	pinMode(leftSensor,  INPUT);
	pinMode(rightSensor, INPUT);
	pinMode(IREmitter,   OUTPUT);

	// Turn on our IR Emitter
	digitalWrite(IREmitter, HIGH);

	// ultrasonic sensors
	pinMode(pingPin, OUTPUT);
	pinMode(echoPin, INPUT);

	// Motor setup
	motor.setupRight(rightMotorSpeed, rightMotorDirection);
	motor.setupLeft(leftMotorSpeed, leftMotorDirection);

	Serial.println("Robot powered up. Awaiting Logo commands via serial communication");
}

void loop() {
  
}


/***************************************************************/
/**      Commands from Logo's TORTIS project,                 **/
/** a pushbutton system for children to young to read and type**/
/***************************************************************/

// forward, aka FD
void FD(int amt){{
  
}

// backward, aka BD
void BD(int amt){
  
}

// turn left, aka LT
void LT(int amt){
  
}

// turn right, aka RT
void RT(int amt){
  
}

void toot(){

}

void pen_up(){
  
}

void pen_down(){
  
}

void light_on(){
  
}

void light_off(){
  
}

// play a Note, not an authentic Logo command, just fun to use.
void NT(int note, int duration) {
	tone(buzzer, note, duration);
	delay(duration);
}

