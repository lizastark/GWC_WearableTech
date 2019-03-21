/*
  BENDING SOUND

  Girls Who Code Campus
  Day 5: Bending Sound
  Example 1

  This example uses a handmade bend sensor, buzzer, and LilyPad
  ProtoSnap Plus board to control sound. Bend or press the sensor 
  to change the frequency or pitch of the noise made by the buzzer

  The LilyPad  reads the analog values coming in, then maps
  them to a specific range of pitches. If you are not getting any
  sound or values in the serial monitor, use the sketch without mapping
  then adjust the mapped values.

  This sketch is adapted from the Pitch follower example (Examples >
  Digital > pitchFollower)
*/

int buzzerPin = A3; //variable to store the buzzer pin

int bendSensorPin = A9; //variable to store the bend sensor pin

int bendSensorReading; //variable to store the values from the bend sensor
// i.e. how much we are bending or pressing

void setup() {

  //Tell Arduino we want this pin to be an output
  pinMode(buzzerPin, OUTPUT);

  //Configure the input pin
  pinMode(bendSensorPin, INPUT_PULLUP);

  //Start the serial monitor
  Serial.begin(9600);

}

void loop() {

  // read the values coming in from the sensor:
  bendSensorReading = analogRead(bendSensorPin);

  // print the raw (i.e. unmapped) sensor reading so you know its range
  Serial.print("Raw bend sensor reading = ");
  Serial.print(bendSensorReading);
  Serial.print("\t");

  // map the analog input range (in this case, 20 - 50 from
  // the bend sensor) to the output pitch range (75 - 2400Hz)
  // change the minimum and maximum input numbers below depending
  // on the range your sensor's giving.
  // map(value, fromLow, fromHigh, toLow, toHigh)

  int myPitch = map(bendSensorReading, 20, 50, 75, 2400);
  // change these values based on the readings you get from your own sensor
  // if you want to change the frequency range, change the last two numbers

  //print the new mapped value to see the pitch frequency
  Serial.print("Pitch frequency = ");
  Serial.println(myPitch);

  // play each frequency for 10 milliseconds
  tone(buzzerPin, myPitch, 10);

  // add a quick delay in between sensor readings to distinguish between frequencies
  delay(1);        
}
