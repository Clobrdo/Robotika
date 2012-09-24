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
	pøijeï			(è. pozice) 
	uchop			()
	polož			()
	
*/













void run()
{
	for (;;)
	{
		motor[1].position(400);
		_delay_ms(500);
		zakladni_pozice();
		_delay_ms(800);
		pc<<"ahoj"<<endl;
		//TODO: Program
	}
}