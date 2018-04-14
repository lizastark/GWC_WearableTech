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

//These variables are constant (they do not change):
const int sensorPin = A5;   // select the input pin for the sensor
const int ledPin1 = 9;      // select the pin for the LED
const int ledPin2 = 10;     // select the pin for the LED
const int ledPin3 = 11;     // select the pin for the LED

//These variables will change:
int sensorValue = 0;  // variable to store the value coming from the sensor


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
  int newSensorValue = map(sensorValue, 15, 160, 0, 255);
  
  // uncomment the line below to constrain the values 
  // in case you start getting negative numbers
  //newSensorValue = constrain(newSensorValue, 0, 255);
  
  //write the new value to the LEDs
  analogWrite(ledPin1, newSensorValue);
  analogWrite(ledPin2, newSensorValue);
  analogWrite(ledPin3, newSensorValue);
  
  //Print the value to the Serial monitor   
  Serial.print("New Sensor Value = ");
  Serial.println(newSensorValue);  

}

