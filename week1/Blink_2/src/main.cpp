#include <Arduino.h>
int leftPin = A1;
int rightPin = A0;
byte currentLed = 0b00000100; //initial bulb.
int counter = 0;
void setup() {
  pinMode(leftPin,INPUT);
  pinMode(rightPin,INPUT);
  DDRD = 0xFF;
  DDRB = 0xFF;
  PORTD = currentLed;
  Serial.begin(9600);
}



void loop() {
  int right = digitalRead(rightPin);
  int left = digitalRead(leftPin);
  if( right == LOW)
  {
    currentLed = currentLed << 1;
    Serial.println(currentLed);
    PORTD = currentLed;
    counter += 1;
    Serial.println(counter);
    if(counter >= 6 && counter < 8){
      PORTD=0;
      currentLed = 0x01 << counter-6;
      PORTB = currentLed;
      Serial.println(currentLed);
    }
    if(counter >= 8 ){
      PORTB=0;
      currentLed = 0b00000100;
      PORTD=currentLed;
      counter = 0;
    }
  }
  if( left == LOW){
    currentLed = currentLed >> 1;
    PORTB=currentLed;
    counter -= 1;
    if(counter <= 5 && counter > 0 ){
      PORTB=0;
      currentLed = 0b10000000 >> 5-counter;
      PORTD= currentLed ;
      Serial.println(counter);
    }
    if(counter < 0){
      PORTD=0;
      currentLed = 0x02;
      PORTB=currentLed;
      counter = 7;
    }
    if(counter == 0){
      PORTD=0b00000100;
    }

  }

  delay(200);


}