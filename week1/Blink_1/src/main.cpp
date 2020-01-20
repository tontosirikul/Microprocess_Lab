// #include <Arduino.h>

// void setup() {
//   DDRD = 0b11111100;
//   DDRB = 0b00000011;
// }

// void loop() {
//   // put your main code here, to run repeatedly:
//   for(int i=0;i<=5;i++){
//       PORTD = 0b00000100 <<i;
//       delay(200);
//     }
//   PORTD = 0;
//   for(int j=0;j<=1;j++){
//       PORTB = 0x01 <<j;
//       delay(200);
//   }
//   PORTB = 0;
// }

#include <Arduino.h>
int leftPin = A1;
int rightPin = A0;
void setup() {
  pinMode(leftPin,INPUT);
  pinMode(rightPin,INPUT);
  DDRD = 0xFF;
  DDRB = 0xFF;
}

void blink(int bulb){
  if(bulb>=0 && bulb <= 5){
    PORTB = 0;
    PORTD = 0b00000100 << bulb;
  }
  else{
    PORTD = 0;
    PORTB = 0b00000001 << bulb-6;
  }
}
void loop() {
  for(int i=0;i<=7;i++){
    blink(i);
    delay(200);
  }
}
