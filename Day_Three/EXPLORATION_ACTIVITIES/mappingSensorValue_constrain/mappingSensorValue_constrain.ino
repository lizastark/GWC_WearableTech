
/*
 * DAY 3, PART 2
 * Mapping sensor values
 * By Your Name(s)
 * Description of what the code does
 * 
 */



int sensorPin = A2;
int sensorVal;
int ledPin = A7;

void setup() {
  // put your setup code here, to run once:
  pinMode(sensorPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  sensorVal = analogRead(sensorPin); //read the sensor data coming in
  int newSensorVal = map(sensorVal,330,240,255,0); //create a new variable to store the mapped values
  newSensorVal = constrain(newSensorVal,0,255);
  Serial.println(newSensorVal);         //print the sensor values to the serial monitor
  analogWrite(ledPin, newSensorVal);    //write the values of the sensor to the LED

}
