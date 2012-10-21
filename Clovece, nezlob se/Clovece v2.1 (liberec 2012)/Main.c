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

void run()
{
	uint8_t kostka_hod;
	inicializace();
	//nastav_rychlost();

	/*for(;;){
		aktualizuj_pozice();
		
	}*/
	
	while(true)
	{
		aktualizuj_pozice();
		if(buttons.isStart())
		{
			kostka_hod = kostka;
			if(CHECKPOLE());	//nìco je v poli
			{
				
			}
			else()	//nic není v poli
			{
				if(kostka_hod==6)
				{
					if(hodnoty_pole[][])	//je obsazeno
					{
						vyhod(8);
					}
					nasad();						
				}
			}	
		}
	}
}