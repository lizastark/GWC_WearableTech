/*
  CALIBRATION

  Girls Who Code Campus
  Day 4: Calibrating your sensor
  Example 2

  This example uses the LilyPad accelerometer and the LilyPad Arduino
  SimpleSnap to calibrate the acceleromter.

  This sketch uses the Calibration example (Examples > Analog > Calibration or
  http://www.arduino.cc/en/Tutorial/Calibration) to help us get a better reading.
  During the first five seconds in setup(), it gathers the minimum and maximum values and
  maps, or adjusts, the incoming data to fit in that range.

  1) Upload the sketch.
  2) Open the serial monitor.
  3) When you see "Calibration Beginning", move your accelerometer to get a full range of values

  Once you have it calibrated to the values you want, you can comment out that
  section of the setup() code.

*/

// These constants won't change:
const int zPin = A2;    // z axis pin

// variables:
int zValue = 0;         // the z axis value
int zMin = 1023;        // minimum sensor value
int zMax = 0;           // maximum sensor value


void setup() {

  Serial.begin(9600);
  pinMode(zPin, INPUT);

  /*
     This is the calibration part of the sketch. Once you upload it,
     open your serial monitor and follow the instuctions.
  */

  //Comment this out once you have your accelerometer calibrated

  // turn on LED to signal the start of the calibration period:
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);

  Serial.println("Calibration beginning");
  Serial.println("Move your accelerometer around");

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

  //End comment
}

void loop() {
  // read the sensor:
  zValue = analogRead(zPin);

  // apply the calibration to the sensor reading
  zValue = map(zValue, zMin, zMax, 0, 255);

  // in case the sensor value is outside the range seen during calibration
  zValue = constrain(zValue, 0, 255);

  //Shows us the values of the accelerometer in the serial monitor
  Serial.print("Z axis = ");
  Serial.print(zValue);
  Serial.print("\t");

  //Conditional to determine if tilted one way
  if (zValue < 110) {
    Serial.println("Tilt State 1");

    //Conditional to determine if tilted the other way
  } else {
    Serial.println("Tilt State 2");
  }


}
