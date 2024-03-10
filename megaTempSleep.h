/* megaTempSleep.h 
All the #includes for megaTempSleep.c
Version     Author          Description
 *  1.0         D. McLaughlin   Initial release for ECE-304 3/8/24
 *  1.1         D. McLaughlib   Cleaned up for GitHub post for ECE-304 class
 **************************************************************/

// Standard AVR-GCC or WIN-AVR Library Includes
#include <avr/io.h>
#include <util/delay.h>
#include <avr/wdt.h>
#include <avr/sleep.h>

// These two includes are for the SSD & i2c library we're using for this project
#include "i2c.h"
#include "SSD1306.h"

// Prototypes for my own functions
void adc_init(void);
unsigned int get_adc(void);
void WDT_OFF(void);