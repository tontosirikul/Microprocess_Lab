#include <Arduino.h>

void setup() {
  DDRD = 0b11111100;
  DDRB = 0b00000011;
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0;i<=5;i++){
      PORTD = 0b00000100 <<i;
      delay(200);
    }
  PORTD = 0;
  for(int j=0;j<=1;j++){
      PORTB = 0x01 <<j;
      delay(200);
  }
  PORTB = 0;
}
