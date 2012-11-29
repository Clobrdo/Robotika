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
	int curr_fig;
	bool hra=true;	//true-cerveny, false-modry
	povol();
	while(!buttons.isStart())
	{}
	nastav_torque();
	//uint8_t kostka_hod;
			pc<<"jedu"<<endl;
	inicializace();
			pc<<"kostka nastavena"<<endl;
	nastav_rychlost(1);	
			pc<<"rychlost nastavena"<<endl;
	zakladni_pozice();
			pc<<"zakladni pozice"<<endl;
	cekej();
			pc<<"cekej ..."<<endl;
	//pc<<aktualizuj_hraci_pole()<<endl;
			pc<<"aktualizuj pole"<<endl;
	/*		naber(33);
			poloz(36);
			naber(34);
			poloz(35);*/
/*	while(1)
	{
		while(!buttons.isLeft()){}
		while(buttons.isLeft()){}
	
		pc.sendChar(127);
	
		for (int i =0; i!=5;++i)
		{
			uint8_t x=pc.get();
			pc<<x<<endl;
		}
	}*/
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
		while(!buttons.isStart()){}
		while(buttons.isStart()){}
		aktualizuj_hraci_pole();
		pc<<"start"<<endl;
		kostka_hod = kostka;
		led.manage(ledky[0][kostka_hod-1]);
		led.program(ledky[1][kostka_hod-1]);
		led.play(ledky[2][kostka_hod-1]);
		pc<<"kostka je "<<kostka_hod<<endl;
		if(hra)
		{
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
			if(curr_pos[2]<=32||curr_pos[2]>=39)
			{
				curr_fig=2;
			}
			else
			{
				curr_fig=3;
			}
		}
		if(curr_pos[curr_fig]<=32)
		{
			if(CHECKPOLICKO(curr_pos[curr_fig]+kostka_hod))
			{
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
			naber(curr_pos[curr_fig]);
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
				}
			}
			poloz(curr_pos[curr_fig]);
			
		}
		else if(curr_pos[curr_fig]>=33&&curr_pos[curr_fig]<=34)
		{
			if(kostka_hod==6)
			{
				if(CHECKPOLICKO(1))
				vyhod(1,curr_fig);
				naber(curr_pos[curr_fig]);
				curr_pos[curr_fig]=1;
				poloz(curr_pos[curr_fig]);
			}
		}
		else if(curr_pos[curr_fig]>=39&&curr_pos[curr_fig<=40])
		{
			if(kostka_hod==6)
			{
				if(CHECKPOLICKO(16))
				vyhod(16,curr_fig);
				naber(curr_pos[curr_fig]);
				curr_pos[curr_fig]=17;
				poloz(curr_pos[curr_fig]);
			}
		}
		if((DOMECEK(2)&&DOMECEK(3))||(DOMECEK(4)&&DOMECEK(5)))	//nekdo vyhral, nova hra
		{
			for(int i=0;i!=4;i++)
			{
				naber(curr_pos[i]);
				{
					switch(i)
					{
						case 0:curr_pos[i]=33;break;
						case 1:curr_pos[1]=34;break;
						case 2:curr_pos[i]=39;break;
						case 3:curr_pos[i]=40;break;
					}
				}
				poloz(curr_pos[i]);	
			}
		}
		//není hotovo - modré figurky do domeèkù
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
