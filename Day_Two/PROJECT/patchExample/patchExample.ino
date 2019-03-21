/*
 * What Do You Stand For? Patch
 * By Your Names(s)
 * 
 * This sketch turns three LEDs on or off based on the state of a switch. This is the code
 * used in the example video. 
 * 
 */

int led = 5;  
int led2 = 6;
int led3 = 9;
int button = A5;
int buttonState;

void setup() {
  // put your setup code here, to run once:
  //LEDs
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

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
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    
    Serial.println("The LED is on!");
  }
  else {

    // if not pressed, turn off LED
    digitalWrite(led, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    
    Serial.println("The LED is on!");
  }
}

