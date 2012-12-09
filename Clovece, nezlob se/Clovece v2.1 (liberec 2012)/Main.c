/*
 * Main.c
 */
#include "bioloid_v2.2.h"
#include "pohyby.h"
#include <avr/delay.h>

void run()
{
	pc<<"Zacinam program ..."<<endl;
	uint8_t curr_fig,naber_temp, pocet_hracu=1, chyba, zmena=0;
	bool hra=true, blue_dom=false, nasad=false;	//true-cerveny, false-modry
	povol();
	pc<<"Pripojte robota, zvolte pocet hracu a stisknete Start ..."<<endl;
	
	while(!buttons.isStart())
	{
		if(buttons.isUp())
		{
			pocet_hracu=1;
		}		
		else if(buttons.isLeft())
		{
			pocet_hracu=0;
		}		
		else if(buttons.isDown())
		{
			aktualizuj_hraci_pole();
			for(int i=1;i<=40;i++)
			{
				pc<<"pozice "<<i<<": "<<check_pole(i)<<endl;
			}
		}
		while(buttons.isDown()){};
	}
	pc<<"Pocet hracu: "<<pocet_hracu<<endl;
	nastav_torque();	
	inicializace();
	pc<<"Inicializace ..."<<endl;
	nastav_rychlost(1);
	pc<<"Nastavuji rychlost ..."<<endl;
	zakladni_pozice();
	pc<<"Zakladni pozice ..."<<endl;
	cekej();
	
	aktualizuj_hraci_pole();
	pc<<"Aktualizuji hraci pole ..."<<endl;
/*
pc<<"   _____  _                                                      _         _                 "<<endl;
pc<<"  / ____|| |                                                    | |       | |                "<<endl;
pc<<" | |     | |  ___ __   __  ___   ___  ___      _ __    ___  ____| |  ___  | |__    ___   ___ "<<endl;
pc<<" | |     | | / _ \\ \ / / / _ \ / __|/ _ \    | '_ \  / _ \|_  /| | / _ \ | '_ \  / __| / _ \""<<endl;
pc<<" | |____ | || (_) |\ V / |  __/| (__|  __/ _  | | | ||  __/ / / | || (_) || |_) | \__ \|  __/"<<endl;
pc<<"  \_____||_| \___/  \_/   \___| \___|\___|( ) |_| |_| \___|/___||_| \___/ |_.__/  |___/ \___|"<<endl;
pc<<"                                          |/                                                 "<<endl;*/
	/*
	while(true)
	{
		
		
	}	
	
	*/
	while(true)
	{	
		for(int i=0;i<=3;i++)
		{
			pc<<"pozice figurky "<<i<<" je "<<curr_pos[i]<<endl;
		}
		//test_pozice();
		chyba=aktualizuj_hraci_pole();
		if(chyba)
		{
			pc<<"Nastala chyba na policku "<<chyba<<endl;
			_delay_ms(1000);
			chyba=aktualizuj_hraci_pole();	
		}
		//pc<<"Figurky jsou v poradku"<<endl;
		pc<<"--------------------------------------------------------"<<endl<<"Nova hra ..."<<endl;
		/*if (p_hra)
		{
			kostka_hod=6; 
			p_hra=false;
		}
		else
		{
			kostka_hod=1;
		}
		*/
	/*	pc<<"hraci pole hodnoty: "<<endl;
		for(int i=1;i<=40;i++)
		{
			pc<<"pozice "<<i<<": "<<check_pole(i)<<endl;
		}*/
		kostka_hod = kostka;
		led.manage(ledky[0][kostka_hod-1]);
		led.program(ledky[1][kostka_hod-1]);
		led.play(ledky[2][kostka_hod-1]);
		pc<<"Na kostce padla "<<kostka_hod<<endl;
		
		if((check_pole(35)&&check_pole(36))||(check_pole(37)&&check_pole(38)))	//nekdo vyhral, nova hra
		{
			pc<<"Konec hry ..."<<endl;
			for(int i=0;i!=4;i++)
			{
				naber_temp=curr_pos[i];
				//naber(curr_pos[i]);
				{
					switch(i)
					{
						case 0:curr_pos[i]=33;break;
						case 1:curr_pos[1]=34;break;
						case 2:curr_pos[i]=40;break;
						case 3:curr_pos[i]=39;break;
					}
				}
				presun(naber_temp, curr_pos[i]);
			}
		}
		if(hra)
		{
			pc<<"Hraje robot - cerveny ... "<<endl;
			hra=false;
			if(curr_pos[0]<=33)
			{
				curr_fig=0;
			}
			else
			{
				curr_fig=1;
			}
		}
		else
		{
			hra=true;
			if(pocet_hracu==0)
			{
				pc<<"Hraje robot - modry ... "<<endl;
				if(curr_pos[2]<=32||curr_pos[2]>=39)
				{
					curr_fig=2;
				}
				else
				{
					curr_fig=3;
				}
			}
			else
			{
				for(int i=0;i<=40;i++)
				{
					pole_fig_old[i]=pole_fig[i];
					//pc<<"pole old "<<i<<" je "<<pole_fig_old[i]<<endl;
				}
				pc<<"Hraje clovek - modry ..."<<endl;
				
				while(!buttons.isStart()){}
				while(buttons.isStart()){}
				zmena=0;
				aktualizuj_hraci_pole();
				for(int i=0;i<=40;i++)
				{
					
					//pc<<"pole aktual "<<i<<" je "<<pole_fig[i]<<endl;
					if(pole_fig_old[i]!=pole_fig[i])
					{
						if(i<14||(i>14&&i<33))
						{
							if(zmena!=0)
							{
								if(i-zmena==kostka_hod)
								{
									pc<<"Spravny tah "<<endl;
									if(curr_pos[2]==zmena+3)
									{
										curr_pos[2]+=kostka_hod;
									}									
									else if(curr_pos[3]==zmena+3)
									{
										curr_pos[3]+=kostka_hod;
									}
								}
								else
								{
									pc<<"Spatny tah "<<endl;
								}
							}
							else
							{
								zmena=i;
							}
							
							pc<<"hrac se posunul"<<endl;
						}
						else if(i==14)
						{
							zmena=i;
							pc<<"hrac mozna nasadil "<<endl;
							if(kostka_hod==6)
							{
								nasad=true;
							}
						}						
				
						else if(i==39)
						{
							pc<<"hrac nasadil"<<endl;
							if(nasad)
							{
								curr_pos[3]=17;
							}
						}
						else if(i==40)
						{
							pc<<"hrac nasadil"<<endl;
							if(nasad)
							{
								curr_pos[2]=17;
							}
						}
						pc<<"nastala zmena na pozici "<<i<<endl;
					}
					
				}
				continue;
			}
		}
		pc<<"Figurka "<<curr_fig<<" je na pozici "<<curr_pos[curr_fig]<<endl;
		if(curr_pos[curr_fig]<=32)
		{
			if(check_pole(curr_pos[curr_fig]+kostka_hod))
			{
				pc<<"Vyhazuju ..."<<endl;
				for(int i=0;i!=5;i++)
				{
					if(curr_pos[i]==curr_pos[curr_fig]+kostka_hod)
					{
						switch(i)
						{
							case 0:curr_pos[0]=33;break;
							case 1:curr_pos[1]=34;break;
							case 2:curr_pos[2]=39;break;
							case 3:curr_pos[3]=40;break;
						}
					}
				}
				vyhod(curr_pos[curr_fig]+kostka_hod,curr_fig);
			}
			naber_temp=curr_pos[curr_fig];
			//naber(curr_pos[curr_fig]);
			curr_pos[curr_fig]+=kostka_hod;
			if(curr_fig<=1)
			{
				if((curr_pos[curr_fig]>32)&&(!(check_pole(35))))
				{
					curr_pos[curr_fig]=35;
				}
				else if((curr_pos[curr_fig]>32)&&(!(check_pole(36))))
				{
					curr_pos[curr_fig]=36;
				}
			}
			else if(curr_fig>=2)
			{
				if(curr_pos[curr_fig]>32)
				{
					curr_pos[curr_fig]-=32;
					blue_dom=true;
				}
				if(curr_pos[curr_fig]>16 && blue_dom)
				{
					blue_dom=false;
					if(!check_pole(37))
					{
						curr_pos[curr_fig]=37;
					}
					else
					{
						curr_pos[curr_fig]=38;
					}
				}
			}
			presun(naber_temp,curr_pos[curr_fig]);
			
		}
		else if(curr_pos[curr_fig]>=33&&curr_pos[curr_fig]<=34)
		{
			if(kostka_hod==6)
			{
				if(check_pole(1))
				vyhod(1,curr_fig);
				naber_temp=curr_pos[curr_fig];
				//naber(curr_pos[curr_fig]);
				curr_pos[curr_fig]=1;
				presun(naber_temp, curr_pos[curr_fig]);
			}
		}
		else if(curr_pos[curr_fig]>=39&&curr_pos[curr_fig<=40])
		{
			if(kostka_hod==6)
			{
				if(check_pole(16))
				vyhod(16,curr_fig);
				naber_temp=curr_pos[curr_fig];
				//naber(curr_pos[curr_fig]);
				curr_pos[curr_fig]=17;
				presun(naber_temp, curr_pos[curr_fig]);
			}
		}
		pc<<"Figurka "<<curr_fig<<" se posunula na pozici "<<curr_pos[curr_fig]<<endl;
	}
}