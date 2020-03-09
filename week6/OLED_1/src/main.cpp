#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h> 
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels #define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define SCREEN_HEIGHT 64

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET -1 // Reset pin # (or -1 if sharing Arduino reset pin)

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void begin(){
  display.clearDisplay();
  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("SW1");
  display.drawCircle(96,12,10,WHITE);
  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(0,33);
  display.println("SW2");
  display.drawCircle(96,42,10,WHITE);
  display.display();
}

void fillsw1(){
    display.fillCircle(96,12,10,WHITE);
    display.display();
}

void fillsw2(){
    display.fillCircle(96,42,10,WHITE);
    display.display();
}

void setup() {
  Serial.begin(9600);
  pinMode(A3,INPUT);
  pinMode(A2,INPUT);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3c); //initialize I2C addr 0x3c display.clearDisplay(); // clears the screen and buffer display.drawPixel(127, 63, WHITE);
  display.clearDisplay();
  // display.drawLine(0, 63, 127, 21, WHITE); 
  // display.drawCircle(110, 50,s 12, WHITE); 
  // display.fillCircle(45, 50, 8, WHITE); 
  // display.drawTriangle(70, 60, 90, 60, 80, 46, WHITE); 
  // display.setTextSize(1); display.setTextColor(WHITE); 
  // display.setCursor(0,0);
  // display.println("Welcome"); 
  // display.setTextSize(2);
  // display.println("KRAI"); 
  // display.setTextColor(BLACK, WHITE); 
  // display.setTextSize(1); 
  // display.println("www.krai.io"); 
  // display.setTextColor(WHITE, BLACK); 
  begin();
}

void loop() {
  int sw1 = digitalRead(A3);
  int sw2 = digitalRead(A2);
  bool state1 = false;
  bool state2 = false;
  if (sw1 == LOW && state1 == false) {
    Serial.println("sw1");
    fillsw1();
    state1 = true;
  }
  if (sw2 == LOW &&  state2 == false){
    Serial.println("sw2");
    fillsw2();
    state1 = true;
  }
  if (state1 == false && state2 == false){
    begin();
  }
  delay(200);
}