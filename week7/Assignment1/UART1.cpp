#include <arduino.h>
float brightness = 0;
String incoming = "";
int Ledpin = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
}
void loop()
{
  if(Serial.available()>0){
    char inByte = Serial.read();
    incoming += inByte;
    Serial.println(incoming);
    if(incoming == "L1"){
      Ledpin = 11;
      incoming ="";
    }else if(incoming == "L2"){
      Ledpin = 10;
      incoming ="";
    }
    if(inByte == 'B'){
      incoming ="";
    }
    //if(('0'<= inByte) && (inByte <= '9')){
      //buff += inByte;
    //}
    if(inByte == '%'){
      	Serial.println(incoming);
     	brightness = incoming.toInt();
     	Serial.println(brightness);
      	//analogWrite(Ledpin,255);
     	analogWrite(Ledpin,int(brightness*2.54));
      	Ledpin = 0;
      	incoming = "";
  	}
  }
}