/*
 * Main.c
 * Hlavni zdrojovy kod pro Clovece, nezlob se
 * Author: Aleš Pernikáø, Jiøí Kyzlink
 */
#include "bioloid_v2.2.h"
#include "pohyby.h"
#include <avr/delay.h>

void run()
{
	pc<<"   _____  _                                                      _         _                 "<<endl;
	pc<<"  / ____|| |                                                    | |       | |                "<<endl;
	pc<<" | |     | |  ___ __   __  ___   ___  ___      _ __    ___  ____| |  ___  | |__    ___   ___ "<<endl;
	pc<<" | |     | | / _ \\ \ / / / _ \ / __|/ _ \    | '_ \  / _ \|_  /| | / _ \ | '_ \  / __| / _ \""<<endl;
	pc<<" | |____ | || (_) |\ V / |  __/| (__|  __/ _  | | | ||  __/ / / | || (_) || |_) | \__ \|  __/"<<endl;
	pc<<"  \_____||_| \___/  \_/   \___| \___|\___|( ) |_| |_| \___|/___||_| \___/ |_.__/  |___/ \___|"<<endl;
	pc<<"                                          |/                                                 "<<endl;
	
	pc<<"Zacinam program ..."<<endl;
	uint8_t curr_fig,naber_temp, pocet_hracu=1, chyba, pribylo;
	bool hra=true, blue_dom[2]{false, false}, nasad=false,zmena;	//true-cerveny, false-modry
	povol();
	pc<<"Pripojte robota, zvolte pocet hracu a stisknete Start ..."<<endl;
	while(!buttons.isStart())
	{
		if(buttons.isUp())
			pocet_hracu=1;		
		else if(buttons.isLeft())
			pocet_hracu=0;	
		else if(buttons.isDown())
		{
			aktualizuj_hraci_pole();
			for(int i=1;i<=40;i++)
			{
				pc<<"pozice "<<i<<": "<<pole_fig[i]<<endl;
			}
		}
	}
	pc<<"Pocet hracu: "<<pocet_hracu<<endl;
	nastav_torque();	
	inicializace();
	nastav_rychlost(1);
	pc<<"Nastavuji rychlost motoru ..."<<endl;
	zakladni_pozice();
	pc<<"Zakladni pozice ..."<<endl;
	cekej();
	aktualizuj_hraci_pole();
	pc<<"Aktualizuji hraci pole ..."<<endl;
	while(true)
	{	
		chyba=aktualizuj_hraci_pole();
		while(chyba)
		{	
			if(chyba==50)
			{
				pc<<"Prilis mnoho figurek v poli."<<endl;
				while(aktualizuj_hraci_pole()==50){_delay_ms(100);}	
			}				
			else if(chyba==51)
			{
				pc<<"Malo figurek v poli."<<endl;
				while(aktualizuj_hraci_pole()==51){_delay_ms(100);}
			}				
			else
			{
				pc<<"Nastala chyba na policku "<<chyba<<endl;
				while(aktualizuj_hraci_pole()==chyba){_delay_ms(100);}
			}				
			chyba=aktualizuj_hraci_pole();	
		}
		pc<<"--------------------------------------------------------"<<endl<<"Nove kolo ..."<<endl;
		for(int i=0;i<=3;i++)
		{
			pc<<"Pozice figurky "<<i<<" je "<<curr_pos[i]<<endl;
		}
		kostka_hod = kostka;
		led.manage(ledky[0][kostka_hod-1]);
		led.program(ledky[1][kostka_hod-1]);
		led.play(ledky[2][kostka_hod-1]);
		pc<<"Na kostce padla "<<kostka_hod<<endl;
		if((pole_fig[35]&&pole_fig[36])||(pole_fig[37]&&pole_fig[38]))	//nekdo vyhral, nova hra
		{
			if(pole_fig[35]&&pole_fig[36])
				pc<<"Cerveny vyhral."<<endl;
			else
				pc<<"Modry vyhral."<<endl;
			if(curr_pos[1]!=34)
				presun(curr_pos[1],34);
			curr_pos[1]=34;
			if(curr_pos[0]!=33)
				presun(curr_pos[0],33);
			curr_pos[0]=33;
			if(curr_pos[2]!=40)
				presun(curr_pos[2],40);
			curr_pos[2]=40;
			if(curr_pos[3]!=39)
				presun(curr_pos[3],39);
			curr_pos[3]=39;
			blue_dom[0]=false;
			blue_dom[1]=false;
		}
		if(hra)
		{
			pc<<"Hraje robot - cerveny ... "<<endl;
			hra=false;
			if(curr_pos[0]<=33)
				curr_fig=0;
			else
				curr_fig=1;
		}
		else
		{
			hra=true;
			if(pocet_hracu==0)
			{
				pc<<"Hraje robot - modry ... "<<endl;
				if(curr_pos[2]<=32||curr_pos[2]>=39)
					curr_fig=2;
				else
					curr_fig=3;
			}
			else
			{
				pc<<"Hraje clovek - modry ..."<<endl;
				zmena=true;
				aktualizuj_hraci_pole();
				while(zmena)
				{
					chyba=aktualizuj_hraci_pole();
					_delay_ms(300);
					for(int i=0;i<=3;i++)
					{
						if(!pole_fig[curr_pos[i]])
						{
							if(i<=1)
							{
								pc<<"Neplatny pohyb s figurkou robota."<<endl;
							}
							else
							{
								aktualizuj_hraci_pole();
								while(chyba==51)chyba=aktualizuj_hraci_pole();
								pc<<"Pohyb s figurkou cloveka. "<<endl;
								if((curr_pos[i]==39||curr_pos[i]==40)&&(kostka_hod==6))
								{
									curr_pos[i]=17;
									pc<<"Hrac nasadil na pozici 17. "<<endl;
									zmena=false;
									break;
								}
								pribylo=check_pribylo();
								if(pribylo==0)
								{
									pc<<"Zadna zmena"<<endl;
									if((kostka_hod!=6)&&(curr_pos[i]>=37))
									{
										zmena=false;
										break;
									}
								}									
								//pc<<"Pribyla figurka "<<i<<" na pozici "<<pribylo<<", byla na pozici "<<chyba<<endl;
								if((pribylo-kostka_hod)==(curr_pos[i])&&(pribylo<=32))
								{
									curr_pos[i]+=kostka_hod;
									pc<<"Presun figurky "<<i<<" na pozici "<<curr_pos[i]<<endl;
									zmena=false;
									break;
								}
								else if((pribylo+32-kostka_hod)==curr_pos[i])
								{
									curr_pos[i]=curr_pos[i]+kostka_hod-32;
									blue_dom[i-2]=true;
									pc<<"Hrac presunul "<<i<<" na pozici "<<curr_pos[i]<<endl;
									zmena=false;
									break;
								}
								else if((pribylo==37||pribylo==38) && blue_dom[i-2] && (curr_pos[i]+kostka_hod>16))
								{
									curr_pos[i]=pribylo;
									pc<<"Hrac se presunul do domecku."<<endl;
									zmena=false;
									break;
								}
								else if((pribylo==33||pribylo==34)&&(curr_pos[i]+kostka_hod)==curr_pos[0])
								{
									pc<<"Hrac vyhodil figurku 0 z policka "<<curr_pos[0]<<endl;
									curr_pos[i]=curr_pos[0];
									curr_pos[0]=pribylo;
									zmena=false;
									break;
								}
								else if((pribylo==33||pribylo==34)&&(curr_pos[i]+kostka_hod)==curr_pos[1])
								{
									pc<<"Hrac vyhodil figurku 1 z policka "<<curr_pos[0]<<endl;
									curr_pos[i]=curr_pos[1];
									curr_pos[1]=pribylo;
									zmena=false;
									break;
								}
								else
								{
									pc<<"Chybny tah."<<endl;
									if((curr_pos[i]>=37&&curr_pos[i]<=40)&&kostka_hod!=6)
										pc<<"Touto figurkou neni mozno tahnout."<<endl;
									else if((curr_pos[i]==39||curr_pos[i]==40)&&kostka_hod==6)
										pc<<"Je mozno nasadit na pozici 17."<<endl;
									else if(curr_pos[i]+kostka_hod>32)
										pc<<"Posunte se na pozici "<<curr_pos[i]+kostka_hod-32<<endl;
									else if ((curr_pos[i]+kostka_hod>16)&&(blue_dom[i-2]))
										pc<<"Posunte se do domecku."<<endl;
									else
										pc<<"Posunte se na pozici "<<curr_pos[i]+kostka_hod<<endl;
									_delay_ms(1000);
								}
							}
						}						
					}
				}
				continue;
			}
		}
		if(curr_pos[curr_fig]<=32)
		{
			naber_temp=curr_pos[curr_fig];
			curr_pos[curr_fig]+=kostka_hod;
			if(curr_fig<=1)
			{
				if((curr_pos[curr_fig]>32)&&(curr_pos[curr_fig]<=34)&&(!(pole_fig[35])))
				{
					curr_pos[curr_fig]=35;
				}
				else if((curr_pos[curr_fig]>32)&&(curr_pos[curr_fig]<=34)&&(!(pole_fig[36])))
				{
					curr_pos[curr_fig]=36;
				}
				else if((curr_pos[curr_fig]>34)&&((!(pole_fig[36])||!pole_fig[35])))
				{
					pc<<"Nemuzu se dostat do domecku."<<endl;
					curr_pos[curr_fig]-=kostka_hod;
					continue;
				}
			}
			else if(curr_fig>=2)
			{
				if(curr_pos[curr_fig]>32)
				{
					curr_pos[curr_fig]-=32;
					blue_dom[curr_fig-2]=true;
				}
				if(curr_pos[curr_fig]>16 && blue_dom[curr_fig-2])
				{
					blue_dom[curr_fig-2]=false;
					if(!pole_fig[38])
					{
						curr_pos[curr_fig]=38;
					}
					else
					{
						curr_pos[curr_fig]=37;
					}
				}
			}
			if(pole_fig[curr_pos[curr_fig]])
			{
				pc<<"Vyhazuju ..."<<endl;
				vyhod(curr_pos[curr_fig],curr_fig);
			}
			presun(naber_temp,curr_pos[curr_fig]);
		}
		else if(curr_pos[curr_fig]>=33&&curr_pos[curr_fig]<=34)
		{
			if(kostka_hod==6)
			{
				if(pole_fig[1])
				{
					pc<<"Vyhazuju ..."<<endl;
					vyhod(1,curr_fig);
				}
				naber_temp=curr_pos[curr_fig];
				curr_pos[curr_fig]=1;
				presun(naber_temp, curr_pos[curr_fig]);
			}
		}
		else if(curr_pos[curr_fig]>=39&&curr_pos[curr_fig<=40])
		{
			if(kostka_hod==6)
			{
				if(pole_fig[16])
				vyhod(16,curr_fig);
				naber_temp=curr_pos[curr_fig];
				curr_pos[curr_fig]=17;
				presun(naber_temp, curr_pos[curr_fig]);
			}
		}
		pc<<"Figurka "<<curr_fig<<" se posunula na pozici "<<curr_pos[curr_fig]<<endl;
	}
}
