//Timing delay for the cooking 
//Hamburger takes ~ 4 mins to cook on each side

#define F_CPU 1000000UL  // 1 MHz
//#define F_CPU 14.7456E6
#include <util/delay.h>
#include "timer.h"

void time_Cook() {
	int i;
	for(i = 0, i < 2400 , i++)	 //delay function for .1 s x 2400 = 	
		delay_ms(100);		 //2400 / 60 = 4 mins
}
