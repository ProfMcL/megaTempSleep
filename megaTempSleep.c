/******************************************************************
 * megaTemp.c Firmware for a digital thermometer based on ATmega328P,
 * TMP-36 sensor and SSD1306 OLED display. Uses watchdog timer (WDT) to sleep
 * system in between temp readings to conserve battery power. Displays
 * Temp in F and C. Note that I commented
 * out line 158 oledSendCommand(SSD1306_DISPLAY_OFF) to keep the display
 * on between temp measurements
 
 *  Version     Author          Description
 *  1.0         D. McLaughlin   Initial release for ECE-304 3/8/24
 *  1.1         D. McLaughlib   Cleaned up for GitHub post for ECE-304 class
 **************************************************************/

#include "megaTempSleep.h"
#define NUMSAMPLES 25 // #ADC Samples to average
#define VREF 1.1      // ADC reference voltage
#define MAXTEMP 80    // Too-Hot indication  at this temp (Deg F)

int main(void)
{
    WDT_OFF(); // Make sure the WDT is off at startup
    float tempC, tempF, analogVoltage;
    unsigned char too_hot;
    unsigned int digitalValue;
    unsigned long int totalValue, tempCinteger, tempFinteger;

    adc_init();
    OLED_Init(); // *** I deleted Display off in this function **

    // Acquire & average NUMSAMPLES temp measurements
    totalValue = 0;
    for (int i = 0; i < NUMSAMPLES; i++)
        totalValue += get_adc(); // Get a sample from temp sensor
    digitalValue = totalValue / NUMSAMPLES;

    // Convert to temp & analog voltage in mV, mult by 10
    tempC = digitalValue * 1.0 * VREF / 10.24 - 50.;
    tempF = tempC * 9. / 5. + 32.;
    analogVoltage = digitalValue * 1.0 * VREF / 1024;
    analogVoltage = analogVoltage * 1000;
    too_hot = (tempF > MAXTEMP);
    tempCinteger = tempC * 10;
    tempFinteger = tempF * 10;

    OLED_GoToLine(1);
    OLED_DisplayNumber(10, tempFinteger/10, 2);
    OLED_DisplayString(".");
    OLED_DisplayNumber(10, tempFinteger % 10, 1);
    OLED_DisplayString(" F");
    OLED_GoToLine(3);
    OLED_DisplayNumber(10, tempCinteger / 10, 2);
    OLED_DisplayString(".");
    OLED_DisplayNumber(10, tempCinteger % 10, 1);
    OLED_DisplayString(" C");

    if (too_hot)
    {
        OLED_GoToLine(5);
        OLED_DisplayString("Too Hot!");
    }
    else
    {
        OLED_GoToLine(5);
        OLED_DisplayString("        ");
    }

    wdt_enable(WDTO_8S);
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    sleep_mode();
    while (1)
        ;

    return 0;
}

// Initialize ADC peripheral
void adc_init(void)
{
    DDRC = 0x00;  // Make all ADC pins inputs
    ADMUX = 0xC2; // Select ADC2; Vref=1.1
    if (F_CPU > 1000000)
        ADCSRA = 0x87; // Enable ADC; divide by 128 for 16 MHz clock
    else
        ADCSRA = 0x83; // Enable ADC; divide by 8 for 1 MHZ clock
}

// Read ADC value
unsigned int get_adc()
{
    ADCSRA |= (1 << ADSC); // Start ADC conversion
    while ((ADCSRA & (1 << ADIF)) == 0)
        ;                      // Wait till ADC finishes
    ADCSRA |= (1 << ADIF);     // Clear ADIF flag
    return ADCL | (ADCH << 8); // Read ADCL first !
}

// Disable WTD and clear reset flag immediately at startup
void WDT_OFF()
{
    MCUSR &= ~(1 << WDRF);
    WDTCSR = (1 << WDCE) | (1 << WDE);
    WDTCSR = 0x00;
}