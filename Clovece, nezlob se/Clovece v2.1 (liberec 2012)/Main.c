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
	cekej			()			//ceka dokud se motory hybou
	*uchop			()
	*polo�			()
	
*/

bool kontrola_figurek()
{
						//kontrolovac� algoritmus
	bool kontrola = true;	//true nebo false, podle toho, jestli jsou figurky na m�st�
	return kontrola;
}

void run()
{
	inicializace();
	//nastav_rychlost();

	/*for(;;){
		for (i2=0; i2!=32; i2++)
		{
			pozice(i2);
			cekej();
		}
		
	}*/
	
	while(true)
	{
		if(buttons.isStart())
		{
			int posun_h = kostka;
			pc<<posun_h<<endl;
		}
		
	
	
	//TODO: Program
	}
}