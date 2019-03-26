/*
 * Basic Tilt Switch
 * By Liza
 * This sketch uses digitalWrite() to read the orientation of a tilt swtich
 * (i.e. if it's pointed vertical or horizontal).
 * 
 */

int tiltPin = 10;
int tiltState;


void setup() {
  // put your setup code here, to run once:
  pinMode(tiltPin, INPUT_PULLUP);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  tiltState = digitalRead(tiltPin);
  Serial.println(tiltState);


}
