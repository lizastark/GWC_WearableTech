/*
  FADE (ANALOG OUTPUT)

  Girls Who Code
  Day 3: Analog Output

  This example uses the LilyPad ProtoSnap Plus board to fade an LED on pin A8 using 
  the analogWrite() function. This function uses Pulse Width Modulation (PWM) so 
  if you want to use this sketch with another pin, it must be PWM-enabled. You can usually
  tell because a pin will have a "~" before it (e.g. ~A8)

  This sketch uses the Fade example (File > Examples > Basic >
  Fade) or http://www.arduino.cc/en/Tutorial/Fade.

 
*/

int ledPin = A8;       // the PWM pin the LED is attached to
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by. Try tinkering with this 
                       // value to change the fade speed.

// the setup routine runs once when you press reset:
void setup() {
  // declare pin A8 to be an output:
  pinMode(ledPin, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // set the brightness of pin A8:
  analogWrite(ledPin , brightness);

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(30);
}
