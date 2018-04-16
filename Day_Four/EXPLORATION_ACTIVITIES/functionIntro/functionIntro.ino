/*
  FUNCTIONS

  Girls Who Code
  Day 4: Intro to Functions
  Example 3

  This example uses a function to print a message from the LilyPad Arduino to
  the serial monitor.

*/

void setup() {
  //Start the serial monitor
  Serial.begin(9600);
  
}

void loop() {
  //call your function
  sayHi();
  
}

// create your function
void sayHi() {
  // tasks the function will perform when called
  Serial.println("Hey girl!");
  
}
