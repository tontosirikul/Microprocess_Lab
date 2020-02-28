#include <Arduino.h>
#include <ThreeWire.h>
#include <RtcDS1302.h>

ThreeWire myWire(4,5,2); //IO,CLK,CE
RtcDS1302<ThreeWire>Rtc(myWire);
const int ledPin = 3;

int printDateTime(const RtcDateTime& dt){ 
  // Serial.print(dt.Year(), DEC);
  // Serial.print('/');
  // Serial.print(dt.Month(), DEC); 
  // Serial.print('/');
  // Serial.print(dt.Day(), DEC); 
  // Serial.print(' '); 
  // Serial.print(dt.Hour(), DEC); 
  // Serial.print(':'); 
  // Serial.print(dt.Minute(), DEC); 
  // Serial.print(':'); 
  // Serial.print(dt.Second(), DEC); 
  // Serial.println();
  // Serial.print("Total Seconds since 1/1/2000 : "); 
  // Serial.print(dt.TotalSeconds());
  // Serial.println();
  // dt.Second();
  return dt.Second();
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Rtc.Begin();
  RtcDateTime setting_time(2020,2,23,23,31,10);
  // year, month, dayOfMonth, hour, minute, second
  printDateTime(setting_time);
  //Try to comment This line
  // Rtc.SetDateTime(setting_time);

}



void loop() {
  //put your main code here, to run repeatedly:
  RtcDateTime now = Rtc.GetDateTime();
  int Second = printDateTime(now);
  if ((Second%2) == 0){
    digitalWrite(ledPin,HIGH);
  }
  else{
    digitalWrite(ledPin,LOW);
  } 
}