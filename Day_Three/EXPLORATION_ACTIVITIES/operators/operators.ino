/*
  OPERATORS

  Girls Who Code
  Day 3: Conditionals && Operators
  Example 4

  This example uses the LilyPad ProtoSnap Development board to demonstrate
  the use of operators in if statements. It reads the state of the light sensor on pin A6
  (an analog input), then turns on an LED depending on the values:
  - if less than or equal to 250, turn on the red LED
  - if greater than 250 and less than 300, turn on the green LED
  - if greater than 300 and less than 335, turn on blue LED
  - else, turn off all LEDs

  This sketch uses the ifStatementConditional example (File > Examples > Control >
  ifStatementConditional) or http://www.arduino.cc/en/Tutorial/IfStatement.


*/

//These variables are constant (they do not change):
const int sensorPin = A6;   // select the input pin for the sensor
const int redLED = 9;       // select the pin for the red LED
const int greenLED = 11;    // select the pin for the green LED
const int blueLED = 10;     // select the pin for the blue LED

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

  Serial.print("Sensor value = ");
  Serial.print(sensorValue);
  Serial.print("\t");

  // If the sensor value is greater than or equal to 250...
  if (sensorValue <= 250) {

    // turn on the red LED.
    digitalWrite(redLED, HIGH);
    Serial.println("Red LED on");

    // If the sensor value is greater than 250 AND less than 300...
  } else if ((sensorValue > 250) && (sensorValue < 300)) {

    // turn on the green LED.
    digitalWrite(greenLED, HIGH);
    Serial.println("Green LED on");

    // If the sensor value is greater than 300 AND less than 335...
  } else if ((sensorValue > 300) && (sensorValue < 335)) {

    // turn on the blue LED.
    digitalWrite(blueLED, HIGH);
    Serial.println("Blue LED on");

    // If the sensor value is outside of this range, turn off all LEDs
  } else {

    // turn off the LEDs.
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, LOW);
    digitalWrite(blueLED, LOW);
    Serial.println("All LEDs off");

  }

}
