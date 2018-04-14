/*
  MAPPING SENSOR VALUES

  Girls Who Code
  Day 3: Mapping the data
  Example 3

  This example uses the LilyPad ProtoSnap Plus board to read the raw values
  coming in from an analog sensor (e.g. light sensor, accelerometer,
  bend sensor, etc) and map them to a usable range with the map() function.

  If the sensor is exposed to a lot of light, the LED will become dim.
  The darker it gets, the brighter the LED will become.


*/

//These variables are constant (they do not change):
const int sensorPin = A6;   // select the input pin for the sensor
const int ledPin = 6;       // select the pin for the LED

//These variables will change:
int sensorValue = 0;        // variable to store the value coming from the sensor
int newSensorValue;         // variable to store the new mapped value


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

  // print the raw values for easy comparison
  Serial.print("Raw sensor reading = ");
  Serial.print(sensorValue);
  Serial.print("\t");

  // In the last example, the values we received from the light
  // sensor were not very usable. Since the range of brightness for an LED
  // is 0 (off) to 255 (all the way on), we need to figure out a way to
  // get the sensor values in that range. This is where the map() function
  // comes in very handy.

  // First, you need to know the lowest and highest values in the sensor range.
  // Place your hand all the way over the light sensor, wait a moment, then read
  // the value from the "Raw sensor reading". This is your lowest value that goes
  // in fromLow. Do the same for the highest value and put it in fromHigh.
  // Tinker around with these values until you get the behavior you want.

  //map(value, fromLow, fromHigh, toLow, toHigh)
  newSensorValue = map(sensorValue, 15, 160, 0, 255);

  //print the new value to the serial monitor
  Serial.print("Mapped value = ");
  Serial.println(newSensorValue);

  //write the new value to the LED
  analogWrite(ledPin, newSensorValue);

  delay(30);

}
