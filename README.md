# megaTempSleep
Firmware for the megaTemp project (ATmega328P digital thermometer) with power-saving via WDT and System sleep

This repository containes several files:

megaTempSLeep.c is the code for the digital thermometer with microcontroller power savings via WDT & Sleep functionality. 

doNothing.c is simplest-possible code used to measure the current drawn by the 328P MCU

OLEDtest.c is simple code to test the OLED with a few lines of display. 

Acknowlegement and License: i2c.c, ic2.h, SSD1306.c and SSD1306.h are user-defined libraries to operate the SSD1306/OLED over the i2C interface. These are open-source codes provided by Preston Sundar, via github, under the MIT license. That same licence covers all code herein. Contributed files are located here:  
https://github.com/prestonsn/AVR-OLED-SSD1306-IIC-DRIVER
 and 
https://github.com/prestonsn/AtmegaXX-I2C-Library

