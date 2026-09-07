/*
  LiquidCrystal Library - Abstract Pulse Wave Animation

  Instead of animating a recognizable figure, this fills all 16 columns
  of the bottom row with custom "density" characters — from empty to
  fully solid — and cycles a sine-like wave of "fullness" across them,
  creating an abstract pulsing/breathing ripple effect.

  Circuit is identical to the original example:
  * LCD RS -> pin 12, Enable -> pin 11
  * LCD D4-D7 -> pins 5, 4, 3, 2
  * LCD R/W -> ground
  * 10K potentiometer wiper -> LCD VO (pin 3)
  * 10K potentiometer on A0 (controls animation speed)
*/

#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// 6 "density" frames, from empty to solid — each fills in one more row
// of pixels from the bottom, like a rising level meter
byte density0[8] = {
  0b00000, 0b00000, 0b00000, 0b00000,
  0b00000, 0b00000, 0b00000, 0b00000
};
byte density1[8] = {
  0b00000, 0b00000, 0b00000, 0b00000,
  0b00000, 0b00000, 0b00000, 0b11111
};
byte density2[8] = {
  0b00000, 0b00000, 0b00000, 0b00000,
  0b00000, 0b00000, 0b11111, 0b11111
};
byte density3[8] = {
  0b00000, 0b00000, 0b00000, 0b00000,
  0b00000, 0b11111, 0b11111, 0b11111
};
byte density4[8] = {
  0b00000, 0b00000, 0b00000, 0b00000,
  0b11111, 0b11111, 0b11111, 0b11111
};
byte density5[8] = {
  0b00000, 0b00000, 0b00000, 0b11111,
  0b11111, 0b11111, 0b11111, 0b11111
};

const int numLevels = 6;
byte* levels[numLevels] = {
  density0, density1, density2, density3, density4, density5
};

const int cols = 16;
float phase = 0.0; // drives the wave across the row

void setup() {
  lcd.begin(16, 2);

  // register the 6 density frames as custom characters 0-5
  for (int i = 0; i < numLevels; i++) {
    lcd.createChar(i, levels[i]);
  }

  lcd.setCursor(0, 0);
  lcd.print(" ~ pulse wave ~ ");
}

void loop() {
  // potentiometer controls how fast the wave moves and the frame delay
  int sensorReading = analogRead(A0);
  int frameDelay = map(sensorReading, 0, 1023, 30, 150);

  // draw one "wave" frame across the bottom row
  for (int col = 0; col < cols; col++) {
    // combine column position and phase into a wave value -1..1
    float wave = sin((col * 0.6) + phase);
    // map -1..1 into a density level 0..numLevels-1
    int level = (int)((wave + 1.0) * 0.5 * (numLevels - 1));
    level = constrain(level, 0, numLevels - 1);

    lcd.setCursor(col, 1);
    lcd.write(byte(level));
  }

  phase += 0.35; // advance the wave each frame
  if (phase > TWO_PI) {
    phase -= TWO_PI;
  }

  delay(frameDelay);
}