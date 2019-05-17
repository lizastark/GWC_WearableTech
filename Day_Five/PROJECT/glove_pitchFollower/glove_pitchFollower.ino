/*
  SOUND GLOVE: PITCH FOLLOWER

  Girls Who Code Campus
  Day 5: Sound Glove
  Example 1

  This example uses a handmade bend sensor, buzzer, and LilyPad
  Arduino SimpleSnap to create a wearable device that controls
  pitch though motion.

  When you bend your finger, the LilyPad Arduino plays a sound.
  The pitch changes based on how much you bend it.

  The LilyPad Arduino reads the analog values coming in, then maps
  them to a specific range of pitches. If you are not getting any
  sound or values in the serial monitor, use the sketch without mapping
  then adjust the mapped values.

  This sketch is adapted from the Pitch follower example (Examples >
  Digital > pitchFollower).

*/

// don't forget to create the pitches.h tab!
#include "pitches.h"

// variables to store the bend sensor and buzzer pins
int buzzerPin = A3;
int bendSensorPin = A9;

// variable to store the values from the bend sensor
int bendSensorReading;

void setup() {

  //Tell Arduino we want this pin to be an output
  pinMode(buzzerPin, OUTPUT);

  //We need to activate a special functionality to reduce the
  //noise in our sensor. If you don't use INPUT_PULLUP
  pinMode(bendSensorPin, INPUT_PULLUP);

  //Start the serial monitor
  Serial.begin(9600);

}

void loop() {

  // read the sensor:
  bendSensorReading = analogRead(bendSensorPin);

  // print the sensor reading so you know its range
  Serial.print("Raw bend sensor reading = ");
  Serial.print(bendSensorReading);
  Serial.print("\t");

  // map the analog input range (in this case, 120 - 450 from
  // the bend sensor) to the output pitch range (75 - 1700Hz)
  // change the minimum and maximum input numbers below depending
  // on the range your sensor's giving.
  // map(value, fromLow, fromHigh, toLow, toHigh)

  int myPitch = map(bendSensorReading, 29, 42, 75, 1700);

  //print the new mapped value to see the pitch frequency
  Serial.print("Pitch frequency = ");
  Serial.println(myPitch);

  // play the pitch:
  tone(buzzerPin, myPitch, 10);
  delay(1);        // delay in between reads for stability
}
