/*
  Blinking LED
  By Your Name(s)
  Description of what the code does (i.e. This sketch blinks an LED)
*/

void setup() {
  // put your setup code here, to run once:
  // set pin 6 as an output
  pinMode(6, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //turn on the LED
  digitalWrite(6, HIGH);
  //wait for 1 second
  delay(100);
  //turn the LED off
  digitalWrite(6, LOW);
  //wait for 1 second
  delay(20);
}

