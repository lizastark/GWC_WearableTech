/*
 * Push Button with Variables
 * By Your Names(s)
 * 
 * This sketch uses variables to store button and LED pins as well as the button state
 * to turn the LEDs on or off. It displays the status in the serial monitor.
 * 
 */

int led = A8;  
int button = A4;
int buttonState;

void setup() {
  // put your setup code here, to run once:
  //LEDs
  pinMode(led, OUTPUT);

  //push button
  pinMode(button, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  //read the button
  buttonState = digitalRead(button);
  
  //check to see if button is pressed
  if (buttonState == LOW) {

    //if pressed, turn on LED
    digitalWrite(led, HIGH);
    
    Serial.println("The LED is on!");
  }
  else {

    // if not pressed, turn off LED
    digitalWrite(led, LOW);
    
    Serial.println("The LED is off!");
  }
}

