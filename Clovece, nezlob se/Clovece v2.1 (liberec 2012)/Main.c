/*
 * Pohyby.c
 *
 */
#include "bioloid_v2.2.h"
#include "pohyby.h"
#include <avr/delay.h>

/*  Prikazy knihovny:

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
	povol();
while(!buttons.isStart())
{}
	nastav_torque();
	uint8_t kostka_hod;
			pc<<"jedu"<<endl;
	inicializace();
			pc<<"kostka nastavena"<<endl;
	nastav_rychlost();	
			pc<<"rychlost nastavena"<<endl;
	zakladni_pozice();
			pc<<"zakladni pozice"<<endl;
	cekej();
			pc<<"cekej ..."<<endl;
	pc<<aktualizuj_hraci_pole()<<endl;
			pc<<"aktualizuj pole"<<endl;
	while(1)
	{
		kostka_hod = kostka;
		pc<<kostka_hod+4<<endl;
		naber(kostka_hod+4);
		kostka_hod = kostka;
		pc<<kostka_hod+4<<endl;
		poloz(kostka_hod+4);
	}		
	
	while(true)
	{
		
		//aktualizuj_hraci_pole();
		if(buttons.isStart())
		{
			pc<<"start"<<endl;
			kostka_hod = kostka;
			pc<<kostka_hod<<endl;
			if(check_hraci_pole())	//neco je v poli
			{
				otevri();
				if(!DOMECEK(0))
				{
					PoziceM1(curr_pos[0]);
					curr_pos[0] += kostka_hod;
					zavri();
					PoziceM1(curr_pos[0]);
					//cekej();
					otevri();
				}
				else if(!DOMECEK(1))
				{
					PoziceM1(curr_pos[1]);
					curr_pos[1] += kostka_hod;
					zavri();
					PoziceM1(curr_pos[1]);
					//cekej();
					otevri();
				}						
			}
					
			else	//nic neni v poli
			{
				pc<<"nic neni v poli"<<endl;
				if(kostka_hod==6)
				{
					pc<<"kostka je 6"<<endl;
					//if(CHECKPOLICKO(8))	//je obsazeno
					//{
						
						otevri();
						_delay_ms(1000);
						//cekej();
						naber(1);
						zavri();
						cekej();
						zakladni_pozice();
						cekej();
						naber(10);
						//cekej();
						otevri();
						cekej();
						/*if(DOMECEK(8))
						{
							PoziceM1(8);		
						}
						else
						{
							PoziceM1(7);
						}*/
						zavri();
						PoziceM1(8);
						//cekej();
						otevri();
					//}
					//nasad_robot();
				}
			}
		}
	}
}
