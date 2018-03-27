/*
  READ BUTTON PRESSES

  Girls Who Code
  Day 2: Button Power Challenge
  Example 1

  This example uses the LilyPad ProtoSnap Plus board to read digital input
  from pin A4, then prints the results to the Serial Monitor. 

  If the button is pressed, the Serial Monitor prints 1. 
  - 1, HIGH, TRUE all mean the same thing. If you see a "1" it means true or on
  
  If the button is not pressed, the Serial Monitor prints 0.
   - 0, LOW, FALSE all mean the same thing. If you see a "0" it means false or off

  This sketch uses the Button example (File > Examples > Basic >
  DigitalReadSerial) or http://www.arduino.cc/en/Tutorial/DigitalReadSerial.


*/

// our push button is on A4. Give it a name:
int pushButton = A4;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  
  // make the pushbutton's pin an input:
  pinMode(pushButton, INPUT_PULLUP);
  
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
  int buttonState = digitalRead(pushButton);

  // print out the state of the button:
  Serial.print("Button state = ");
  Serial.println(buttonState);
  
  delay(1);        // delay in between reads for stability
}
