/*
 * Main.c
 */
#include "bioloid_v2.2.h"
#include "pohyby.h"
#include <avr/delay.h>

/*  Prikazy knihovny:

	zakladni_pozice		()
	nastav_rychlost		()
	cekej				()			//ceka dokud se motory hybou
	naber				()
	poloz				()
	vyhod				()
	check_hraci_pole	()		//true dokud je neco v POLI ne v domeckach

*/

void run()
{
	pc<<"Zacinam program ..."<<endl;
	uint8_t curr_fig,naber_temp;
	bool hra=true, blue_dom=false;	//true-cerveny, false-modry
	povol();
	pc<<"Pripojte robota a stisknete Start ..."<<endl;
	while(!buttons.isStart())
	{}
	nastav_torque();	
	inicializace();
	pc<<"Inicializace ..."<<endl;
	nastav_rychlost(1);
	pc<<"Nastavuji rychlost ..."<<endl;
	zakladni_pozice();
	pc<<"Zakladni pozice ..."<<endl;
	cekej();
/*
pc<<"   _____  _                                                      _         _                 "<<endl;
pc<<"  / ____|| |                                                    | |       | |                "<<endl;
pc<<" | |     | |  ___ __   __  ___   ___  ___      _ __    ___  ____| |  ___  | |__    ___   ___ "<<endl;
pc<<" | |     | | / _ \\ \ / / / _ \ / __|/ _ \    | '_ \  / _ \|_  /| | / _ \ | '_ \  / __| / _ \""<<endl;
pc<<" | |____ | || (_) |\ V / |  __/| (__|  __/ _  | | | ||  __/ / / | || (_) || |_) | \__ \|  __/"<<endl;
pc<<"  \_____||_| \___/  \_/   \___| \___|\___|( ) |_| |_| \___|/___||_| \___/ |_.__/  |___/ \___|"<<endl;
pc<<"                                          |/                                                 "<<endl;*/
	
	/*while(true)
	{
		
		if(buttons.isDown())
		{
			aktualizuj_hraci_pole();
		}
		while(buttons.isDown()){};
	}	*/
	//}
	/*while(1)
	{
		if(buttons.isStart())
		{
			while(buttons.isStart())
			{
			}
				for(i=0; i!=pocet_motoru; i++)
				{
					motor[i+1].speed(1023);
				}
			
			//pohyb_na_bod2(100,100,100);
			
			for (;;)
			{
				//pohyb_na_bod2(50,50,50);
				for (int a=0;a!=360;a++)
				{
					pohyb_na_bod2(150,0,120,a);
					//pc<<a<<endl;
					_delay_ms(10);
				}
				for (int a=360;a!=0;a--)
				{
					pohyb_na_bod2(150,0,120,a);
					//pc<<a<<endl;
					_delay_ms(10);
				}
			
			}
			
			test_pozice();
			kostka_hod = kostka;
			pc<<kostka_hod;
			naber(curr_pos[0]);
			curr_pos[0]+=kostka_hod;
			poloz(curr_pos[0]);
		}
	}		
	*/
	while(true)
	{	
		//test_pozice();
		//while(!buttons.isStart()){}
		//while(buttons.isStart()){}
		aktualizuj_hraci_pole();
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
		pc<<"hraci pole hodnoty: "<<endl;
		for(int i=1;i<=40;i++)
		{
			pc<<"pozice "<<i<<": "<<pole_fig[i]<<endl;
		}
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
			pc<<"Hraje clovek - modry ... "<<endl;
			/*
			aktualizuj_hraci_pole();
			*/
			if(curr_pos[2]<=32||curr_pos[2]>=39)
			{
				curr_fig=2;
			}
			else
			{
				curr_fig=3;
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
				if((curr_pos[curr_fig]>32)&&(!(DOMECEK(3))))
				{
					curr_pos[curr_fig]=35;
				}
				else if((curr_pos[curr_fig]>32)&&(!(DOMECEK(4))))
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
		
	/*	if(!(DOMECEK(0)&&DOMECEK(1)))	//neco je v poli
		{
			pc<<"neco je v poli"<<endl;
			if(!DOMECEK(0))
			{
				curr_fig=0;
			}
			else if(!DOMECEK(1))
			{
				curr_fig=1;
			}
			if(CHECKPOLICKO(curr_pos[curr_fig]+kostka_hod))	//obsazeno
			{
				vyhod(curr_pos[curr_fig]+kostka_hod);
			}
			naber(curr_pos[curr_fig]);
			curr_pos[curr_fig] += kostka_hod;
			if((curr_pos[curr_fig]>32)&&(!(DOMECEK(3))))
			{
				curr_pos[curr_fig]=35;
			}
			else if((curr_pos[curr_fig]>32)&&(!(DOMECEK(4))))
			{
				curr_pos[curr_fig]=36;
			}
			poloz(curr_pos[curr_fig]);						
		}		
		else	
		{
			pc<<"nic neni v poli"<<endl;
			if(kostka_hod==6)
			{
				pc<<"kostka je 6"<<endl;
				if(CHECKPOLICKO(1))
				{
					pc<<"vyhazuju"<<endl;
					vyhod(1);
				}
				if(DOMECEK(0))
				{
					curr_fig=0;
					naber(33);
				}
				else if(DOMECEK(1))
				{
					curr_fig=1;
					naber(34);
				}
				curr_pos[curr_fig]=1;
				poloz(curr_pos[curr_fig]);
			}
		}
		*/
	}
}
