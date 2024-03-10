/***************************************************************************
 sleeper.c
 * Code to test ATmega328P power saving by Watchdog Timer (WDT)
 * This demo waits 3 seconds then powers down for 8 seconds
 * via SlEEP_MODE_POWER_DOWN with system reset on WDT timeout.
 *  Version     Author          Description
 *  1.0         D. McLaughlin   Initial release for ECE-304 3/8/24
 *  1.1         D. McLaughlib   Cleaned up for GitHub post for ECE-304 class
 ****************************************************************************/

#include <avr/io.h>
#include <util/delay.h>
#include <avr/wdt.h>
#include <avr/sleep.h>

// Disable WTD and clear reset flag immediately at startup
void WDT_OFF()
{
	MCUSR &= ~(1 << WDRF);
	WDTCSR = (1 << WDCE) | (1 << WDE);
	WDTCSR = 0x00;
}

int main(void)
{
	WDT_OFF(); // Disable WDT & clear reset flag @ startup

	_delay_ms(3000);		

	wdt_enable(WDTO_8S); // Start the WDT; reset after 8 seconds
	
	set_sleep_mode(SLEEP_MODE_PWR_DOWN);
	sleep_mode();		// Put the system to sleep
	while (1)
		;
}