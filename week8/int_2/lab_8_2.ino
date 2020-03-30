#define ledPin 8
#define intPin 3
int time = 0;
bool toggle = 1;
int count=0;
void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(intPin,INPUT);
  Serial.begin(9600);
  noInterrupts();
  TCCR1A = 0;
  TCCR1B = 0;
  
  TCNT1 = (65536-62000);
  TCCR1B |= (1 << CS12);
  TIMSK1 |= (1 << TOIE1);
  interrupts();
  
}

void loop()
{ 
  Serial.print(count);
  Serial.print(":");
  Serial.println(time);
  digitalWrite(ledPin, toggle);
  
}
ISR(TIMER1_OVF_vect){
  TCNT1 = 3036;
  if(time>3){
    time = 1;
  }
  if(count == time){
    toggle = !toggle;
    digitalWrite(ledPin, toggle);
    time++;
  }
  else{
   	count++;
  }
}
