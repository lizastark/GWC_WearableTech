/*
 * My First Function
 * By Your Name(s)
 * This sketch uses a function to print a message from the
 * serial monitor.
 * 
 */


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 
  sayHi(); //call your function in the loop
}

void sayHi() {
  //tasks the function will perform when called
  Serial.println("Hey girl!");

  //add a delay so we don't get a super long scroll
  delay(500);
}

