/*
  MOTION CHANGER WITH COUNTER + FUNCTIONS

  Girls Who Code Campus
  Day 4: Motion Changer Challenge
  Project Example

  
  >>Insert explanation from sketch on GitHub

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

int counter = 0; //This is our counter

int steps = 0;

void setup() {

  Serial.begin(9600);


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
  delay(50);
  // apply the calibration to the sensor reading
  zValue = map(zValue, zMin, zMax, 0, 255);

  // in case the sensor value is outside the range seen during calibration
  zValue = constrain(zValue, 0, 255);

  Serial.print("Z axis = ");
  Serial.print(zValue);
  Serial.print("\t");
  Serial.print("Counter = ");
  Serial.print(counter);
  Serial.print("\t");
  Serial.print("Steps = ");
  Serial.println(steps);

  if (zValue < 110) {
    turnOnLeftLED();

  } else if (zValue > 110 && zValue < 130) {
    turnOnMiddleLED();

  } else if (zValue > 130) {
    turnOnRightLED();

  } else {
    turnOffAllLEDs();
  }

  countSteps();


}


void turnOnLeftLED() {
  digitalWrite(leftLED, HIGH);
  digitalWrite(middleLED, LOW);
  digitalWrite(rightLED, LOW);
  counter = 1;

}

void turnOnMiddleLED() {
  digitalWrite(middleLED, HIGH);
  digitalWrite(leftLED, LOW);
  digitalWrite(rightLED, LOW);
  counter = 2;
}

void turnOnRightLED() {
  digitalWrite(rightLED, HIGH);
  digitalWrite(leftLED, LOW);
  digitalWrite(middleLED, LOW);
  counter = 3;

}

void turnOffAllLEDs() {
  digitalWrite(leftLED, LOW);
  digitalWrite(middleLED, LOW);
  digitalWrite(rightLED, LOW);

}

void countSteps() {
  if (counter == 3) {
    digitalWrite(leftLED, HIGH);
    digitalWrite(middleLED, HIGH);
    digitalWrite(rightLED, HIGH);

    steps++; //Increase the number in this variable by 1
    delay(500); //Add a short delay to make sure we don't count extra steps!

  } else {
    return; //This just says don't do anything

  }

  counter = 0;
}


