/*
   DAY 4 GWC CAMPUS
   Motion Changer Example
   By Your Name(s)
   This sketch controls the Motion Changer patch using the LilyPad Arduino SimpleSnap.
   It uses conditionals, operators, and custom functions. It also integrates debouncing
   to make sure the tilt switch is actually tilted and not just experiencing noise.

   This code is based on the "Better Debouncer" example by Lady Ada that you can find here:
   http://www.ladyada.net/learn/sensor/tilt.html

*/


int tiltPin = 5;      // the number of the tilt pin
int tiltState;         // the current reading from the tilt pin

int ledPin = 9;       // the number of the LED pin
int vibePin = 6;      // the number of the vibe motor pin

int outputState = HIGH;   // the current state of the output pins

int previousTiltState = LOW;    // the previous reading from the input pin

// the following variables are long because the time, measured in milliseconds,
// will quickly become a bigger number than can be stored in an int.
long time = 0;         // the last time the tilt switch changed states
//(i.e. from on to off or off to on)

long debounce = 50;    // the debounce time (i.e. how much time we wait to make
// sure the button is really pressed - increase if the output flickers

int switchState; //declare the variable that will hold the debounced reading later
// this is the variable we moved from the loop

void setup()
{
  pinMode(tiltPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  pinMode(vibePin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  tiltState = digitalRead(tiltPin);
  Serial.println(tiltState);

  checkTiltStateChange();

  checkDebounce();

  invertOutput();

  digitalWrite(ledPin, outputState);
  digitalWrite(vibePin, outputState);

  // save the last reading so we can check it again in the next round
  previousTiltState = tiltState;
}

void checkTiltStateChange() {
  // If the switch changed, due to bounce or pressing...
  if (tiltState != previousTiltState) {
    // reset the debouncing timer
    time = millis();
  }
}


void checkDebounce() {
  if ((millis() - time) > debounce) {
    // whichever way the sensor is tilted, it's been that way long
    // enough for us to know it has actually changed states
    switchState = tiltState;
  }
}


void invertOutput() {
  // invert the output so the LED turns
  // on when the switch is closed
  if (switchState == HIGH) {
    outputState = LOW;
  }
  else {
    outputState = HIGH;
  }
}


