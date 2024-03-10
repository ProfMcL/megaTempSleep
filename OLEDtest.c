/******************************************************************
 * OLEDtest.c Firmware for simple tests of the  SSD1306 OLED display.
 * All we do in this code is write a few lines to the OLED display. 
 * Note we're using the i2c and SSD1306 libraries to operate the OLED.
 * 
 *      Version     Author          Description
 *      1.0         D. McLaughlin   Initial release for ECE-304 3/8/24
 *      1.1         D. McLaughlib   Cleaned up for GitHub post for ECE-304 class
 **************************************************************/

#include <avr/io.h>
#include "i2c.h"
#include "SSD1306.h"

int main(void)
{
    OLED_Init();
    OLED_GoToLine(1);
    OLED_DisplayString("98.6 F");
    // OLED_GoToLine(3);
    // OLED_DisplayString("98.6 F");
    OLED_GoToLine(5);
    OLED_DisplayString("Too Hot!");

   while (1);
    return 0;
}
