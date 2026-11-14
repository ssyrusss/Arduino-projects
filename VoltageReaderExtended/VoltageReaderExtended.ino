#include "arduino_secrets.h"

int voltagepin = A2;
int redpin = 8;
int yellowpin = 9;
int greenpin = 10;
float v2 = 0;
int readVal = 0; 
int delaytime = 500;

void setup() {
  // put your setup code here, to run once:

pinMode(redpin, OUTPUT);
pinMode(yellowpin, OUTPUT);
pinMode(greenpin, OUTPUT);
pinMode(voltagepin, INPUT); // recieving an input from the arduino board on A3
Serial.begin(9600); // band in which we communicate

}

void loop() {
  // put your main code here, to run repeatedly:
  readVal = analogRead(voltagepin); // 10-bit code 0-1023
  v2 = (5./1023.) * readVal; // voltage calculation
  Serial.println(v2); // printing voltage on serial monitor
  if (v2 < 3) {
    digitalWrite(greenpin, HIGH);
    digitalWrite(yellowpin, LOW);
    digitalWrite(redpin, LOW);
  } else if (v2 > 3 && v2 < 4) {
    digitalWrite(greenpin, LOW);
    digitalWrite(yellowpin, HIGH);
    digitalWrite(redpin, LOW);
  } else if (v2 > 4) {
    digitalWrite(greenpin, LOW);
    digitalWrite(yellowpin, LOW);
    digitalWrite(redpin, HIGH);
  }
}
