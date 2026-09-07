#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET    -1
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

String inputText = "";

void setup() {
  Serial.begin(9600);

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    while (true);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Type in ");
  display.setCursor(0, 12);
  display.println("Serial Monitor:");
  display.display();

  
  Serial.println("Set BAUD to 9600");
  Serial.println("Set 'Both NL & CR' instead of 'No line ending'");
  Serial.println("Set-up ready");
  Serial.println("Type something and press Enter:");
}

void loop() {
  if (Serial.available() > 0) {
    char incomingChar = Serial.read();

    if (incomingChar == '\n' || incomingChar == '\r') {
      // only redraw if there's actual text — ignore stray/duplicate
      // line-ending characters so the screen doesn't get cleared twice
      if (inputText.length() > 0) {
        showText(inputText);
        inputText = "";
      }
    } else if (incomingChar == 8 || incomingChar == 127) {
      if (inputText.length() > 0) {
        inputText.remove(inputText.length() - 1);
      }
    } else {
      inputText += incomingChar;
    }
  }
}

void showText(String text) {
  display.clearDisplay();
  display.setCursor(0, 0);
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.println(text);
  display.display();

  Serial.print("Displayed: ");
  Serial.println(text);
}