/*
  READING SENSOR VALUES (ANALOG INPUTS)

  Girls Who Code
  Day 3: Analog Input
  Example 2

  This example uses the LilyPad ProtoSnap Development board to read the raw values
  coming in from an analog sensor (e.g. light sensor, accelerometer,
  bend sensor, etc). It reads the light sensor input from pin A6, then writes them to the LED
  on pin 6 and prints the results to the Serial Monitor.

  If the sensor is exposed to a lot of light, the values will be higher. 
  The darker it gets, the lower the values.
 

*/

//These variables are constant (they do not change):
const int sensorPin = A5;    // select the input pin for the sensor
const int ledPin = 6;     // select the pin for the LED

//These variables will change:
int sensorValue = 0;  // variable to store the value coming from the sensor


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

  //write the value of the sensor to the output
  analogWrite(ledPin, sensorValue);

  //Print the sensor value to the Serial monitor
  Serial.print("Sensor value = ");
  Serial.println(sensorValue);

  delay(30);

}
