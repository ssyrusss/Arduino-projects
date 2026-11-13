#include "arduino_secrets.h"

int redpin = A3;
float v2 = 0;
int readVal = 0; 
int delaytime = 500;

void setup() {
  // put your setup code here, to run once:

pinMode(redpin, INPUT); // recieving an input from the arduino board on A3
Serial.begin(9600); // band in which we communicate

}

void loop() {
  // put your main code here, to run repeatedly:
  readVal = analogRead(redpin); // 10-bit code 0-1023
  v2 = (5./1023.) * readVal; // voltage calculation
  Serial.println(v2); // printing voltage on serial monitor
  delay(1000); // delay input so theres less junk in serial monitor
}
