# megaTempSleep
Firmware for the megaTemp project (ATmega328P digital thermometer) with power-saving via WDT &amp; System sleep
This repository containes several files:

megaTempSLeep.c is the code for the thermometer with the WDT & Sleep functionality.

doNothing.c is simplest-possible code used to measure the current drawn by the 328P MCU

OLEDtest.c is simple code to test the OLED with a few lines of display. 

Acknowledgeent and License: i2c.c, ic2.h, SSD1306.c and SSD1306.h are user-defined libraries to operate the OLED. These are open-source codes by Preston Sundar under the MIT license. That same licence covers all code herein. Contributed files located here:  
https://github.com/prestonsn/AVR-OLED-SSD1306-IIC-DRIVER
https://github.com/prestonsn/AtmegaXX-I2C-Library

