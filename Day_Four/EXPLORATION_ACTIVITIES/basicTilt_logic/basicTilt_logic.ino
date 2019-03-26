/*
 * Tilt Switch with Normal Logic
 * 
 * This sketch reverses the inverted logic of the tilt switch
 * by storing the tiltState in a new variable and switching
 * HIGH and LOW
 * 
 */

int tiltPin = 10; // the number of the tilt pin
int tiltState;    // the current reading from the tilt pin
int outputState;  // the variable to invert the logic     

void setup() {
  // put your setup code here, to run once:
  pinMode(tiltPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  tiltState = digitalRead(tiltPin);
  if (tiltState == HIGH) {
    outputState = LOW;
  } else {
    outputState = HIGH;
  }

  Serial.println(outputState);
}
