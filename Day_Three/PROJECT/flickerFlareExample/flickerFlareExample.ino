/*
  FLICKER FLARE

  Girls Who Code
  Day 3: Flicker Flare Light Sensing Garment
  Project Example

  This example uses the LilyPad ProtoSnap Plus board to read the raw values
  coming in from an analog sensor (e.g. light sensor, accelerometer,
  bend sensor, etc) and map them to a usable range with the map() function.

  If the sensor is exposed to a lot of light, the LED will turn off.
  The darker it gets, the brighter the LED will become brighter.
*/

//variables for input and output on SimpleSnap
int sensorPin = A5;   // select the input pin for the sensor
int ledPin1 = 9;      // select the pin for the LED
int ledPin2 = 10;     // select the pin for the LED
int ledPin3 = 11;     // select the pin for the LED

/*
  Uncomment to use these variables:
  
  //variables for input and output on LilyPad Protosnap Plus
  int sensorPin = A2;   // select the input pin for the sensor
  int ledPin1 = 6;      // select the pin for the LED
  int ledPin2 = A7;     // select the pin for the LED
  int ledPin3 = A8;     // select the pin for the LED
  
*/

// variable to store the value coming from the sensor
int sensorValue = 0;

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);

  // declare the sensorPin as an INPUT:
  pinMode(sensorPin, INPUT);

  // start serial communication
  Serial.begin(9600);
}

void loop() {

  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);

  // print the raw values for easy comparison
  Serial.print("Raw sensor reading = ");
  Serial.print(sensorValue);
  Serial.print("\t");

  //map the sensor values based on your readings
  int newSensorValue = map(sensorValue, 15, 220, 0, 255);

  //constrain the values so you don't get jumpy LED behavior
  newSensorValue = constrain(newSensorValue, 0, 255);

  //write the new value to the LEDs
  analogWrite(ledPin1, newSensorValue);
  analogWrite(ledPin2, newSensorValue);
  analogWrite(ledPin3, newSensorValue);

  //Print the value to the Serial monitor
  Serial.print("New Sensor Value = ");
  Serial.println(newSensorValue);

}

