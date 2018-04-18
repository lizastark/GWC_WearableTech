/*
  SOUND GLOVE: TONE SERIES

  Girls Who Code Campus
  Day 5: Sound Glove
  Example 2

  This example uses a handmade bend sensor, buzzer, and LilyPad
  Arduino SimpleSnap to create a wearable device that controls
  a sequence of tones though motion.

  The program plays a different series of tones for different positions
  of the finger: extended, at rest, or bent. It uses arrays, for() loops,
  and functions.

*/

// don't forget to create the pitches.h tab!
#include "pitches.h"

// variables to store the bend sensor and buzzer pins
int buzzerPin = 9;
int bendSensorPin = A3;

// variable to store the values from the bend sensor
int bendSensorReading;

// arrays to store the sequence of tones
int extendedTones[] = {NOTE_F2, NOTE_C2, NOTE_G2};
int flatTones[] = {NOTE_F4, NOTE_C4, NOTE_G4};
int bentTones[] = {NOTE_F6, NOTE_C6, NOTE_G6,};

// timing variables
int toneDuration = 200;
int noteCount = 3;
int pauseBetweenNotes = 100;



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
  Serial.print("Bend sensor reading = ");
  Serial.print(bendSensorReading);
  Serial.print("\t");

  if (bendSensorReading < 350) {
    playBent();
    Serial.println("Finger bent");


  } else if (bendSensorReading > 350 && bendSensorReading < 550) {
    playExtended();
    Serial.println("Finger extended");

  } else if (bendSensorReading > 550) {
    playFlat();
    Serial.println("Finger flat");

  } else {
    return;

  }

}

void playExtended() {
  for (int thisNote = 0; thisNote < noteCount; thisNote++) {
    tone(buzzerPin, extendedTones[thisNote], toneDuration);
    delay(pauseBetweenNotes);

  }

  noTone(buzzerPin);
}

void playFlat() {
  for (int thisNote = 0; thisNote < noteCount; thisNote++) {
    tone(buzzerPin, flatTones[thisNote], toneDuration);
    delay(pauseBetweenNotes);

  }

  noTone(buzzerPin);
}

void playBent() {
  for (int thisNote = 0; thisNote < noteCount; thisNote++) {
    tone(buzzerPin, bentTones[thisNote], toneDuration);
    delay(pauseBetweenNotes);

  }

  noTone(buzzerPin);

}

