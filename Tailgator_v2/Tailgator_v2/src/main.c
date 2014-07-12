
/*
John Taylor
06.05.14
Tests the programmability of the atmega32A
Blinks 2 LEDS 
*/
#include <asf.h>
#include <avr/io.h>
#include <util/delay.h>
/*
Below this wall of text we define pre-processor statements that allow me to define what the registers
should look like in the LED_ON and LED_OFF etc. states. The compiler looks for 
anywhere in my program where I use these variables and replaces them with the hex
number that I associate them with.

For Example if the compiler sees I use LED1_ON it will replace it with 0x01
*/

/*
To control the output pins on the microprocessor, we must change the REGISTERS in software. A register is just a set of bits.
for example, the DDRA (data direction register A) register controls the direction of bits for the PORTA. 
Similarly, the PORTA register is where you either read (if DDRA is set to input) or write (if DDRA is set to output) 
the data on PORTA. You can find out which pins are associated with PORTA 
in the microprocessor data sheet. For our microprocessor the PORT A pins are pins 33-40.

Each Register is 8 bits, which is why we can control 8 pins (33-40) with port A. 
*/

/*
We will connect LED1 to A0 and LED2 to A1

when we want to set the data direction register we don't want to remember all of the bits, so we define these nice 
constants so that we don't have to type it every time and our code is more readable. Remeber that the convention with 
constants in moto programming languages is capital letters and underscore for spaces ex MY_VAR. Also with these particular
constants in C, we don't use an equals sign, instead we use a #define.

for example:
		 #define MY_VAR 1 
makes a constant that you can use anywhere in your program that is defined as the number 1
*/
#define A0_OUTPUT 0x01
#define A1_OUTPUT 0x02
/*
Examples:
A0_OUTPUT
In our architecture a 0 corresponds to input and 1 corresponds to output, We want to set A0 to an output so 
we can blink LEDS with it. As you can see below we make a constant that is 0x01; translated to binary this is an 8 bit number as follows.
The zeroth bit of this register represents the A0 direction.

									A0_OUTPUT = 0x01 = 0000 0001
									
To set the direction of A1, which will control LED2 we define a constant that will set the directon of A1

									A1_OUTPUT = 0x01 = 0000 0010
*/




//The LED on/off constants are similar to output direction constants. We will use these to set the appropriate registers
//when we want to turn LEDS on or off
#define LED1_ON 0x01
#define LEDS_OFF 0x00
#define LED2_ON 0x02


int main (void)
{
	board_init();
	//set DDRA to both of these constants we defined
	DDRA = A0_OUTPUT + A1_OUTPUT;
	
	//infinite loop
	for(;;)
	{
		//Here we just set port A based on our constants we defined earlier. 
		//It is much easier to read using constants this way, rather than setting raw hex values
		
		PORTA = LED1_ON;
		_delay_ms(500);
		
		PORTA  = LEDS_OFF;
		_delay_ms(200);
		
		PORTA = LED2_ON;
		_delay_ms(500);
		
		PORTA  = LEDS_OFF;
		_delay_ms(200);
	}
}
