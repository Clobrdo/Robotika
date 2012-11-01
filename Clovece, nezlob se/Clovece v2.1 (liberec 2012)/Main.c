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
	otevri				()
	zavri				()
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
				otevri();
				if(!DOMECEK(0))
				{
					pozice(curr_pos[0][0]);
					curr_pos[0][0] += kostka_hod;
					zavri();
					pozice(curr_pos[0][0]);
					cekej();
					otevri();
				}
				else if(!DOMECEK(1))
				{
					pozice(curr_pos[0][1]);
					curr_pos[0][1] += kostka_hod;
					zavri();
					pozice(curr_pos[0][1]);
					cekej();
					otevri();
				}						
			}
					
			else	//nic neni v poli
			{
				if(kostka_hod==6)
				{
					if(CHECKPOLICKO(8))	//je obsazeno
					{
						otevri();
						pozice(8);
						cekej();
						zavri();
						pozice(1);
						cekej();
						otevri();
						if(DOMECEK(8))
						{
							pozice(8);		
						}
						else
						{
							pozice(7);
						}
						cekej();
						zavri();
						pozice(8);
						cekej();
						otevri();
					}
					//nasad_robot();
				}
			}
		}
	}
}
