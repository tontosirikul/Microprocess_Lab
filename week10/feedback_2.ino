#include <SPI.h>
#define MOTOR_D1_PIN 7 
#define MOTOR_D2_PIN 8 
#define MOTOR_PWM_PIN 9
#define DATA 11
#define CLK 13
#define SS 5
#define SS_2 4
#define ledpin 6
bool previous_read_A;
bool previous_read_B;
int count = 0;
int error;
int setpoint = 5000;
bool state = 0;
int number[10] = {
  0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F
};

void spi_write_1(unsigned char cData) {
  shiftOut(DATA, CLK, MSBFIRST, cData);
  digitalWrite(SS, HIGH);
  digitalWrite(SS,LOW);
}

void spi_write_2(unsigned char cData) {
  shiftOut(DATA, CLK, MSBFIRST, cData);
  digitalWrite(SS_2, HIGH);
  digitalWrite(SS_2,LOW);
}

void setup() {
  pinMode(MOTOR_D1_PIN,OUTPUT); 
  pinMode(MOTOR_D2_PIN,OUTPUT); 
  pinMode(MOTOR_PWM_PIN,OUTPUT);
  setSpeed(100);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(SS, OUTPUT);
  pinMode(SS_2,OUTPUT);
  pinMode(DATA, OUTPUT);
  pinMode(CLK, OUTPUT);
  pinMode(SS,OUTPUT);
  pinMode(SS_2,OUTPUT);
  pinMode(ledpin,OUTPUT);
  Serial.begin(9600); 
  Serial.println("Test Encoder");
  attachInterrupt(digitalPinToInterrupt(2), checkEdge, RISING);
  attachInterrupt(digitalPinToInterrupt(3), checkEdge, RISING);
}
void loop() {
  error = setpoint - count;
  int control_value = 1.0*float(error);
  setSpeed(control_value);
  if( count > 0){
    digitalWrite(ledpin,LOW);
  	spi_write_1(number[(count/100)/10]);
  	spi_write_2(number[(count/100)%10]);
  }
  if( count < 0){
    digitalWrite(ledpin,HIGH);
    spi_write_1(number[abs((count/100)/10)]);
  	spi_write_2(number[abs((count/100)%10)]);
  }
  if (state == 1){
    //Serial.print("CW:");
  	Serial.print(count++);
    Serial.print(",");
    Serial.println(setpoint);
  }
  else{
    //Serial.print("CCW:");
  	Serial.print(count++);
    Serial.print(",");
    Serial.println(setpoint);
  }
  if(Serial.available()){
    String goal = Serial.readString();
    setpoint = goal.toInt();
  }
  delay(200);
}

void setSpeed(int speed){
  if (speed > 0){
    digitalWrite(MOTOR_D1_PIN,HIGH);
    digitalWrite(MOTOR_D2_PIN,LOW); 
    analogWrite(MOTOR_PWM_PIN,abs(speed));
  }
  
  if (speed < 0){
    digitalWrite(MOTOR_D1_PIN,LOW);
    digitalWrite(MOTOR_D2_PIN,HIGH); 
    analogWrite(MOTOR_PWM_PIN,abs(speed));
  }                  
}
void checkEdge(){
	bool currentA = digitalRead(2);
  	bool currentB = digitalRead(3);
    if ((previous_read_A == 1) && (currentA == 0)){
      count--;
      state = 0;
    }
  	if ((previous_read_B == 1) && (currentB == 0)){
      count++;
      state = 1;
  	}
  	previous_read_A = currentA;
  	previous_read_B = currentB;
}
