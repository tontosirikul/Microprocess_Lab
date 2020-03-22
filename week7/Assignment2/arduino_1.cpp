#include<arduino.h>
#include <SoftwareSerial.h>
int sensorValue = 0;
SoftwareSerial mySerial =  SoftwareSerial(9, 8);
void setup()
{
  mySerial.begin(4800);
  pinMode(A0, INPUT);
}

void loop()
{
  sensorValue = analogRead(A0);
  mySerial.println(sensorValue);
  delay(200);
}