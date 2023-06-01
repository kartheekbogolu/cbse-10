#include<Arduino.h>
const int xPin=2;
const int yPin=3;
const int zPin=13;
void setup(){
pinMode(xPin,INPUT);
pinMode(yPin,INPUT);
pinMode(zPin,OUTPUT);
}
void loop() {
bool x=digitalRead(xPin);
bool y=digitalRead(yPin);
bool z=!(x||y);
digitalWrite(zPin,z);
}

