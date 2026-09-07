/*
  LiquidCrystal Library - Geometric Pattern Animation (no blinking)

  Fixed: removed the center block that was toggling on/off every
  other frame (which looked like a blinking cursor). The pattern now
  only expands/contracts smoothly with no flashing elements.
*/

#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

byte diagUp[8] = {
  0b00001, 0b00010, 0b00100, 0b01000,
  0b10000, 0b00000, 0b00000, 0b00000
};
byte diagDown[8] = {
  0b10000, 0b01000, 0b00100, 0b00010,
  0b00001, 0b00000, 0b00000, 0b00000
};
byte cornerTL[8] = {
  0b11111, 0b10000, 0b10000, 0b10000,
  0b10000, 0b00000, 0b00000, 0b00000
};
byte cornerTR[8] = {
  0b11111, 0b00001, 0b00001, 0b00001,
  0b00001, 0b00000, 0b00000, 0b00000
};
byte cornerBL[8] = {
  0b00000, 0b00000, 0b00000, 0b10000,
  0b10000, 0b10000, 0b10000, 0b11111
};
byte cornerBR[8] = {
  0b00000, 0b00000, 0b00000, 0b00001,
  0b00001, 0b00001, 0b00001, 0b11111
};

enum { DIAG_UP, DIAG_DOWN, CORNER_TL, CORNER_TR, CORNER_BL, CORNER_BR };

const int cols = 16;
const int rows = 2;
int frame = 0;
const int maxFrame = 8;

void setup() {
  lcd.begin(16, 2);
  lcd.noCursor();
  lcd.noBlink();

  lcd.createChar(DIAG_UP, diagUp);
  lcd.createChar(DIAG_DOWN, diagDown);
  lcd.createChar(CORNER_TL, cornerTL);
  lcd.createChar(CORNER_TR, cornerTR);
  lcd.createChar(CORNER_BL, cornerBL);
  lcd.createChar(CORNER_BR, cornerBR);
}

void clearDisplay() {
  for (int r = 0; r < rows; r++) {
    lcd.setCursor(0, r);
    lcd.print("                "); // 16 spaces
  }
}

void drawFrame(int size) {
  clearDisplay();

  int centerCol = cols / 2;
  int left = centerCol - size;
  int right = centerCol + size;

  if (left < 0) left = 0;
  if (right > cols - 1) right = cols - 1;

  lcd.setCursor(left, 0);
  lcd.write(byte(CORNER_TL));
  for (int c = left + 1; c < right; c++) {
    lcd.setCursor(c, 0);
    lcd.write(byte(((c - left) % 2 == 0) ? DIAG_UP : DIAG_DOWN));
  }
  if (right > left) {
    lcd.setCursor(right, 0);
    lcd.write(byte(CORNER_TR));
  }

  lcd.setCursor(left, 1);
  lcd.write(byte(CORNER_BL));
  for (int c = left + 1; c < right; c++) {
    lcd.setCursor(c, 1);
    lcd.write(byte(((c - left) % 2 == 0) ? DIAG_DOWN : DIAG_UP));
  }
  if (right > left) {
    lcd.setCursor(right, 1);
    lcd.write(byte(CORNER_BR));
  }
}

void loop() {
  int sensorReading = analogRead(A0);
  int frameDelay = map(sensorReading, 0, 1023, 80, 400);

  drawFrame(frame);

  frame++;
  if (frame > maxFrame) {
    frame = 0;
  }

  delay(frameDelay);
}