#define ledPin 8
#define intPin 3
int time = 1;
void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(intPin,INPUT);
  attachInterrupt(digitalPinToInterrupt(intPin),led_trigger,RISING);
  Serial.begin(9600);
}

void loop()
{
  
  Serial.println(time);
  digitalWrite(ledPin, HIGH);
  delay(time*1000); // Wait for 1000 millisecond(s)
  digitalWrite(ledPin, LOW);
  delay(time*1000); // Wait for 1000 millisecond(s)
}
void led_trigger(){
  time += 1;
  if(time>3){
    time = 1;
  }
}
