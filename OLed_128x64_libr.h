#ifndef oledsmart
#define oledsmart

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Arduino.h"


class OLedSmart
{
  public:
    OLedSmart(Adafruit_SSD1306 givenDisplay);

    void Initialize();
    void PrintTimeANDDate(String time, String date);

  private:
    //---functions---
    void printSymbol_18x29(char symb, int xPos, int yPos);
    void printSymbol_6x9(int symbID, int xPos, int yPos);
    void drawHLine(int xFrom, int xTo, int y, int color);
    void drawVLine(int x, int yFrom, int yTo, int color);

    template <int rows, int cols>
    void drawFromBitmap(int (&bitmap)[rows][cols], int xPos, int yPos);
    //---------------

    //---variables---
    Adafruit_SSD1306 display;
    //---------------
};

#endif
