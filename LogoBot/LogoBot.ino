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
#define LED 7

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
int moveSpeed = 255;  //speed can vary from 0, stopped, to 255, full speed
int moveTime = 1000;  //duration in ms of movement in command such as forward

// Create our motor object
Motor motor;

// Strings and boolean for receiving Logo commands via serial communication
String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete


void setup() {
	Serial.begin(9600);
  inputString.reserve(600);
  inputString = "";

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
  Serial.println("Setup Right Motor");
	motor.setupLeft(leftMotorSpeed, leftMotorDirection);
  Serial.println("Setup Left Motor");
	Serial.println("Robot powered up. Awaiting Logo commands via serial communication");
}

void loop() {
   serialEvent(); //call the function
  // print the string when a newline arrives:
  if (stringComplete) {
    
    //Serial.println(inputString);
    executeCommand(inputString);
    
    // clear the string:
    inputString = "";
    stringComplete = false;
  }
}

//captures the command sent via serial
void serialEvent() {
  //Serial.println("Starting aggregation of serial characters");
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
   
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n' || inChar == ' ') {
      stringComplete = true;
    } else {
      inputString += inChar;
      Serial.print("adding character: ");
      Serial.println(inChar);
    }
  }
}

//TO DO - add the ability to parse out numbers following commands
//this version simply matches the command with the function and execute it
void executeCommand(String command){
  //command.toLowerCase();
  Serial.println(command);
  if (command == "forward" || command == "fd"){
    FD(moveTime);
    Serial.println("Moving forward");
  } else {
    if (command == "backward" || command == "bd"){
      BD(moveTime);
      Serial.println("Moving backward");
    } else {
      if (command == "right" || command == "rt"){
        RT(moveTime);
        Serial.println("Right Turn");
      } else {
        if (command == "left" || command == "lt"){
          LT(moveTime);
          Serial.println("Left Turn");
        } else {
          if (command == "toot"){
            toot();
            Serial.println("Toot");
          } else {
            if (command == "light_on"){
              light_on();
              Serial.println("Lights On");
            } else {
              if (command == "light_off"){
                light_off();
                Serial.println("Lights Off");
              } else {
                Serial.print("Unable to execute:_");
                Serial.println(command);
              }
            }
          }
        }
      }
    }
  }
  
}

/***************************************************************/
/**      Commands from Logo's TORTIS project,                 **/
/** a pushbutton system for children to young to read and type**/
/***************************************************************/

// forward, aka FD
void FD(int amt){
  motor.left(moveSpeed);
  motor.right(moveSpeed);
  delay(amt);
  motor.left(0);
  motor.right(0);
}

// backward, aka BD
void BD(int amt){
  motor.left(-moveSpeed);
  motor.right(-moveSpeed);
  delay(amt);
  motor.left(0);
  motor.right(0);
}

// turn left, aka LT
void LT(int amt){
  motor.left(-moveSpeed);
  motor.right(moveSpeed);
  delay(amt);
  motor.left(0);
  motor.right(0);
}

// turn right, aka RT
void RT(int amt){
  motor.left(moveSpeed);
  motor.right(-moveSpeed);
  delay(amt);
  motor.left(0);
  motor.right(0);
}

void toot(){
  NT(NOTE_G3, 400);
  delay(100);
  NT(NOTE_G3, 400);
}

void pen_up(){
  
}

void pen_down(){
  
}

void light_on(){
  digitalWrite(LED, HIGH);
}

void light_off(){
  digitalWrite(LED, LOW);
}

// play a Note, not an authentic Logo command, just fun to use.
void NT(int note, int duration) {
	tone(buzzer, note, duration);
	delay(duration);
}

