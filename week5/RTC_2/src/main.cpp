#include <Arduino.h>
#include <ThreeWire.h>
#include <RtcDS1302.h>

ThreeWire myWire(4,5,2); // IO, SCLK, CE 
RtcDS1302<ThreeWire> Rtc(myWire);
const int ledPin = 3;

int printMin(const RtcDateTime& dt){  
  // Serial.print(dt.Minute(), DEC); 
  // Serial.print(':'); 
  // Serial.print(dt.Second(), DEC); 
  // Serial.println();
  // Serial.println();
  return dt.Minute();
}

int printSec(const RtcDateTime& dt){  
  // Serial.print(dt.Minute(), DEC); 
  // Serial.print(':'); 
  // Serial.print(dt.Second(), DEC); 
  // Serial.println();
  // Serial.println();
  return dt.Second();
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Rtc.Begin();
  RtcDateTime setting_time(2020,2,2,23,0,0);
  // year, month, dayOfMonth, hour, minute, second
  // printDateTime(setting_time);
  //Try to comment This line
  Rtc.SetDateTime(setting_time);
  Serial.print('Start');
  Serial.println();
}

void loop() {
  // put your main code here, to run repeatedly:
  RtcDateTime now = Rtc.GetDateTime(); 
  int min = printMin(now);
  int sec = printSec(now);
  if ((sec%2) == 0){
    digitalWrite(ledPin,HIGH);
  }
  else{
    digitalWrite(ledPin,LOW);
  }
  if (min == 2 && sec == 0){
    Serial.print('stop');
    Serial.println();
  }
  Serial.print(min);
  Serial.print(':');
  Serial.print(sec);
  Serial.println();
  delay(1000);
}