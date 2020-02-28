#include <SPI.h>
#include <arduino.h>
#define DATA 11
#define CLK 13
#define SS 10
#define SS_2 9
#define leftPin 2
#define rightPin 3

int counter = 0;

int number[10] = {
  0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F
};

void spi_1(int data){
  SPI.transfer(data); 
  digitalWrite(SS,HIGH); 
  digitalWrite(SS,LOW);
  delay(200);
}

void spi_2(int data){
  SPI.transfer(data); 
  digitalWrite(SS_2,HIGH); 
  digitalWrite(SS_2,LOW);
  delay(200);
}

void setup() {
  // put your setup code here, to run once:
  SPI.begin();
  SPI.beginTransaction(SPISettings(14000000, MSBFIRST, SPI_MODE0));
  pinMode(SS,OUTPUT);
  pinMode(SS_2,OUTPUT);
  pinMode(leftPin,INPUT);
  pinMode(rightPin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int right = digitalRead(rightPin);
  int left = digitalRead(leftPin);
  if(right==LOW){
    Serial.println("Right");
  }
  if(left==LOW){
    Serial.println("Left");
  }
}