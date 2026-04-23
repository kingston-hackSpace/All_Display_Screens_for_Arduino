# Seeed SSD1306 OLED displays

----
### DESCRIPTION

OLEDs we have in hackSpace are small displays; they are also known as monochrome displays, they are only about 1” diagonal, but very readable due to the high contrast. This display is made of 128x64 individual white OLED pixels, each one is turned on or off by the micro-controller. Because the display makes its own light, no backlight is required, allowing better energy saving. Briefly saying an OLED display is just better and modified version of and LCD display.

----
### SPECIFICATIONS

- Resolution: 128 x 64

- Interface: I2C

- Supply Voltage: 3.3/5V

- Display Colour : White

----
### WIRING
The OLED screen communicates via I2C protocol. You need two pins on the arduino UNO, two for data (SDA SCL), two for power(VCC GND). On an arduino UNO, the SDA port is A4 and the SCL port is A5.

See [reference image here](https://github.com/kingston-hackSpace/All_Display_Screens_for_Arduino/blob/main/OLED_bb.png)

----

 ### INSTALLING THE DISPLAY LIBRARY
 
- In the Arduino IDE go to **Sketch -> Include Libraries -> Manage libraries...**

- Search for **Adafruit_SSD1306 by Adafruit** and choose to install the library. (Additionally, you can find the library at Adafruit's repository [here](https://github.com/adafruit/Adafruit_SSD1306))

----

 ### CODE AND INSTRUCTIONS

A list of all the available methods for the OLED Screen can be found here...

https://www.instructables.com/Arduino-and-the-SSD1306-OLED-I2C-128x64-Display/

*Note:* The highest frame rate on an arduino UNO on full performance mode is around 7 fps.
