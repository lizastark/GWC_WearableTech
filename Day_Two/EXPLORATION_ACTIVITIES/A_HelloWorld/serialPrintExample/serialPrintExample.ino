/*
  SERIAL PRINT EXAMPLE

  Girls Who Code
  Day 2: Hello, World
  Example 3

  This example uses the LilyPad ProtoSnap Plus board to print to the Serial
  Monitor.

  It prints "Hello, World" to the Serial Monitor every two seconds.


*/

void setup() {

  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

}

// the loop routine runs over and over again forever:
void loop() {

  // Print "Hello, World"
  Serial.println("Hello, World");

  // delay for two seconds then print again
  delay(2000);

}
