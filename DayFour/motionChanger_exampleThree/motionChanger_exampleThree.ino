/*
  Girls Who Code Campus
  Day 4: Motion Changer Challenge
  Example 3

  This example uses the LilyPad accelerometer and the LilyPad Arduino
  SimpleSnap to create a wearable device that senses tilt.

  This sketch uses a counter to determine if a step has been taken.

   If the Motion Changer is oriented straight up, the yellow LED turns on.
   If the Motion Changer is oriented back, the blue LED turns on.
   If the Motion Changer is oriented forward, the green LED turns on.

  This sketch uses the Calibration example (Examples > Analog > Calibration or
  http://www.arduino.cc/en/Tutorial/Calibration) to help us get a better reading.
  During the first five seconds in setup(), it gathers the minimum and maximum values and
  maps, or adjusts, the incoming data to fit in that range.

  1) Upload the sketch.
  2) Open the serial monitor.
  3) When you see "Calibration Beginning", move your SVL ....

  Once you have it calibrated to the values you want, you can comment out that
  section of the setup() code.

*/


// These constants won't change:
const int zPin = A5;    // z axis pin

const int leftLED = 5;  // left LED pin - BLUE
const int middleLED = 6;  // middle LED pin - YELLOW
const int rightLED = 9;  // left LED pin - GREEN

// Variables that will change:
int zValue = 0;         // the z axis value
int zMin = 1023;        // minimum sensor value
int zMax = 0;           // maximum sensor value

int counter = 0; //Variable to store the count

int steps = 0; //Variable to store the number of steps

void setup() {

  Serial.begin(9600);

  /*
      This is the calibration part of the sketch. Once you upload it,
      open your serial monitor and follow the instuctions.
  */

  //Comment out here once you have calibrated
  /*
    // turn on LED to signal the start of the calibration period:
    pinMode(13, OUTPUT);
    digitalWrite(13, HIGH);

    Serial.println("Calibration beginning");

    // calibrate during the first five seconds
    while (millis() < 5000) {
    zValue = analogRead(zPin);

    // record the maximum sensor value
    if (zValue > zMax) {
      zMax = zValue;
    }

    // record the minimum sensor value
    if (zValue < zMin) {
      zMin = zValue;
    }
    }

    // signal the end of the calibration period
    digitalWrite(13, LOW);
    Serial.println("Calibration ending");
  */
  //End comment
}

void loop() {
  // read the sensor:
  zValue = analogRead(zPin);

  // apply the calibration to the sensor reading
  zValue = map(zValue, zMin, zMax, 0, 255);

  // in case the sensor value is outside the range seen during calibration
  zValue = constrain(zValue, 0, 255);

  //Print everything out in the serial monitor so we can
  //see the values coming in, the counter, and the number of steps
  Serial.print("Z axis = ");
  Serial.print(zValue);
  Serial.print("\t");
  Serial.print("Counter = ");
  Serial.print(counter);
  Serial.print("\t");
  Serial.print("Steps = ");
  Serial.println(steps);

  //Conditional to determine left/forward tilt
  if (zValue < 110) {
    digitalWrite(leftLED, HIGH);
    digitalWrite(middleLED, LOW);
    digitalWrite(rightLED, LOW);
    counter = 1;

    //Conditional to determine center orientation
  } else if (zValue > 110 && zValue < 130) {
    digitalWrite(middleLED, HIGH);
    digitalWrite(leftLED, LOW);
    digitalWrite(rightLED, LOW);
    counter = 2;

    //Conditional to determine right/backward tilt
  } else if (zValue > 130) {
    digitalWrite(rightLED, HIGH);
    digitalWrite(leftLED, LOW);
    digitalWrite(middleLED, LOW);
    counter = 3;

    //Just in case, turn off all LEDs if you get a weird value
  } else {
    digitalWrite(leftLED, LOW);
    digitalWrite(middleLED, LOW);
    digitalWrite(rightLED, LOW);
  }

/*
 * When you take a step, your foot orients from (1) back to 
 * (2) center to (3) front. If someone has completed all three 
 * actions, that probably means they have taken a step! 
 * 
 * In the if statements above, we set the counter to a different 
 * value, then test to see if that value is true here using the
 * "==" operator.
 * 
 * If it's true, we turn on all the LEDs to give visual feedback, 
 * then add 1 to the step variable. If not, we don't do anything
 * now and check again in the next loop.
 * 
 */

  if (counter == 3) { //Check to see if the counter is equal to 3

    //Turn on all LEDs if it's true
    digitalWrite(leftLED, HIGH);
    digitalWrite(middleLED, HIGH);
    digitalWrite(rightLED, HIGH);

    //Increase the step number by one
    steps++;//Remember: steps++ is the same thing as steps = steps + 1

    //Set a delay to make sure we're taking a step
    //Comment this out and upload again to see why it's important
    delay(500);
    
  } else {
    return;
  }

//We need to set the counter back to zero so we can test it again
//in the next loop. Comment this out and upload again to see why it's important
  counter = 0;
}
