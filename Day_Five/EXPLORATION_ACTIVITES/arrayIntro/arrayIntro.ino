/*
  INTRO TO ARRAYS

  Girls Who Code
  Day 1: Intro to Arrays
  Example 1

  This example uses the LilyPad ProtoSnap Development Board to light the row of
  white LEDs using an array. Each LED pin is an element stored in an array. We access
  the LEDs by their index number (remember - we start counting at zero) to set the
  pinMode and turn them on and off.

*/

// set a variable to hold the delay() value
int timer = 500;

// declare and initalize your array
int ledPins[] = {5, 6, A2, A4, A3};

// int ledPins[5] = {5, 6, A2, A4, A3}; would also work

void setup() {
  // tell Arduino all of the pins in the array are outputs
  pinMode(ledPins[0], OUTPUT); // set pin 5 to output
  pinMode(ledPins[1], OUTPUT); // set pin 6 to output
  pinMode(ledPins[2], OUTPUT); // set pin A2 to output
  pinMode(ledPins[3], OUTPUT); // set pin A4 to output
  pinMode(ledPins[4], OUTPUT); // set pin A3 to output

}

void loop() {
  // turn on pin 5
  digitalWrite(ledPins[0], HIGH);
  delay(timer);
  digitalWrite(ledPins[0], LOW);
  delay(timer);

  // turn on pin 6
  digitalWrite(ledPins[1], HIGH);
  delay(timer);
  digitalWrite(ledPins[1], LOW);
  delay(timer);

  // turn on pin A2
  digitalWrite(ledPins[2], HIGH);
  delay(timer);
  digitalWrite(ledPins[2], LOW);
  delay(timer);

  // turn on pin A4
  digitalWrite(ledPins[3], HIGH);
  delay(timer);
  digitalWrite(ledPins[3], LOW);
  delay(timer);

  // the last led has gone missing!
  // write the statements to turn the final led on and off


}
