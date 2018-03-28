/*
  PATCH EXAMPLE

  Girls Who Code Campus
  Day 2: What Do You Stand For? Patch
  Project Example 1

  This example uses the slide switch, LEDs, and the LilyPad Arduino
  SimpleSnap to control the behavior of the LEDs.

  If the slide switch is off, both LEDs will be off.
  If the slide switch is on, both LEDs will be on.

  This sketch uses the button tutorial (File > Examples > Digital >
  Button) or http://www.arduino.cc/en/Tutorial/Button

*/

// constants won't change. They're used here to
// set pin numbers:
const int buttonPin = A2;     // the number of the pushbutton pin
const int ledPin =  6;      // the number of the LED pin
const int ledPin2 = A5;


// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);

  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT_PULLUP);

  // start the serial monitor
  Serial.begin(9600);
}

void loop() {
  // read the state of the switch value:
  buttonState = digitalRead(buttonPin);

  // print it to the serial monitor
  Serial.println(buttonState);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {

    // turn both LEDs on:
    digitalWrite(ledPin, HIGH);
    digitalWrite(ledPin2, HIGH);


  }
  else {

    // turn LED off:
    digitalWrite(ledPin, LOW);
    digitalWrite(ledPin2, LOW);


  }
}
