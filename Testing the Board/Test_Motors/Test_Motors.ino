

#define leftMotorSpeed 9
#define rightMotorSpeed 10
#define leftDirection 4
#define rightDirection 8


void setup(){
  pinMode(leftMotorSpeed, OUTPUT);
  pinMode(rightMotorSpeed, OUTPUT);
  pinMode(leftDirection, OUTPUT);
  pinMode(rightDirection, OUTPUT);  

  Serial.begin(19200);
  delay(100);
}

void loop(){
  //Serial.print("1");
  setleftSpeed(-250);
  //Serial.println("Setting left to 180 and right to -180");
  setrightSpeed(250);
  delay(1200);
  completeMotorTest(); //runs our complete motor test
  //Delete or comment out the line above and write your own code in here
  //use pieces of code from the completeMotorTest() function below
  
  //What can you make the robot do?  
      //lines, Donuts, figure 8's, a box, spirograph art?
}


void completeMotorTest(){  //tests every possible speed in forward and reverse for each wheel
  int d = 4; //milliseconds given for each speed, 
  //using 2 ms enables this test be performed on a table or on the floor

//run left motor forward
  //ramp up the speed from stopped (0) to maximum forward speed (255)
  for (int speed = 0; speed <= 255; speed++){
    setleftSpeed(speed);
    delay(d);
  }
  //ramp down the left motor from maximum forward (255) speed to stopped (0)
  for (int speed = 255; speed >= 0; speed--){
    setleftSpeed(speed);
    delay(d);
  }
  
// run left motor backward
  //ramp up the speed from stopped to maximum backward speed (-255)
  for (int speed = 0; speed >= -255; speed--){
    setleftSpeed(speed);
    delay(d);
  }
  //ramp down the speed from maximum backward to stopped 
  for (int speed = -255; speed <= 0; speed++){
    setleftSpeed(speed);
    delay(d);
  }

  delay(500);  // wait a second

// run right motor forward
  //ramp up the speed
  for (int speed = 0; speed <= 255; speed++){
    setrightSpeed(speed);
    delay(d);
  }
  //ramp down the speed
  for (int speed = 255; speed >= 0; speed--){
    setrightSpeed(speed);
    delay(d);
  }
  
// run right motor backward
  //ramp up  
  for (int speed = 0; speed >= -255; speed--){
    setrightSpeed(speed);
    delay(d);
  }
  //ramp down
  for (int speed = -255; speed <= 0; speed++){
    setrightSpeed(speed);
    delay(d);
  }
  
  delay(500);  //wait a second
}

void setleftSpeed(int Lspeed){
  if (Lspeed==0){
    analogWrite(leftMotorSpeed, 0);
    digitalWrite(leftDirection, LOW);
    Serial.println("Setting left speed to 0");
    
  } else {
    if(Lspeed>0){
      digitalWrite(leftDirection, HIGH);
      analogWrite(leftMotorSpeed, Lspeed);
      Serial.println("left Fwd");
      
    }
    if(Lspeed<0){
      digitalWrite(leftDirection, LOW);
      analogWrite(leftMotorSpeed, abs(Lspeed) );
      Serial.println("left Bck");      
      
    }
  }
  
}

void setrightSpeed(int Rspeed){
    if (Rspeed==0){
    analogWrite(rightMotorSpeed, 0);
    digitalWrite(rightDirection, LOW);
    Serial.println("Setting right Speed to 0");
  } else {
    if(Rspeed>0){
      digitalWrite(rightDirection, HIGH);
      analogWrite(rightMotorSpeed, Rspeed);
      Serial.println("right Fwd");
    }
    if(Rspeed<0){
      digitalWrite(rightDirection, LOW);
      analogWrite(rightMotorSpeed, abs(Rspeed) );
      Serial.println("right Bck");      
   }
  }
}

