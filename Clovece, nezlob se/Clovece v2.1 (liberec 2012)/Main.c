/*
 * Pohyby.c
 *
 * Created: 22.9.2012 20:11:26
 *  Author: jirka1
 */ 

#include "bioloid_v2.1.h"
#include "pohyby.h"
#include <avr/delay.h>

/*  Pøíkazy knihovny:

	zakladni_pozice	()
	nastav_rychlost	()
	pozice			(è. pozice)
	*uchop			()
	*polož			()
	
*/

void run()
{
	//nastav_rychlost();
	for (;;)
	{
		zakladni_pozice();
		motor[4].position(560);
		_delay_ms(5000);
		pc<<"ahoj"<<endl;
		//TODO: Program
	}
}