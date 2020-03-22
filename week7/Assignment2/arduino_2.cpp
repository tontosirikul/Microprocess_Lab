#include <arduino.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial =  SoftwareSerial(9, 8);
String buff = "";
int brightness = 0;
void setup()
{
  mySerial.begin(4800);
  pinMode(10, OUTPUT);
}

void loop()
{
  if(mySerial.available()>0){
    char inByte = mySerial.read();
    if(inByte != '\n'){
      buff += inByte;
    }else{
      brightness = buff.toInt();
      analogWrite(10,brightness);
      buff = "";
    }
  }
}