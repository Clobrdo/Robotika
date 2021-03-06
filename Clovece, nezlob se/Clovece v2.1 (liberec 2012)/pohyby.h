/*
 * pohyby.h
 * Knihovna pro Clovece, nezlob se
 * Created: 22.9.2012 20:35:06
 *  Author: Ale� Pernik��, Ji�� Kyzlink
*/

#include <util/delay.h>

#define	rychlost_motoru			250
#define pocet_motoru			7
#define kostka					((TCNT0 % 6)+1)
#define DelayPriPolozeni		400
#define delka_ramena1			66
#define delka_ramena2			94
#define delka_ramena3			66
#define delka_ramena4			50
#define M_PI_6					0.5235987755983
	
uint8_t kostka_hod;	
uint8_t i=0;		//promn�n� do smy�ek
uint8_t i2=0;		//-------||----------
bool pole_fig[41]{};
uint8_t curr_pos[4]{33,34,40,39};
	
const uint16_t VychoziPozice[7] PROGMEM ={512,556,167,975,651,486,548};
const bool ledky[3][6]{{false, false, false, true, true, true},{false, true, true, false, false, true},{true, false, true, false, true, false}};

const uint16_t Motor_1[41] PROGMEM =
{
//0		1		2		3		4		5		6.587	7.554	8.510	9.468	10		11		12		13		14		15		16		17		18		19		20		21		22		23		24		25		26		27		28		29		30		31		32		chl_R1	chl_R2	dom_R1	domR2	chl_HR1	chl_HR2
512,	164,	124,	88,		50,		14,		1099,	1066,	1022,	468,	428,	1014,	972,	935,	892,	858,	819,	777,	742,	698,	660,	624,	585,	552,	509,	469,	430,	395,	357,	319,	280,	244,	205,	176,	220,	196,	199,	811,	811,	833,	791
};

const uint16_t PohybyOstaniMotory[4][18] PROGMEM =
{
//Klasicke pozice		Nezasahnute pozice		Chlivek					Domecek_dal				Domecek_blize				Presun
//NadF	ZacNakl	PolF	NadF	ZacNakl	NadF	NadCH	PolF	...		NadCH	PolF	NadF	NadCH	ZacN	NadF
{351,	334,	252,	769,	758,	807,	340,	260,	235,	610,	610,	610,	663,	822,	826,	516,	739,	726},
{812,	808,	811,	167,	201,	201,	723,	765,	766,	396,	396,	285,	359, 	199,	171,	520,	167,	166},
{201,	270,	275,	764,	760,	760,	330,	360,	365,	312,	312,	361,	394,	419,	305,	505,	866,	749},
{182,	182,	187,	817,	788,	788,	203,	204,	210,	229,	229,	220,	201,	163,	238,	200,	166,	860}
};

const uint16_t hodnoty_rychlost[7] PROGMEM=
{
rychlost_motoru,	//1
rychlost_motoru,	//2
rychlost_motoru,	//3
rychlost_motoru,	//4
rychlost_motoru,	//5
rychlost_motoru,	//6
rychlost_motoru		//7
};

void inicializace()
{
	TCCR0 |= (1 << CS00);
}

void povol()
{
	for(i=0; i!=pocet_motoru; i++)
	{
		motor[i+1].clearTorque();
	}
}

void cekej()
{
	uint8_t icekej=1;
	_delay_ms(170);
	while(icekej!=pocet_motoru)
	{
		if (motor[icekej].present_speed()==0)	{icekej++;}
	}
}

void nastav_torque()
{
	for(i=0; i!=pocet_motoru; i++)
	{
		motor[i+1].torqueLimit(1000);
	}
	for(i=0; i!=pocet_motoru; i++)
	{
		motor[i+1].setTorque();
	}
	cekej();
}

void nastav_rychlost(uint8_t delitel)	//cim vyssi je delitel tim pomaleji to jede
{
	for(i=0; i!=pocet_motoru; i++)
	{
		motor[i+1].speed((pgm_read_word(&(hodnoty_rychlost[(i)]))/delitel));
	}
}

void zakladni_pozice()					// nastavi motory do zakladni pozice
{
	for(i=0; i!=pocet_motoru; i++)
	{
		motor[i+1].position(pgm_read_word(&(VychoziPozice[(i)])));
	}
	cekej();
}

void PoziceM1(uint8_t c_pozice)			//nastavi pozici motoru 1 dle c. pozice
{
	motor[1].position(pgm_read_word(&(Motor_1[c_pozice])));
	cekej();
}

/*void PoziceM1_P(uint16_t pozice5, uint8_t rychlost)
{
	motor[1].speed(1023);
	//pc<<"plynule"<<endl;
	uint16_t puvod = motor[1].position();
	int tmp = pozice5-puvod;
	double pozice_motoru;
	for (i2=0;i2!=91;i2++)
	{
		pozice_motoru=(sin(i2*0.0174532925)*tmp)+puvod;
		motor[1].position(int(pozice_motoru));
		_delay_us(1024-(tmp*3));
	}
	motor[1].speed(rychlost_motoru);
}
*/
void otevri()							//otevrit celisti
{		
	motor[6].position(486);
	motor[7].position(548);
	cekej();
}

void zavri(bool poradne)							//zavrit celisti
{
	if (poradne)
	{
		motor[6].position(540);
		motor[7].position(480);
	}
	else
	{
		motor[6].position(509);
		motor[7].position(515);		
	}
	cekej();
}

void naberpoloz(uint8_t c_pozice, bool naber, uint8_t c_cilove_pozice)
{
	if (c_cilove_pozice>=3 && c_cilove_pozice<=16)
	{
		if (motor[2].position()<512)
		{	
			nastav_rychlost(1);
			
			motor[5].position(pgm_read_word(&(PohybyOstaniMotory[3][3])));
			motor[4].position(pgm_read_word(&(PohybyOstaniMotory[2][3])));
			motor[2].position(512);
			motor[3].position(pgm_read_word(&(PohybyOstaniMotory[1][3])));			
			cekej();
		}
		if (c_pozice>=24)
		{
			PoziceM1(c_pozice-16);
		}
		else
		{
			PoziceM1(c_pozice+16);
		}
		for (i2=3; i2!=6; i2++)
		{
			nastav_rychlost(i2-2);
			for (i=2; i!=6; i++)
			{
				motor[i].position(pgm_read_word(&(PohybyOstaniMotory[(i-2)][i2])));
			}
			cekej();
			if (i2==4 && !naber)
			{
				zavri(false);
				_delay_ms(DelayPriPolozeni);
			}
		}
		cekej();
		otevri();
		if (naber)
		{
			cekej();
			zavri(true);
		}
		for (i=2; i!=6; i++)
		{
			motor[i].position(pgm_read_word(&(PohybyOstaniMotory[(i-2)][3])));
		}
		cekej();
	}	
	else if ((c_pozice>=33 && c_pozice<=34)||(c_pozice>=39 && c_pozice<=40))
	{
		PoziceM1(c_pozice);
		for (i2=6; i2!=9; i2++)
		{
			nastav_rychlost(i2-2);
			for (i=2; i!=6; i++)
			{
				motor[i].position(pgm_read_word(&(PohybyOstaniMotory[(i-2)][i2])));
			}
			if (i2==7 && !naber)
			{
				zavri(false);
				_delay_ms(DelayPriPolozeni);
			}
			cekej();
		}
		cekej();
		otevri();
		if (naber)
		{
			cekej();
			zavri(true);
		}
		for (i=2; i!=6; i++)
		{
			motor[i].position(pgm_read_word(&(PohybyOstaniMotory[(i-2)][6])));
		}
		cekej();
	}
	else if(c_pozice==35 || c_pozice==38)
	{
		PoziceM1(c_pozice);
		for (i2=9; i2!=12; i2++)
		{
			nastav_rychlost(i2-8);
			for (i=2; i!=6; i++)
			{
				motor[i].position(pgm_read_word(&(PohybyOstaniMotory[(i-2)][i2])));
			}
			cekej();
			if (i2==10 && !naber)
			{
				zavri(false);
				_delay_ms(DelayPriPolozeni);
			}
		}
		cekej();		
		otevri();
		if (naber)
		{
			cekej();
			zavri(true);
		}
		cekej();
		for (i=2; i!=6; i++)
		{
			motor[i].position(pgm_read_word(&(PohybyOstaniMotory[(i-2)][10])));
		}	
		cekej();	
	}
	else if(c_pozice==36 || c_pozice==37)
	{
		PoziceM1(c_pozice);
		for (i2=12; i2!=15; i2++)
		{
			nastav_rychlost(i2-11);
			for (i=2; i!=6; i++)
			{
				motor[i].position(pgm_read_word(&(PohybyOstaniMotory[(i-2)][i2])));
			}
			cekej();
			if (i2==13 && !naber)
			{
				zavri(false);
				_delay_ms(DelayPriPolozeni);
			}
		}
		cekej();
		otevri();
		if (naber)
		{
			cekej();
			zavri(true);
		}
		cekej();
		for (i=2; i!=6; i++)
		{
			motor[i].position(pgm_read_word(&(PohybyOstaniMotory[(i-2)][13])));
		}
		cekej();
	}
	else
	{
		PoziceM1(c_pozice);		
		if (motor[2].position()>512)
		{
			for (i=2; i!=6; i++)
			{
				motor[i].position(pgm_read_word(&(PohybyOstaniMotory[(i-2)][0])));
			}
			motor[2].position(512);
			cekej();
		}	
		for (i2=0; i2!=3; i2++)
		{
			nastav_rychlost(i2+1);			
			for (i=2; i!=6; i++)
			{
				motor[i].position(pgm_read_word(&(PohybyOstaniMotory[(i-2)][i2])));
			}
			cekej();
			if (i2==1 && !naber)
			{
				zavri(false);
				_delay_ms(DelayPriPolozeni);
			}
		}
		cekej();
		otevri();
		if (naber)
		{
			cekej();
			zavri(true);
		}
		for (i=2; i!=6; i++)
		{
			motor[i].position(pgm_read_word(&(PohybyOstaniMotory[(i-2)][0])));
		}
		cekej();
	}
	nastav_rychlost(1);
}	

void presun(uint8_t zdroj, uint8_t cil)
{
	pc<<"Probiha presun z pozice "<<zdroj<<" na pozici "<<cil<<endl;
	naberpoloz(zdroj, true, cil);
	naberpoloz(cil, false, cil);	
}
void vyhod(uint8_t c_pozice, uint8_t curr_fig)
{
	for(int i=0;i!=4;i++)
	{
		if((curr_pos[i]==curr_pos[curr_fig])&&(curr_fig!=i))
		{
			switch(i)
			{
				case 0:curr_pos[0]=33;break;
				case 1:curr_pos[1]=34;break;
				case 2:curr_pos[2]=40;break;
				case 3:curr_pos[3]=39;break;
			}
		}
	}
	if(curr_fig<=1)
	{
		if(!pole_fig[40])
		{
			presun(c_pozice, 40);
		}
		else
		{
			presun(c_pozice, 39);
		}
	}
	else
	{
		if(!pole_fig[34])
		{
			presun(c_pozice, 34);
		}
		else
		{
			presun(c_pozice, 33);
		}
	}
}

bool check_hraci_pole()
{
	bool vysledek=false;
	for (i=1; i!=32; i++)
	{
		if(pole_fig[i]) {i=31; vysledek=true;}
	}
	return vysledek;
}

uint8_t aktualizuj_hraci_pole()	//p�idat dal�� funkci, kter� zkontroluje, zda hodnoty v curr_pos[] odpov�daj� skute�nosti
{
	uint8_t chyba_policko = 0, temp_pozice = 0, pocet_fig=0, cislo;
	pc.sendChar(127);
	for (i=0; i!=5; i++)
	{
		temp_pozice = pc.get();
		for (i2=0; i2!=8; i2++)
		{
			cislo=i*8+i2+1;
			if (cislo<=29)
			{
				cislo+=3;
			}
			else if(cislo>29 && cislo<=32)
			{
				cislo-=29;
			}
			pole_fig[cislo]=temp_pozice%2;
			temp_pozice/=2;
		}
	}
	for(i=0;i<=3;i++)
	{
		if(!pole_fig[curr_pos[i]])
		{
			chyba_policko=curr_pos[i];
		}
	}
	for(i=1;i<=40;i++)
	{
		if(pole_fig[i])
		{
			pocet_fig++;
		}			
	}
	if(pocet_fig>4)
	{
		chyba_policko=50;
	}
	else if(pocet_fig<4)
	{
		chyba_policko=51;
	}
	return chyba_policko;
}	

uint8_t check_pribylo()
{
	for(int i=0;i<=40;i++)
	{
		if(pole_fig[i])
		{
			if((curr_pos[0]!=i)&&(curr_pos[1]!=i)&&(curr_pos[2]!=i)&&(curr_pos[3]!=i))
			{
				return i;
			}
		}
	}
	return 0;
}

void test_pozice()
{
	uint16_t pozice_moturu[7]={512,	512, 512, 512, 512, 512, 512};
	for(i=1;i!=7;i++)
	{
		pozice_moturu[i-1]=motor[i].position();
	}
	while(true)
	{
		pc<<"Testovani pozic: "<<endl;
		char x;
		x=pc.get();
		switch(x)
		{
			case 'd':pozice_moturu[0]-=3;motor[1].position(pozice_moturu[0]);break;
			case 'e':pozice_moturu[0]+=3;motor[1].position(pozice_moturu[0]);break;
			case 'f':pozice_moturu[1]-=3;motor[2].position(pozice_moturu[1]);break;
			case 'r':pozice_moturu[1]+=3;motor[2].position(pozice_moturu[1]);break;
			case 'g':pozice_moturu[2]-=3;motor[3].position(pozice_moturu[2]);break;
			case 't':pozice_moturu[2]+=3;motor[3].position(pozice_moturu[2]);break;
			case 'h':pozice_moturu[3]-=3;motor[4].position(pozice_moturu[3]);break;
			case 'z':pozice_moturu[3]+=3;motor[4].position(pozice_moturu[3]);break;
			case 'j':pozice_moturu[4]-=3;motor[5].position(pozice_moturu[4]);break;
			case 'u':pozice_moturu[4]+=3;motor[5].position(pozice_moturu[4]);break;
			case 'k':pozice_moturu[5]-=3;motor[6].position(pozice_moturu[5]);motor[7].position(1024-pozice_moturu[5]);break;
			case 'i':pozice_moturu[5]+=3;motor[6].position(pozice_moturu[5]);motor[7].position(1024-pozice_moturu[5]);break;
			case 'q':povol();break;
			case 'w':nastav_torque();break;
			case 'a':for(i=1;i<7;i++)pc<<"Motor"<<i<<":"<<motor[i].position()<<endl<<endl;for(i=1;i!=7;i++)pozice_moturu[i-1]=motor[i].position();break;
			case 'v':aktualizuj_hraci_pole();break;
		}
	}
}
