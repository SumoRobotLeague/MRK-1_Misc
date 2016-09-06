
#include <SoftwareSerial.h>  //for the bluetooth communication

#define LeftSpeedPin 9
#define RightSpeedPin 10
#define LeftDirPin 4
#define RightDirPin 8

//Bluetooth over Serial
#define TXpin A5  //connects to the bluetooth's RXD
#define RXpin A4  //connects to the bluetooth's TXD

SoftwareSerial mySerial(RXpin, TXpin); 

int btNumber1 = 0;
int btNumber2 = 0;
int leftMotor = 0;
int rightMotor = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(50);

  mySerial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(8);  
  //read from bluetooth and print it via the USB serial connection
  if(mySerial.available()>1){  ///**Does this need to change for 4-byte numbers
    
    btNumber1 = mySerial.read();
    btNumber2 = mySerial.read();

       leftMotor = map(btNumber1, 1, 199, -255, 255);  // convert the 3 to 253 speed being received from bluetooth to a number from -255 to 255
        Serial.print(" Left speed: ");
        Serial.print(String(leftMotor, DEC));
       rightMotor = map(btNumber2, 1, 199, 255, -255); 
        Serial.print(" Right speed: ");
        Serial.print(String (rightMotor, DEC));
        Serial.println(" ");
    
  }

     setLeftSpeed(leftMotor);
     delayMicroseconds(5);
     setRightSpeed(rightMotor);
     delayMicroseconds(5);

}

  

void setLeftSpeed(int Lspeed){
  if (Lspeed==0){
    analogWrite(LeftSpeedPin, 0);
    digitalWrite(LeftDirPin, LOW);
    //Serial.println("Setting left speed to 0");
    
  } else {
    if(Lspeed>0){
      digitalWrite(LeftDirPin, HIGH);
      analogWrite(LeftSpeedPin, Lspeed);
      //Serial.println("Left Fwd");
      
    }
    if(Lspeed<0){
      digitalWrite(LeftDirPin, LOW);
      analogWrite(LeftSpeedPin, abs(Lspeed) );
      //Serial.println("Left Bck");      
      
    }
  }
  
}

void setRightSpeed(int Rspeed){
    if (Rspeed==0){
    analogWrite(RightSpeedPin, 0);
    digitalWrite(RightDirPin, LOW);
    //Serial.println("Setting Right Speed to 0");
  } else {
    if(Rspeed>0){
      digitalWrite(RightDirPin, HIGH);
      analogWrite(RightSpeedPin, Rspeed);
      //Serial.println("Right Fwd");
    }
    if(Rspeed<0){
      digitalWrite(RightDirPin, LOW);
      analogWrite(RightSpeedPin, abs(Rspeed) );
      //Serial.println("Right Bck");      
   }
  }
}

