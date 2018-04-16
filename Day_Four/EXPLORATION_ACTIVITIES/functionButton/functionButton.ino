/*
  FUNCTION WITH A BUTTON

  Girls Who Code
  Day 4: Button Power Challenge
  Example 4

  This example uses the LilyPad ProtoSnap Development Board to turn an LED on and off 
  using a push button.

*/

// constants won't change. They're used here to
// set pin numbers:
const int buttonPin = 5;     // the number of the push button pin

// variables will change:
int buttonState = 0;         // variable for reading the push button status

void setup() {
    //Start the serial monitor
  Serial.begin(9600);
  
  // initialize the push button pin as an input:
  pinMode(buttonPin, INPUT_PULLUP);
  
}

void loop() {
  // read the state of the push button value:
  buttonState = digitalRead(buttonPin);

  // check if the push button is pressed.
  if (buttonState == LOW) {
    
    // turn LED on:
    sayHi();
    
  }
  
}

// create your function
void sayHi() {

  // tasks the function will perform when called
  Serial.println("Hey girl!");
  
  //add a delay
  delay(300);
  
}
