/*
  MELODY

  Girls Who Code
  Day 1: Intro to Loops + Arrays
  Example 6

  This example uses the LilyPad ProtoSnap Development Board to play a melody on
  the buzzer using for() loops and arrays.

  This sketch uses the toneMelody example (Examples > Digital > toneMelody or
  (http://www.arduino.cc/en/Tutorial/Tone).

*/

// don't forget to make a new tab named pitches.h and copy/paste ALL of the notes there
// https://github.com/lizastark/GWC_WearableTech/blob/master/Day_Five/EXPLORATION_ACTIVITES/melody/pitches.h
#include "pitches.h"

// variable to store our speaker pin
int speaker = 5;

// variable to store the number of notes in our array
int noteCount = 8;

// array to store the notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// array to store how long each note is played
int noteDurations[] = {
  250, 125, 125, 250, 250, 250, 250, 250
};

void setup() {
  //tell Arduino this is an output
  pinMode(speaker, OUTPUT);

}

void loop() {
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < noteCount; thisNote++) {
    // cycle through the notes
    tone(speaker, melody[thisNote], noteDurations);

    // to distinguish the notes, we need to set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDurations[thisNote] * 1.30;
    delay(pauseBetweenNotes);

    // stop the tone playing:
    noTone(speaker);
  }
  // delay a bit between each melody
  delay(2000);
}
