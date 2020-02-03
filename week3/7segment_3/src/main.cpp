#include <Arduino.h>
int clk_pin = 13;//SHCP or clock
int latch_pin = 10;//STCP or latch
int data_pin = 11;//DS or input
byte number[10] = {0x7E,0x30,0x6D,0x79,0x33,0x5B,0x5F,0x70,0x7F,0x7B};
int leftPin = 2;
int rightPin = 3;
int count = 0;
void setLED(uint16_t state){
  digitalWrite(latch_pin,LOW);
  for(int i = 0 ; i < 8 ; i++){
    digitalWrite(data_pin,(state>>(7-i)) & 0x1);
    digitalWrite(clk_pin,HIGH);
    delayMicroseconds(2);
    digitalWrite(clk_pin,LOW);
    delayMicroseconds(2);
  }
  digitalWrite(latch_pin,HIGH);
}
void setup() {
  pinMode(clk_pin,OUTPUT);
  pinMode(latch_pin,OUTPUT);
  pinMode(data_pin,OUTPUT);
  setLED(number[count]);
}
void loop() {
  int right = digitalRead(rightPin);
  int left = digitalRead(leftPin);
  if(right==LOW){
    count++;
    setLED(number[count]);
    Serial.println(count);
    if(count>9){
      count=0;
      setLED(number[count]);
    }
  }

  if(left==LOW){
    count--;
    setLED(number[count]);
    Serial.println(count);
    if(count<0){
      count=9;
      setLED(number[count]);
    }
  }
  delay(200);
}