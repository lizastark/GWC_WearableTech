/*
  FUNCTION WITH A BUTTON

  Girls Who Code
  Day 4: Using functions with a button
  Example 4

  This example uses the LilyPad ProtoSnap Development Board to turn LEDs on and off
  using a push button.

*/

// constants won't change. They're used here to
// set pin numbers:
const int buttonPin = A5;     // the number of the push button pin
const int ledOne = 5;
const int ledTwo = 6;
const int ledThree = A2;
const int ledFour = A4;
const int ledFive = A3;


// variables will change:
int buttonState = 0;         // variable for reading the push button status

void setup() {
  //Start the serial monitor
  Serial.begin(9600);

  // tell Arduino these are outputs
  pinMode(ledOne, OUTPUT);
  pinMode(ledTwo, OUTPUT);
  pinMode(ledThree, OUTPUT);
  pinMode(ledFour, OUTPUT);
  pinMode(ledFive, OUTPUT);

  // initialize the push button pin as an input:
  pinMode(buttonPin, INPUT_PULLUP);

}

void loop() {
  // read the state of the push button value:
  buttonState = digitalRead(buttonPin);

  // check if the push button is pressed.
  if (buttonState == LOW) {

    turnOnEvenLEDs();

  } else {

    turnOnOddLEDs();

  }

}

// turn on all the even LEDs in bottom row
void turnOnEvenLEDs() {

  digitalWrite(ledOne, LOW);
  digitalWrite(ledTwo, HIGH);
  digitalWrite(ledThree, LOW);
  digitalWrite(ledFour, HIGH);
  digitalWrite(ledFive, LOW);

  //for debugging
  Serial.println("Evens are on!");

}

// turn on all the odd LEDs in bottom row
void turnOnOddLEDs() {

  digitalWrite(ledOne, HIGH);
  digitalWrite(ledTwo, LOW);
  digitalWrite(ledThree, HIGH);
  digitalWrite(ledFour, LOW);
  digitalWrite(ledFive, HIGH);

  //for debugging
  Serial.println("Odds are on!");

}
