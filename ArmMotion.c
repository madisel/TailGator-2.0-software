/*
 * GccApplication1.c
 *
 * Created: 2/20/2014 6:16:12 PM
 *  Author: taviog
 */ 


#include <avr/io.h>
#include "ArmMotion.h"

void move_up()
{
	while(ADC1 <= 1000)
	{
		PORTB = '01';
	}
	PORTB = '00';
}

void move_down()
{
	while(500 <= ADC1 && ADC1 <= 524)
	{
		PORTB = '10';
	}
	PORTB = '00';
}