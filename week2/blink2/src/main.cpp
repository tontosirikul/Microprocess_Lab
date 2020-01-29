#include <Arduino.h>
int clkPin = 13;//SHCP or clock
int latchPin = 10;//STCP or latch
int dataPin = 11;//DS or input
int leftPin = 2;
int rightPin = 3;
uint16_t currentLed = 0x1;
int count = 0;
void setLED(uint16_t state){
  digitalWrite(latchPin,LOW);
  for(int i = 0 ; i < 16 ; i++){
    digitalWrite(dataPin,(state>>(15-i)) & 0x1);
    digitalWrite(clkPin,HIGH);
    delayMicroseconds(2);
    digitalWrite(clkPin,LOW);
    delayMicroseconds(2);
  }
  digitalWrite(latchPin,HIGH);
}
void setup() {
  pinMode(clkPin,OUTPUT);
  pinMode(latchPin,OUTPUT);
  pinMode(dataPin,OUTPUT);
  pinMode(leftPin,INPUT);
  pinMode(rightPin,INPUT);
  setLED(currentLed);
  Serial.begin(9600);
}
void loop() {
  int right = digitalRead(rightPin);
  int left = digitalRead(leftPin);
  
  if(right==LOW){
    currentLed = currentLed<<1;
    setLED(currentLed);
    count++;
    if(count>=16){
        currentLed=0x1;
        setLED(currentLed);
        count=0;
      }
    //Serial.println(count);
  }

  if(left==LOW){
    currentLed = currentLed>>1;
    setLED(currentLed);
    count--;
    if(count<0){
      currentLed = 0x8000;
      setLED(currentLed);
      count=15;
    }
    //Serial.println(count);
  }


  delay(200);
}