
/*
John Taylor
06.05.14
Tests the programmability of the atmega32A
blinks a high-true LED  on pin A0
*/
#include <asf.h>
#include <avr/io.h>
#include <util/delay.h>
/*
define pre-processor statements that allow me to define what the registers
should look like in the LED_ON and LED_OFF etc. states
*/
#define LED_ON 0x01
#define LED_OFF 0x00
#define A0_OUTPUT 0x01

int main (void)
{
	board_init();
	DDRA = A0_OUTPUT;
	
	//infinite loop
	for(;;)
	{
		PORTA = LED_ON;
		_delay_ms(50);
		PORTA  = LED_OFF;
		_delay_ms(50);
	}
}
