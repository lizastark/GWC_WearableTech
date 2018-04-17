/*
  INTRO TO FOR() LOOPS

  Girls Who Code
  Day 1: Intro to Loops
  Example 2

  This example uses the LilyPad ProtoSnap Development Board to
  blink an LED on pin 5 ten times using a for() loop, then blink
  an LED on pin 6 once.

*/

int ledPinOne = 5; // led to blink ten times
int ledPinTwo = 6; // led to blink once

void setup() {
  // tell Arduino all of the pins in the array are outputs
  pinMode(ledPinOne, OUTPUT);
  pinMode(ledPinTwo, OUTPUT);

}

void loop() {
  // blink ledPinOne ten times:
  for (int i = 1; i < 11; i++) {
    digitalWrite(ledPinOne, HIGH);
    delay(100);
    digitalWrite(ledPinOne, LOW);
    delay(100);
  }

  // blink ledPinTwo once after the program exits the for() loop:
  digitalWrite(ledPinTwo, HIGH);
  delay(100);
  digitalWrite(ledPinTwo, LOW);
  delay(100);


}
