/*
 * Pohyby.c
 *
 * Created: 22.9.2012 20:11:26
 *  Author: jirka1
 */ 

#include "bioloid_v2.1.h"
#include "pohyby.h"
#include <avr/delay.h>

/*  P��kazy knihovny:

	zakladni_pozice	()
	nastav_rychlost	()
	pozice			(�. pozice)
	*uchop			()
	*polo�			()
	
*/
int kostka()
{
	int kostka_h;
				//Du�an�v algoritmus na n�hodnost kostky
	return kostka_h;	
}
bool kontrola_figurek()
{
						//kontrolovac� algoritmus
	bool kontrola = true;	//true nebo false, podle toho, jestli jsou figurky na m�st�
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