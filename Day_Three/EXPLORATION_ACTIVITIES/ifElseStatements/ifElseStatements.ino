/*
  IF/ELSE STATEMENTS

  Girls Who Code
  Day 3: Intro to Conditionals
  Example 5

  This example uses the LilyPad ProtoSnap Plus board to demonstrate
  the use of if() and else if() statements. It reads the state of the light sensor on pin A2
  (an analog input), then turns on an LED depending on the values:
  - if less than or equal to 75, turn on the red LED
  - if greater than 76 and less than 150, turn on the green LED
  - if greater than 151 and less than 255, turn on blue LED
  - else, turn off all LEDs

  ************* NEED TO CHANGE THESE VALUES *************

  This sketch uses the ifStatementConditional example (File > Examples > Control >
  ifStatementConditional) or http://www.arduino.cc/en/Tutorial/IfStatement.


*/

//These variables are constant (they do not change):
const int sensorPin = A2;   // select the input pin for the sensor
const int redLED = 6;       // select the pin for the red LED
const int greenLED = A7;    // select the pin for the green LED
const int blueLED = A8;     // select the pin for the blue LED

//These variables will change:
int sensorValue = 0;        // variable to store the value coming from the sensor


void setup() {

  //Tell Arduino we want these pins to be outputs:
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);

  //We need to activate a special functionality to reduce the
  //noise in our sensor. If you don't use INPUT_PULLUP
  pinMode(sensorPin, INPUT_PULLUP);

  //Start the serial monitor
  Serial.begin(9600);

}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);

  Serial.print("Raw sensor reading = ");
  Serial.print(sensorValue);
  Serial.print("\t");

  // If the sensor value is greater than or equal to 75...
  if (sensorValue <= 75) {

    // turn on the red LED.
    digitalWrite(redLED, HIGH);

    // If the sensor value is greater than 76 AND less than 150...
  } else if ((sensorValue > 76) && (sensorValue < 150)) {

    // turn on the green LED.
    digitalWrite(greenLED, HIGH);

    // If the sensor value is greater than 151 AND less than 255...
  } else if ((sensorValue > 151) && (sensorValue < 255)) {

    // turn on the blue LED.
    digitalWrite(blueLED, HIGH);

    // If the sensor value is outside of this range, turn off all LEDs
  } else {

    // turn off the LEDs.
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, LOW);
    digitalWrite(blueLED, LOW);

  }

}
