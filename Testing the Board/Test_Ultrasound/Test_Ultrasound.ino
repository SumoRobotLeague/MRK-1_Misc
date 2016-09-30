#define echo_Pin  8
#define pingPin  7

#define timeout 7000   //this timeout prevents the pulseIn function from waiting up to a second for a signal
// Sound travels 120 cm in 7000 microseconds which is more than the diameter of the mini-class sumo ring, or Dohyo.
// Any echoes received beyond this time would be irrelevant to mini-class sumo competition.  

void setup() {
  Serial.begin(9600);
  pinMode(echo_Pin, INPUT);
  pinMode(pingPin, OUTPUT);

  // initialize serial communication between the robot's arduino brain and your computer via USB cable
  Serial.begin(9600);
}

void loop() {

  long duration, inches, cm;

  // The PING))) or chirp of ultrasound is triggered by a HIGH pulse of at least 10 microseconds.
  // Make sure the pin is LOW before and after to ensure a clean HIGH pulse:
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(10);   //manufacturer recommends at least 10 microseconds
  digitalWrite(pingPin, LOW);

  // record how long it takes to get an echo but only up to the timeout value which is in microseconds
  duration = pulseIn(echo_Pin, HIGH, timeout);

  // convert the time into a distance
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);

  //print out the results on a single line
  Serial.print(duration);
  Serial.println(" us,  ");
  Serial.print(inches);
  Serial.print(" in,  ");
  Serial.print(cm);
  Serial.println(" cm");  //println prints what is inside the ( ) and then cues up a new line for the next print or println command.

  delay(500);  // delay so that you have time to read the printout in the serial monitor, remove this delay for competition
}

long microsecondsToInches(long microseconds)
{
  // According to Parallax's datasheet for the PING))), there are
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
  // second).  This gives the distance travelled by the ping, outbound
  // and return, so we divide by 2 to get the distance of the obstacle.
  // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}

