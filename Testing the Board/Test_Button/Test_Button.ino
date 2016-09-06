#define pushButton 2

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  delay(100);
  // make the pushbutton's pin an input:
  pinMode(pushButton, INPUT_PULLUP);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
  int buttonState = digitalRead(pushButton);
  // print out the state of the button:
  Serial.println(buttonState);
  delay(100);        // delay in between reads for stability
}



