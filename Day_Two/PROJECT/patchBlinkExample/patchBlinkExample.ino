/*
  PATCH BLINK EXAMPLE

  Girls Who Code Campus
  Day 2: What Do You Stand For? Patch
  Project Example 2

  This example uses the slide switch, LEDs, and the LilyPad Arduino
  SimpleSnap to control the behavior of the LEDs.

  If the slide switch is off, the second LED will blink quickly.
  If the slide switch is on, the first LED will blink slowly.

  This sketch uses the button tutorial (File > Examples > Digital >
  Button) or http://www.arduino.cc/en/Tutorial/Button

*/

// constants won't change. They're used here to
// set pin numbers:
const int buttonPin = A2;     // the number of the pushbutton pin
const int ledPin =  6;      // the number of the LED pin
const int ledPin2 = A5;
const int fastBlink = 30;
const int slowBlink = 500;


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

    // blink the first LED
    digitalWrite(ledPin, HIGH);
    delay(fastBlink);
    digitalWrite(ledPin, LOW);
    delay(fastBlink);

  }
  else {

    // blink the second LED
    digitalWrite(ledPin2, HIGH);
    delay(slowBlink); //
    digitalWrite(ledPin2, LOW);
    delay(slowBlink);


  }
}
