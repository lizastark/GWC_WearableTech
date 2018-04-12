/*
  ADD SLIDE SWITCH

  Girls Who Code
  Day 2: Button Power Challenge
  Example 3

  This example uses the LilyPad Development Board to turn the green LED on when the slide
  switch is on and the red LED on when the slide switch is off.

*/

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;   // the number of the slide switch pin

const int redLED =  9;      // the number of the red LED pin
const int greenLED = 11;    // the number of the green LED pin


// variables will change:
int buttonState = 0;         // variable for reading the slide switch state 

void setup() {
  // put your setup code here, to run once

  // initialize the LEDs as outputs:
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

  // initialize the slide switch pin as an input:
  pinMode(buttonPin, INPUT_PULLUP);

}

void loop() {
  // put your main code here, to run repeatedly

  // read the state of the switch value:
  buttonState = digitalRead(buttonPin);

  // check if the slide switch is on or off.
  // if it on, the buttonState is HIGH:
  if (buttonState == HIGH) {

    // turn on the green LED on and the red LED off:
    digitalWrite(greenLED, HIGH);
    digitalWrite(redLED, LOW);

  }
  else {
    // if the slide switch is off, turn the red LED on
    // and the green LED off
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, HIGH);
  }

}
