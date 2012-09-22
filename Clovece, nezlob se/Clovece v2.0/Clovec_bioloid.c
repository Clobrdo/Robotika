#include "bioloid_v2.1.h"

void naber_nezasahnute_pozice()
{
	//otevre celisti
	motor[2].position(605);
	motor[3].position(39);
	motor[4].position(977);
	motor[5].position(688);
	motor[6].position(486);
	motor[7].position(548);
	syncWait(1000000);
	//zacne naklanet ruku nad figurku
	motor[2].position(610);
	motor[3].position(530);
	motor[4].position(689);
	motor[5].position(792);
	motor[6].position(486);
	motor[7].position(548);
	syncWait(3000000);
	//nakloni se uplne nad figurku
	motor[2].position(540);
	motor[3].position(621);
	motor[4].position(687);
	motor[5].position(715);
	motor[6].position(486);
	motor[7].position(548);
	syncWait(3000000);
	//zavre celisti
	motor[2].position(540);
	motor[3].position(621);
	motor[4].position(687);
	motor[5].position(715);
	motor[6].position(520);
	motor[7].position(504);
	syncWait(1000000);
	//zvedne ruku nahoru
	motor[2].position(610);
	motor[3].position(276);
	motor[4].position(671);
	motor[5].position(782);
	motor[6].position(520);
	motor[7].position(504);
	syncWait(3000000);
}
void vyloz_nezasahnute_pozice()
{
	//zacne se naklanet
	motor[2].position(632);
	motor[3].position(370);
	motor[4].position(766);
	motor[5].position(779);
	motor[6].position(520);
	motor[7].position(504);
	syncWait(3000000);
	//polozi figurku
	motor[2].position(569);
	motor[3].position(570);//570
	motor[4].position(636);
	motor[5].position(815);
	motor[6].position(520);
	motor[7].position(504);
	syncWait(3000000);
	//otevre celisti
	motor[2].position(569);
	motor[3].position(570);//560
	motor[4].position(636);
	motor[5].position(815);
	motor[6].position(486);
	motor[7].position(548);
	syncWait(1000000);
	//zvedne rameno
	motor[2].position(528);
	motor[3].position(512);
	motor[4].position(793);
	motor[5].position(740);
	motor[6].position(486);
	motor[7].position(548);
	syncWait(2000000);
}

void naber()
{
	
	//otoci se nad figurku
	motor[2].position(605);
	motor[3].position(39);
	motor[4].position(977);
	motor[5].position(688);
	motor[6].position(512);
	motor[7].position(512);
	syncWait(3500000);
	//nad chlivkem  otevre celisti
	motor[2].position(605);
	motor[3].position(39);
	motor[4].position(977);
	motor[5].position(688);
	motor[6].position(486);
	motor[7].position(548);
	syncWait(1000000);
	//zacne se naklanet
	motor[2].position(460);
	motor[3].position(448);
	motor[4].position(372);
	motor[5].position(170);
	motor[6].position(486);
	motor[7].position(548);
	syncWait(3000000);
	//nakloni se nad figurku
	motor[2].position(460);
	motor[3].position(448);
	motor[4].position(320);
	motor[5].position(248);
	motor[6].position(486);
	motor[7].position(548);
	syncWait(3000000);
	//nad figurkou zavre celisti
	motor[2].position(460);
	motor[3].position(453);
	motor[4].position(320);
	motor[5].position(248);
	motor[6].position(530);
	motor[7].position(494);
	syncWait(1000000);
	//narovna rameno
	motor[2].position(500);
	motor[3].position(700);
	motor[4].position(314);
	motor[5].position(248);
	motor[6].position(530);
	motor[7].position(494);
	syncWait(3000000);
}

void vyloz()
{
	//narovna rameno - zakladni pozice
	motor[2].position(500);
	motor[3].position(700);
	motor[4].position(314);
	motor[5].position(248);
	motor[6].position(530);
	motor[7].position(494);
	syncWait(3000000);
	//nad figurkou celisti zavrene
	motor[2].position(490);//480
	motor[3].position(435);
	motor[4].position(320);
	motor[5].position(260);
	motor[6].position(530);
	motor[7].position(494);
	syncWait(3000000);
	//srovnani figurky v celistech
	motor[2].position(490);//480
	motor[3].position(435);
	motor[4].position(320);
	motor[5].position(260);
	motor[6].position(510);
	motor[7].position(510);
	syncWait(1500000);
	//nakloni se nad figurku
	motor[2].position(480);//480
	motor[3].position(435);
	motor[4].position(320);
	motor[5].position(260);
	motor[6].position(486);
	motor[7].position(548);
	syncWait(3000000);
	//natoci se nad pole
	motor[2].position(605);
	motor[3].position(39);
	motor[4].position(977);
	motor[5].position(688);
	motor[6].position(486);
	motor[7].position(548);
	syncWait(2000000);
}
void vyloz_na_pozici_chlivek1()
{
	//robot nad chlivkem
	motor[1].position(198);
	motor[2].position(500);
	motor[3].position(700);
	motor[4].position(314);
	motor[5].position(248);
	motor[6].position(530);
	motor[7].position(494);
	syncWait(2000000);
	//polozi figurku
	motor[1].position(197);
	motor[2].position(570);
	motor[3].position(324);
	motor[4].position(336);
	motor[5].position(270);
	motor[6].position(530);
	motor[7].position(494);
	syncWait(5000000);
	//otevre celisti
	motor[1].position(197);
	motor[2].position(570);
	motor[3].position(324);
	motor[4].position(336);
	motor[5].position(270);
	motor[6].position(486);
	motor[7].position(524);
	syncWait(2000000);
	//rameno nahoru
	motor[1].position(198);
	motor[2].position(750);
	motor[3].position(292);
	motor[4].position(373);
	motor[5].position(200);
	motor[6].position(486);
	motor[7].position(524);
	syncWait(2000000);

}
void cti_tlacitka(uint8_t tlacitka[])
{
	for(int i=0; i!=5; ++i)
	{
		tlacitka[i] = pc.get();	
		led.rxd(1);
		syncWait(100000);
		led.rxd(0);
	}
}
void sila()
{		
	for(int i = 1, i != 6,++i )
	{
		motor [i]. torqueLimit (1023);
	}
}
void rychlost()
{	
	for(int i = 1, i != 8,++i )
	{
		motor [i]. speed(50);
	}
}
void zakladni_pozice()
{
	motor[1].position(512);
	motor[2].position(605);
	motor[3].position(39);
	motor[4].position(977);
	motor[5].position(688);
	motor[6].position(512);
	motor[7].position(512);
}


void chlivek_clovek_pozice39()
{
	//nakloni se s figurkou nad chlivek
	motor[1].position(838);
	motor[2].position(521);
	motor[3].position(459);
	motor[4].position(343);
	motor[5].position(287);
	motor[6].position(512);
	motor[7].position(512);
	syncWait(7000000);
	//zacne pokladat figurku
	motor[1].position(838);
	motor[2].position(500);
	motor[3].position(440);
	motor[4].position(457);
	motor[5].position(180);
	motor[6].position(512);
	motor[7].position(512);
	syncWait(1000000);
	//polozi figurku
	motor[1].position(838);
	motor[2].position(450);
	motor[3].position(440);
	motor[4].position(457);
	motor[5].position(190);
	motor[6].position(512);
	motor[7].position(512);
	syncWait(4000000);
	//otevre celisti
	motor[1].position(838);
	motor[2].position(450);
	motor[3].position(440);
	motor[4].position(457);
	motor[5].position(190);
	motor[6].position(486);
	motor[7].position(548);
	syncWait(4000000);
	//zvedne rameno
	motor[1].position(838);
	motor[2].position(550);
	motor[3].position(453);
	motor[4].position(434);
	motor[5].position(161);
	motor[6].position(486);
	motor[7].position(548);
	syncWait(4000000);

}
void chlivek_clovek_pozice40()
{
	//nakloni se s figurkou nad chlivek
	motor[1].position(788);
	motor[2].position(521);
	motor[3].position(459);
	motor[4].position(343);
	motor[5].position(287);
	motor[6].position(512);
	motor[7].position(512);
	syncWait(7000000);
	//zacne pokladat figurku
	motor[1].position(788);
	motor[2].position(500);
	motor[3].position(440);
	motor[4].position(457);
	motor[5].position(180);
	motor[6].position(512);
	motor[7].position(512);
	syncWait(1000000);
	//polozi figurku
	motor[1].position(788);
	motor[2].position(450);
	motor[3].position(440);
	motor[4].position(457);
	motor[5].position(190);
	motor[6].position(512);
	motor[7].position(512);
	syncWait(4000000);
	//otevre celisti
	motor[1].position(788);
	motor[2].position(450);
	motor[3].position(440);
	motor[4].position(457);
	motor[5].position(190);
	motor[6].position(486);
	motor[7].position(548);
	syncWait(4000000);
	//zvedne rameno
	motor[1].position(788);
	motor[2].position(550);
	motor[3].position(453);
	motor[4].position(434);
	motor[5].position(161);
	motor[6].position(486);
	motor[7].position(548);
	syncWait(4000000);

}
void chlivek_robot_pozice33()//vezme figurku z chlivku - funkcni
{
	//dostane se do zakladni pozice
	motor[1].position(512);
	motor[2].position(605);
	motor[3].position(39);
	motor[4].position(977);
	motor[5].position(688);
	motor[6].position(512);
	motor[7].position(512);
	syncWait(4000000);
	//zakladni pozice ale otoci se nad pole
	motor[1].position(180);
	motor[2].position(605);
	motor[3].position(39);
	motor[4].position(977);
	motor[5].position(688);
	motor[6].position(512);
	motor[7].position(512);
	syncWait(1000000);
	//nad chlivkem  otevre celisti
	motor[1].position(180);
	motor[2].position(605);
	motor[3].position(39);
	motor[4].position(977);
	motor[5].position(688);
	motor[6].position(486);
	motor[7].position(548);
	syncWait(4000000);
	//zacne se naklanet
	motor[1].position(180);
	motor[2].position(592);
	motor[3].position(302);
	motor[4].position(411);
	motor[5].position(214);
	motor[6].position(486);
	motor[7].position(548);
	syncWait(6000000);
	//nakloni se nad figurku
	motor[1].position(180);
	motor[2].position(415);
	motor[3].position(447);
	motor[4].position(477);
	motor[5].position(170);
	motor[6].position(486);
	motor[7].position(548);
	syncWait(5000000);
	//nad figurkou zavre celisti
	motor[1].position(180);
	motor[2].position(415);
	motor[3].position(447);
	motor[4].position(477);
	motor[5].position(170);
	motor[6].position(524);
	motor[7].position(500);
	syncWait(2000000);
	//vezme figurku
	motor[1].position(180);
	motor[2].position(415);
	motor[3].position(505);
	motor[4].position(500);
	motor[5].position(170);
	motor[6].position(524);
	motor[7].position(500);
	syncWait(3000000);
	//zvedne figurku 2
	motor[1].position(180);
	motor[2].position(420);
	motor[3].position(652);
	motor[4].position(184);
	motor[5].position(166);
	motor[6].position(530);
	motor[7].position(494);
	syncWait(2000000);
	//druhy motor se zakloni
	motor[1].position(180);
	motor[2].position(570);
	motor[3].position(652);
	motor[4].position(184);
	motor[5].position(166);
	motor[6].position(530);
	motor[7].position(494);
	syncWait(2000000);
	//zacne pokladat figurku
	motor[1].position(168);
	motor[2].position(538);
	motor[3].position(409);
	motor[4].position(284);
	motor[5].position(238);//238
	motor[6].position(530);
	motor[7].position(494);
	syncWait(1000000);
	//zacne pokladat figurku
	motor[1].position(168);
	motor[2].position(470);
	motor[3].position(440);//440
	motor[4].position(372);
	motor[5].position(170);//170
	motor[6].position(530);
	motor[7].position(494);
	syncWait(3000000);
	//zacne pokladat figurku
	motor[1].position(168);
	motor[2].position(470);
	motor[3].position(453);//453
	motor[4].position(320);
	motor[5].position(245);//255 puvodni pred upravou
	motor[6].position(530);
	motor[7].position(494);
	syncWait(3000000);
	//otevre celisti
	motor[1].position(168);
	motor[2].position(470);
	motor[3].position(453);
	motor[4].position(320);
	motor[5].position(245);//255
	motor[6].position(496);
	motor[7].position(534);
	syncWait(3000000);
	//narovna rameno
	motor[1].position(168);
	motor[2].position(570);
	motor[3].position(433);
	motor[4].position(314);
	motor[5].position(257);
	motor[6].position(496);
	motor[7].position(534);
	syncWait(2000000);
}
void chlivek_robot_pozice34()//vezme figurku z chlivku - funkcni
{
	//dostane se do zakladni pozice
	motor[1].position(512);
	motor[2].position(605);
	motor[3].position(39);
	motor[4].position(977);
	motor[5].position(688);
	motor[6].position(512);
	motor[7].position(512);
	syncWait(4000000);
	//zakladni pozice ale otoci se nad pole
	motor[1].position(222);
	motor[2].position(605);
	motor[3].position(39);
	motor[4].position(977);
	motor[5].position(688);
	motor[6].position(512);
	motor[7].position(512);
	syncWait(1000000);
	//nad chlivkem  otevre celisti
	motor[1].position(222);
	motor[2].position(605);
	motor[3].position(39);
	motor[4].position(977);
	motor[5].position(688);
	motor[6].position(486);
	motor[7].position(548);
	syncWait(4000000);
	//zacne se naklanet
	motor[1].position(222);
	motor[2].position(592);
	motor[3].position(302);
	motor[4].position(411);
	motor[5].position(214);
	motor[6].position(486);
	motor[7].position(548);
	syncWait(6000000);
	//nakloni se nad figurku
	motor[1].position(222);
	motor[2].position(415);
	motor[3].position(447);
	motor[4].position(477);
	motor[5].position(170);
	motor[6].position(486);
	motor[7].position(548);
	syncWait(5000000);
	//nad figurkou zavre celisti
	motor[1].position(222);
	motor[2].position(415);
	motor[3].position(447);
	motor[4].position(477);
	motor[5].position(170);
	motor[6].position(524);
	motor[7].position(500);
	syncWait(2000000);
	//vezme figurku
	motor[1].position(222);
	motor[2].position(415);
	motor[3].position(505);
	motor[4].position(500);
	motor[5].position(170);
	motor[6].position(524);
	motor[7].position(500);
	syncWait(3000000);
	//zvedne figurku 2
	motor[1].position(222);
	motor[2].position(420);
	motor[3].position(652);
	motor[4].position(184);
	motor[5].position(166);
	motor[6].position(530);
	motor[7].position(494);
	syncWait(2000000);
	//druhy motor se zakloni
	motor[1].position(222);
	motor[2].position(570);
	motor[3].position(652);
	motor[4].position(184);
	motor[5].position(166);
	motor[6].position(530);
	motor[7].position(494);
	syncWait(2000000);
	//zacne pokladat figurku
	motor[1].position(168);
	motor[2].position(538);
	motor[3].position(409);
	motor[4].position(284);
	motor[5].position(238);
	motor[6].position(530);
	motor[7].position(494);
	syncWait(1000000);
	//zacne pokladat figurku
	motor[1].position(168);
	motor[2].position(470);
	motor[3].position(440);//440
	motor[4].position(372);
	motor[5].position(170);
	motor[6].position(530);
	motor[7].position(494);
	syncWait(3000000);
	//zacne pokladat figurku
	motor[1].position(168);
	motor[2].position(470);
	motor[3].position(453);//453
	motor[4].position(320);
	motor[5].position(255);//255 puvodni pred upravou
	motor[6].position(530);
	motor[7].position(494);
	syncWait(3000000);
	//otevre celisti
	motor[1].position(168);
	motor[2].position(470);
	motor[3].position(453);
	motor[4].position(320);
	motor[5].position(255);//255
	motor[6].position(496);
	motor[7].position(534);
	syncWait(3000000);
	//narovna rameno
	motor[1].position(168);
	motor[2].position(580);
	motor[3].position(433);
	motor[4].position(314);
	motor[5].position(257);
	motor[6].position(496);
	motor[7].position(534);
	syncWait(2000000);
}

void pozice_512()//vsechny serva do pozice 512
{
	for(int i=1;i!=8;i++)
	{
		motor[i].position(512);
	}
}
void kostka()
{
	 bool is_any = true;
	 do 
	 {
		is_any = buttons.isUp() | buttons.isDown() | buttons.isLeft() | buttons.isRight() | buttons.isStart();
	 } 
	 while (!is_any);
	 if(buttons.isUp() == true)
	 {
	 	 Cislo = 2;
	 }
	 else if(buttons.isLeft() == true)
	 {
		 Cislo = 5;
	 }
	 else if(buttons.isRight() == true)
	 {
		 Cislo = 3;
	 }
	 else if(buttons.isDown() == true)

	 {
	 	 Cislo = 4;
	 }
	 else if(buttons.isStart() == true)
	 {
	 	 Cislo = 1;
	 }
	 pc << "Kostka je  " <<Cislo<< endl;
}

void zobrazeni()
{
	if (Cislo == 1)//vystupy na ridici jednotku,binarni kostka
	{
		led.manage(0);
		led.program(0);
		led.play(1);
	}
	else if (Cislo == 2)
	{
		led.manage(0);
		led.program(1);
		led.play(0);
	}
	else if (Cislo == 3)
	{
		led.manage(0);
		led.program(1);
		led.play(1);
	}
	else if (Cislo == 4)
	{
		led.manage(1);
		led.program(0);
		led.play(0);
	}
	else if (Cislo == 5)
	{
		led.manage(1);
		led.program(0);
		led.play(1);
	}
	else if (Cislo == 6)
	{
		led.manage(1);
		led.program(1);
		led.play(0);
	}
	

}
void zobrazeni0()
{
	led.manage(0);
	led.program(0);
	led.play(0);
}


void hra_robot()
{	
	led.txd(1);
//	if(H1 == 1) //hraje robot 
//	{	
	pc<<"Hraje robot"<<endl;
		zakladni_pozice();
		cti_tlacitka(tlacitka);
		prepocet_klavesnice();
		if (F1_0 == 0)
		{
			Cislo = 6;
		}
		else 
		{
			kostka();//cislice 1-6 tlacitka na ridici jednotce	
		}
		zobrazeni();//zobrazi cisla v bin tvaru na LEDkach
		if (Cislo == 6)
		{	
		//	if (TL30 == 0) //jen za predpokladu jeli na startu robota 0
		//	{
		//		if (TL33 == 1) //jen za predpokladu jeli start volno a v chlivku je na pozici 33 figurka
		//		{
					A = 0;
					chlivek_robot_pozice33();//zavola podprogram na premisteni figurky na start
					TL33 = 0;//vynuluje soucasnou pozici
					F1_0 = 1;//figurka je ve hre
		//		}
		//	}
		}	
		else if (Cislo != 6) 
		{
			if(F1_0 == 1)//je-li figurka robota ve hre pokracuje se dal
			{
				A = A + Cislo;//pricte hodnotu kostky k promene, nova hodnota
				
				if (A == D)//robot vyhodi cloveka
				{
					zjisteni_pozice();//presun figurku do chlivku na pozici 39. hraciho pole
					kalkulace_tahu_robot();//podle moznosti presune figurku
					TL39 = 1; //zapise 1 do chlivku "start"	
					D = 16;//pomocna promena se rovna zakladu
					F1_1 = 0;//figurka cloveka neni ve hre
				}
				else if (A != D)//robot nevyhodi figurku cloveka
				{
					kalkulace_tahu_robot();//zavola podprogram na kontrolu nove a puvodni pozice nakonec presune figurku
				}
			}
			
			B = B + Cislo;//puvodni pozice figurky	
		}
		led.aux(1);
	zakladni_pozice();
	led.txd(0);
	zobrazeni0();
}
void hra_clovek()
{	
	pc << "Hraje hrac" <<endl;
	led.rxd(1);
		cti_tlacitka(tlacitka);
		if (F1_1 == 0)
		{
			Cislo = 6;
		}
		else 
		{
			kostka();//cislice 1-6 tlacitka na ridici jednotce	
		}
		zobrazeni();
		syncWait(2000000);
		if (F1_1 = 1)//clovek nasadil figurku,figurka je na startu
		{
			C = C + Cislo;
			D = C;
		}
		
		if (Cislo == 6)//clovek ma v hracim poli figurku
		{
			F1_1 = 1;//figurka cloveka je ve hre
			C = 16;
			kalkulace_tahu_clovek();
			TL39 = 0;//vynuluje pozici v chlivku
		}

		if(D == A)//doslo k vyhozeni robotovy figurky
		{
			A = 0;
			TL33 = 1;//figurka robota je v chlivku
			F1_0 = 0;//figurka robota neni ve hre
		}
		
	led.rxd(0);
	zobrazeni0();
}

void nastaveni_pozice_volno()
{
	for(int i=1; i!=8; i++ )
	{
		motor [i].torqueLimit (0);
		motor [i]. setTorque ();
		pc << i << " =    "; 
		pc <<"volno    "<< motor.position()<<endl;
	}
	pc << endl;
	pc << endl;
}

void run()
{
	pc << "run" << endl;
	uint8_t tlacitka[5] = {0,0,0,0,0};
//	led.aux(1);
	rychlost();
	sila();
	char x;
	for(;;)
		{
		hra_robot();
		pc<<"A =  "<<A<<endl;
		pc<<"B =  "<<B<<endl;
		syncWait(500000);
		hra2();
		pc<<"C =  "<<C<<endl;
		pc<<"D =  "<<D<<endl;

		syncWait(500000);
		pc << "..." << endl;
		}
}

/*
	x=pc.get();
		switch(x)
			{
			
			case'o':
				vyloz_nezasahnute_pozice();
				break;


			case'i':
				chlivek_clovek_pozice39();
				break;

			case'u':
				chlivek_robot_pozice34();
				break;

	
			case'a':
				chlivek_robot_pozice33();
				break;

			case's':
				zakladni_pozice();
				break;

			case'd':
				vyloz_na_pozici_chlivek1();
				break;
			
			case'e':
				nastaveni_pozice_volno();
				break;
			
			case'r':
				rotace();
				break;
				
			case'b':
				vyloz_na_pozici30();
				break;

			case'p':
				naber_na_pozici27();
				break;
			}
*/	
