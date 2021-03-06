#include "OLed_128x64_libr.h"

OLedSmart::OLedSmart(Adafruit_SSD1306 givenDisplay)
{
  display = givenDisplay;
}


//-----------public functions-------------

void OLedSmart::Initialize()
{
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  display.clearDisplay();
  display.display();
}

// prints current time from given set of characters
void OLedSmart::PrintTimeANDDate(String time, String date)
{
  display.clearDisplay();
  // 14;29
  // 38;29
  // 74;29
  // 98;29
  // 55;29 - ':'
  printSymbol_18x29(time[0], 14, 29);
  printSymbol_18x29(time[1], 38, 29);
  printSymbol_18x29(time[2], 74, 29);
  printSymbol_18x29(time[3], 98, 29);
  printSymbol_18x29(':', 55, 29);

  printSymbol_6x9('0', 14, 16);
  printSymbol_6x9('ф', 22, 16);
  printSymbol_6x9('д', 30, 16);
  printSymbol_6x9('е', 38, 16);
  printSymbol_6x9('и', 46, 16);
  printSymbol_6x9('к', 54, 16);
  printSymbol_6x9('л', 62, 16);
  printSymbol_6x9('м', 70, 16);
  printSymbol_6x9('н', 78, 16);
  printSymbol_6x9('о', 86, 16);
  printSymbol_6x9('п', 94, 16);
  printSymbol_6x9('р', 101, 16);
  printSymbol_6x9('с', 108, 16);
  printSymbol_6x9('т', 115, 16);
  display.display();
  
}
//----------------------------------------

//-----------private functions------------

#pragma region 18x29_SYMBOL
// prints a given symbol 18x29 pixels at a given position
void OLedSmart::printSymbol_18x29(char symb, int xPos, int yPos)
{
  switch(symb)
  {
    case '0':
      drawHLine(xPos + 7, xPos + 10, yPos, WHITE);
      drawHLine(xPos + 5, xPos + 6, yPos + 1, WHITE);
      drawHLine(xPos + 11, xPos + 12, yPos + 1, WHITE);
      drawHLine(xPos + 4, xPos + 4, yPos + 2, WHITE);
      drawHLine(xPos + 13, xPos + 13, yPos + 2, WHITE);
      drawVLine(xPos + 3, yPos + 3, yPos + 4, WHITE);
      drawVLine(xPos + 14, yPos + 3, yPos + 4, WHITE);
      drawVLine(xPos + 2, yPos + 5, yPos + 6, WHITE);
      drawVLine(xPos + 15, yPos + 5, yPos + 6, WHITE);
      drawVLine(xPos + 1, yPos + 7, yPos + 9, WHITE);
      drawVLine(xPos + 16, yPos + 7, yPos + 9, WHITE);
      drawVLine(xPos, yPos + 10, yPos + 18, WHITE);
      drawVLine(xPos + 17, yPos + 10, yPos + 18, WHITE);
      drawVLine(xPos + 1, yPos + 19, yPos + 21, WHITE);
      drawVLine(xPos + 16, yPos + 19, yPos + 21, WHITE);
      drawVLine(xPos + 2, yPos + 22, yPos + 23, WHITE);
      drawVLine(xPos + 15, yPos + 22, yPos + 23, WHITE);
      drawVLine(xPos + 3, yPos + 24, yPos + 25, WHITE);
      drawVLine(xPos + 14, yPos + 24, yPos + 25, WHITE);
      drawHLine(xPos + 4, xPos + 4, yPos + 26, WHITE);
      drawHLine(xPos + 13, xPos + 13, yPos + 26, WHITE);
      drawHLine(xPos + 5, xPos + 6, yPos + 27, WHITE);
      drawHLine(xPos + 11, xPos + 12, yPos + 27, WHITE);
      drawHLine(xPos + 7, xPos + 10, yPos + 28, WHITE);
      break;
    case '1':
      drawVLine(xPos + 12, yPos, yPos + 28, WHITE);
      for (int i = 0; i <= 12; i++)
        drawHLine(xPos + i, xPos + i, yPos + 11 - i, WHITE);
      break;
    case '2':
      drawHLine(xPos, xPos + 17, yPos + 28, WHITE);
      for (int delta = 0; delta <= 17; delta++)
        drawHLine(xPos + delta, xPos + delta, yPos + 27 - delta, WHITE);
      drawVLine(xPos + 17, yPos + 6, yPos + 10, WHITE);
      drawVLine(xPos + 16, yPos + 4, yPos + 5, WHITE);
      drawVLine(xPos + 15, yPos + 3, yPos + 3, WHITE);
      drawVLine(xPos + 14, yPos + 2, yPos + 2, WHITE);
      drawHLine(xPos + 12, xPos + 13, yPos + 1, WHITE);
      drawHLine(xPos + 6, xPos + 11, yPos, WHITE);
      drawHLine(xPos + 4, xPos + 5, yPos + 1, WHITE);
      drawHLine(xPos + 3, xPos + 3, yPos + 2, WHITE);
      drawHLine(xPos + 2, xPos + 2, yPos + 3, WHITE);
      drawVLine(xPos + 1, yPos + 4, yPos + 5, WHITE);
      drawVLine(xPos, yPos + 6, yPos + 10, WHITE);
      break;
    case '3':
      drawHLine(xPos + 6, xPos + 11, yPos, WHITE);
      drawHLine(xPos + 4, xPos + 5, yPos + 1, WHITE);
      drawHLine(xPos + 12, xPos + 13, yPos + 1, WHITE);
      drawHLine(xPos + 3, xPos + 3, yPos + 2, WHITE);
      drawHLine(xPos + 14, xPos + 14, yPos + 2, WHITE);
      drawHLine(xPos + 2, xPos + 2, yPos + 3, WHITE);
      drawHLine(xPos + 15, xPos + 15, yPos + 3, WHITE);
      drawVLine(xPos + 1, yPos + 4, yPos + 5, WHITE);
      drawVLine(xPos + 16, yPos + 4, yPos + 5, WHITE);
      drawVLine(xPos + 17, yPos + 5, yPos + 10, WHITE);
      for (int i = 0; i <= 2; i++)
        drawHLine(xPos + 16 - i, xPos + 16 - i, yPos + 11 + i, WHITE);
      drawHLine(xPos + 9, xPos + 13, yPos + 14, WHITE);
      for (int i = 0; i <= 2; i++)
        drawHLine(xPos + 14 + i, xPos + 14 + i, yPos + 15 + i, WHITE);
      drawVLine(xPos + 17, yPos + 18, yPos + 22, WHITE);
      drawVLine(xPos + 16, yPos + 23, yPos + 24, WHITE);
      drawVLine(xPos + 1, yPos + 23, yPos + 24, WHITE);
      drawHLine(xPos + 15, xPos + 15, yPos + 25, WHITE);
      drawHLine(xPos + 2, xPos + 2, yPos + 25, WHITE);
      drawHLine(xPos + 14, xPos + 14, yPos + 26, WHITE);
      drawHLine(xPos + 3, xPos + 3, yPos + 26, WHITE);
      drawHLine(xPos + 4, xPos + 5, yPos + 27, WHITE);
      drawHLine(xPos + 12, xPos + 13, yPos + 27, WHITE);
      drawHLine(xPos + 6, xPos + 11, yPos + 28, WHITE);
      break;
    case '4':
      drawVLine(xPos + 2, yPos, yPos + 11, WHITE);
      drawVLine(xPos + 3, yPos + 12, yPos + 13, WHITE);
      drawVLine(xPos + 4, yPos + 14, yPos + 14, WHITE);
      drawHLine(xPos + 5, xPos + 15, yPos + 15, WHITE);
      drawVLine(xPos + 16, yPos, yPos + 28, WHITE);
      break;
    case '5':
      drawHLine(xPos, xPos + 17, yPos, WHITE);
      drawVLine(xPos, yPos + 1, yPos + 10, WHITE);
      drawHLine(xPos, xPos + 11, yPos + 11, WHITE);
      drawHLine(xPos + 12, xPos + 13, yPos + 12, WHITE);
      drawHLine(xPos + 14, xPos + 14, yPos + 13, WHITE);
      drawHLine(xPos + 15, xPos + 15, yPos + 14, WHITE);
      drawVLine(xPos + 16, yPos + 15, yPos + 16, WHITE);
      drawVLine(xPos + 17, yPos + 17, yPos + 22, WHITE);
      drawVLine(xPos + 16, yPos + 23, yPos + 24, WHITE);
      drawHLine(xPos + 15, xPos + 15, yPos + 25, WHITE);
      drawHLine(xPos + 14, xPos + 14, yPos + 26, WHITE);
      drawHLine(xPos + 12, xPos + 13, yPos + 27, WHITE);
      drawHLine(xPos, xPos + 11, yPos + 28, WHITE);
      break;
    case '6':
      drawHLine(xPos + 6, xPos + 13, yPos, WHITE);
      drawHLine(xPos + 4, xPos + 5, yPos + 1, WHITE);
      drawHLine(xPos + 14, xPos + 15, yPos + 1, WHITE);
      drawHLine(xPos + 3, xPos + 3, yPos + 2, WHITE);
      drawHLine(xPos + 16, xPos + 16, yPos + 2, WHITE);
      drawHLine(xPos + 2, xPos + 2, yPos + 3, WHITE);
      drawVLine(xPos + 1, yPos + 4, yPos + 5, WHITE);
      drawVLine(xPos, yPos + 6, yPos + 22, WHITE);
      drawHLine(xPos + 6, xPos + 11, yPos + 11, WHITE);
      drawHLine(xPos + 4, xPos + 5, yPos + 12, WHITE);
      drawHLine(xPos + 12, xPos + 13, yPos + 12, WHITE);
      drawHLine(xPos + 3, xPos + 3, yPos + 13, WHITE);
      drawHLine(xPos + 14, xPos + 14, yPos + 13, WHITE);
      drawHLine(xPos + 2, xPos + 2, yPos + 14, WHITE);
      drawHLine(xPos + 15, xPos + 15, yPos + 14, WHITE);
      drawVLine(xPos + 1, yPos + 15, yPos + 16, WHITE);
      drawVLine(xPos + 16, yPos + 15, yPos + 16, WHITE);
      drawVLine(xPos + 17, yPos + 17, yPos + 22, WHITE);
      drawVLine(xPos + 1, yPos + 23, yPos + 24, WHITE);
      drawVLine(xPos + 16, yPos + 23, yPos + 24, WHITE);
      drawHLine(xPos + 2, xPos + 2, yPos + 25, WHITE);
      drawHLine(xPos + 15, xPos + 15, yPos + 25, WHITE);
      drawHLine(xPos + 3, xPos + 3, yPos + 26, WHITE);
      drawHLine(xPos + 14, xPos + 14, yPos + 26, WHITE);
      drawHLine(xPos + 4, xPos + 5, yPos + 27, WHITE);
      drawHLine(xPos + 12, xPos + 13, yPos + 27, WHITE);
      drawHLine(xPos + 6, xPos + 11, yPos + 28, WHITE);
      break;
    case '7':
      drawHLine(xPos, xPos + 17, yPos, WHITE);
      for (int n = 0; n < 2; n++)
      {
        for (int j = 0; j < 2; j++)
        {
          drawHLine(xPos + j * 3 + n * 8, xPos + j * 3 + n * 8, yPos + 28 - 5 * j - 13 * n, WHITE);
          drawVLine(xPos + 1 + j * 3 + n * 8, yPos + 26 - 5 * j - 13 * n, yPos + 27 - 5 * j - 13 * n, WHITE);
          drawVLine(xPos + 2 + j * 3 + n * 8, yPos + 24 - 5 * j - 13 * n, yPos + 25 - 5 * j - 13 * n, WHITE);
        }
        drawHLine(xPos + 6 + n * 8, xPos + 6 + n * 8, yPos + 18 - 13 * n, WHITE);
        drawVLine(xPos + 7 + n * 8, yPos + 16 - 13 * n, yPos + 17 - 13 * n, WHITE);
      }
      drawHLine(xPos + 16, xPos + 16, yPos + 2, WHITE);
      drawHLine(xPos + 17, xPos + 17, yPos + 1, WHITE);
      break;
    case '8':
      drawHLine(xPos + 6, xPos + 11, yPos, WHITE);
      drawHLine(xPos + 5, xPos + 5, yPos + 1, WHITE);
      drawHLine(xPos + 12, xPos + 12, yPos + 1, WHITE);
      drawHLine(xPos + 4, xPos + 4, yPos + 2, WHITE);
      drawHLine(xPos + 13, xPos + 13, yPos + 2, WHITE);
      drawHLine(xPos + 3, xPos + 3, yPos + 3, WHITE);
      drawHLine(xPos + 14, xPos + 14, yPos + 3, WHITE);
      drawVLine(xPos + 2, yPos + 4, yPos + 9, WHITE);
      drawVLine(xPos + 15, yPos + 4, yPos + 9, WHITE);
      drawHLine(xPos + 3, xPos + 3, yPos + 10, WHITE);
      drawHLine(xPos + 14, xPos + 14, yPos + 10, WHITE);
      drawHLine(xPos + 4, xPos + 4, yPos + 11, WHITE);
      drawHLine(xPos + 13, xPos + 13, yPos + 11, WHITE);
      drawHLine(xPos +  4, xPos + 5, yPos + 12, WHITE);
      drawHLine(xPos + 12, xPos + 13, yPos + 12, WHITE);
      drawHLine(xPos + 3, xPos + 3, yPos + 13, WHITE);
      drawHLine(xPos + 6, xPos + 11, yPos + 13, WHITE);
      drawHLine(xPos + 14, xPos + 14, yPos + 13, WHITE);
      drawHLine(xPos + 2, xPos + 2, yPos + 14, WHITE);
      drawHLine(xPos + 15, xPos + 15, yPos + 14, WHITE);
      drawVLine(xPos + 1, yPos + 15, yPos + 16, WHITE);
      drawVLine(xPos + 16, yPos + 15, yPos + 16, WHITE);
      drawVLine(xPos, yPos + 17, yPos + 22, WHITE);
      drawVLine(xPos + 17, yPos + 17, yPos + 22, WHITE);
      drawVLine(xPos + 1, yPos + 23, yPos + 24, WHITE);
      drawVLine(xPos + 16, yPos + 23, yPos + 24, WHITE);
      drawHLine(xPos + 2, xPos + 2, yPos + 25, WHITE);
      drawHLine(xPos + 15, xPos + 15, yPos + 25, WHITE);
      drawHLine(xPos + 3, xPos + 3, yPos + 26, WHITE);
      drawHLine(xPos + 14, xPos + 14, yPos + 26, WHITE);
      drawHLine(xPos + 4, xPos + 5, yPos + 27, WHITE);
      drawHLine(xPos + 12, xPos + 13, yPos + 27, WHITE);
      drawHLine(xPos + 6, xPos + 11, yPos + 28, WHITE); 
      break;
    case '9':
      drawHLine(xPos + 6, xPos + 11, yPos, WHITE);
      drawHLine(xPos + 4, xPos + 5, yPos + 1, WHITE);
      drawHLine(xPos + 12, xPos + 13, yPos + 1, WHITE);
      drawHLine(xPos + 3, xPos + 3, yPos + 2, WHITE);
      drawHLine(xPos + 14, xPos + 14, yPos + 2, WHITE);
      drawHLine(xPos + 2, xPos + 2, yPos + 3, WHITE);
      drawHLine(xPos + 15, xPos + 15, yPos + 3, WHITE);
      drawVLine(xPos + 1, yPos + 4, yPos + 5, WHITE);
      drawVLine(xPos + 16, yPos + 4, yPos + 5, WHITE);
      drawVLine(xPos, yPos + 6, yPos + 11, WHITE);
      drawVLine(xPos + 17, yPos + 6, yPos + 22, WHITE);
      drawVLine(xPos + 1, yPos + 12, yPos + 13, WHITE);
      drawVLine(xPos + 16, yPos + 12, yPos + 13, WHITE);
      drawHLine(xPos + 2, xPos + 2, yPos + 14, WHITE);
      drawHLine(xPos + 15, xPos + 15, yPos + 14, WHITE);
      drawHLine(xPos + 3, xPos + 3, yPos + 15, WHITE);
      drawHLine(xPos + 14, xPos + 14, yPos + 15, WHITE);
      drawHLine(xPos + 4, xPos + 5, yPos + 16, WHITE);
      drawHLine(xPos + 12, xPos + 13, yPos + 16, WHITE);
      drawHLine(xPos + 6, xPos + 11, yPos + 17, WHITE);
      drawVLine(xPos + 16, yPos + 23, yPos + 24, WHITE);
      drawHLine(xPos + 15, xPos + 15, yPos + 25, WHITE);
      drawHLine(xPos + 1, xPos + 1, yPos + 25, WHITE);
      drawHLine(xPos + 2, xPos + 2, yPos + 26, WHITE);
      drawHLine(xPos + 14, xPos + 14, yPos + 26, WHITE);
      drawHLine(xPos + 3, xPos + 4, yPos + 27, WHITE);
      drawHLine(xPos + 12, xPos + 13, yPos + 27, WHITE);
      drawHLine(xPos + 5, xPos + 11, yPos + 28, WHITE);
      break;
    case ':':
      drawHLine(xPos + 8, xPos + 9, yPos + 8, WHITE);
      drawHLine(xPos + 8, xPos + 9, yPos + 9, WHITE);
      drawHLine(xPos + 8, xPos + 9, yPos + 19, WHITE);
      drawHLine(xPos + 8, xPos + 9, yPos + 20, WHITE);
      break;
      
  }

  display.display();
}
#pragma endregion

#pragma region 6x9_SYMBOL
// prints a given symbol 6x9 pixels at a given position
void OLedSmart::printSymbol_6x9(int symbID, int xPos, int yPos)
{
  vector<vector<int>> arr;
  switch(symbID)
  {
    case 'а':
      drawVLine(xPos + 4, yPos + 2, yPos + 7, WHITE);
      drawHLine(xPos + 1, xPos + 3, yPos + 3, WHITE);
      drawVLine(xPos, yPos + 4, yPos + 7, WHITE);
      drawHLine(xPos + 1, xPos + 3, yPos + 8, WHITE);
      drawVLine(xPos + 5, yPos + 7, yPos + 8, WHITE);
      break;
    case 'б':
      drawHLine(xPos + 2, xPos + 5, yPos + 1, WHITE);
      break;
    case 'в':
      drawHLine(xPos + 2, xPos + 3, yPos, WHITE);
      drawVLine(xPos + 1, yPos + 1, yPos + 8, WHITE);
      drawVLine(xPos + 4, yPos + 1, yPos + 3, WHITE);
      drawVLine(xPos + 3, yPos + 4, yPos + 5, WHITE);
      drawVLine(xPos + 4, yPos + 6, yPos + 7, WHITE);
      drawHLine(xPos + 2, xPos + 3, yPos + 8, WHITE);
      drawHLine(xPos, xPos, yPos + 6, WHITE);
      break;
    case 'д':
      drawHLine(xPos + 2, xPos + 3, yPos + 3, WHITE);
      drawVLine(xPos + 1, yPos + 4, yPos + 6, WHITE);
      drawVLine(xPos + 4, yPos + 4, yPos + 6, WHITE);
      drawHLine(xPos, xPos + 5, yPos + 7, WHITE);
      drawHLine(xPos, xPos, yPos + 8, WHITE);
      drawHLine(xPos + 5, xPos + 5, yPos + 8, WHITE);
      break;
    case 'е':
      drawHLine(xPos + 1, xPos + 3, yPos + 3, WHITE);
      drawVLine(xPos, yPos + 4, yPos + 7, WHITE);
      drawVLine(xPos + 4, yPos + 4, yPos + 5, WHITE);
      drawHLine(xPos + 1, xPos + 3, yPos + 6, WHITE);
      drawHLine(xPos + 1, xPos + 4, yPos + 8, WHITE);
      break;
    case 'и':
      drawVLine(xPos, yPos + 3, yPos + 7, WHITE);
      drawHLine(xPos + 1, xPos + 5, yPos + 8, WHITE);
      drawHLine(xPos + 4, xPos + 4, yPos + 8, BLACK);
      drawVLine(xPos + 4, yPos + 3, yPos + 7, WHITE);
      break;
    case 'к':
      drawVLine(xPos + 1, yPos + 3, yPos + 8, WHITE);
      for (int d = 0; d < 3; d++)
        drawHLine(xPos + 4 - d, xPos + 4 - d, yPos + 3 + d, WHITE);
      for (int d = 0; d < 3; d++)
        drawHLine(xPos + 2 + d, xPos + 2 + d, yPos + 6 + d, WHITE);
      break;
    case 'л':
      drawHLine(xPos + 2, xPos + 3, yPos + 3, WHITE);
      drawVLine(xPos + 4, yPos + 4, yPos + 8, WHITE);
      drawVLine(xPos + 1, yPos + 4, yPos + 7, WHITE);
      drawHLine(xPos, xPos + 1, yPos + 8, WHITE);
      break;
    case 'м':
      drawVLine(xPos, yPos + 3, yPos + 8, WHITE);
      drawVLine(xPos + 5, yPos + 3, yPos + 8, WHITE);
      drawHLine(xPos + 1, xPos + 1, yPos + 4, WHITE);
      drawHLine(xPos + 4, xPos + 4, yPos + 4, WHITE);
      drawHLine(xPos + 2, xPos + 3, yPos + 5, WHITE);
      break;
    case 'н':
      drawVLine(xPos + 1, yPos + 3, yPos + 8, WHITE);
      drawVLine(xPos + 4, yPos + 3, yPos + 8, WHITE);
      drawHLine(xPos + 2, xPos + 3, yPos + 5, WHITE);
      break;
    case 'о':
      drawHLine(xPos + 1, xPos + 4, yPos + 3, WHITE);
      drawHLine(xPos + 1, xPos + 4, yPos + 8, WHITE);
      drawVLine(xPos, yPos + 4, yPos + 7, WHITE);
      drawVLine(xPos + 5, yPos + 4, yPos + 7, WHITE);
      break;
    case 'п':
      drawVLine(xPos, yPos + 3, yPos + 8, WHITE);
      drawHLine(xPos + 1, xPos + 1, yPos + 4, WHITE);
      drawHLine(xPos + 2, xPos + 3, yPos + 3, WHITE);
      drawVLine(xPos + 4, yPos + 4, yPos + 8, WHITE);
      break;
    case 'р':
      drawHLine(xPos + 2, xPos + 3, yPos + 3, WHITE);
      drawVLine(xPos + 1, yPos + 4, yPos + 8, WHITE);
      drawHLine(xPos + 1, xPos + 3, yPos + 6, WHITE);
      drawVLine(xPos + 4, yPos + 4, yPos + 5, WHITE);
      break;
    case 'с':
      drawHLine(xPos + 1, xPos + 3, yPos + 3, WHITE);
      drawVLine(xPos, yPos + 4, yPos + 7, WHITE);
      drawHLine(xPos + 1, xPos + 3, yPos + 8, WHITE);
      drawVLine(xPos + 4, yPos + 4, yPos + 4, WHITE);
      drawVLine(xPos + 4, yPos + 7, yPos + 7, WHITE);
      break;
    case 'т':
      drawHLine(xPos + 1, xPos + 5, yPos + 3, WHITE);
      drawVLine(xPos + 3, yPos + 4, yPos + 8, WHITE);
      break;
    case 'у':
      drawVLine(xPos + 1, yPos + 3, yPos + 5, WHITE);
      drawVLine(xPos + 5, yPos + 3, yPos + 8, WHITE);
      drawHLine(xPos + 2, xPos + 4, yPos + 6, WHITE);
      drawHLine(xPos + 1, xPos + 4, yPos + 8, WHITE);
      break;
    case 'ф':
      drawHLine(xPos + 1, xPos + 3, yPos + 3, WHITE);
      drawVLine(xPos, yPos + 4, yPos + 5, WHITE);
      drawVLine(xPos + 4, yPos + 4, yPos + 5, WHITE);
      drawVLine(xPos + 2, yPos + 4, yPos + 8, WHITE);
      drawHLine(xPos + 1, xPos + 3, yPos + 6, WHITE);
      drawHLine(xPos + 1, xPos + 1, yPos + 8, WHITE);
      break;
    case '0':
      arr = vector<vector<int>>(9,  vector<int>(6,   0, 0, 1, 1, 0, 0),
                                    vector<int>(6,   0, 1, 0, 0, 1, 0),
                                    vector<int>(6,   1, 0, 0, 0, 0, 1),
                                    vector<int>(6,   1, 0, 0, 0, 0, 1),
                                    vector<int>(6,   1, 0, 0, 0, 0, 1),
                                    vector<int>(6,   1, 0, 0, 0, 0, 1),
                                    vector<int>(6,   1, 0, 0, 0, 0, 1),
                                    vector<int>(6,   0, 1, 0, 0, 1, 0),
                                    vector<int>(6,   0, 0, 1, 1, 0, 0));
      Serial.println(arr.get(0).get(2), DEC);
      drawFromBitmap(arr, xPos, yPos);
      break;
    case '1':
      break;
    case '2':
      drawHLine(xPos + 1, xPos + 4, yPos, WHITE);
      drawVLine(xPos, yPos + 1, yPos + 2, WHITE);
      drawVLine(xPos + 5, yPos + 1, yPos + 2, WHITE);
      for (int d = 0; d <= 4; d++)
        drawHLine(xPos + 4 - d, xPos + 4 - d, yPos + 3 + d, WHITE);
      drawHLine(xPos, xPos + 5, yPos + 8, WHITE);
      break;
    case '3':
      drawHLine(xPos + 1, xPos + 4, yPos, WHITE);
      drawVLine(xPos, yPos + 1, yPos + 2, WHITE);
      drawVLine(xPos + 5, yPos + 1, yPos + 3, WHITE);
      drawHLine(xPos + 3, xPos + 4, yPos + 4, WHITE);
      drawVLine(xPos + 5, yPos + 5, yPos + 7, WHITE);
      drawHLine(xPos + 1, xPos + 4, yPos + 8, WHITE);
      drawVLine(xPos, yPos + 6, yPos + 7, WHITE);  
      break;
    case '4':
      drawVLine(xPos, yPos, yPos + 4, WHITE);
      drawVLine(xPos + 5, yPos, yPos + 8, WHITE);
      drawHLine(xPos + 1, xPos + 4, yPos + 5, WHITE);
      break;
    case '5':
      drawHLine(xPos, xPos + 5, yPos, WHITE);
      drawVLine(xPos, yPos , yPos + 3, WHITE);
      drawHLine(xPos + 1, xPos + 4, yPos + 3, WHITE);
      drawVLine(xPos + 5, yPos + 4, yPos + 7, WHITE);
      drawHLine(xPos, xPos + 4, yPos + 8, WHITE);
      break;
    case '6':
      drawHLine(xPos + 1, xPos + 4, yPos, WHITE);
      drawVLine(xPos, yPos + 1, yPos + 7, WHITE);
      drawHLine(xPos + 1, xPos + 4, yPos + 4, WHITE);
      drawHLine(xPos + 1, xPos + 4, yPos + 8, WHITE);
      drawVLine(xPos + 5, yPos + 1, yPos + 7, WHITE);
      drawVLine(xPos + 5, yPos + 2, yPos + 4, BLACK);
      break;
    case '7':
      drawHLine(xPos, xPos + 5, yPos, WHITE);
      drawVLine(xPos + 5, yPos + 1, yPos + 2, WHITE);
      for(int d = 0; d <= 4; d++)
        drawHLine(xPos + 4 - d, xPos + 4 - d, yPos + 3 + d, WHITE);
      drawHLine(xPos, xPos, yPos + 8, WHITE);
      break;
    case '8':
      drawHLine(xPos + 2, xPos + 3, yPos, WHITE);
      drawVLine(xPos + 1, yPos + 1, yPos + 2, WHITE);
      drawVLine(xPos + 4, yPos + 1, yPos + 2, WHITE);
      drawHLine(xPos + 2, xPos + 3, yPos + 3, WHITE);
      drawHLine(xPos + 1, xPos + 1, yPos + 4, WHITE);
      drawHLine(xPos + 4, xPos + 4, yPos + 4, WHITE);
      drawVLine(xPos, yPos + 5, yPos + 6, WHITE);
      drawVLine(xPos + 5, yPos + 5, yPos + 6, WHITE);
      drawHLine(xPos + 1, xPos + 1, yPos + 7, WHITE);
      drawHLine(xPos + 4, xPos + 4, yPos + 7, WHITE);
      drawHLine(xPos + 2, xPos + 3, yPos + 8, WHITE);
      break;
    case '9':
      drawHLine(xPos + 1, xPos + 4, yPos, WHITE);
      drawVLine(xPos, yPos + 1, yPos + 3, WHITE);
      drawVLine(xPos + 5, yPos + 1, yPos + 7, WHITE);
      drawHLine(xPos + 1, xPos + 4, yPos + 4, WHITE);
      drawHLine(xPos + 1, xPos + 4, yPos + 8, WHITE);
      drawHLine(xPos, xPos, yPos + 7, WHITE);
      break;
    default:
      break;
  }
}
#pragma endregion

// draws a straight horizontal line
void OLedSmart::drawHLine(int xFrom, int xTo, int y, int color)
{
  for(int dX = xFrom; dX <= xTo; dX++)
    display.drawPixel(dX, y, color);
}

// draws a straight vertical line
void OLedSmart::drawVLine(int x, int yFrom, int yTo, int color)
{
  for(int dY = yFrom; dY <= yTo; dY++)
    display.drawPixel(x, dY, color);
}
//----------------------------------------

template <int rows, int cols>
void OLedSmart::drawFromBitmap(int (&bitmap)[rows][cols], int xPos, int yPos)
{
  for (int y = 0; y < rows; y++)
    for (int x = 0; x < cols; x++)
      display.drawPixel(xPos + x, yPos + y, bitmap[y][x] == 1 ? WHITE : BLACK);
}

void OLedSmart::drawFromBitmap(vector<vector<int>> bitmap, int xPos, int yPos)
{
  for (unsigned int y = 0; y < bitmap.count(); y++)
    for (unsigned int x = 0; x < bitmap.get(y).count(); x++)
      display.drawPixel(xPos + x, yPos + y, bitmap.get(y).get(x) == 1 ? WHITE : BLACK);
}
