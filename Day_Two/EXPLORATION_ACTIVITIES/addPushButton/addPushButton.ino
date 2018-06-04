/*
  ADD A PUSH BUTTON

  Girls Who Code
  Day 2: Button Power Challenge
  Example 1

  This example uses the LilyPad ProtoSnap Development Board to turn an LED on and off 
  using a push button.

  If the button is pressed, the LED turns on.
  If the button is not pressed, the LED is off.

  This sketch uses the Button example (File > Examples > Digital >
  Button) or http://www.arduino.cc/en/Tutorial/Button.

*/

// constants won't change. They're used here to
// set pin numbers:
const int buttonPin = A5;     // the number of the push button pin
const int ledPin =  A2;      // the number of the LED pin


// variables will change:
int buttonState = 0;         // variable for reading the push button status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  
  // initialize the push button pin as an input:
  pinMode(buttonPin, INPUT_PULLUP);
  
}

void loop() {
  // read the state of the push button value:
  buttonState = digitalRead(buttonPin);

  // check if the push button is pressed.
  if (buttonState == HIGH) {
    
    // turn LED off:
    digitalWrite(ledPin, LOW);
    
  }
  else {
    
    // turn LED on:
    digitalWrite(ledPin, HIGH);
    
  }
}
