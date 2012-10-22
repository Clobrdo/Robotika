/*
 * Pohyby.c
 *
 */
#include "bioloid_v2.1.h"
#include "pohyby.h"
#include <avr/delay.h>

/*  P??kazy knihovny:

	zakladni_pozice		()
	nastav_rychlost		()
	pozice				(c. pozice)
	cekej				()			//ceka dokud se motory hybou
	uchop				()
	povol				()
	poloz				()
	zvedni				()
	nasad_robot			()
	check_hraci_pole	()		//true dokud je neco v POLI ne v domeckach

*/

void run()
{
	uint8_t kostka_hod;
	inicializace();
	nastav_rychlost();	
	
	while(true)
	{
		aktualizuj_hraci_pole();
		if(buttons.isStart())
		{
			kostka_hod = kostka;
			if(check_hraci_pole())	//neco je v poli
			{				
			}
					
			else	//nic neni v poli
			{
				if(kostka_hod==6)
				{
					//if(hodnoty_pole[][])	//je obsazeno
					//{
					//	vyhod(8);
					//}
					nasad_robot();
				}
			}
		}
	}
}
