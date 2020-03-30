#define MOTOR_D1_PIN 7 
#define MOTOR_D2_PIN 8 
#define MOTOR_PWM_PIN 9
bool previous_read_A;
bool previous_read_B;
int count = 0;
bool state;
void setup() {
  pinMode(MOTOR_D1_PIN,OUTPUT); 
  pinMode(MOTOR_D2_PIN,OUTPUT); 
  pinMode(MOTOR_PWM_PIN,OUTPUT);
  
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  Serial.begin(9600); 
  Serial.println("Test Encoder");
  setSpeed(100);
  attachInterrupt(digitalPinToInterrupt(2), checkEdge, RISING);
  attachInterrupt(digitalPinToInterrupt(3), checkEdge, RISING);
}
void loop() {
  if (state == 1){
    Serial.print("CW:");
  	Serial.println(count);
  }
  else{
    Serial.print("CCW:");
  	Serial.println(count);
  }
}

void setSpeed(int speed){
  if (speed < 0){
    digitalWrite(MOTOR_D1_PIN,HIGH);
    digitalWrite(MOTOR_D2_PIN,LOW); 
    analogWrite(MOTOR_PWM_PIN,abs(speed));
  }
  
  if (speed > 0){
    digitalWrite(MOTOR_D1_PIN,LOW);
    digitalWrite(MOTOR_D2_PIN,HIGH); 
    analogWrite(MOTOR_PWM_PIN,abs(speed));
  }                  
}
void checkEdge(){
	bool currentA = digitalRead(2);
  	bool currentB = digitalRead(3);
    if ((previous_read_A == 1) && (currentA == 0)){
      count++;
      state = 1;
    }
  	if ((previous_read_B == 1) && (currentB == 0)){
      count--;
      state = 0;
  	}
  	previous_read_A = currentA;
  	previous_read_B = currentB;
}
