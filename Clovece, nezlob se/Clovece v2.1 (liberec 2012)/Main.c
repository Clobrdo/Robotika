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
				if(!domecek[0])
				{
					pozice(ak_pozice[0]);
					ak_pozice[0] += kostka_hod;
					zavri();
					pozice(ak_pozice[0]);
					otevri();
				}
				else if(!domecek[1])
				{
					pozice(ak_pozice[1]);
					ak_pozice[1] += kostka_hod;
					zavri();
					pozice(ak_pozice[1]);
					otevri();
				}						
			}
					
			else	//nic neni v poli
			{
				if(kostka_hod==6)
				{
					if(CHECKPOLICKO(8))	//je obsazeno
					{
						pozice(8);
						otevri();
						if(domecek[8])
						{
							//pozice();	//nevim jaka je to pozice
						}
						else
						{
							//pozice();
						}
						zavri();
					}
					nasad_robot();
				}
			}
		}
	}
}
