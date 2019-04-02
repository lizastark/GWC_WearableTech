/*
 * 
 * Dimming sequence
 * By Your Name(s)
 * This sketch uses analogWrite() to make an LED brighter then dimmer
 * 
 */


int ledRed = 6;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledRed, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  analogWrite(ledRed, 1);
  delay(250);
  analogWrite(ledRed, 10);
  delay(250);
  analogWrite(ledRed, 100);
  delay(250);
  analogWrite(ledRed, 255);
  delay(250);


}
