#include <Arduino.h>
int clk_pin = 13;//SHCP or clock
int latch_pin = 10;//STCP or latch
int data_pin = 11;//DS or input
void setLED(uint16_t state){
  digitalWrite(latch_pin,LOW);
  for(int i = 0 ; i < 16 ; i++){
    digitalWrite(data_pin,(state>>(15-i)) & 0x1);
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
}
void loop() {
  for(int i=0;i<16;i++){
    setLED(0x1<<i);
    delay(200);
  }
}