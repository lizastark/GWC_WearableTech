/*
  IF ELSE STATEMENTS

  Girls Who Code
  Day 3: Conditionals && Operators
  Example 3

  This example uses the LilyPad ProtoSnap Development board to demonstrate
  the use of if() statements. It reads the state of the light sensor on pin A6
  (an analog input) and turns on an LED only if the light sensor goes
  above a certain threshold level. It prints the analog value regardless
  of the level.

  This sketch uses the ifStatementConditional example (File > Examples > Control >
  ifStatementConditional) or http://www.arduino.cc/en/Tutorial/IfStatement.


*/

//These variables are constant (they do not change):
const int sensorPin = A6;   // select the input pin for the sensor
const int ledPin = 6;       // select the pin for the LED
const int threshold = 250;  // an arbitrary threshold level that's in
// the range of the analog input

//These variables will change:
int sensorValue = 0;        // variable to store the value coming from the sensor


void setup() {

  //Tell Arduino we want this pin to be an output
  pinMode(ledPin, OUTPUT);
 
  //Tell Arduino we want this pin to be an input
  pinMode(sensorPin, INPUT);

  //Start the serial monitor
  Serial.begin(9600);

}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);

  Serial.print("Sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t");

  // If the sensor value is greater than the threshold (400 in this case)...
  if (sensorValue > threshold) {

    // turn on the LED.
    digitalWrite(ledPin, LOW);

    // Print the status
    Serial.println("Status: Above threshold");

    // If it is not greater than the threshold...
  } else if (sensorValue < threshold) {

    // turn off the LED.
    digitalWrite(ledPin, HIGH);

    // Print the status
    Serial.println("Status: Below threshold");
  }

}
