#include "bioloid_v2.1.h"
int A,B,C,D,I1,I2,K1,K2,F1_0,F2_0,F1_1,F2_1;// A,B - pomocne promenne pro kalkulaci pozic
int TL1,TL2,TL3,TL4,TL5,TL6,TL7,TL8,TL9,TL10,TL11,TL12,TL13,TL14,TL15,TL16,TL17,TL18,TL19,TL20,TL21,TL22,TL23,TL24,TL25,TL26,TL27,TL28,TL29,TL30,TL31,TL32,TL33,TL34,TL35,TL36,TL37,TL38,TL39,TL40;//upraveno podle hraci plochy
int TL0_1,TL1_1,TL2_1,TL3_1,TL4_1,TL5_1,TL6_1,TL7_1,TL8_1,TL9_1,TL10_1,TL11_1,TL12_1,TL13_1,TL14_1,TL15_1,TL16_1,TL17_1,TL18_1,TL19_1,TL20_1,TL21_1,TL22_1,TL23_1,TL24_1,TL25_1,TL26_1,TL27_1,TL28_1,TL29_1,TL30_1,TL31_1,TL32_1,TL33_1,TL34_1,TL35_1,TL36_1,TL37_1,TL38_1,TL39_1,TL40_1;//nove pozice podle kterych se bude porovnat plocha
int Cislo;
int Vyhod;
uint8_t tlacitka[5] = {0,0,0,0,0};


void prepocet_klavesnice()
{
	TL1 = 0;
	TL2 = 0;
	TL3 = 0;
	TL4 = 0;
	TL5 = 0;
	TL6 = 0;
	TL7 = 0;
	TL8 = 0;
	TL9 = 0;
	TL10 = 0;
	TL11 = 0;
	TL12 = 0;
	TL13 = 0;
	TL14 = 0;
	TL15 = 0;
	TL16 = 0;
	TL17 = 0;
	TL18 = 0;
	TL19 = 0;
	TL20 = 0;
	TL21 = 0;
	TL22 = 0;
	TL23 = 0;
	TL24 = 0;
	TL25 = 0;
	TL26 = 0;
	TL27 = 0;
	TL28 = 0;
	TL29 = 0;
	TL30 = 0;
	TL31 = 0;
	TL32 = 0;
	TL33 = 0;
	TL34 = 0;
	TL35 = 0;
	TL36 = 0;
	TL37 = 0;
	TL38 = 0;
	TL39 = 0;
	TL40 = 0;

	if (tlacitka[0] == 129 or tlacitka[0] == 65 or tlacitka[0] == 33 or tlacitka[0] == 17 or tlacitka[0] == 9 or tlacitka[0] == 5 or tlacitka[0] == 3 or tlacitka[0] == 1)
	{
		TL1 = 1;
	}
	if (tlacitka[0] == 130 or tlacitka[0] == 66 or tlacitka[0] == 34 or tlacitka[0] == 18 or tlacitka[0] == 10 or tlacitka[0] == 6 or tlacitka[0] == 3 or tlacitka[0] == 2)
	{
		TL2 = 1;
	}
	if (tlacitka[0] == 132 or tlacitka[0] == 68 or tlacitka[0] == 36 or tlacitka[0] == 20 or tlacitka[0] == 12 or tlacitka[0] == 6 or tlacitka[0] == 5 or tlacitka[0] == 4)
	{
		TL3 = 1;
	}
	if (tlacitka[0] == 136 or tlacitka[0] == 72 or tlacitka[0] == 40 or tlacitka[0] == 24 or tlacitka[0] == 12 or tlacitka[0] == 10 or tlacitka[0] == 9 or tlacitka[0] == 8)
	{
		TL4 = 1;
	}
	if (tlacitka[0] == 144 or tlacitka[0] == 80 or tlacitka[0] == 48 or tlacitka[0] == 32 or tlacitka[0] == 20 or tlacitka[0] == 18 or tlacitka[0] == 17 or tlacitka[0] == 16)
	{
		TL5 = 1;
	}
	if (tlacitka[0] == 160 or tlacitka[0] == 96 or tlacitka[0] == 48 or tlacitka[0] == 40 or tlacitka[0] == 36 or tlacitka[0] == 34 or tlacitka[0] == 33 or tlacitka[0] == 32)
	{
		TL6 = 1;
	}
	if (tlacitka[0] == 192 or tlacitka[0] == 96 or tlacitka[0] == 80 or tlacitka[0] == 72 or tlacitka[0] == 68 or tlacitka[0] == 66 or tlacitka[0] == 65 or tlacitka[0] == 64)
	{
		TL7 = 1;
	}
	if (tlacitka[0] == 192 or tlacitka[0] == 160 or tlacitka[0] == 144 or tlacitka[0] == 136 or tlacitka[0] == 132 or tlacitka[0] == 130 or tlacitka[0] == 131 or tlacitka[0] == 128)
	{
		TL8 = 1;
	}
	if (tlacitka[1] == 129 or tlacitka[1] == 65 or tlacitka[1] == 33 or tlacitka[1] == 17 or tlacitka[1] == 9 or tlacitka[1] == 5 or tlacitka[1] == 3 or tlacitka[1] == 1)
	{
		TL9 = 1;
	}
	if (tlacitka[1] == 130 or tlacitka[1] == 66 or tlacitka[1] == 34 or tlacitka[1] == 18 or tlacitka[1] == 10 or tlacitka[1] == 6 or tlacitka[1] == 3 or tlacitka[1] == 2)
	{
		TL10 = 1;
	}
	if (tlacitka[1] == 132 or tlacitka[1] == 68 or tlacitka[1] == 36 or tlacitka[1] == 20 or tlacitka[1] == 12 or tlacitka[1] == 6 or tlacitka[1] == 5 or tlacitka[1] == 4)
	{
		TL11 = 1;
	}
	if (tlacitka[1] == 136 or tlacitka[1] == 72 or tlacitka[1] == 40 or tlacitka[1] == 24 or tlacitka[1] == 12 or tlacitka[1] == 10 or tlacitka[1] == 9 or tlacitka[1] == 8)
	{
		TL12 = 1;
	}
	if (tlacitka[1] == 144 or tlacitka[1] == 80 or tlacitka[1] == 48 or tlacitka[1] == 32 or tlacitka[1] == 20 or tlacitka[1] == 18 or tlacitka[1] == 17 or tlacitka[1] == 16)
	{
		TL13 = 1;
	}
	if (tlacitka[1] == 160 or tlacitka[1] == 96 or tlacitka[1] == 48 or tlacitka[1] == 40 or tlacitka[1] == 36 or tlacitka[1] == 34 or tlacitka[1] == 33 or tlacitka[1] == 32)
	{
		TL14 = 1;
	}
	if (tlacitka[1] == 192 or tlacitka[1] == 96 or tlacitka[1] == 80 or tlacitka[1] == 72 or tlacitka[1] == 68 or tlacitka[1] == 66 or tlacitka[1] == 65 or tlacitka[1] == 64)
	{
		TL15 = 1;
	}
	if (tlacitka[1] == 192 or tlacitka[1] == 160 or tlacitka[1] == 144 or tlacitka[1] == 136 or tlacitka[1] == 132 or tlacitka[1] == 130 or tlacitka[1] == 131 or tlacitka[1] == 128)
	{
		TL16 = 1;
	}
	if (tlacitka[2] == 129 or tlacitka[2] == 65 or tlacitka[2] == 33 or tlacitka[2] == 17 or tlacitka[2] == 9 or tlacitka[2] == 5 or tlacitka[2] == 3 or tlacitka[2] == 1)
	{
		TL17 = 1;
	}
	if (tlacitka[2] == 130 or tlacitka[2] == 66 or tlacitka[2] == 34 or tlacitka[2] == 18 or tlacitka[2] == 10 or tlacitka[2] == 6 or tlacitka[2] == 3 or tlacitka[2] == 2)
	{
		TL18 = 1;
	}
	if (tlacitka[2] == 132 or tlacitka[2] == 68 or tlacitka[2] == 36 or tlacitka[2] == 20 or tlacitka[2] == 12 or tlacitka[2] == 6 or tlacitka[2] == 5 or tlacitka[2] == 4)
	{
		TL19 = 1;
	}
	if (tlacitka[2] == 136 or tlacitka[2] == 72 or tlacitka[2] == 40 or tlacitka[2] == 24 or tlacitka[2] == 12 or tlacitka[2] == 10 or tlacitka[2] == 9 or tlacitka[2] == 8)
	{
		TL20 = 1;
	}
	if (tlacitka[2] == 144 or tlacitka[2] == 80 or tlacitka[2] == 48 or tlacitka[2] == 32 or tlacitka[2] == 20 or tlacitka[2] == 18 or tlacitka[2] == 17 or tlacitka[2] == 16)
	{
		TL21 = 1;
	}
	if (tlacitka[2] == 160 or tlacitka[2] == 96 or tlacitka[2] == 48 or tlacitka[2] == 40 or tlacitka[2] == 36 or tlacitka[2] == 34 or tlacitka[2] == 33 or tlacitka[2] == 32)
	{
		TL22 = 1;
	}
	if (tlacitka[2] == 192 or tlacitka[2] == 96 or tlacitka[2] == 80 or tlacitka[2] == 72 or tlacitka[2] == 68 or tlacitka[2] == 66 or tlacitka[2] == 65 or tlacitka[2] == 64)
	{
		TL23 = 1;
	}
	if (tlacitka[2] == 192 or tlacitka[2] == 160 or tlacitka[2] == 144 or tlacitka[2] == 136 or tlacitka[2] == 132 or tlacitka[2] == 130 or tlacitka[2] == 131 or tlacitka[2] == 128)
	{
		TL24 = 1;
	}
	if (tlacitka[3] == 129 or tlacitka[3] == 65 or tlacitka[3] == 33 or tlacitka[3] == 17 or tlacitka[3] == 9 or tlacitka[3] == 5 or tlacitka[3] == 3 or tlacitka[3] == 1)
	{
		TL25 = 1;
	}
	if (tlacitka[3] == 130 or tlacitka[3] == 66 or tlacitka[3] == 34 or tlacitka[3] == 18 or tlacitka[3] == 10 or tlacitka[3] == 6 or tlacitka[3] == 3 or tlacitka[3] == 2)
	{
		TL26 = 1;
	}
	if (tlacitka[3] == 132 or tlacitka[3] == 68 or tlacitka[3] == 36 or tlacitka[3] == 20 or tlacitka[3] == 12 or tlacitka[3] == 6 or tlacitka[3] == 5 or tlacitka[3] == 4)
	{
		TL27 = 1;
	}
	if (tlacitka[3] == 136 or tlacitka[3] == 72 or tlacitka[3] == 40 or tlacitka[3] == 24 or tlacitka[3] == 12 or tlacitka[3] == 10 or tlacitka[3] == 9 or tlacitka[3] == 8)
	{
		TL28 = 1;
	}
	if (tlacitka[3] == 144 or tlacitka[3] == 80 or tlacitka[3] == 48 or tlacitka[3] == 32 or tlacitka[3] == 20 or tlacitka[3] == 18 or tlacitka[3] == 17 or tlacitka[3] == 16)
	{
		TL29 = 1;
	}
	if (tlacitka[3] == 160)
	{
		TL30 = 1;
	}
	if (tlacitka[3] == 96)
	{
		TL30 = 1;
	}
	if (tlacitka[3] == 48)
	{
		TL30 = 1;
	}
	if (tlacitka[3] == 40)
	{
		TL30 = 1;
	}
	if (tlacitka[3] == 36)
	{
		TL30 = 1;
	}
	if (tlacitka[3] == 34)
	{
		TL30 = 1;
	}
	if (tlacitka[3] == 33)
	{
		TL30 = 1;
	}
	if (tlacitka[3] == 32)
	{
		TL30 = 1;
	}
	if (tlacitka[3] == 192 or tlacitka[3] == 96 or tlacitka[3] == 80 or tlacitka[3] == 72 or tlacitka[3] == 68 or tlacitka[3] == 66 or tlacitka[3] == 65 or tlacitka[3] == 64)
	{
		TL31 = 1;
	}
	if (tlacitka[3] == 192 or tlacitka[3] == 160 or tlacitka[3] == 144 or tlacitka[3] == 136 or tlacitka[3] == 132 or tlacitka[3] == 130 or tlacitka[3] == 131 or tlacitka[3] == 128)
	{
		TL32 = 1;
	}
	//chlivky + default pozice

	if (tlacitka[4] == 129 || tlacitka[4] == 65 || tlacitka[4] == 33 || tlacitka[4] == 17 || tlacitka[4] == 9 || tlacitka[4] == 5 || tlacitka[4] == 3 || tlacitka[4] == 1)
	{
		TL33 = 1;
	}	
	if (tlacitka[4] == 130 or tlacitka[4] == 66 or tlacitka[4] == 34 or tlacitka[4] == 18 or tlacitka[4] == 10 or tlacitka[4] == 6 or tlacitka[4] == 3 or tlacitka[4] == 2)
	{
		TL34 = 1;
	}
	if (tlacitka[4] == 132 or tlacitka[4] == 68 or tlacitka[4] == 36 or tlacitka[4] == 20 or tlacitka[4] == 12 or tlacitka[4] == 6 or tlacitka[4] == 5 or tlacitka[4] == 4)
	{
		TL35 = 1;
	}
	if (tlacitka[4] == 136 or tlacitka[4] == 72 or tlacitka[4] == 40 or tlacitka[4] == 24 or tlacitka[4] == 12 or tlacitka[4] == 10 or tlacitka[4] == 9 or tlacitka[4] == 8)
	{
		TL36 = 1;
	}
	if (tlacitka[4] == 144 or tlacitka[4] == 80 or tlacitka[4] == 48 or tlacitka[4] == 32 or tlacitka[4] == 20 or tlacitka[4] == 18 or tlacitka[4] == 17 or tlacitka[4] == 16)
	{
		TL37 = 1;
	}
	if (tlacitka[4] == 160 or tlacitka[4] == 96 or tlacitka[4] == 48 or tlacitka[4] == 40 or tlacitka[4] == 36 or tlacitka[4] == 34 or tlacitka[4] == 33 or tlacitka[4] == 32)
	{
		TL38 = 1;
	}
	if (tlacitka[4] == 192 or tlacitka[4] == 96 or tlacitka[4] == 80 or tlacitka[4] == 72 or tlacitka[4] == 68 or tlacitka[4] == 66 or tlacitka[4] == 65 or tlacitka[4] == 64)
	{
		TL39 = 1;
	}
	if (tlacitka[4] == 192 or tlacitka[4] == 160 or tlacitka[4] == 144 or tlacitka[4] == 136 or tlacitka[4] == 132 or tlacitka[4] == 130 or tlacitka[4] == 131 or tlacitka[4] == 128)
	{
		TL40 = 1;
	}
}

void definice()
{
	TL0_1 = 0;
	TL1_1 = 1;
	TL2_1 = 2;
	TL3_1 = 3;
	TL4_1 = 4;
	TL5_1 = 5;
	TL6_1 = 6;
	TL7_1 = 7;
	TL8_1 = 8;
	TL9_1 = 9;
	TL10_1 = 10;
	TL11_1 = 11;
	TL12_1 = 12;
	TL13_1 = 13;
	TL14_1 = 14;
	TL15_1 = 15;
	TL16_1 = 16;
	TL17_1 = 17;
	TL18_1 = 18;
	TL19_1 = 19;
	TL20_1 = 20;
	TL21_1 = 21;
	TL22_1 = 22;
	TL23_1 = 23;
	TL24_1 = 24;
	TL25_1 = 25;
	TL26_1 = 26;
	TL27_1 = 27;
	TL28_1 = 28;
	TL29_1 = 29;
	TL30_1 = 30;
	TL31_1 = 31;
	TL32_1 = 32;
}
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

void naber_na_pozici3()
{
	motor[1].position(587);
	naber_nezasahnute_pozice();
}

void vyloz_na_pozici3()
{
	motor[1].position(587);
	vyloz_nezasahnute_pozice();
}

void naber_na_pozici4()
{
	motor[1].position(554);
	naber_nezasahnute_pozice();
}

void vyloz_na_pozici4()
{
	motor[1].position(554);
	vyloz_nezasahnute_pozice();
}

void naber_na_pozici5()
{
	motor[1].position(510);
	naber_nezasahnute_pozice();
}

void vyloz_na_pozici5()
{
	motor[1].position(510);
	vyloz_nezasahnute_pozice();
}

void naber_na_pozici6()
{
	motor[1].position(468);
	naber_nezasahnute_pozice();
}

void vyloz_na_pozici6()
{
	motor[1].position(468);
	vyloz_nezasahnute_pozice();
}

void naber_na_pozici7()
{
	motor[1].position(428);
	naber_nezasahnute_pozice();
}

void vyloz_na_pozici7()
{
	motor[1].position(428);
	vyloz_nezasahnute_pozice();
}

void naber_na_pozici8()
{
	motor[1].position(1014);
	naber();
}

void vyloz_na_pozici8()
{
	motor[1].position(1014);
	vyloz();
}

void naber_na_pozici9()
{
	motor[1].position(972);
	naber();
}

void vyloz_na_pozici9()
{
	motor[1].position(972);
	vyloz();
}

void naber_na_pozici10()
{
	motor[1].position(935);
	naber();
}

void vyloz_na_pozici10()
{
	motor[1].position(935);
	vyloz();
}

void naber_na_pozici11()
{
	motor[1].position(892);
	naber();
}

void vyloz_na_pozici11()
{
	motor[1].position(892);
	vyloz();
}

void naber_na_pozici12()
{
	motor[1].position(858);
	naber();
}

void vyloz_na_pozici12()
{
	motor[1].position(858);
	vyloz();
}

void naber_na_pozici13()
{
	motor[1].position(819);
	naber();
}

void vyloz_na_pozici13()
{
	motor[1].position(819);
	vyloz();
}

void naber_na_pozici14()
{
	motor[1].position(780);
	naber();
}

void vyloz_na_pozici14()
{
	motor[1].position(780);
	vyloz();
}

void naber_na_pozici15()
{
	motor[1].position(743);
	naber();
}

void vyloz_na_pozici15()
{
	motor[1].position(743);
	vyloz();
}

void naber_na_pozici16()
{
	motor[1].position(700);
	naber();
}

void vyloz_na_pozici16()
{
	motor[1].position(700);
	vyloz();
}

void naber_na_pozici17()
{
	motor[1].position(659);
	naber();
}

void vyloz_na_pozici17()
{
	motor[1].position(659);
	vyloz();
}

void naber_na_pozici18()
{
	motor[1].position(626);
	naber();
}

void vyloz_na_pozici18()
{
	motor[1].position(626);
	vyloz();
}

void naber_na_pozici19()
{
	motor[1].position(589);
	naber();
}

void vyloz_na_pozici19()
{
	motor[1].position(589);
	vyloz();
}

void naber_na_pozici20()
{
	motor[1].position(548);
	naber();
}

void vyloz_na_pozici20()
{
	motor[1].position(548);
	vyloz();
}

void naber_na_pozici21()
{
	motor[1].position(510);
	naber();
}

void vyloz_na_pozici21()
{
	motor[1].position(510);
	vyloz();
}

void naber_na_pozici22()
{
	motor[1].position(470);
	naber();
}

void vyloz_na_pozici22()
{
	motor[1].position(470);
	vyloz();
}

void naber_na_pozici23()
{
	motor[1].position(434);
	naber();
}

void vyloz_na_pozici23()
{
	motor[1].position(434);
	vyloz();
}

void naber_na_pozici24()
{
	motor[1].position(392);
	naber();
}

void vyloz_na_pozici24()
{
	motor[1].position(392);
	vyloz();
}

void naber_na_pozici25()
{
	motor[1].position(352);
	naber();
}

void vyloz_na_pozici25()
{
	motor[1].position(352);
	vyloz();
}

void naber_na_pozici26()
{
	motor[1].position(316);
	naber();
}

void vyloz_na_pozici26()
{
	motor[1].position(316);
	vyloz();
}

void naber_na_pozici27()
{
	motor[1].position(283);
	naber();
}

void vyloz_na_pozici27()
{
	motor[1].position(283);
	vyloz();
}

void naber_na_pozici28()
{
	motor[1].position(239);
	naber();
}

void vyloz_na_pozici28()
{
	motor[1].position(239);
	vyloz();
}

void naber_na_pozici29()
{
	motor[1].position(202);
	naber();
}

void vyloz_na_pozici29()
{
	motor[1].position(202);
	vyloz();
}

void naber_na_pozici30()
{
	motor[1].position(168);
	naber();
}

void vyloz_na_pozici30()
{
	motor[1].position(168);
	vyloz();
}

void naber_na_pozici31()
{
	motor[1].position(126);
	naber();
}

void vyloz_na_pozici31()
{
	motor[1].position(126);
	vyloz();
}

void naber_na_pozici32()
{
	motor[1].position(88);
	naber();
}

void vyloz_na_pozici32()
{
	motor[1].position(88);
	vyloz();
}

void naber_na_pozici1()
{
	motor[1].position(50);
	naber();
}

void vyloz_na_pozici1()
{
	motor[1].position(50);
	vyloz();
}

void naber_na_pozici2()
{
	motor[1].position(14);
	naber();
}

void vyloz_na_pozici2()
{
	motor[1].position(14);
	vyloz();
}

void kalkulace_tahu_robot()
{
	if (A == 1)
	{
		if (A == TL1_1)	//figurka je na pozici 31. hraciho pole
		{
			if (B == TL0_1)//minula hodnota 
			{ 
				naber_na_pozici30();//presun figurku na pozici 30.hraciho pole
				syncWait(2000000);
				vyloz_na_pozici31();
				syncWait(2000000);
			}
		}
	}
	if (A == 2)
	{
		if (A == TL2_1)//figurka je na pozici 32. hraciho pole
		{
			if (B == TL0_1)//B = 0  -  zacina ze startu pozice 30. hraci plochy 
			{
				naber_na_pozici30();//presun figurku na pozici 32. hraciho pole z pozice 30
				syncWait(2000000);
				vyloz_na_pozici32();
				syncWait(2000000);
			}
			if (B == TL1_1)//figurka je na pozici 31. hraciho pole 
			{
				naber_na_pozici31();//presun figurku na pozici 32. hraciho pole z pozice 31
				syncWait(2000000);
				vyloz_na_pozici32();
				syncWait(2000000);
			}
		}
	}
	if (A == 3)
	{
		if (A == TL3_1)//figurka je na pozici 33. hraciho pole
		{
			if (B == TL0_1)//B zacina za startu 30 
			{
				naber_na_pozici30();
				syncWait(2000000);
				vyloz_na_pozici1();
				syncWait(2000000);//presun figurku na pozici 1. hraciho pole z pozice 30
			}
			if (B == TL1_1)//figurka je na pozici 31
			{
				naber_na_pozici31();
				syncWait(2000000);
				vyloz_na_pozici1();
				syncWait(2000000);//presun figurku na pozici 1. hraciho pole z pozice 31 
			}
			if (B == TL2_1)//figurka je na pozici 32
			{
				naber_na_pozici32();
				syncWait(2000000);
				vyloz_na_pozici1();
				syncWait(2000000);//presun figurku na pozici 1. hraciho pole z pozice 32 
			}
		}
	}
	if (A == 4)	
	{
		if (A == TL4_1)
		{
			if (B == TL0_1)
			{
				naber_na_pozici30();
				syncWait(2000000);
				vyloz_na_pozici2();
				syncWait(2000000);//presun figurku na pozici 2. hraciho pole z pozice 30
			}
			if (B == TL1_1)
			{
				naber_na_pozici31();
				syncWait(2000000);
				vyloz_na_pozici2();
				syncWait(5000000);//presun figurku na pozici 2. hraciho pole z pozice 31
			}
			if (B == TL2_1)
			{
				naber_na_pozici32();
				syncWait(2000000);
				vyloz_na_pozici2();
				syncWait(2000000);//presun figurku na pozici 2. hraciho pole z pozice 32
			}
			if (B == TL3_1)
			{
				naber_na_pozici1();
				syncWait(2000000);
				vyloz_na_pozici2();
				syncWait(2000000);//presun figurku na pozici 2. hraciho pole z pozice 1
			}
		}
	}
	if (A == 5)	
	{
		if (A == TL5_1)
		{
			if (B == TL0_1)
			{
				naber_na_pozici30();
				syncWait(2000000);
				vyloz_na_pozici3();
				syncWait(2000000);//presun figurku na pozici 3. hraciho pole z pozice 30
			}
			if (B == TL1_1)
			{
				naber_na_pozici31();
				syncWait(5000000);
				vyloz_na_pozici3();
				syncWait(2000000);//presun figurku na pozici 3. hraciho pole z pozice 31
			}
			if (B == TL2_1)
			{
				naber_na_pozici32();
				syncWait(5000000);
				vyloz_na_pozici3();
				syncWait(2000000);//presun figurku na pozici 3. hraciho pole z pozice 32
			}
			if (B == TL3_1)
			{
				naber_na_pozici1();
				syncWait(5000000);
				vyloz_na_pozici3();
				syncWait(2000000);//presun figurku na pozici 3. hraciho pole z pozice 1
			}
			if (B == TL4_1)
			{
				naber_na_pozici2();
				syncWait(5000000);
				vyloz_na_pozici3();
				syncWait(2000000);//presun figurku na pozici 3. hraciho pole z pozice 2
			}
		}
	}
	if (A == 6)
	{	
		if (A == TL6_1)
		{
			if (B == TL0_1)
			{
				naber_na_pozici30();
				syncWait(5000000);
				vyloz_na_pozici4();
				syncWait(2000000);
				//presun figurku na pozici 4. hraciho pole z pozice 30
			}
			if (B == TL1_1)
			{
				naber_na_pozici31();
				syncWait(5000000);
				vyloz_na_pozici4();
				syncWait(2000000);
				//presun figurku na pozici 4. hraciho pole z pozice 31
			}
			if (B == TL2_1)
			{
				naber_na_pozici32();
				syncWait(5000000);
				vyloz_na_pozici4();
				syncWait(2000000);
				//presun figurku na pozici 4. hraciho pole z pozice 32
			}
			if (B == TL3_1)
			{
				naber_na_pozici1();
				syncWait(5000000);
				vyloz_na_pozici4();
				syncWait(2000000);
				//presun figurku na pozici 4. hraciho pole z pozice 1
			}
			if (B == TL4_1)
			{
				naber_na_pozici2();
				syncWait(5000000);
				vyloz_na_pozici4();
				syncWait(2000000);
				//presun figurku na pozici 4. hraciho pole z pozice 2
			}
			if (B == TL5_1)
			{
				naber_na_pozici3();
				syncWait(5000000);
				vyloz_na_pozici4();
				syncWait(2000000);
				//presun figurku na pozici 4. hraciho pole z pozice 3
			}
		}
	}
	if (A == 7)
	{
		if(A == TL7_1)
		{
			if (B == TL0_1)
			{
				naber_na_pozici30();
				syncWait(5000000);
				vyloz_na_pozici5();
				syncWait(2000000);
				//presun figurku na pozici 5. hraciho pole z pozice 30
			}
			if (B == TL1_1)
			{
				naber_na_pozici31();
				syncWait(5000000);
				vyloz_na_pozici5();
				syncWait(2000000);
				//presun figurku na pozici 5. hraciho pole z pozice 31
			}
			if (B == TL2_1)
			{
				naber_na_pozici32();
				syncWait(5000000);
				vyloz_na_pozici5();
				syncWait(2000000);
				//presun figurku na pozici 5. hraciho pole z pozice 32
			}
			if (B == TL3_1)
			{
				naber_na_pozici1();
				syncWait(5000000);
				vyloz_na_pozici5();
				syncWait(2000000);
				//presun figurku na pozici 5. hraciho pole z pozice 1
			}
			if (B == TL4_1)
			{
				naber_na_pozici2();
				syncWait(5000000);
				vyloz_na_pozici5();
				syncWait(2000000);
				//presun figurku na pozici 5. hraciho pole z pozice 2
			}
			if (B == TL5_1)
			{
				naber_na_pozici3();
				syncWait(5000000);
				vyloz_na_pozici5();
				syncWait(2000000);
				//presun figurku na pozici 5. hraciho pole z pozice 3
			}
			if (B == TL6_1)
			{
				naber_na_pozici4();
				syncWait(5000000);
				vyloz_na_pozici5();
				syncWait(2000000);
				//presun figurku na pozici 5. hraciho pole z pozice 4
			}

		}
	}
	if (A == 8)
	{
		if(A == TL8_1)
		{
			if (B == TL0_1)
			{
				naber_na_pozici30();
				syncWait(5000000);
				vyloz_na_pozici6();
				syncWait(2000000);
				//presun figurku na pozici 6. hraciho pole z pozice 30
			}
			if (B == TL1_1)
			{
				naber_na_pozici31();
				syncWait(5000000);
				vyloz_na_pozici6();
				syncWait(2000000);
				//presun figurku na pozici 6. hraciho pole z pozice 31
			}
			if (B == TL2_1)
			{
				naber_na_pozici32();
				syncWait(5000000);
				vyloz_na_pozici6();
				syncWait(2000000);
				//presun figurku na pozici 6. hraciho pole z pozice 32
			}
			if (B == TL3_1)
			{
				naber_na_pozici1();
				syncWait(5000000);
				vyloz_na_pozici6();
				syncWait(2000000);
				//presun figurku na pozici 6. hraciho pole z pozice 1
			}
			if (B == TL4_1)
			{
				naber_na_pozici2();
				syncWait(5000000);
				vyloz_na_pozici6();
				syncWait(2000000);
				//presun figurku na pozici 6. hraciho pole z pozice 2
			}
			if (B == TL5_1)
			{
				naber_na_pozici3();
				syncWait(2000000);
				vyloz_na_pozici6();
				syncWait(2000000);
				//presun figurku na pozici 6. hraciho pole z pozice 3
			}
			if (B == TL6_1)
			{
				naber_na_pozici4();
				syncWait(2000000);
				vyloz_na_pozici6();
				syncWait(2000000);
				//presun figurku na pozici 6. hraciho pole z pozice 4
			}
			if (B == TL7_1)
			{
				naber_na_pozici5();
				syncWait(2000000);
				vyloz_na_pozici6();
				syncWait(2000000);
				//presun figurku na pozici 6. hraciho pole z pozice 5
			}
		}
	}
	if (A == 9)
	{
		if(A == TL9_1)
		{
			if (B == TL0_1)
			{
				naber_na_pozici30();
				syncWait(5000000);
				vyloz_na_pozici7();
				syncWait(2000000);
				//presun figurku na pozici 7. hraciho pole z pozice 30
			}
			if (B == TL1_1)
			{
				naber_na_pozici31();
				syncWait(5000000);
				vyloz_na_pozici7();
				syncWait(2000000);
				//presun figurku na pozici 7. hraciho pole z pozice 31
			}
			if (B == TL2_1)
			{
				naber_na_pozici32();
				syncWait(5000000);
				vyloz_na_pozici7();
				syncWait(2000000);
				//presun figurku na pozici 7. hraciho pole z pozice 32
			}
			if (B == TL3_1)
			{
				naber_na_pozici1();
				syncWait(5000000);
				vyloz_na_pozici7();
				syncWait(2000000);
				//presun figurku na pozici 7. hraciho pole z pozice 1
			}
			if (B == TL4_1)
			{
				naber_na_pozici2();
				syncWait(5000000);
				vyloz_na_pozici7();
				syncWait(2000000);
				//presun figurku na pozici 7. hraciho pole z pozice 2
			}
			if (B == TL5_1)
			{
				naber_na_pozici3();
				syncWait(2000000);
				vyloz_na_pozici7();
				syncWait(2000000);
				//presun figurku na pozici 7. hraciho pole z pozice 3
			}
			if (B == TL6_1)
			{
				naber_na_pozici4();
				syncWait(2000000);
				vyloz_na_pozici7();
				syncWait(2000000);
				//presun figurku na pozici 7. hraciho pole z pozice 4
			}
			if (B == TL7_1)
			{
				naber_na_pozici5();
				syncWait(2000000);
				vyloz_na_pozici7();
				syncWait(2000000);
				//presun figurku na pozici 7. hraciho pole z pozice 5
			}
			if (B == TL8_1)
			{
				naber_na_pozici6();
				syncWait(2000000);
				vyloz_na_pozici7();
				syncWait(2000000);
				//presun figurku na pozici 7. hraciho pole z pozice 6
			}
		}
	}
	if (A == 10)
	{
		if(A == TL10_1)
		{
			if (B == TL0_1)
			{
				naber_na_pozici30();
				syncWait(5000000);
				vyloz_na_pozici8();
				syncWait(5000000);
				//presun figurku na pozici 8. hraciho pole z pozice 30
			}
			if (B == TL1_1)
			{
				naber_na_pozici31();
				syncWait(5000000);
				vyloz_na_pozici8();
				syncWait(5000000);
				//presun figurku na pozici 8. hraciho pole z pozice 31
			}
			if (B == TL2_1)
			{
				naber_na_pozici32();
				syncWait(5000000);
				vyloz_na_pozici8();
				syncWait(5000000);
				//presun figurku na pozici 8. hraciho pole z pozice 32
			}
			if (B == TL3_1)
			{
				naber_na_pozici1();
				syncWait(5000000);
				vyloz_na_pozici8();
				syncWait(5000000);
				//presun figurku na pozici 8. hraciho pole z pozice 1
			}
			if (B == TL4_1)
			{
				naber_na_pozici2();
				syncWait(5000000);
				vyloz_na_pozici8();
				syncWait(5000000);
				//presun figurku na pozici 8. hraciho pole z pozice 2
			}
			if (B == TL5_1)
			{
				naber_na_pozici3();
				syncWait(2000000);
				vyloz_na_pozici8();
				syncWait(2000000);
				//presun figurku na pozici 8. hraciho pole z pozice 3
			}
			if (B == TL6_1)
			{
				naber_na_pozici4();
				syncWait(2000000);
				vyloz_na_pozici8();
				syncWait(2000000);
				//presun figurku na pozici 8. hraciho pole z pozice 4
			}
			if (B == TL7_1)
			{
				naber_na_pozici5();
				syncWait(2000000);
				vyloz_na_pozici8();
				syncWait(2000000);
				//presun figurku na pozici 8. hraciho pole z pozice 5
			}
			if (B == TL8_1)
			{
				naber_na_pozici6();
				syncWait(5000000);
				vyloz_na_pozici8();
				syncWait(2000000);
				//presun figurku na pozici 8. hraciho pole z pozice 6
			}
			if (B == TL9_1)
			{
				naber_na_pozici7();
				syncWait(5000000);
				vyloz_na_pozici8();
				syncWait(2000000);
				//presun figurku na pozici 8. hraciho pole z pozice 7
			}
		}
	}
	if (A == 11)
	{
		if(A == TL11_1)
		{
			if (B == TL0_1)
			{
				naber_na_pozici30();
				syncWait(5000000);
				vyloz_na_pozici9();
				syncWait(5000000);
				//presun figurku na pozici 9. hraciho pole z pozice 30
			}
			if (B == TL1_1)
			{
				naber_na_pozici31();
				syncWait(5000000);
				vyloz_na_pozici9();
				syncWait(5000000);
				//presun figurku na pozici 9. hraciho pole z pozice 31
			}
			if (B == TL2_1)
			{
				naber_na_pozici32();
				syncWait(5000000);
				vyloz_na_pozici9();
				syncWait(2000000);
				//presun figurku na pozici 9. hraciho pole z pozice 32
			}
			if (B == TL3_1)
			{
				naber_na_pozici1();
				syncWait(5000000);
				vyloz_na_pozici9();
				syncWait(2000000);
				//presun figurku na pozici 9. hraciho pole z pozice 1
			}
			if (B == TL4_1)
			{
				naber_na_pozici2();
				syncWait(5000000);
				vyloz_na_pozici9();
				syncWait(2000000);
				//presun figurku na pozici 9. hraciho pole z pozice 2
			}
			if (B == TL5_1)
			{
				naber_na_pozici3();
				syncWait(5000000);
				vyloz_na_pozici9();
				syncWait(2000000);
				//presun figurku na pozici 9. hraciho pole z pozice 3
			}
			if (B == TL6_1)
			{
				naber_na_pozici4();
				syncWait(5000000);
				vyloz_na_pozici9();
				syncWait(2000000);
				//presun figurku na pozici 9. hraciho pole z pozice 4
			}
			if (B == TL7_1)
			{
				naber_na_pozici5();
				syncWait(5000000);
				vyloz_na_pozici9();
				syncWait(2000000);
				//presun figurku na pozici 9. hraciho pole z pozice 5
			}
			if (B == TL8_1)
			{
				naber_na_pozici6();
				syncWait(5000000);
				vyloz_na_pozici9();
				syncWait(2000000);
				//presun figurku na pozici 9. hraciho pole z pozice 6
			}
			if (B == TL9_1)
			{
				naber_na_pozici7();
				syncWait(2000000);
				vyloz_na_pozici9();
				syncWait(2000000);
				//presun figurku na pozici 9. hraciho pole z pozice 7
			}
			if (B == TL10_1)
			{
				naber_na_pozici8();
				syncWait(5000000);
				vyloz_na_pozici9();
				syncWait(2000000);
				//presun figurku na pozici 9. hraciho pole z pozice 8
			}
		}
	}
	if (A == 12)
	{
		if(A == TL12_1)
		{
			if (B == TL0_1)
			{
				naber_na_pozici30();
				syncWait(5000000);
				vyloz_na_pozici10();
				syncWait(2000000);
				//presun figurku na pozici 10. hraciho pole z pozice 30
			}
			if (B == TL1_1)
			{
				naber_na_pozici31();
				syncWait(5000000);
				vyloz_na_pozici10();
				syncWait(2000000);
				//presun figurku na pozici 10. hraciho pole z pozice 31
			}
			if (B == TL2_1)
			{
				naber_na_pozici32();
				syncWait(5000000);
				vyloz_na_pozici10();
				syncWait(5000000);
				//presun figurku na pozici 10. hraciho pole z pozice 32
			}
			if (B == TL3_1)
			{
				//presun figurku na pozici 10. hraciho pole z pozice 1
			}
			if (B == TL4_1)
			{
				//presun figurku na pozici 10. hraciho pole z pozice 2
			}
			if (B == TL5_1)
			{
				naber_na_pozici3();
				syncWait(5000000);
				vyloz_na_pozici10();
				syncWait(2000000);
				//presun figurku na pozici 10. hraciho pole z pozice 3
			}
			if (B == TL6_1)
			{
				naber_na_pozici4();
				syncWait(5000000);
				vyloz_na_pozici10();
				syncWait(2000000);
				//presun figurku na pozici 10. hraciho pole z pozice 4
			}
			if (B == TL7_1)
			{
				naber_na_pozici5();
				syncWait(5000000);
				vyloz_na_pozici10();
				syncWait(2000000);
				//presun figurku na pozici 10. hraciho pole z pozice 5
			}
			if (B == TL8_1)
			{
				naber_na_pozici6();
				syncWait(5000000);
				vyloz_na_pozici10();
				syncWait(2000000);
				//presun figurku na pozici 10. hraciho pole z pozice 6
			}
			if (B == TL9_1)
			{
				naber_na_pozici7();
				syncWait(5000000);
				vyloz_na_pozici10();
				syncWait(2000000);
				//presun figurku na pozici 10. hraciho pole z pozice 7
			}
			if (B == TL10_1)
			{
				naber_na_pozici8();
				syncWait(5000000);
				vyloz_na_pozici10();
				syncWait(2000000);
				//presun figurku na pozici 10. hraciho pole z pozice 8
			}
			if (B == TL11_1)
			{
				naber_na_pozici9();
				syncWait(2000000);
				vyloz_na_pozici10();
				syncWait(2000000);
				//presun figurku na pozici 10. hraciho pole z pozice 9
			}
		}
	}		
	if (A == 13)
	{
		if(A == TL13_1)
		{
			if (B == TL0_1)
			{
				//presun figurku na pozici 11. hraciho pole z pozice 30
			}
			if (B == TL1_1)
			{
				//presun figurku na pozici 11. hraciho pole z pozice 31
			}
			if (B == TL2_1)
			{
				//presun figurku na pozici 11. hraciho pole z pozice 32
			}
			if (B == TL3_1)
			{
				//presun figurku na pozici 11. hraciho pole z pozice 1
			}
			if (B == TL4_1)
			{
				//presun figurku na pozici 11. hraciho pole z pozice 2
			}
			if (B == TL5_1)
			{
				//presun figurku na pozici 11. hraciho pole z pozice 3
			}
			if (B == TL6_1)
			{
				naber_na_pozici4();
				syncWait(5000000);
				vyloz_na_pozici11();
				syncWait(2000000);
				//presun figurku na pozici 11. hraciho pole z pozice 4
			}
			if (B == TL7_1)
			{
				naber_na_pozici5();
				syncWait(5000000);
				vyloz_na_pozici11();
				syncWait(2000000);
				//presun figurku na pozici 11. hraciho pole z pozice 5
			}
			if (B == TL8_1)
			{
				naber_na_pozici6();
				syncWait(5000000);
				vyloz_na_pozici11();
				syncWait(2000000);
				//presun figurku na pozici 11. hraciho pole z pozice 6
			}
			if (B == TL9_1)
			{
				naber_na_pozici7();
				syncWait(5000000);
				vyloz_na_pozici11();
				syncWait(2000000);
				//presun figurku na pozici 11. hraciho pole z pozice 7
			}
			if (B == TL10_1)
			{
				naber_na_pozici8();
				syncWait(5000000);
				vyloz_na_pozici11();
				syncWait(2000000);
				//presun figurku na pozici 11. hraciho pole z pozice 8
			}
			if (B == TL11_1)
			{
				naber_na_pozici9();
				syncWait(2000000);
				vyloz_na_pozici11();
				syncWait(2000000);
				//presun figurku na pozici 11. hraciho pole z pozice 9
			}
			if (B == TL12_1)
			{
				naber_na_pozici10();
				syncWait(2000000);
				vyloz_na_pozici11();
				syncWait(2000000);
				//presun figurku na pozici 11. hraciho pole z pozice 10
			}
		}
	}		
	if (A == 14)
	{
		if(A == TL14_1)
		{
			if (B == TL0_1)
			{
				//presun figurku na pozici 12. hraciho pole z pozice 30
			}
			if (B == TL1_1)
			{
				//presun figurku na pozici 12. hraciho pole z pozice 31
			}
			if (B == TL2_1)
			{
				//presun figurku na pozici 12. hraciho pole z pozice 32
			}
			if (B == TL3_1)
			{
				//presun figurku na pozici 12. hraciho pole z pozice 1
			}
			if (B == TL4_1)
			{
				//presun figurku na pozici 12. hraciho pole z pozice 2
			}
			if (B == TL5_1)
			{
				//presun figurku na pozici 12. hraciho pole z pozice 3
			}
			if (B == TL6_1)
			{
				//presun figurku na pozici 12. hraciho pole z pozice 4
			}
			if (B == TL7_1)
			{
				naber_na_pozici5();
				syncWait(5000000);
				vyloz_na_pozici12();
				syncWait(2000000);
				//presun figurku na pozici 12. hraciho pole z pozice 5
			}
			if (B == TL8_1)
			{
				naber_na_pozici6();
				syncWait(5000000);
				vyloz_na_pozici12();
				syncWait(2000000);
				//presun figurku na pozici 12. hraciho pole z pozice 6
			}
			if (B == TL9_1)
			{
				naber_na_pozici7();
				syncWait(5000000);
				vyloz_na_pozici12();
				syncWait(2000000);
				//presun figurku na pozici 12. hraciho pole z pozice 7
			}
			if (B == TL10_1)
			{
				naber_na_pozici8();
				syncWait(5000000);
				vyloz_na_pozici12();
				syncWait(2000000);
				//presun figurku na pozici 12. hraciho pole z pozice 8
			}
			if (B == TL11_1)
			{
				naber_na_pozici9();
				syncWait(2000000);
				vyloz_na_pozici12();
				syncWait(2000000);
				//presun figurku na pozici 12. hraciho pole z pozice 9
			}
			if (B == TL12_1)
			{
				naber_na_pozici10();
				syncWait(2000000);
				vyloz_na_pozici12();
				syncWait(2000000);
				//presun figurku na pozici 12. hraciho pole z pozice 10
			}
			if (B == TL13_1)
			{
				naber_na_pozici11();
				syncWait(2000000);
				vyloz_na_pozici12();
				syncWait(2000000);
				//presun figurku na pozici 12. hraciho pole z pozice 11
			}
		}
	}		
	if (A == 15)
	{
		if(A == TL15_1)
		{
			if (B == TL0_1)
			{
				//presun figurku na pozici 13. hraciho pole z pozice 30
			}
			if (B == TL1_1)
			{
				//presun figurku na pozici 13. hraciho pole z pozice 31
			}
			if (B == TL2_1)
			{
				//presun figurku na pozici 13. hraciho pole z pozice 32
			}
			if (B == TL3_1)
			{
				//presun figurku na pozici 13. hraciho pole z pozice 1
			}
			if (B == TL4_1)
			{
				//presun figurku na pozici 13. hraciho pole z pozice 2
			}
			if (B == TL5_1)
			{
				//presun figurku na pozici 13. hraciho pole z pozice 3
			}
			if (B == TL6_1)
			{
				//presun figurku na pozici 13. hraciho pole z pozice 4
			}
			if (B == TL7_1)
			{
				//presun figurku na pozici 13. hraciho pole z pozice 5
			}
			if (B == TL8_1)
			{
				naber_na_pozici6();
				syncWait(5000000);
				vyloz_na_pozici13();
				syncWait(2000000);
				//presun figurku na pozici 13. hraciho pole z pozice 6
			}
			if (B == TL9_1)
			{
				naber_na_pozici7();
				syncWait(5000000);
				vyloz_na_pozici13();
				syncWait(2000000);
				//presun figurku na pozici 13. hraciho pole z pozice 7
			}
			if (B == TL10_1)
			{
				naber_na_pozici8();
				syncWait(5000000);
				vyloz_na_pozici13();
				syncWait(2000000);
				//presun figurku na pozici 13. hraciho pole z pozice 8
			}
			if (B == TL11_1)
			{
				naber_na_pozici9();
				syncWait(2000000);
				vyloz_na_pozici13();
				syncWait(2000000);
				//presun figurku na pozici 13. hraciho pole z pozice 9
			}
			if (B == TL12_1)
			{
				naber_na_pozici10();
				syncWait(2000000);
				vyloz_na_pozici13();
				syncWait(2000000);
				//presun figurku na pozici 13. hraciho pole z pozice 10
			}
			if (B == TL13_1)
			{
				naber_na_pozici11();
				syncWait(2000000);
				vyloz_na_pozici13();
				syncWait(2000000);
				//presun figurku na pozici 13. hraciho pole z pozice 11
			}
			if (B == TL14_1)
			{
				naber_na_pozici12();
				syncWait(2000000);
				vyloz_na_pozici13();
				syncWait(2000000);
				//presun figurku na pozici 13. hraciho pole z pozice 12
			}
		}
	}
	if (A == 16)
	{
		if(A == TL16_1)
		{
			if (B == TL0_1)
			{
				//presun figurku na pozici 14. hraciho pole z pozice 30
			}
			if (B == TL1_1)
			{
				//presun figurku na pozici 14. hraciho pole z pozice 31
			}
			if (B == TL2_1)
			{
				//presun figurku na pozici 14. hraciho pole z pozice 32
			}
			if (B == TL3_1)
			{
				//presun figurku na pozici 14. hraciho pole z pozice 1
			}
			if (B == TL4_1)
			{
				//presun figurku na pozici 14. hraciho pole z pozice 2
			}
			if (B == TL5_1)
			{
				//presun figurku na pozici 14. hraciho pole z pozice 3
			}
			if (B == TL6_1)
			{
				//presun figurku na pozici 14. hraciho pole z pozice 4
			}
			if (B == TL7_1)
			{
				//presun figurku na pozici 14. hraciho pole z pozice 5
			}
			if (B == TL8_1)
			{
				//presun figurku na pozici 14. hraciho pole z pozice 6
			}
			if (B == TL9_1)
			{
				naber_na_pozici7();
				syncWait(5000000);
				vyloz_na_pozici14();
				syncWait(2000000);
				//presun figurku na pozici 14. hraciho pole z pozice 7
			}
			if (B == TL10_1)
			{
				naber_na_pozici8();
				syncWait(5000000);
				vyloz_na_pozici14();
				syncWait(2000000);
				//presun figurku na pozici 14. hraciho pole z pozice 8
			}
			if (B == TL11_1)
			{
				naber_na_pozici9();
				syncWait(2000000);
				vyloz_na_pozici14();
				syncWait(2000000);
				//presun figurku na pozici 14. hraciho pole z pozice 9
			}
			if (B == TL12_1)
			{
				naber_na_pozici10();
				syncWait(2000000);
				vyloz_na_pozici14();
				syncWait(2000000);
				//presun figurku na pozici 14. hraciho pole z pozice 10
			}
			if (B == TL13_1)
			{
				naber_na_pozici11();
				syncWait(2000000);
				vyloz_na_pozici14();
				syncWait(2000000);
				//presun figurku na pozici 14. hraciho pole z pozice 11
			}
			if (B == TL14_1)
			{
				naber_na_pozici12();
				syncWait(2000000);
				vyloz_na_pozici14();
				syncWait(2000000);
				//presun figurku na pozici 14. hraciho pole z pozice 12
			}
			if (B == TL15_1)
			{
				naber_na_pozici13();
				syncWait(2000000);
				vyloz_na_pozici14();
				syncWait(2000000);
				//presun figurku na pozici 14. hraciho pole z pozice 13
			}
		}
	}
	if (A == 17)
	{
		if(A == TL17_1)
		{
			if (B == TL0_1)
			{
				//presun figurku na pozici 15. hraciho pole z pozice 30
			}
			if (B == TL1_1)
			{
				//presun figurku na pozici 15. hraciho pole z pozice 31
			}
			if (B == TL2_1)
			{
				//presun figurku na pozici 15. hraciho pole z pozice 32
			}
			if (B == TL3_1)
			{
				//presun figurku na pozici 15. hraciho pole z pozice 1
			}
			if (B == TL4_1)
			{
				//presun figurku na pozici 15. hraciho pole z pozice 2
			}
			if (B == TL5_1)
			{
				//presun figurku na pozici 15. hraciho pole z pozice 3
			}
			if (B == TL6_1)
			{
				//presun figurku na pozici 15. hraciho pole z pozice 4
			}
			if (B == TL7_1)
			{
				//presun figurku na pozici 15. hraciho pole z pozice 5
			}
			if (B == TL8_1)
			{
				//presun figurku na pozici 15. hraciho pole z pozice 6
			}
			if (B == TL9_1)
			{
				//presun figurku na pozici 15. hraciho pole z pozice 7
			}
			if (B == TL10_1)
			{
				naber_na_pozici8();
				syncWait(2000000);
				vyloz_na_pozici15();
				syncWait(2000000);
				//presun figurku na pozici 15. hraciho pole z pozice 8
			}
			if (B == TL11_1)
			{
				naber_na_pozici9();
				syncWait(2000000);
				vyloz_na_pozici15();
				syncWait(2000000);
				//presun figurku na pozici 15. hraciho pole z pozice 9
			}
			if (B == TL12_1)
			{
				naber_na_pozici10();
				syncWait(2000000);
				vyloz_na_pozici15();
				syncWait(2000000);
				//presun figurku na pozici 15. hraciho pole z pozice 10
			}
			if (B == TL13_1)
			{
				naber_na_pozici11();
				syncWait(2000000);
				vyloz_na_pozici15();
				syncWait(2000000);
				//presun figurku na pozici 15. hraciho pole z pozice 11
			}
			if (B == TL14_1)
			{
				naber_na_pozici12();
				syncWait(2000000);
				vyloz_na_pozici15();
				syncWait(2000000);
				//presun figurku na pozici 15. hraciho pole z pozice 12
			}
			if (B == TL15_1)
			{
				naber_na_pozici13();
				syncWait(2000000);
				vyloz_na_pozici15();
				syncWait(2000000);
				//presun figurku na pozici 15. hraciho pole z pozice 13
			}
			if (B == TL16_1)
			{
				naber_na_pozici14();
				syncWait(2000000);
				vyloz_na_pozici15();
				syncWait(2000000);
				//presun figurku na pozici 15. hraciho pole z pozice 14
			}
		}
	}
	if (A == 18)
	{
		if(A == TL18_1)
		{
			if (B == TL0_1)
			{
				//presun figurku na pozici 16. hraciho pole z pozice 30
			}
			if (B == TL1_1)
			{
				//presun figurku na pozici 16. hraciho pole z pozice 31
			}
			if (B == TL2_1)
			{
				//presun figurku na pozici 16. hraciho pole z pozice 32
			}
			if (B == TL3_1)
			{
				//presun figurku na pozici 16. hraciho pole z pozice 1
			}
			if (B == TL4_1)
			{
				//presun figurku na pozici 16. hraciho pole z pozice 2
			}
			if (B == TL5_1)
			{
				//presun figurku na pozici 16. hraciho pole z pozice 3
			}
			if (B == TL6_1)
			{
				//presun figurku na pozici 16. hraciho pole z pozice 4
			}
			if (B == TL7_1)
			{
				//presun figurku na pozici 16. hraciho pole z pozice 5
			}
			if (B == TL8_1)
			{
				//presun figurku na pozici 16. hraciho pole z pozice 6
			}
			if (B == TL9_1)
			{
				//presun figurku na pozici 16. hraciho pole z pozice 7
			}
			if (B == TL10_1)
			{
				//presun figurku na pozici 16. hraciho pole z pozice 8
			}
			if (B == TL11_1)
			{
				naber_na_pozici9();
				syncWait(2000000);
				vyloz_na_pozici16();
				syncWait(2000000);
				//presun figurku na pozici 16. hraciho pole z pozice 9
			}
			if (B == TL12_1)
			{
				naber_na_pozici10();
				syncWait(2000000);
				vyloz_na_pozici16();
				syncWait(2000000);
				//presun figurku na pozici 16. hraciho pole z pozice 10
			}
			if (B == TL13_1)
			{
				naber_na_pozici11();
				syncWait(2000000);
				vyloz_na_pozici16();
				syncWait(2000000);
				//presun figurku na pozici 16. hraciho pole z pozice 11
			}
			if (B == TL14_1)
			{
				naber_na_pozici12();
				syncWait(2000000);
				vyloz_na_pozici16();
				syncWait(2000000);
				//presun figurku na pozici 16. hraciho pole z pozice 12
			}
			if (B == TL15_1)
			{
				naber_na_pozici13();
				syncWait(2000000);
				vyloz_na_pozici16();
				syncWait(2000000);
				//presun figurku na pozici 16. hraciho pole z pozice 13
			}
			if (B == TL16_1)
			{
				naber_na_pozici14();
				syncWait(2000000);
				vyloz_na_pozici16();
				syncWait(2000000);
				//presun figurku na pozici 16. hraciho pole z pozice 14
			}
			if (B == TL17_1)
			{
				naber_na_pozici15();
				syncWait(2000000);
				vyloz_na_pozici16();
				syncWait(2000000);
				//presun figurku na pozici 16. hraciho pole z pozice 15
			}
		}
	}
	if (A == 19)
	{
		if(A == TL19_1)
		{
			if (B == TL0_1)
			{
				//presun figurku na pozici 17. hraciho pole z pozice 30
			}
			if (B == TL1_1)
			{
				//presun figurku na pozici 17. hraciho pole z pozice 31
			}
			if (B == TL2_1)
			{
				//presun figurku na pozici 17. hraciho pole z pozice 32
			}
			if (B == TL3_1)
			{
				//presun figurku na pozici 17. hraciho pole z pozice 1
			}
			if (B == TL4_1)
			{
				//presun figurku na pozici 17. hraciho pole z pozice 2
			}
			if (B == TL5_1)
			{
				//presun figurku na pozici 17. hraciho pole z pozice 3
			}
			if (B == TL6_1)
			{
				//presun figurku na pozici 17. hraciho pole z pozice 4
			}
			if (B == TL7_1)
			{
				//presun figurku na pozici 17. hraciho pole z pozice 5
			}
			if (B == TL8_1)
			{
				//presun figurku na pozici 17. hraciho pole z pozice 6
			}
			if (B == TL9_1)
			{
				//presun figurku na pozici 17. hraciho pole z pozice 7
			}
			if (B == TL10_1)
			{
				//presun figurku na pozici 17. hraciho pole z pozice 8
			}
			if (B == TL11_1)
			{
				//presun figurku na pozici 17. hraciho pole z pozice 9
			}
			if (B == TL12_1)
			{
				naber_na_pozici10();
				syncWait(2000000);
				vyloz_na_pozici17();
				syncWait(2000000);
				//presun figurku na pozici 17. hraciho pole z pozice 10
			}
			if (B == TL13_1)
			{
				naber_na_pozici11();
				syncWait(2000000);
				vyloz_na_pozici17();
				syncWait(2000000);
				//presun figurku na pozici 17. hraciho pole z pozice 11
			}
			if (B == TL14_1)
			{
				naber_na_pozici12();
				syncWait(2000000);
				vyloz_na_pozici17();
				syncWait(2000000);
				//presun figurku na pozici 17. hraciho pole z pozice 12
			}
			if (B == TL15_1)
			{
				naber_na_pozici13();
				syncWait(2000000);
				vyloz_na_pozici17();
				syncWait(2000000);
				//presun figurku na pozici 17. hraciho pole z pozice 13
			}
			if (B == TL16_1)
			{
				naber_na_pozici14();
				syncWait(2000000);
				vyloz_na_pozici17();
				syncWait(2000000);
				//presun figurku na pozici 17. hraciho pole z pozice 14
			}
			if (B == TL17_1)
			{
				naber_na_pozici15();
				syncWait(2000000);
				vyloz_na_pozici17();
				syncWait(2000000);
				//presun figurku na pozici 17. hraciho pole z pozice 15
			}
			if (B == TL18_1)
			{
				naber_na_pozici16();
				syncWait(2000000);
				vyloz_na_pozici17();
				syncWait(2000000);
				//presun figurku na pozici 17. hraciho pole z pozice 16
			}
		}
	}
	if (A == 20)
	{
		if(A == TL20_1)
		{
			if (B == TL0_1)
			{
				//presun figurku na pozici 18. hraciho pole z pozice 30
			}
			if (B == TL1_1)
			{
				//presun figurku na pozici 18. hraciho pole z pozice 31
			}
			if (B == TL2_1)
			{
				//presun figurku na pozici 18. hraciho pole z pozice 32
			}
			if (B == TL3_1)
			{
				//presun figurku na pozici 18. hraciho pole z pozice 1
			}
			if (B == TL4_1)
			{
				//presun figurku na pozici 18. hraciho pole z pozice 2
			}
			if (B == TL5_1)
			{
				//presun figurku na pozici 18. hraciho pole z pozice 3
			}
			if (B == TL6_1)
			{
				//presun figurku na pozici 18. hraciho pole z pozice 4
			}
			if (B == TL7_1)
			{
				//presun figurku na pozici 18. hraciho pole z pozice 5
			}
			if (B == TL8_1)
			{
				//presun figurku na pozici 18. hraciho pole z pozice 6
			}
			if (B == TL9_1)
			{
				//presun figurku na pozici 18. hraciho pole z pozice 7
			}
			if (B == TL10_1)
			{
				//presun figurku na pozici 18. hraciho pole z pozice 8
			}
			if (B == TL11_1)
			{
				//presun figurku na pozici 18. hraciho pole z pozice 9
			}
			if (B == TL12_1)
			{
				//presun figurku na pozici 18. hraciho pole z pozice 10
			}
			if (B == TL13_1)
			{
				naber_na_pozici11();
				syncWait(2000000);
				vyloz_na_pozici18();
				syncWait(2000000);
				//presun figurku na pozici 18. hraciho pole z pozice 11
			}
			if (B == TL14_1)
			{
				naber_na_pozici12();
				syncWait(2000000);
				vyloz_na_pozici18();
				syncWait(2000000);
				//presun figurku na pozici 18. hraciho pole z pozice 12
			}
			if (B == TL15_1)
			{
				naber_na_pozici13();
				syncWait(2000000);
				vyloz_na_pozici18();
				syncWait(2000000);
				//presun figurku na pozici 18. hraciho pole z pozice 13
			}
			if (B == TL16_1)
			{
				naber_na_pozici14();
				syncWait(2000000);
				vyloz_na_pozici18();
				syncWait(2000000);
				//presun figurku na pozici 18. hraciho pole z pozice 14
			}
			if (B == TL17_1)
			{
				naber_na_pozici15();
				syncWait(2000000);
				vyloz_na_pozici18();
				syncWait(2000000);
				//presun figurku na pozici 18. hraciho pole z pozice 15
			}
			if (B == TL18_1)
			{
				naber_na_pozici16();
				syncWait(2000000);
				vyloz_na_pozici18();
				syncWait(2000000);
				//presun figurku na pozici 18. hraciho pole z pozice 16
			}
			if (B == TL19_1)
			{
				naber_na_pozici17();
				syncWait(2000000);
				vyloz_na_pozici18();
				syncWait(2000000);
				//presun figurku na pozici 18. hraciho pole z pozice 17
			}
		}
	}
	if (A == 21)
	{
		if(A == TL21_1)
		{
			if (B == TL0_1)
			{
				//presun figurku na pozici 19. hraciho pole z pozice 30
			}
			if (B == TL1_1)
			{
				//presun figurku na pozici 19. hraciho pole z pozice 31
			}
			if (B == TL2_1)
			{
				//presun figurku na pozici 19. hraciho pole z pozice 32
			}
			if (B == TL3_1)
			{
				//presun figurku na pozici 19. hraciho pole z pozice 1
			}
			if (B == TL4_1)
			{
				//presun figurku na pozici 19. hraciho pole z pozice 2
			}
			if (B == TL5_1)
			{
				//presun figurku na pozici 19. hraciho pole z pozice 3
			}
			if (B == TL6_1)
			{
				//presun figurku na pozici 19. hraciho pole z pozice 4
			}
			if (B == TL7_1)
			{
				//presun figurku na pozici 19. hraciho pole z pozice 5
			}
			if (B == TL8_1)
			{
				//presun figurku na pozici 19. hraciho pole z pozice 6
			}
			if (B == TL9_1)
			{
				//presun figurku na pozici 19. hraciho pole z pozice 7
			}
			if (B == TL10_1)
			{
				//presun figurku na pozici 19. hraciho pole z pozice 8
			}
			if (B == TL11_1)
			{
				//presun figurku na pozici 19. hraciho pole z pozice 9
			}
			if (B == TL12_1)
			{
				//presun figurku na pozici 19. hraciho pole z pozice 10
			}
			if (B == TL13_1)
			{
				//presun figurku na pozici 19. hraciho pole z pozice 11
			}
			if (B == TL14_1)
			{
				naber_na_pozici12();
				syncWait(2000000);
				vyloz_na_pozici19();
				syncWait(2000000);
				//presun figurku na pozici 19. hraciho pole z pozice 12
			}
			if (B == TL15_1)
			{
				naber_na_pozici13();
				syncWait(2000000);
				vyloz_na_pozici19();
				syncWait(2000000);
				//presun figurku na pozici 19. hraciho pole z pozice 13
			}
			if (B == TL16_1)
			{
				naber_na_pozici14();
				syncWait(2000000);
				vyloz_na_pozici19();
				syncWait(2000000);
				//presun figurku na pozici 19. hraciho pole z pozice 14
			}
			if (B == TL17_1)
			{
				naber_na_pozici15();
				syncWait(2000000);
				vyloz_na_pozici19();
				syncWait(2000000);
				//presun figurku na pozici 19. hraciho pole z pozice 15
			}
			if (B == TL18_1)
			{
				naber_na_pozici16();
				syncWait(2000000);
				vyloz_na_pozici19();
				syncWait(2000000);
				//presun figurku na pozici 19. hraciho pole z pozice 16
			}
			if (B == TL19_1)
			{
				naber_na_pozici17();
				syncWait(2000000);
				vyloz_na_pozici19();
				syncWait(2000000);
				//presun figurku na pozici 19. hraciho pole z pozice 17
			}
			if (B == TL20_1)
			{
				naber_na_pozici18();
				syncWait(2000000);
				vyloz_na_pozici19();
				syncWait(2000000);
				//presun figurku na pozici 19. hraciho pole z pozice 18
			}
		}
	}
	if (A == 22)
	{
		if(A == TL22_1)
		{
			if (B == TL0_1)
			{
				//presun figurku na pozici 20. hraciho pole z pozice 30
			}
			if (B == TL1_1)
			{
				//presun figurku na pozici 20. hraciho pole z pozice 31
			}
			if (B == TL2_1)
			{
				//presun figurku na pozici 20. hraciho pole z pozice 32
			}
			if (B == TL3_1)
			{
				//presun figurku na pozici 20. hraciho pole z pozice 1
			}
			if (B == TL4_1)
			{
				//presun figurku na pozici 20. hraciho pole z pozice 2
			}
			if (B == TL5_1)
			{
				//presun figurku na pozici 20. hraciho pole z pozice 3
			}
			if (B == TL6_1)
			{
				//presun figurku na pozici 20. hraciho pole z pozice 4
			}
			if (B == TL7_1)
			{
				//presun figurku na pozici 20. hraciho pole z pozice 5
			}
			if (B == TL8_1)
			{
				//presun figurku na pozici 20. hraciho pole z pozice 6
			}
			if (B == TL9_1)
			{
				//presun figurku na pozici 20. hraciho pole z pozice 7
			}
			if (B == TL10_1)
			{
				//presun figurku na pozici 20. hraciho pole z pozice 8
			}
			if (B == TL11_1)
			{
				//presun figurku na pozici 20. hraciho pole z pozice 9
			}
			if (B == TL12_1)
			{
				//presun figurku na pozici 20. hraciho pole z pozice 10
			}
			if (B == TL13_1)
			{
				//presun figurku na pozici 20. hraciho pole z pozice 11
			}
			if (B == TL14_1)
			{
				//presun figurku na pozici 20. hraciho pole z pozice 12
			}
			if (B == TL15_1)
			{
				naber_na_pozici13();
				syncWait(2000000);
				vyloz_na_pozici20();
				syncWait(2000000);
				//presun figurku na pozici 20. hraciho pole z pozice 13
			}
			if (B == TL16_1)
			{
				naber_na_pozici14();
				syncWait(2000000);
				vyloz_na_pozici20();
				syncWait(2000000);
				//presun figurku na pozici 20. hraciho pole z pozice 14
			}
			if (B == TL17_1)
			{
				naber_na_pozici15();
				syncWait(2000000);
				vyloz_na_pozici20();
				syncWait(2000000);
				//presun figurku na pozici 20. hraciho pole z pozice 15
			}
			if (B == TL18_1)
			{
				naber_na_pozici16();
				syncWait(2000000);
				vyloz_na_pozici20();
				syncWait(2000000);
				//presun figurku na pozici 20. hraciho pole z pozice 16
			}
			if (B == TL19_1)
			{
				naber_na_pozici17();
				syncWait(2000000);
				vyloz_na_pozici20();
				syncWait(2000000);
				//presun figurku na pozici 20. hraciho pole z pozice 17
			}
			if (B == TL20_1)
			{
				naber_na_pozici18();
				syncWait(2000000);
				vyloz_na_pozici20();
				syncWait(2000000);
				//presun figurku na pozici 20. hraciho pole z pozice 18
			}
			if (B == TL21_1)
			{
				naber_na_pozici19();
				syncWait(2000000);
				vyloz_na_pozici20();
				syncWait(2000000);
				//presun figurku na pozici 20. hraciho pole z pozice 19
			}
		}
	}
	if (A == 23)
	{
		if(A == TL23_1)
		{
			if (B == TL0_1)
			{
				//presun figurku na pozici 21. hraciho pole z pozice 30
			}
			if (B == TL1_1)
			{
				//presun figurku na pozici 21. hraciho pole z pozice 31
			}
			if (B == TL2_1)
			{
				//presun figurku na pozici 21. hraciho pole z pozice 32
			}
			if (B == TL3_1)
			{
				//presun figurku na pozici 21. hraciho pole z pozice 1
			}
			if (B == TL4_1)
			{
				//presun figurku na pozici 21. hraciho pole z pozice 2
			}
			if (B == TL5_1)
			{
				//presun figurku na pozici 21. hraciho pole z pozice 3
			}
			if (B == TL6_1)
			{
				//presun figurku na pozici 21. hraciho pole z pozice 4
			}
			if (B == TL7_1)
			{
				//presun figurku na pozici 21. hraciho pole z pozice 5
			}
			if (B == TL8_1)
			{
				//presun figurku na pozici 21. hraciho pole z pozice 6
			}
			if (B == TL9_1)
			{
				//presun figurku na pozici 21. hraciho pole z pozice 7
			}
			if (B == TL10_1)
			{
				//presun figurku na pozici 21. hraciho pole z pozice 8
			}
			if (B == TL11_1)
			{
				//presun figurku na pozici 21. hraciho pole z pozice 9
			}
			if (B == TL12_1)
			{
				//presun figurku na pozici 21. hraciho pole z pozice 10
			}
			if (B == TL13_1)
			{
				//presun figurku na pozici 21. hraciho pole z pozice 11
			}
			if (B == TL14_1)
			{
				//presun figurku na pozici 21. hraciho pole z pozice 12
			}
			if (B == TL15_1)
			{
				//presun figurku na pozici 21. hraciho pole z pozice 13
			}
			if (B == TL16_1)
			{
				naber_na_pozici14();
				syncWait(2000000);
				vyloz_na_pozici21();
				syncWait(2000000);
				//presun figurku na pozici 21. hraciho pole z pozice 14
			}
			if (B == TL17_1)
			{
				naber_na_pozici15();
				syncWait(2000000);
				vyloz_na_pozici21();
				syncWait(2000000);
				//presun figurku na pozici 21. hraciho pole z pozice 15
			}
			if (B == TL18_1)
			{
				naber_na_pozici16();
				syncWait(2000000);
				vyloz_na_pozici21();
				syncWait(2000000);
				//presun figurku na pozici 21. hraciho pole z pozice 16
			}
			if (B == TL19_1)
			{
				naber_na_pozici17();
				syncWait(2000000);
				vyloz_na_pozici21();
				syncWait(2000000);
				//presun figurku na pozici 21. hraciho pole z pozice 17
			}
			if (B == TL20_1)
			{
				naber_na_pozici18();
				syncWait(2000000);
				vyloz_na_pozici21();
				syncWait(2000000);
				//presun figurku na pozici 21. hraciho pole z pozice 18
			}
			if (B == TL21_1)
			{
				naber_na_pozici19();
				syncWait(2000000);
				vyloz_na_pozici21();
				syncWait(2000000);
				//presun figurku na pozici 21. hraciho pole z pozice 19
			}
			if (B == TL22_1)
			{
				naber_na_pozici20();
				syncWait(2000000);
				vyloz_na_pozici21();
				syncWait(2000000);
				//presun figurku na pozici 21. hraciho pole z pozice 20
			}
		}
	}
	if (A == 24)
	{
		if(A == TL24_1)
		{
			if (B == TL0_1)
			{
				//presun figurku na pozici 22. hraciho pole z pozice 30
			}
			if (B == TL1_1)
			{
				//presun figurku na pozici 22. hraciho pole z pozice 31
			}
			if (B == TL2_1)
			{
				//presun figurku na pozici 22. hraciho pole z pozice 32
			}
			if (B == TL3_1)
			{
				//presun figurku na pozici 22. hraciho pole z pozice 1
			}
			if (B == TL4_1)
			{
				//presun figurku na pozici 22. hraciho pole z pozice 2
			}
			if (B == TL5_1)
			{
				//presun figurku na pozici 22. hraciho pole z pozice 3
			}
			if (B == TL6_1)
			{
				//presun figurku na pozici 22. hraciho pole z pozice 4
			}
			if (B == TL7_1)
			{
				//presun figurku na pozici 22. hraciho pole z pozice 5
			}
			if (B == TL8_1)
			{
				//presun figurku na pozici 22. hraciho pole z pozice 6
			}
			if (B == TL9_1)
			{
				//presun figurku na pozici 22. hraciho pole z pozice 7
			}
			if (B == TL10_1)
			{
				//presun figurku na pozici 22. hraciho pole z pozice 8
			}
			if (B == TL11_1)
			{
				//presun figurku na pozici 22. hraciho pole z pozice 9
			}
			if (B == TL12_1)
			{
				//presun figurku na pozici 22. hraciho pole z pozice 10
			}
			if (B == TL13_1)
			{
				//presun figurku na pozici 22. hraciho pole z pozice 11
			}
			if (B == TL14_1)
			{
				//presun figurku na pozici 22. hraciho pole z pozice 12
			}
			if (B == TL15_1)
			{
				//presun figurku na pozici 22. hraciho pole z pozice 13
			}
			if (B == TL16_1)
			{
				//presun figurku na pozici 22. hraciho pole z pozice 14
			}
			if (B == TL17_1)
			{
				naber_na_pozici15();
				syncWait(2000000);
				vyloz_na_pozici22();
				syncWait(2000000);
				//presun figurku na pozici 22. hraciho pole z pozice 15
			}
			if (B == TL18_1)
			{
				naber_na_pozici16();
				syncWait(2000000);
				vyloz_na_pozici22();
				syncWait(2000000);
				//presun figurku na pozici 22. hraciho pole z pozice 16
			}
			if (B == TL19_1)
			{
				naber_na_pozici17();
				syncWait(2000000);
				vyloz_na_pozici22();
				syncWait(2000000);
				//presun figurku na pozici 22. hraciho pole z pozice 17
			}
			if (B == TL20_1)
			{
				naber_na_pozici18();
				syncWait(2000000);
				vyloz_na_pozici22();
				syncWait(2000000);
				//presun figurku na pozici 22. hraciho pole z pozice 18
			}
			if (B == TL21_1)
			{
				naber_na_pozici19();
				syncWait(2000000);
				vyloz_na_pozici22();
				syncWait(2000000);
				//presun figurku na pozici 22. hraciho pole z pozice 19
			}
			if (B == TL22_1)
			{
				naber_na_pozici20();
				syncWait(2000000);
				vyloz_na_pozici22();
				syncWait(2000000);
				//presun figurku na pozici 22. hraciho pole z pozice 20
			}
			if (B == TL23_1)
			{
				naber_na_pozici21();
				syncWait(2000000);
				vyloz_na_pozici22();
				syncWait(2000000);
				//presun figurku na pozici 22. hraciho pole z pozice 21
			}
		}
	}
	if (A == 25)
	{
		if(A == TL25_1)
		{
			if (B == TL0_1)
			{
				//presun figurku na pozici 23. hraciho pole z pozice 30
			}
			if (B == TL1_1)
			{
				//presun figurku na pozici 23. hraciho pole z pozice 31
			}
			if (B == TL2_1)
			{
				//presun figurku na pozici 23. hraciho pole z pozice 32
			}
			if (B == TL3_1)
			{
				//presun figurku na pozici 23. hraciho pole z pozice 1
			}
			if (B == TL4_1)
			{
				//presun figurku na pozici 23. hraciho pole z pozice 2
			}
			if (B == TL5_1)
			{
				//presun figurku na pozici 23. hraciho pole z pozice 3
			}
			if (B == TL6_1)
			{
				//presun figurku na pozici 23. hraciho pole z pozice 4
			}
			if (B == TL7_1)
			{
				//presun figurku na pozici 23. hraciho pole z pozice 5
			}
			if (B == TL8_1)
			{
				//presun figurku na pozici 23. hraciho pole z pozice 6
			}
			if (B == TL9_1)
			{
				//presun figurku na pozici 23. hraciho pole z pozice 7
			}
			if (B == TL10_1)
			{
				//presun figurku na pozici 23. hraciho pole z pozice 8
			}
			if (B == TL11_1)
			{
				//presun figurku na pozici 23. hraciho pole z pozice 9
			}
			if (B == TL12_1)
			{
				//presun figurku na pozici 23. hraciho pole z pozice 10
			}
			if (B == TL13_1)
			{
				//presun figurku na pozici 23. hraciho pole z pozice 11
			}
			if (B == TL14_1)
			{
				//presun figurku na pozici 23. hraciho pole z pozice 12
			}
			if (B == TL15_1)
			{
				//presun figurku na pozici 23. hraciho pole z pozice 13
			}
			if (B == TL16_1)
			{
				//presun figurku na pozici 23. hraciho pole z pozice 14
			}
			if (B == TL17_1)
			{
				//presun figurku na pozici 23. hraciho pole z pozice 15
			}
			if (B == TL18_1)
			{
				naber_na_pozici16();
				syncWait(2000000);
				vyloz_na_pozici23();
				syncWait(2000000);
				//presun figurku na pozici 23. hraciho pole z pozice 16
			}
			if (B == TL19_1)
			{
				naber_na_pozici17();
				syncWait(2000000);
				vyloz_na_pozici23();
				syncWait(2000000);
				//presun figurku na pozici 23. hraciho pole z pozice 17
			}
			if (B == TL20_1)
			{
				naber_na_pozici18();
				syncWait(2000000);
				vyloz_na_pozici23();
				syncWait(2000000);
				//presun figurku na pozici 23. hraciho pole z pozice 18
			}
			if (B == TL21_1)
			{
				naber_na_pozici19();
				syncWait(2000000);
				vyloz_na_pozici23();
				syncWait(2000000);
				//presun figurku na pozici 23. hraciho pole z pozice 19
			}
			if (B == TL22_1)
			{
				naber_na_pozici20();
				syncWait(2000000);
				vyloz_na_pozici23();
				syncWait(2000000);
				//presun figurku na pozici 23. hraciho pole z pozice 20
			}
			if (B == TL23_1)
			{
				naber_na_pozici21();
				syncWait(2000000);
				vyloz_na_pozici23();
				syncWait(2000000);
				//presun figurku na pozici 23. hraciho pole z pozice 21
			}
			if (B == TL24_1)
			{
				naber_na_pozici22();
				syncWait(2000000);
				vyloz_na_pozici23();
				syncWait(2000000);
				//presun figurku na pozici 23. hraciho pole z pozice 22
			}
		}
	}
	if (A == 26)
	{
		if(A == TL26_1)
		{
			if (B == TL0_1)
			{
				//presun figurku na pozici 24. hraciho pole z pozice 30
			}
			if (B == TL1_1)
			{
				//presun figurku na pozici 24. hraciho pole z pozice 31
			}
			if (B == TL2_1)
			{
				//presun figurku na pozici 24. hraciho pole z pozice 32
			}
			if (B == TL3_1)
			{
				//presun figurku na pozici 24. hraciho pole z pozice 1
			}
			if (B == TL4_1)
			{
				//presun figurku na pozici 24. hraciho pole z pozice 2
			}
			if (B == TL5_1)
			{
				//presun figurku na pozici 24. hraciho pole z pozice 3
			}
			if (B == TL6_1)
			{
				//presun figurku na pozici 24. hraciho pole z pozice 4
			}
			if (B == TL7_1)
			{
				//presun figurku na pozici 24. hraciho pole z pozice 5
			}
			if (B == TL8_1)
			{
				//presun figurku na pozici 24. hraciho pole z pozice 6
			}
			if (B == TL9_1)
			{
				//presun figurku na pozici 24. hraciho pole z pozice 7
			}
			if (B == TL10_1)
			{
				//presun figurku na pozici 24. hraciho pole z pozice 8
			}
			if (B == TL11_1)
			{
				//presun figurku na pozici 24. hraciho pole z pozice 9
			}
			if (B == TL12_1)
			{
				//presun figurku na pozici 24. hraciho pole z pozice 10
			}
			if (B == TL13_1)
			{
				//presun figurku na pozici 24. hraciho pole z pozice 11
			}
			if (B == TL14_1)
			{
				//presun figurku na pozici 24. hraciho pole z pozice 12
			}
			if (B == TL15_1)
			{
				//presun figurku na pozici 24. hraciho pole z pozice 13
			}
			if (B == TL16_1)
			{
				//presun figurku na pozici 24. hraciho pole z pozice 14
			}
			if (B == TL17_1)
			{
				//presun figurku na pozici 24. hraciho pole z pozice 15
			}
			if (B == TL18_1)
			{
				//presun figurku na pozici 24. hraciho pole z pozice 16
			}
			if (B == TL19_1)
			{
				naber_na_pozici17();
				syncWait(2000000);
				vyloz_na_pozici24();
				syncWait(2000000);
				//presun figurku na pozici 24. hraciho pole z pozice 17
			}
			if (B == TL20_1)
			{
				naber_na_pozici18();
				syncWait(2000000);
				vyloz_na_pozici24();
				syncWait(2000000);
				//presun figurku na pozici 24. hraciho pole z pozice 18
			}
			if (B == TL21_1)
			{
				naber_na_pozici19();
				syncWait(2000000);
				vyloz_na_pozici24();
				syncWait(2000000);
				//presun figurku na pozici 24. hraciho pole z pozice 19
			}
			if (B == TL22_1)
			{
				naber_na_pozici20();
				syncWait(2000000);
				vyloz_na_pozici24();
				syncWait(2000000);
				//presun figurku na pozici 24. hraciho pole z pozice 20
			}
			if (B == TL23_1)
			{
				naber_na_pozici21();
				syncWait(2000000);
				vyloz_na_pozici24();
				syncWait(2000000);
				//presun figurku na pozici 24. hraciho pole z pozice 21
			}
			if (B == TL24_1)
			{
				naber_na_pozici22();
				syncWait(2000000);
				vyloz_na_pozici24();
				syncWait(2000000);
				//presun figurku na pozici 24. hraciho pole z pozice 22
			}
			if (B == TL25_1)
			{
				naber_na_pozici23();
				syncWait(2000000);
				vyloz_na_pozici24();
				syncWait(2000000);
				//presun figurku na pozici 24. hraciho pole z pozice 23
			}
		}
	}
	if (A == 27)
	{
		if(A == TL27_1)
		{
			if (B == TL0_1)
			{
				//presun figurku na pozici 25. hraciho pole z pozice 30
			}
			if (B == TL1_1)
			{
				//presun figurku na pozici 25. hraciho pole z pozice 31
			}
			if (B == TL2_1)
			{
				//presun figurku na pozici 25. hraciho pole z pozice 32
			}
			if (B == TL3_1)
			{
				//presun figurku na pozici 25. hraciho pole z pozice 1
			}
			if (B == TL4_1)
			{
				//presun figurku na pozici 25. hraciho pole z pozice 2
			}
			if (B == TL5_1)
			{
				//presun figurku na pozici 25. hraciho pole z pozice 3
			}
			if (B == TL6_1)
			{
				//presun figurku na pozici 25. hraciho pole z pozice 4
			}
			if (B == TL7_1)
			{
				//presun figurku na pozici 25. hraciho pole z pozice 5
			}
			if (B == TL8_1)
			{
				//presun figurku na pozici 25. hraciho pole z pozice 6
			}
			if (B == TL9_1)
			{
				//presun figurku na pozici 25. hraciho pole z pozice 7
			}
			if (B == TL10_1)
			{
				//presun figurku na pozici 25. hraciho pole z pozice 8
			}
			if (B == TL11_1)
			{
				//presun figurku na pozici 25. hraciho pole z pozice 9
			}
			if (B == TL12_1)
			{
				//presun figurku na pozici 25. hraciho pole z pozice 10
			}
			if (B == TL13_1)
			{
				//presun figurku na pozici 25. hraciho pole z pozice 11
			}
			if (B == TL14_1)
			{
				//presun figurku na pozici 25. hraciho pole z pozice 12
			}
			if (B == TL15_1)
			{
				//presun figurku na pozici 25. hraciho pole z pozice 13
			}
			if (B == TL16_1)
			{
				//presun figurku na pozici 25. hraciho pole z pozice 14
			}
			if (B == TL17_1)
			{
				//presun figurku na pozici 25. hraciho pole z pozice 15
			}
			if (B == TL18_1)
			{
				//presun figurku na pozici 25. hraciho pole z pozice 16
			}
			if (B == TL19_1)
			{
				//presun figurku na pozici 25. hraciho pole z pozice 17
			}
			if (B == TL20_1)
			{
				naber_na_pozici18();
				syncWait(2000000);
				vyloz_na_pozici25();
				syncWait(2000000);
				//presun figurku na pozici 25. hraciho pole z pozice 18
			}
			if (B == TL21_1)
			{
				naber_na_pozici19();
				syncWait(2000000);
				vyloz_na_pozici25();
				syncWait(2000000);
				//presun figurku na pozici 25. hraciho pole z pozice 19
			}
			if (B == TL22_1)
			{
				naber_na_pozici20();
				syncWait(2000000);
				vyloz_na_pozici25();
				syncWait(2000000);
				//presun figurku na pozici 25. hraciho pole z pozice 20
			}
			if (B == TL23_1)
			{
				naber_na_pozici21();
				syncWait(2000000);
				vyloz_na_pozici25();
				syncWait(2000000);
				//presun figurku na pozici 25. hraciho pole z pozice 21
			}
			if (B == TL24_1)
			{
				naber_na_pozici22();
				syncWait(2000000);
				vyloz_na_pozici25();
				syncWait(2000000);
				//presun figurku na pozici 25. hraciho pole z pozice 22
			}
			if (B == TL25_1)
			{
				naber_na_pozici23();
				syncWait(2000000);
				vyloz_na_pozici25();
				syncWait(2000000);
				//presun figurku na pozici 25. hraciho pole z pozice 23
			}
			if (B == TL26_1)
			{
				naber_na_pozici24();
				syncWait(2000000);
				vyloz_na_pozici25();
				syncWait(2000000);
				//presun figurku na pozici 25. hraciho pole z pozice 24
			}
		}
	}
	if (A == 28)
	{
		if(A == TL28_1)
		{
			if (B == TL0_1)
			{
				//presun figurku na pozici 26. hraciho pole z pozice 30
			}
			if (B == TL1_1)
			{
				//presun figurku na pozici 26. hraciho pole z pozice 31
			}
			if (B == TL2_1)
			{
				//presun figurku na pozici 26. hraciho pole z pozice 32
			}
			if (B == TL3_1)
			{
				//presun figurku na pozici 26. hraciho pole z pozice 1
			}
			if (B == TL4_1)
			{
				//presun figurku na pozici 26. hraciho pole z pozice 2
			}
			if (B == TL5_1)
			{
				//presun figurku na pozici 26. hraciho pole z pozice 3
			}
			if (B == TL6_1)
			{
				//presun figurku na pozici 26. hraciho pole z pozice 4
			}
			if (B == TL7_1)
			{
				//presun figurku na pozici 26. hraciho pole z pozice 5
			}
			if (B == TL8_1)
			{
				//presun figurku na pozici 26. hraciho pole z pozice 6
			}
			if (B == TL9_1)
			{
				//presun figurku na pozici 26. hraciho pole z pozice 7
			}
			if (B == TL10_1)
			{
				//presun figurku na pozici 26. hraciho pole z pozice 8
			}
			if (B == TL11_1)
			{
				//presun figurku na pozici 26. hraciho pole z pozice 9
			}
			if (B == TL12_1)
			{
				//presun figurku na pozici 26. hraciho pole z pozice 10
			}
			if (B == TL13_1)
			{
				//presun figurku na pozici 26. hraciho pole z pozice 11
			}
			if (B == TL14_1)
			{
				//presun figurku na pozici 26. hraciho pole z pozice 12
			}
			if (B == TL15_1)
			{
				//presun figurku na pozici 26. hraciho pole z pozice 13
			}
			if (B == TL16_1)
			{
				//presun figurku na pozici 26. hraciho pole z pozice 14
			}
			if (B == TL17_1)
			{
				//presun figurku na pozici 26. hraciho pole z pozice 15
			}
			if (B == TL18_1)
			{
				//presun figurku na pozici 26. hraciho pole z pozice 16
			}
			if (B == TL19_1)
			{
				//presun figurku na pozici 26. hraciho pole z pozice 17
			}
			if (B == TL20_1)
			{
				//presun figurku na pozici 26. hraciho pole z pozice 18
			}
			if (B == TL21_1)
			{
				naber_na_pozici19();
				syncWait(2000000);
				vyloz_na_pozici26();
				syncWait(2000000);
				//presun figurku na pozici 26. hraciho pole z pozice 19
			}
			if (B == TL22_1)
			{
				naber_na_pozici20();
				syncWait(2000000);
				vyloz_na_pozici26();
				syncWait(2000000);
				//presun figurku na pozici 26. hraciho pole z pozice 20
			}
			if (B == TL23_1)
			{
				naber_na_pozici21();
				syncWait(2000000);
				vyloz_na_pozici26();
				syncWait(2000000);
				//presun figurku na pozici 26. hraciho pole z pozice 21
			}
			if (B == TL24_1)
			{
				naber_na_pozici22();
				syncWait(2000000);
				vyloz_na_pozici26();
				syncWait(2000000);
				//presun figurku na pozici 26. hraciho pole z pozice 22
			}
			if (B == TL25_1)
			{
				naber_na_pozici23();
				syncWait(2000000);
				vyloz_na_pozici26();
				syncWait(2000000);
				//presun figurku na pozici 26. hraciho pole z pozice 23
			}
			if (B == TL26_1)
			{
				naber_na_pozici24();
				syncWait(2000000);
				vyloz_na_pozici26();
				syncWait(2000000);
				//presun figurku na pozici 26. hraciho pole z pozice 24
			}
			if (B == TL27_1)
			{
				naber_na_pozici25();
				syncWait(2000000);
				vyloz_na_pozici26();
				syncWait(2000000);
				//presun figurku na pozici 26. hraciho pole z pozice 25
			}
		}
	}
	if (A == 29)
	{
		if(A == TL29_1)
		{
			if (B == TL0_1)
			{
				//presun figurku na pozici 27. hraciho pole z pozice 30
			}
			if (B == TL1_1)
			{
				//presun figurku na pozici 27. hraciho pole z pozice 31
			}
			if (B == TL2_1)
			{
				//presun figurku na pozici 27. hraciho pole z pozice 32
			}
			if (B == TL3_1)
			{
				//presun figurku na pozici 27. hraciho pole z pozice 1
			}
			if (B == TL4_1)
			{
				//presun figurku na pozici 27. hraciho pole z pozice 2
			}
			if (B == TL5_1)
			{
				//presun figurku na pozici 27. hraciho pole z pozice 3
			}
			if (B == TL6_1)
			{
				//presun figurku na pozici 27. hraciho pole z pozice 4
			}
			if (B == TL7_1)
			{
				//presun figurku na pozici 27. hraciho pole z pozice 5
			}
			if (B == TL8_1)
			{
				//presun figurku na pozici 27. hraciho pole z pozice 6
			}
			if (B == TL9_1)
			{
				//presun figurku na pozici 27. hraciho pole z pozice 7
			}
			if (B == TL10_1)
			{
				//presun figurku na pozici 27. hraciho pole z pozice 8
			}
			if (B == TL11_1)
			{
				//presun figurku na pozici 27. hraciho pole z pozice 9
			}
			if (B == TL12_1)
			{
				//presun figurku na pozici 27. hraciho pole z pozice 10
			}
			if (B == TL13_1)
			{
				//presun figurku na pozici 27. hraciho pole z pozice 11
			}
			if (B == TL14_1)
			{
				//presun figurku na pozici 27. hraciho pole z pozice 12
			}
			if (B == TL15_1)
			{
				//presun figurku na pozici 27. hraciho pole z pozice 13
			}
			if (B == TL16_1)
			{
				//presun figurku na pozici 27. hraciho pole z pozice 14
			}
			if (B == TL17_1)
			{
				//presun figurku na pozici 27. hraciho pole z pozice 15
			}
			if (B == TL18_1)
			{
				//presun figurku na pozici 27. hraciho pole z pozice 16
			}
			if (B == TL19_1)
			{
				//presun figurku na pozici 27. hraciho pole z pozice 17
			}
			if (B == TL20_1)
			{
				//presun figurku na pozici 27. hraciho pole z pozice 18
			}
			if (B == TL21_1)
			{
				//presun figurku na pozici 27. hraciho pole z pozice 19
			}
			if (B == TL22_1)
			{
				naber_na_pozici20();
				syncWait(2000000);
				vyloz_na_pozici27();
				syncWait(2000000);
				//presun figurku na pozici 27. hraciho pole z pozice 20
			}
			if (B == TL23_1)
			{
				naber_na_pozici21();
				syncWait(2000000);
				vyloz_na_pozici27();
				syncWait(2000000);
				//presun figurku na pozici 27. hraciho pole z pozice 21
			}
			if (B == TL24_1)
			{
				naber_na_pozici22();
				syncWait(2000000);
				vyloz_na_pozici27();
				syncWait(2000000);
				//presun figurku na pozici 27. hraciho pole z pozice 22
			}
			if (B == TL25_1)
			{
				naber_na_pozici23();
				syncWait(2000000);
				vyloz_na_pozici27();
				syncWait(2000000);
				//presun figurku na pozici 27. hraciho pole z pozice 23
			}
			if (B == TL26_1)
			{
				naber_na_pozici24();
				syncWait(2000000);
				vyloz_na_pozici27();
				syncWait(2000000);
				//presun figurku na pozici 27. hraciho pole z pozice 24
			}
			if (B == TL27_1)
			{
				naber_na_pozici25();
				syncWait(2000000);
				vyloz_na_pozici27();
				syncWait(2000000);
				//presun figurku na pozici 27. hraciho pole z pozice 25
			}
			if (B == TL28_1)
			{
				naber_na_pozici26();
				syncWait(2000000);
				vyloz_na_pozici27();
				syncWait(2000000);
				//presun figurku na pozici 27. hraciho pole z pozice 26
			}
		}
	}
	if (A == 30)
	{
		if(A == TL30_1)
		{
			if (B == TL0_1)
			{
				//presun figurku na pozici 28. hraciho pole z pozice 30
			}
			if (B == TL1_1)
			{
				//presun figurku na pozici 28. hraciho pole z pozice 31
			}
			if (B == TL2_1)
			{
				//presun figurku na pozici 28. hraciho pole z pozice 32
			}
			if (B == TL3_1)
			{
				//presun figurku na pozici 28. hraciho pole z pozice 1
			}
			if (B == TL4_1)
			{
				//presun figurku na pozici 28. hraciho pole z pozice 2
			}
			if (B == TL5_1)
			{
				//presun figurku na pozici 28. hraciho pole z pozice 3
			}
			if (B == TL6_1)
			{
				//presun figurku na pozici 28. hraciho pole z pozice 4
			}
			if (B == TL7_1)
			{
				//presun figurku na pozici 28. hraciho pole z pozice 5
			}
			if (B == TL8_1)
			{
				//presun figurku na pozici 28. hraciho pole z pozice 6
			}
			if (B == TL9_1)
			{
				//presun figurku na pozici 28. hraciho pole z pozice 7
			}
			if (B == TL10_1)
			{
				//presun figurku na pozici 28. hraciho pole z pozice 8
			}
			if (B == TL11_1)
			{
				//presun figurku na pozici 28. hraciho pole z pozice 9
			}
			if (B == TL12_1)
			{
				//presun figurku na pozici 28. hraciho pole z pozice 10
			}
			if (B == TL13_1)
			{
				//presun figurku na pozici 28. hraciho pole z pozice 11
			}
			if (B == TL14_1)
			{
				//presun figurku na pozici 28. hraciho pole z pozice 12
			}
			if (B == TL15_1)
			{
				//presun figurku na pozici 28. hraciho pole z pozice 13
			}
			if (B == TL16_1)
			{
				//presun figurku na pozici 28. hraciho pole z pozice 14
			}
			if (B == TL17_1)
			{
				//presun figurku na pozici 28. hraciho pole z pozice 15
			}
			if (B == TL18_1)
			{
				//presun figurku na pozici 28. hraciho pole z pozice 16
			}
			if (B == TL19_1)
			{
				//presun figurku na pozici 28. hraciho pole z pozice 17
			}
			if (B == TL20_1)
			{
				//presun figurku na pozici 28. hraciho pole z pozice 18
			}
			if (B == TL21_1)
			{
				//presun figurku na pozici 28. hraciho pole z pozice 19
			}
			if (B == TL22_1)
			{
				//presun figurku na pozici 28. hraciho pole z pozice 20
			}
			if (B == TL23_1)
			{
				naber_na_pozici21();
				syncWait(2000000);
				vyloz_na_pozici28();
				syncWait(2000000);
				//presun figurku na pozici 28. hraciho pole z pozice 21
			}
			if (B == TL24_1)
			{
				naber_na_pozici22();
				syncWait(2000000);
				vyloz_na_pozici28();
				syncWait(2000000);
				//presun figurku na pozici 28. hraciho pole z pozice 22
			}
			if (B == TL25_1)
			{
				naber_na_pozici23();
				syncWait(2000000);
				vyloz_na_pozici28();
				syncWait(2000000);
				//presun figurku na pozici 28. hraciho pole z pozice 23
			}
			if (B == TL26_1)
			{
				naber_na_pozici24();
				syncWait(2000000);
				vyloz_na_pozici28();
				syncWait(2000000);
				//presun figurku na pozici 28. hraciho pole z pozice 24
			}
			if (B == TL27_1)
			{
				naber_na_pozici25();
				syncWait(2000000);
				vyloz_na_pozici28();
				syncWait(2000000);
				//presun figurku na pozici 28. hraciho pole z pozice 25
			}
			if (B == TL28_1)
			{
				naber_na_pozici26();
				syncWait(2000000);
				vyloz_na_pozici28();
				syncWait(2000000);
				//presun figurku na pozici 28. hraciho pole z pozice 26
			}
			if (B == TL29_1)
			{
				naber_na_pozici27();
				syncWait(2000000);
				vyloz_na_pozici28();
				syncWait(2000000);
				//presun figurku na pozici 28. hraciho pole z pozice 27
			}
		}
	}
	if (A == 31)
	{
		if(A == TL31_1)
		{
			if (B == TL0_1)
			{
				//presun figurku na pozici 29. hraciho pole z pozice 30
			}
			if (B == TL1_1)
			{
				//presun figurku na pozici 29. hraciho pole z pozice 31
			}
			if (B == TL2_1)
			{
				//presun figurku na pozici 29. hraciho pole z pozice 32
			}
			if (B == TL3_1)
			{
				//presun figurku na pozici 29. hraciho pole z pozice 1
			}
			if (B == TL4_1)
			{
				//presun figurku na pozici 29. hraciho pole z pozice 2
			}
			if (B == TL5_1)
			{
				//presun figurku na pozici 29. hraciho pole z pozice 3
			}
			if (B == TL6_1)
			{
				//presun figurku na pozici 29. hraciho pole z pozice 4
			}
			if (B == TL7_1)
			{
				//presun figurku na pozici 29. hraciho pole z pozice 5
			}
			if (B == TL8_1)
			{
				//presun figurku na pozici 29. hraciho pole z pozice 6
			}
			if (B == TL9_1)
			{
				//presun figurku na pozici 29. hraciho pole z pozice 7
			}
			if (B == TL10_1)
			{
				//presun figurku na pozici 29. hraciho pole z pozice 8
			}
			if (B == TL11_1)
			{
				//presun figurku na pozici 29. hraciho pole z pozice 9
			}
			if (B == TL12_1)
			{
				//presun figurku na pozici 29. hraciho pole z pozice 10
			}
			if (B == TL13_1)
			{
				//presun figurku na pozici 29. hraciho pole z pozice 11
			}
			if (B == TL14_1)
			{
				//presun figurku na pozici 29. hraciho pole z pozice 12
			}
			if (B == TL15_1)
			{
				//presun figurku na pozici 29. hraciho pole z pozice 13
			}
			if (B == TL16_1)
			{
				//presun figurku na pozici 29. hraciho pole z pozice 14
			}
			if (B == TL17_1)
			{
				//presun figurku na pozici 29. hraciho pole z pozice 15
			}
			if (B == TL18_1)
			{
				//presun figurku na pozici 29. hraciho pole z pozice 16
			}
			if (B == TL19_1)
			{
				//presun figurku na pozici 29. hraciho pole z pozice 17
			}
			if (B == TL20_1)
			{
				//presun figurku na pozici 29. hraciho pole z pozice 18
			}
			if (B == TL21_1)
			{
				//presun figurku na pozici 29. hraciho pole z pozice 19
			}
			if (B == TL22_1)
			{
				//presun figurku na pozici 29. hraciho pole z pozice 20
			}
			if (B == TL23_1)
			{
				//presun figurku na pozici 29. hraciho pole z pozice 21
			}
			if (B == TL24_1)
			{
				naber_na_pozici22();
				syncWait(2000000);
				vyloz_na_pozici29();
				syncWait(2000000);
				//presun figurku na pozici 29. hraciho pole z pozice 22
			}
			if (B == TL25_1)
			{
				naber_na_pozici23();
				syncWait(2000000);
				vyloz_na_pozici29();
				syncWait(2000000);
				//presun figurku na pozici 29. hraciho pole z pozice 23
			}
			if (B == TL26_1)
			{
				naber_na_pozici24();
				syncWait(2000000);
				vyloz_na_pozici29();
				syncWait(2000000);
				//presun figurku na pozici 29. hraciho pole z pozice 24
			}
			if (B == TL27_1)
			{
				naber_na_pozici25();
				syncWait(2000000);
				vyloz_na_pozici29();
				syncWait(2000000);
				//presun figurku na pozici 29. hraciho pole z pozice 25
			}
			if (B == TL28_1)
			{
				naber_na_pozici26();
				syncWait(2000000);
				vyloz_na_pozici29();
				syncWait(2000000);
				//presun figurku na pozici 29. hraciho pole z pozice 26
			}
			if (B == TL29_1)
			{
				naber_na_pozici27();
				syncWait(2000000);
				vyloz_na_pozici29();
				syncWait(2000000);
				//presun figurku na pozici 29. hraciho pole z pozice 27
			}
			if (B == TL30_1)
			{
				naber_na_pozici28();
				syncWait(2000000);
				vyloz_na_pozici29();
				syncWait(2000000);
				//presun figurku na pozici 29. hraciho pole z pozice 28
			}
		}
	}
	if (A >= 32)
	{
		if(A >= TL31_1)
		{
		
			if (B == TL24_1)
			{
				naber_na_pozici22();
				syncWait(2000000);
				vyloz_na_pozici_chlivek1();
				syncWait(2000000);
				//presun figurku do chlivku hraciho pole z pozice 26
			}
			if (B == TL25_1)
			{
				naber_na_pozici23();
				syncWait(2000000);
				vyloz_na_pozici_chlivek1();
				syncWait(2000000);
				//presun figurku do chlivku hraciho pole z pozice 27
			}
			if (B == TL26_1)
			{
				naber_na_pozici24();
				syncWait(2000000);
				vyloz_na_pozici_chlivek1();
				syncWait(2000000);
				//presun figurku do chlivku hraciho pole z pozice 28
			}
			if (B == TL27_1)
			{
				naber_na_pozici25();
				syncWait(2000000);
				vyloz_na_pozici_chlivek1();
				syncWait(2000000);
				//presun figurku do chlivku hraciho pole z pozice 29
			}
			if (B == TL28_1)
			{
				naber_na_pozici26();
				syncWait(2000000);
				vyloz_na_pozici_chlivek1();
				syncWait(2000000);
				//presun figurku do chlivku hraciho pole z pozice 30
			}
			if (B == TL29_1)
			{
				naber_na_pozici27();
				syncWait(2000000);
				vyloz_na_pozici_chlivek1();
				syncWait(2000000);
				//presun figurku do chlivku hraciho pole z pozice 31
			}
			if (B == TL30_1)
			{
				naber_na_pozici28();
				syncWait(2000000);
				vyloz_na_pozici_chlivek1();
				syncWait(2000000);
				//presun figurku do chlivku hraciho pole z pozice 31
			}
			if (B == TL31_1)
			{
				naber_na_pozici29();
				syncWait(2000000);
				vyloz_na_pozici_chlivek1();
				syncWait(2000000);
				//presun figurku do chlivku hraciho pole z pozice 31
			}
		}
	}
}


void kalkulace_tahu_clovek()
{
	if (D == 32)
	{
		D = 0;
	}
	if (C == 17)//figurka na pozici TL17_1
	{
		D = TL17_1;
	}
	if (C == 18)//figurka na pozici TL18_1
	{
		D = TL18_1;
	}
	if (C == 19)//figurka na pozici TL19_1
	{
		D = TL19_1;
	}
	if (C == 20)//figurka na pozici TL20_1
	{
		D = TL20_1;
	}
	if (C == 21)//figurka na pozici TL21_1
	{
		D = TL21_1;
	}
	if (C == 22)//figurka na pozici TL22_1
	{
		D = TL22_1;
	}	
	if (C == 23)//figurka na pozici TL23_1
	{
		D = TL23_1;
	}
	if (C == 24)//figurka na pozici TL24_1
	{
		D = TL24_1;
	}
	if (C == 25)//figurka na pozici TL25_1
	{
		D = TL25_1;
	}
	if (C == 26)//figurka na pozici TL26_1
	{
		D = TL26_1;
	}
	if (C == 27)//figurka na pozici TL27_1
	{
		D = TL27_1;
	}
	if (C == 28)//figurka na pozici TL28_1
	{
		D = TL28_1;
	}
	if (C == 29)//figurka na pozici TL29_1
	{
		D = TL29_1;
	}
	if (C == 30)//figurka na pozici TL30_1
	{
		D = TL30_1;
	}
	if (C == 31)//figurka na pozici TL31_1
	{
		D = TL31_1;
	}
	if (C == 0)//figurka na pozici TL0_1
	{
		D = TL0_1;
	}
	if (C == 1)//figurka na pozici TL1_1
	{
		D = TL1_1;
	}
	if (C == 2)//figurka na pozici TL2_1
	{
		D = TL2_1;
	}
	if (C == 3)//figurka na pozici TL3_1
	{
		D = TL3_1;
	}
	if (C == 4)//figurka na pozici TL4_1
	{
		D = TL4_1;
	}
	if (C == 5)//figurka na pozici TL5_1
	{
		D = TL5_1;
	}
	if (C == 6)//figurka na pozici TL6_1
	{
		D = TL6_1;
	}
	if (C == 7)//figurka na pozici TL7_1
	{
		D = TL7_1;
	}
	if (C == 8)//figurka na pozici TL8_1
	{
		D = TL8_1;
	}
	if (C == 9)//figurka na pozici TL9_1
	{
		D = TL9_1;
	}
	if (C == 10)//figurka na pozici TL10_1
	{
		D = TL10_1;
	}
	if (C == 11)//figurka na pozici TL11_1
	{
		D = TL11_1;
	}
	if (C == 12)//figurka na pozici TL12_1
	{
		D = TL12_1;
	}
	if (C == 13)//figurka na pozici TL13_1
	{
		D = TL13_1;
	}
	if (C == 14)//figurka na pozici TL14_1
	{
		D = TL14_1;
	}
	if (C == 15)//figurka na pozici TL15_1
	{
		D = TL15_1;
	}
	if (C == 16)//figurka na pozici TL16_1
	{
		D = TL16_1;
	}
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
	motor [1]. torqueLimit (1023);
	motor [2]. torqueLimit (1023);
	motor [3]. torqueLimit (1023);
	motor [4]. torqueLimit (1023);
	motor [5]. torqueLimit (1023);
}
void rychlost()
{	
	
	motor[1].speed(50);
	motor[2].speed(50);
	motor[3].speed(50);
	motor[4].speed(50);
	motor[5].speed(50);
	motor[6].speed(50);
	motor[7].speed(50);
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

void chlivek_start_robot()//presune figurku z chlivku na start robota
{
	zakladni_pozice();
	chlivek_robot_pozice33();
}

void zjisteni_pozice()
{
	if (A == 0)
	{
		naber_na_pozici30();
		chlivek_clovek_pozice39();
	}
	if (A == 1)
	{
		naber_na_pozici31();
		chlivek_clovek_pozice39();
	}
	
	if (A == 2)
	{
		naber_na_pozici32();
		chlivek_clovek_pozice39();
	}

	if (A == 3)
	{
		naber_na_pozici1();
		chlivek_clovek_pozice39();
	}
	
	if (A == 4)
	{
		naber_na_pozici2();
		chlivek_clovek_pozice39();
	}
	
	if (A == 5)
	{
		naber_na_pozici3();
		chlivek_clovek_pozice39();
	}
	
	if (A == 6)
	{
		naber_na_pozici4();
		chlivek_clovek_pozice39();
	}
	
	if (A == 7)
	{
		naber_na_pozici5();
		chlivek_clovek_pozice39();
	}
	
	if (A == 8)
	{
		naber_na_pozici6();
		chlivek_clovek_pozice39();
	}
	
	if (A == 9)
	{
		naber_na_pozici7();
		chlivek_clovek_pozice39();
	}
	
	if (A == 10)
	{
		naber_na_pozici8();
		chlivek_clovek_pozice39();
	}
	
	if (A == 11)
	{
		naber_na_pozici9();
		chlivek_clovek_pozice39();
	}
	
	if (A == 12)
	{
		naber_na_pozici10();
		chlivek_clovek_pozice39();
	}
	
	if (A == 13)
	{
		naber_na_pozici11();
		chlivek_clovek_pozice39();
	}
	
	if (A == 14)
	{
		naber_na_pozici12();
		chlivek_clovek_pozice39();
	}
	
	if (A == 15)
	{
		naber_na_pozici13();
		chlivek_clovek_pozice39();
	}
	
	if (A == 16)
	{
		naber_na_pozici14();
		chlivek_clovek_pozice39();
	}
	
	if (A == 17)
	{
		naber_na_pozici15();
		chlivek_clovek_pozice39();
	}
	
	if (A == 18)
	{
		naber_na_pozici16();
		chlivek_clovek_pozice39();
	}
	
	if (A == 19)
	{
		naber_na_pozici17();
		chlivek_clovek_pozice39();
	}
	
	if (A == 20)
	{
		naber_na_pozici18();
		chlivek_clovek_pozice39();
	}
	
	if (A == 21)
	{
		naber_na_pozici19();
		chlivek_clovek_pozice39();
	}
	
	if (A == 22)
	{
		naber_na_pozici20();
		chlivek_clovek_pozice39();
	}
	
	if (A == 23)
	{
		naber_na_pozici21();
		chlivek_clovek_pozice39();
	}
	
	if (A == 24)
	{
		naber_na_pozici22();
		chlivek_clovek_pozice39();
	}
	
	if (A == 25)
	{
		naber_na_pozici23();
		chlivek_clovek_pozice39();
	}
	
	if (A == 26)
	{
		naber_na_pozici24();
		chlivek_clovek_pozice39();
	}
	
	if (A == 27)
	{
		naber_na_pozici25();
		chlivek_clovek_pozice39();
	}
	
	if (A == 28)
	{
		naber_na_pozici26();
		chlivek_clovek_pozice39();
	}
	
	if (A == 29)
	{
		naber_na_pozici27();
		chlivek_clovek_pozice39();
	}
	
	if (A == 30)
	{
		naber_na_pozici28();
		chlivek_clovek_pozice39();
	}
	
	if (A == 31)
	{
		naber_na_pozici29();
		chlivek_clovek_pozice39();
	}
}
void pozice_512()//vsechny serva do pozice 512
{
	motor[1].position(512);
	motor[2].position(512);
	motor[3].position(512);
	motor[4].position(512);
	motor[5].position(512);
	motor[6].position(512);
	motor[7].position(512);

}
void vyhod_preddefinovano()
{
	naber_na_pozici25();
	syncWait(2000000);
	chlivek_clovek_pozice39();
	syncWait(2000000);
	naber_na_pozici22();
	syncWait(2000000);
	vyloz_na_pozici25();
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


void hra()
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
void hra2()
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

void rotace ()
{
	motor[1].position (1022);
	syncWait(10000000);
	motor[1].position (2);
	syncWait(10000000);
}
void run()
{
	pc << "run" << endl;
	A = 0;
	B = 0;
	C = 16;
	D = 16;
	F1_0 = 0;
	F1_1 = 0;
	uint8_t tlacitka[5] = {0,0,0,0,0};
//	led.aux(1);
	definice();
	rychlost();
	sila();
	char x;
	for(;;)
		{
		hra();
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



