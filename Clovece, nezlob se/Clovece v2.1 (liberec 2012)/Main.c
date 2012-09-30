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
	cekej			()			//ceka dokud se motory hybou
	*uchop			()
	*polož			()
	
*/

bool kontrola_figurek()
{
						//kontrolovací algoritmus
	bool kontrola = true;	//true nebo false, podle toho, jestli jsou figurky na místì
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