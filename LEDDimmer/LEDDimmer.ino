#include "arduino_secrets.h"

int greenpin = 10;
int voltpin = A2;
int readVal;
float v2;
float dim;


void setup() {
  // put your setup code here, to run once:
  
  pinMode(greenpin, OUTPUT);
  pinMode(voltpin, INPUT);
  Serial.begin(9600);
}

void loop() {
  readVal = analogRead(voltpin);
  v2 = (5./1023.) * readVal;
  Serial.println(v2);
  dim = v2 * 51;

  analogWrite(greenpin, dim);


  // put your main code here, to run repeatedly:

}