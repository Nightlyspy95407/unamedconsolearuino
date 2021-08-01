#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
//definitions and stuff and constants and normal integers
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// The pins for I2C are defined by the Wire-library. 
// On an arduino UNO:       A4(SDA), A5(SCL)
// On an arduino MEGA 2560: 20(SDA), 21(SCL)
// On an arduino LEONARDO:   2(SDA),  3(SCL), ...
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define NUMFLAKES     10 
#define LOGO_HEIGHT   16
#define LOGO_WIDTH    16


//some setup stuff for the display the current project has atm
static const unsigned char PROGMEM logo_bmp[] =
{
//go ahead and put a logo or something here in a bitmap and convert it to .cpp(optional)(if you don't use this delete this part for more memory)

};

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
//feel free to put a loading screen or something here as well too, don't forget to put a 
}

void loop() {
  //this is where the game or program goes or it could go in setup but you would have to make it loop or not end.
  //don't forget to put display.display() after every time you want the display to update!
}
