#include "OLed_128x64_libr.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
OLedSmart oLedSmart = OLedSmart(display);

void setup()
{
  oLedSmart.Initialize();
  delay(5000);
  oLedSmart.PrintTimeANDDate("2351", "10");
}

void loop()
{
  
}
