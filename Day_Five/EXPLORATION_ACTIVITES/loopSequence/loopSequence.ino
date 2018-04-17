/*
  FOR() LOOP LED SEQUENCE

  Girls Who Code
  Day 1: Intro to Loops
  Example 3

  This example uses the LilyPad ProtoSnap Development Board to light LEDs 9-11 on the
  Tri-Color LED in sequence using a for() loop.

  This sketch uses the For() loop example (Examples > Control > ForLoopIteration or
  http://www.arduino.cc/en/Tutorial/ForLoop).

*/

// set a variable to hold the delay() value
int timer = 1000;     // increase it to slow down the loop

void setup() {
  //The loop runs through each pin and tells the Arduino it is an output
  for (int thisPin = 9; thisPin < 11; thisPin++) {
    pinMode(thisPin, OUTPUT);
  }
  /*
     This is the same as saying:
     pinMode(9, OUTPUT);
     pinMode(10, OUTPUT);
     pinMode(11, OUTPUT);
  */

  // start serial communication
  Serial.begin(9600);
}

void loop() {
  // loop from pin 9 to pin 11 to turn each LED on and off:
  for (int thisPin = 9; thisPin < 12; thisPin++) {
    Serial.println("//----NEW CYCLE THROUGH THE FOR LOOP---->>");

    // turn the pin on:
    digitalWrite(thisPin, HIGH);

    // print status to the serial monitor
    Serial.print(thisPin);
    Serial.println(" is on");

    // hold for a bit
    delay(timer);

    // turn the pin off:
    digitalWrite(thisPin, LOW);

    // print status to the serial monitor
    Serial.print(thisPin);
    Serial.println(" is off");
  }

  Serial.println("*****END THIS FOR LOOP CYCLE*****");

}
