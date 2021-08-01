#include <DHT.h>
#include <DHT_U.h>
#include <dht.h>
#define Type DHT11
int sensePin=7;
DHT HT(sensePin,Type);
float humidity;
float tempC;
float tempF;


#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
//definitions and stuff and constants and normal integers

const int buttonPin = 2;
const int buttonPin1 = 3;

int buttonNew;
int buttonOld=1;
int buttonOld1=1;
int buttonNew1;


//dht definitions and functions above

#define OLED_RESET     4 
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define NUMFLAKES     10 // Number of snowflakes in the animation example
#define DHT11_PIN 7
#define LOGO_HEIGHT   16
#define LOGO_WIDTH    16
//adafruit logo below, just because some of this code is from a demo they made
static const unsigned char PROGMEM logo_bmp[] =
{ 0b00000000, 0b11000000,
  0b00000001, 0b11000000,
  0b00000001, 0b11000000,
  0b00000011, 0b11100000,
  0b11110011, 0b11100000,
  0b11111110, 0b11111000,
  0b01111110, 0b11111111,
  0b00110011, 0b10011111,
  0b00011111, 0b11111100,
  0b00001101, 0b01110000,
  0b00011011, 0b10100000,
  0b00111111, 0b11100000,
  0b00111111, 0b11110000,
  0b01111100, 0b11110000,
  0b01110000, 0b01110000,
  0b00000000, 0b00110000 };

void setup() {
  Serial.begin(9600);
  HT.begin();
  pinMode(buttonPin, INPUT);
  pinMode(buttonPin1, INPUT);
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  display.display();
  delay(2000); // Pause for 2 seconds

  // Clear the buffer
  display.clearDisplay();

  // Draw a single pixel in white
  display.drawPixel(10, 10, SSD1306_WHITE);

  // Show the display buffer on the screen. You MUST call display() after
  // drawing commands to make them visible on screen!
  display.display();
  delay(2000);
  // display.display() is NOT necessary after every single drawing command,
  // unless that's what you want...rather, you can batch up a bunch of
  // drawing operations and then update the screen all at once by calling
  // display.display().
}

void loop() {
  //humidity is possible feature for later. as well as tempature
  humidity=HT.readHumidity();
  tempC=HT.readTemperature();
  tempF=HT.readTemperature(true);
  //below is the page you see when you power it on
  display.clearDisplay();
  display.setTextSize(0); // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println(F("Welcome to")); // Show initial text
  display.setCursor(10, 10);
  display.setTextSize(1);
  display.println(F("unnamed"));
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 25);
  display.setTextSize(0);
  display.println(F("Press Button"));
  display.setTextColor(SSD1306_WHITE);
  display.display();
  buttonNew = digitalRead(buttonPin);
  buttonNew1 = digitalRead(buttonPin);
  //first button check below and homepage
  if (buttonOld==1 && buttonNew==0) {
    // turn LED on:
    display.clearDisplay();
    display.setTextSize(0);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println(F("/Home/"));
    display.setCursor(2, 20);
    display.setTextSize(0);
    display.println(F("Temp. & Humidity"));
    display.display();
    //display test and second button check below
  } if (buttonOld1==1 && buttonNew1==0) {
       display.clearDisplay();
      display.clearDisplay();
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.println(F("display test"));
      display.display();
      for(;;);
  }
  
  
 
  delay(100);
  
}
