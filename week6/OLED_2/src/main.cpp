#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h> 
#include <Adafruit_SSD1306.h>
#include <ThreeWire.h> 
#include <RtcDS1302.h>

ThreeWire myWire(4,5,2);
RtcDS1302<ThreeWire> Rtc(myWire);

#define SCREEN_WIDTH 128 // OLED display width, in pixels #define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define SCREEN_HEIGHT 64
#define OLED_RESET -1 // Reset pin # (or -1 if sharing Arduino reset pin)

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void printDatetime(const RtcDateTime& dt){
  // Serial.print(dt.Year(), DEC);
  // Serial.print('/');
  // Serial.print(dt.Month(), DEC);
  // Serial.print('/');
  // Serial.print(dt.Day(), DEC);
  // Serial.print(' ');
  // Serial.print(dt.Hour(), DEC);
  // Serial.print(':');
  // Serial.print(dt.Minute(), DEC);
  // Serial.print(':');
  // Serial.print(dt.Second(), DEC);
  // Serial.println();
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,5);
  display.println("YEARS:");
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(38,5);
  display.println(dt.Year(), DEC);

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,20);
  display.println("MONTH:");
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(38,20);
  display.println(dt.Month(), DEC);

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,35);
  display.println("DATE:");
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(38,35);
  display.println(dt.Day(), DEC);

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,50);
  display.println("TIME:");
  display.setCursor(38,50);
  display.setTextColor(WHITE);
  display.setCursor(30,50);
  display.println(dt.Hour(), DEC);
  display.setCursor(38,50);
  display.println(":");
  display.setCursor(46,50);
  display.println(dt.Minute(), DEC);
  display.setCursor(62,50);
  display.println(":");
  display.setCursor(68,50);
  display.println(dt.Second(), DEC);

  display.display();
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Rtc.Begin();
  RtcDateTime setting_time(2020,3,9,16,0,0);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3c); //initialize I2C addr 0x3c display.clearDisplay(); // clears the screen and buffer display.drawPixel(127, 63, WHITE);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,5);
  display.println("YEARS:");
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,20);
  display.println("MONTH:");
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,35);
  display.println("DAY/DATE:");
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,50);
  display.println("TIME:");
  display.display();
}

void loop() {
  // put your main code here, to run repeatedly:
  RtcDateTime now = Rtc.GetDateTime();
  printDatetime(now);
}