/*
   Push Button with Variables
   By Your Names(s)

   This sketch uses if statements to turn an LED on if the button
   is pressed and off if the button is not pressed.

*/

void setup() {
  // put your setup code here, to run once:
  //LEDs
  pinMode(A8, OUTPUT);

  //push button
  pinMode(A4, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:

  //check to see if button is pressed
  if (digitalRead(A4) == LOW) {

    //if pressed, turn on LED
    digitalWrite(A8, HIGH);
  }
  else {

    // if not pressed, turn off LED
    digitalWrite(A8, LOW);
  }
}

