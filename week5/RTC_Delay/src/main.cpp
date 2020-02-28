#include <Arduino.h>

const int ledPin = 3;

int count = 1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Rtc.SetDateTime(setting_time);
  Serial.print('Start');
  Serial.println();
}

void loop() {
  if ((sec%2) == 0){
    digitalWrite(ledPin,HIGH);
  }
  else{
    digitalWrite(ledPin,LOW);
  }
  delay(1000);
  count++;
}