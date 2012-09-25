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
int kostka()
{
	int kostka_h;
				//Dušanùv algoritmus na náhodnost kostky
	return kostka_h;	
}
bool kontrola_figurek()
{
						//kontrolovací algoritmus
	bool kontrola = true;	//true nebo false, podle toho, jestli jsou figurky na místì
	return kontrola;
}
void run()
{
	zakladni_pozice();
	motor[4].position(560);
	nastav_rychlost();
	while(true)
	{
		if(buttons.isStart())
		{
			int posun_h = kostka();
		}
		_delay_ms(5000);
		pc<<"ahoj"<<endl;
		//TODO: Program
	}
}