/*
  FOR() LOOPS && ARRAYS

  Girls Who Code
  Day 1: Intro to Loops + Arrays
  Example 5

  This example uses the LilyPad ProtoSnap Development Board to light the whiteLEDs
  in sequence using a for() loop and arrays.

  This sketch uses the For() loop example (Examples > Control > ForLoopIteration or
  http://www.arduino.cc/en/Tutorial/ForLoop) and the Array example (Examples > Control >
  Arrays or http://www.arduino.cc/en/Tutorial/Array).

*/

// set a variable to hold the delay() value
int timer = 1000;     // increase it to slow down the loop

int ledPins[] = {5, 6, A2, A4, A3};

int pinCount = 5;

void setup() {
  //The loop runs through each pin and tells the Arduino it is an output
  for (int thisPin = 0; thisPin < pinCount; thisPin++) {
    // we access the pin we need by indexing it in the array
    pinMode(ledPins[thisPin], OUTPUT);
  }
  /*
     This is the same as saying:
     pinMode(5, OUTPUT);
     pinMode(6, OUTPUT);
     pinMode(A2, OUTPUT);
     pinMode(A4, OUTPUT);
     pinMode(A3, OUTPUT);
  */

  // start serial communication
  Serial.begin(9600);
}

void loop() {
  // cycle through the pins to turn each LED on and off:
  for (int thisPin = 0; thisPin < pinCount; thisPin++) {
    Serial.println("//----NEW CYCLE THROUGH THE FOR LOOP---->>");

    // we access the pin we need by indexing it in the array
    // turn the pin on:
    digitalWrite(ledPins[thisPin], HIGH);

    // we access the pin we need by indexing it in the array
    // print status to the serial monitor
    Serial.print(ledPins[thisPin]);
    Serial.println(" is on");

    // hold for a bit
    delay(timer);

    // we access the pin we need by indexing it in the array
    // turn the pin off:
    digitalWrite(ledPins[thisPin], LOW);

    // we access the pin we need by indexing it in the array
    // print status to the serial monitor
    Serial.print(ledPins[thisPin]);
    Serial.println(" is off");
  }

  Serial.println("*****END THIS FOR LOOP CYCLE*****");

}
