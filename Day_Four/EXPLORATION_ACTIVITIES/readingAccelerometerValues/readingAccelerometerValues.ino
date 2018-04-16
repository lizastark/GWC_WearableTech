/*
  READING ACCELEROMETER VALUES

  Girls Who Code
  Day 4: Reading Accelerometer Values
  Example 1

  This example uses the LilyPad ProtoSnap Development board to read the raw values
  coming in from the Z-axis pin on an accelerometer. Since we need to read analog values 
  coming in from the sensor, this is the same sketch we used in Day 3 without the LED. 
  It reads the accelerometer input from pin A2, then prints the results to the Serial Monitor.

*/

//These variables are constant (they do not change):
const int sensorPin = A2;    // select the input pin for the sensor

//These variables will change:
int sensorValue = 0;  // variable to store the value coming from the sensor


void setup() {

  //Tell Arduino we want this pin to be an input
  pinMode(sensorPin, INPUT);

  //Start the serial monitor
  Serial.begin(9600);

}

void loop() {

  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);

  //Print the sensor value to the Serial monitor
  Serial.print("Sensor value = ");
  Serial.println(sensorValue);

  delay(30);

}
