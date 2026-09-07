/*
  LiquidCrystal Library - Walking Character Animation

  A variation on the custom-character animation example: instead of
  a figure animating in place, this one walks across the bottom row,
  cycling through several leg-position frames as it moves.

  The circuit is identical to the original example:
  * LCD RS pin to digital pin 12
  * LCD Enable pin to digital pin 11
  * LCD D4 pin to digital pin 5
  * LCD D5 pin to digital pin 4
  * LCD D6 pin to digital pin 3
  * LCD D7 pin to digital pin 2
  * LCD R/W pin to ground
  * 10K potentiometer wiper to LCD VO (pin 3), ends to +5V/GND
  * 10K potentiometer on A0 (controls walking speed)
*/

#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Three walk-cycle frames: legs together, mid-stride, legs apart
byte walk1[8] = {
  0b00100,
  0b01110,
  0b00100,
  0b01110,
  0b10101,
  0b00100,
  0b01010,
  0b00000
};

byte walk2[8] = {
  0b00100,
  0b01110,
  0b00100,
  0b01110,
  0b10101,
  0b00100,
  0b00100,
  0b00000
};

byte walk3[8] = {
  0b00100,
  0b01110,
  0b00100,
  0b01110,
  0b10101,
  0b00100,
  0b01000,
  0b00010
};

const int numFrames = 3;
byte* frames[numFrames] = { walk1, walk2, walk3 };

int position = 0;      // current column (0-15)
int frameIndex = 0;    // current walk frame
int direction = 1;     // 1 = moving right, -1 = moving left

void setup() {
  lcd.begin(16, 2);

  // register all walk frames as custom characters 0-2
  for (int i = 0; i < numFrames; i++) {
    lcd.createChar(i, frames[i]);
  }

  lcd.setCursor(0, 0);
  lcd.print("Walking...");
}

void loop() {
  // read potentiometer to control walking speed
  int sensorReading = analogRead(A0);
  int delayTime = map(sensorReading, 0, 1023, 100, 400);

  // clear the previous position on the bottom row
  lcd.setCursor(position, 1);
  lcd.print(" ");

  // advance position, bouncing off the edges (0 to 15)
  position += direction;
  if (position >= 15) {
    position = 15;
    direction = -1;
  } else if (position <= 0) {
    position = 0;
    direction = 1;
  }

  // draw the figure at its new position using the next walk frame
  lcd.setCursor(position, 1);
  lcd.write(byte(frameIndex));

  frameIndex = (frameIndex + 1) % numFrames;

  delay(delayTime);
}