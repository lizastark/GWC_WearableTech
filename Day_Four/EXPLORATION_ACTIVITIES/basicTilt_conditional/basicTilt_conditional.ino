/*
 * Tilt Switch with Output
 * By Liza
 * This sketch uses digitalWrite() to read a tilt swtich and
 * turn an  LED and vibe motor on or off based on the orientation
 * of the tilt switch.
 * 
 */

int tiltPin = 10;      // the number of the tilt pin
int tiltState;         // the current reading from the tilt pin

int ledPin = A8;       // the number of the LED pin
int vibePin = 11;      // the number of the vibe motor pin

int outputState = HIGH;   // the current state of the output pins

void setup() {
  // put your setup code here, to run once:
  pinMode(tiltPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  pinMode(vibePin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  tiltState = digitalRead(tiltPin);
  Serial.println(tiltState);

  // invert the output so the LED turns
  // on when the switch is closed
  if (tiltState == HIGH) {
    outputState = LOW;
  }
  else {
    outputState = HIGH;
  }

  digitalWrite(ledPin, outputState);
  digitalWrite(vibePin, outputState);

}
