/* Simple bitmap image demo for the 2.13" 250x122 Monochrome ePaper
   (SSD1680 chip) on the Feather RP2040 ThinkInk.

   This draws a small hand-made 8x8 pixel heart, similar to the
   custom character we made earlier for the LCD — but here, instead
   of registering it as a "character," we draw it directly as an
   image using drawBitmap().
*/
#include "Adafruit_ThinkInk.h"

#ifdef ARDUINO_ADAFRUIT_FEATHER_RP2040_THINKINK
#define EPD_DC PIN_EPD_DC
#define EPD_CS PIN_EPD_CS
#define EPD_BUSY PIN_EPD_BUSY
#define SRAM_CS -1
#define EPD_RESET PIN_EPD_RESET
#define EPD_SPI &SPI1
#else
#define EPD_DC 10
#define EPD_CS 9
#define EPD_BUSY 7
#define SRAM_CS 6
#define EPD_RESET 8
#define EPD_SPI &SPI
#endif

ThinkInk_213_Mono_GDEY0213B74 display(EPD_DC, EPD_RESET, EPD_CS, SRAM_CS, EPD_BUSY, EPD_SPI);

// An 16x16 pixel image, one byte per row (16 pixels wide = 16 bits = 1 byte).
const unsigned char heart16[] PROGMEM = {
  0b00000000, 0b00000000,
  0b01111100, 0b00111110,
  0b11111110, 0b01111111,
  0b11111111, 0b11111111,
  0b11111111, 0b11111111,
  0b11111111, 0b11111111,
  0b01111111, 0b11111110,
  0b00111111, 0b11111100,
  0b00011111, 0b11111000,
  0b00001111, 0b11110000,
  0b00000111, 0b11100000,
  0b00000011, 0b11000000,
  0b00000001, 0b10000000,
  0b00000000, 0b00000000,
  0b00000000, 0b00000000,
  0b00000000, 0b00000000
};


void setup() {
  Serial.begin(115200);
  delay(2000);

  display.begin(THINKINK_MONO);

  display.clearBuffer();
  // drawBitmap(x, y, bitmap array, width, height, color)
  display.drawBitmap(10, 10, heart16, 16, 16, EPD_BLACK);
  display.display();
}

void loop() {
}
