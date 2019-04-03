/*
  TONE EXAMPLE

  Girls Who Code Campus
  Day 5: Get Noisy
  Example 1

  This example uses the  LilyPad ProtoSnap Plus board
  to control the pitch of the buzzer.

  tone(pin, frequency)
  tone(pin, frequency, duration)

  Parameters
  pin: the pin on which to generate the tone
  frequency: the frequency of the tone in hertz - unsigned int
  duration: the duration of the tone in milliseconds (optional) - unsigned long

*/

//tell Arduino to include the file with the notes in it
#include "pitches.h"

int buzzerPin = A3; //variable to store the buzzer pin

void setup() {
  // put your setup code here, to run once:

  //Tell Arduino we want this pin to be an output
  pinMode(buzzerPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  //Play a C note
  tone(buzzerPin, NOTE_C4);
  delay(500);

  //Play a G note
  tone(buzzerPin, NOTE_G3);
  delay(500);

  //Play an A note
  tone(buzzerPin, NOTE_A3);
  delay(500);

}
