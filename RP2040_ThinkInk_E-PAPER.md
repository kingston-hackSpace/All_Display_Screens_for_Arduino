# Adafruit Feather RP2040 ThinkInk + E-PAPER
---
## IMPORTANT
In this tutorial we will use:

BOARD: [Adafruit Feather RP2040 ThinkInk](https://learn.adafruit.com/adafruit-rp2040-feather-thinkink/overview)

E-PAPER PANEL: [2.13" 250x122 Monochrome or Gray eInk / ePaper - Bare Display - SSD1680Z Chip](https://learn.adafruit.com/bare-e-ink-displays-crash-course/2-13-250x122-monochrome-or-gray-eink-ssd1680z)

DRIVER:

    // 2.13" Monochrome displays with 250x122 pixels and SSD1680Z chipset
    ThinkInk_213_Mono_GDEY0213B74 display(EPD_DC, EPD_RESET, EPD_CS, SRAM_CS, EPD_BUSY, EPD_SPI);
    
---
## What is e-paper??

E-paper uses a completely different technology from LCD or OLED displays. Instead of pixels that light up, e-paper works using thousands of tiny microcapsules, each filled with black and white particles suspended in liquid. When an electric charge is applied, the black particles move to the top (making that spot look dark) or the white particles move to the top (making it look light) — similar to how real ink or paper reflects light, rather than emitting it.

**Why it stays visible with no power?**

When you unplug the board, it remains displaying the latest image. This is because the particles in each microcapsule physically stay in place when there is no electricity applied. The display only draws power on update, then can be powered off completely and remain displaying on it. 

## Which micro-controller should I use?

Adafruit has developed a microcontroller designed specifically to program e-paper panels, this is the Adafruit Feather RP2040 ThinkInk. It allows us to connect the e-paper directly to the board.
Note: You could use an Arduino or ESP32 board, but you will need an additional breakout


**Driver:** E-paper panels vary a lot between manufacturers. Each panel has its own timing sequence and voltage profile tuned to how quickly and cleanly that specific batch of ink particles move. That's why your need to select a DRIVER that is suitable to your e-paper. This will be part of your code. (Using the wrong one sends the panel instructions tuned for slightly different physical ink)


----
# TUTORIAL
----
## HARDWARE

- Adafruit Feather RP2040 ThinkInk Board

- 2.13" 250x122 Monochrome or Gray eInk / ePaper - Bare Display - SSD1680Z Chip

- USB to USB-C cable

----
## CODE AND INSTRUCTIONS

1. Start by setting up the ThinkInk board for Arduino IDE. Follow the instructions [here](https://learn.adafruit.com/adafruit-rp2040-feather-thinkink/arduino-ide-setup).

2. Test that the Arduino IDE has been able to stablish communication with the board. To do this, [load the Blink Sketch, as explained here](https://learn.adafruit.com/adafruit-rp2040-feather-thinkink/arduino-usage).

3. Install the following library : **Adafruit EPD by Adafruit**. If you need help installing the library, open the following link, scroll down and follow [this Arduino Library instructions](https://learn.adafruit.com/adafruit-rp2040-feather-thinkink/eink-example-2).

4. Upload [this code](https://github.com/kingston-hackSpace/All_Display_Screens_for_Arduino/blob/main/E-Paper_test.ino) to your board. The panel should display an animation.

----
## IMAGES

Our E-paper can display images, HOWEVER, since it's a monochrome panel (only pure black or white, no shades of gray), any image needs to be converted to a 1-bit black-and-white bitmap before it can be shown. Photos or color images need to go through a conversion step first, see below. 

**Converting images to 1-bit bitmaps**

1. 

----
## EXTRAS

Find the library package here: https://github.com/adafruit/Adafruit_EPD 
