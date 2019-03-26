/*

   Tilt Debouncer
   By Your Name(s)
   This sketch uses conditionals, operators, and a timing function called millis()
   to make sure the tilt switch is actually tilted and not just experiencing noise.

   This code is based on the "Better Debouncer" example by Lady Ada that you can find here:
   http://www.ladyada.net/learn/sensor/tilt.html

    NOTE: YOU DO NOT NEED TO WRITE IN ALL THE COMMENTS! THERE'S A LOT AND WE HAVE
    A LOT TO COVER. YOU CAN ADD THEM IN LATER.

*/


int tiltPin = 10;      // the number of the tilt pin 
                       // pin 10 on Plus Board, pin 5 on SimpleSnap
int tiltState;         // the current reading from the tilt pin

int ledPin = A8;       // the number of the LED pin 
                      // pin A8 on Plus Board, pin 9 on SimpleSnap
int vibePin = 11;     // the number of the vibe motor pin 
                      // pin 11 on Plus Board, pin 6 on SimpleSnap

int outputState = HIGH;   // the current state of the output pins

int previousTiltState = LOW;    // the previous reading from the input pin

// the following variables are long because the time, measured in milliseconds,
// will quickly become a bigger number than can be stored in an int.
long time = 0;         // the last time the tilt switch changed states
//(i.e. from on to off or off to on)

long debounce = 50;    // the debounce time (i.e. how much time we wait to make
// sure the button is really pressed - increase if the output flickers


void setup()
{
  pinMode(tiltPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  pinMode(vibePin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int switchState; //declare the variable that will hold the debounced reading later

  tiltState = digitalRead(tiltPin);
  Serial.println(tiltState);

  // If the switch changed, due to bounce or pressing...
  if (tiltState != previousTiltState) {
    // reset the debouncing timer
    time = millis();
  }

  if ((millis() - time) > debounce) {
    // whichever way the sensor is tilted, it's been that way long
    // enough for us to know it has actually changed states
    switchState = tiltState;
  }

  // invert the output so the LED turns
  // on when the switch is closed
  if (switchState == HIGH) {
    outputState = LOW;
  }
  else {
    outputState = HIGH;
  }

  digitalWrite(ledPin, outputState);
  digitalWrite(vibePin, outputState);

  // save the last reading so we can check it again in the next round
  previousTiltState = tiltState;
}
