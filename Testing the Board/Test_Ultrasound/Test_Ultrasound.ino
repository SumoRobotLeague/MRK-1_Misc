#define echo_Pin  8
#define pingPin  7

void setup() {
  Serial.begin(9600);
  pinMode(echo_Pin, INPUT);
  pinMode(pingPin, OUTPUT);

  // initialize serial communication:
  Serial.begin(9600);
}

void loop() {

  long duration, inches, cm;

  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(10);   //manufacturer recommends at least 10 microseconds
  digitalWrite(pingPin, LOW);

  // record how long it takes to get an echo
  duration = pulseIn(echo_Pin, HIGH);

  // convert the time into a distance
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);

  Serial.print(inches);
  delay(100);
  Serial.print("in, ");
  delay(100);
  Serial.print(cm);
  delay(100);
  Serial.print("cm");
  delay(100);
  Serial.println();
  delay(100);

  delay(500);
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

