/*
 * pohyby.h
 *
 * Created: 22.9.2012 20:35:06
 *  Author: jirka1
*/

#include <util/delay.h>

#define	rychlost_motoru			150
#define pocet_motoru			7
#define	speed_koef				0,8
#define kostka					((TCNT0 % 6)+1)
#define SETBIT(ADDRESS,BIT)		(ADDRESS |= (1<<BIT)) 
#define CHECKBIT(ADDRESS,BIT)	((ADDRESS & (1<<BIT))!=0) 
#define CLEARBIT(ADDRESS,BIT)	(ADDRESS &= ~(1<<BIT)) 
#define CHECKPOLICKO(BIT)		CHECKBIT(hraci_pole,BIT)
#define DOMECEK(BIT)			CHECKBIT(promena_DOMECEK,BIT)
	
uint8_t i=0;		//promnìná do smyèek
uint8_t i2=0;		//-------||----------
uint32_t hraci_pole=0;			//cudliky na poli
uint8_t promena_DOMECEK=0;		//cudliky v domecku

const uint16_t VychoziPozice[7] PROGMEM =
{
512,
605,
39,	
977,
688,
486,
548
};

const uint16_t Motor_1[38] PROGMEM =
{
//0		1		2		3		4		5		6		7		8		9		10		11		12		13		14		15		16		17		18		19		20		21		22		23		24		25		26		27		28		29		30		31		32		ch1		chC39	chR33	chR34	chC40
512,	50,		14,		587,	554,	510,	468,	428,	1014,	972,	935,	892,	858,	819,	780,	743,	700,	659,	626,	589,	548,	510,	470,	434,	392,	352,	316,	283,	239,	202,	168,	126,	88,		198,	838,	168,	168,	788
};

const uint16_t PohybyOstaniMotory[4][15] PROGMEM =
{
//Klasicke pozice		Nezasahnute pozice		Chlivek 39, 40			Chlivek 33				Chlivek34
//NadF	ZacNakl	NadF	NadF	ZacNakl	NadF	NadCH	PolF	...		NadCH	PolF	NadF	NadCH	ZacN	NadF
{605,	460,	460,	605,	610,	540,	521,	500,	450,	605,	592,	180,	605,	592,	415},
{39,	488,	448,	39,		530,	621,	459,	440,	440,	39,		302,	415,	39, 	302,	447},
{977,	372,	320,	977,	689,	687,	343,	457,	457,	977,	411,	447,	977,	411,	477},
{688,	170,	248,	688,	792,	715,	287,	180,	190,	688,	214,	170,	688,	214,	170}
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

uint8_t curr_pos[4]
{
 0,	1,	8,	9		
};

void inicializace()
{
	TCCR0 |= (1 << CS00);
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

void nastav_rychlost()
{
	for(i=0; i!=pocet_motoru; i++)
	{
		motor[i+1].speed(pgm_read_word(&(hodnoty_rychlost[(i)])));
	}
}

void zakladni_pozice()
{
	for(i=0; i!=pocet_motoru; i++)
	{
		motor[i+1].position(pgm_read_word(&(VychoziPozice[(i)])));
	}
	cekej();
}

void povol()
{
	for(i=0; i!=pocet_motoru; i++)
	{
		motor[i+1].clearTorque();
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

void PoziceM1(uint8_t c_pozice)
{
	motor[1].position(pgm_read_word(&(Motor_1[c_pozice])));
	cekej();
}

void otevri()		//otevrit celisti
{
	motor[6].position(486);
	motor[7].position(548);
	cekej();
}

void zavri()		//zavrit celisti
{
	motor[6].position(520);
	motor[7].position(504);
	cekej();
}

void naberpoloz(uint8_t c_pozice, bool naber)
{
	PoziceM1(c_pozice);
	if (c_pozice<8 && c_pozice>2)
	{
		pc<<"nezasahnute"<<endl;
		for (i2=4; i2!=6; i2++)
		{
			for (i=2; i!=8; i++)
			{
				motor[i].position(pgm_read_word(&(PohybyOstaniMotory[(i-2)][i2])));
			}
			cekej();
		}
		otevri();
		if (naber)
		{
			zavri();
		}
		for (i=2; i!=8; i++)
		{
			motor[i].position(pgm_read_word(&(PohybyOstaniMotory[(i-2)][4])));
		}
		cekej();		
	} 
	else
	{
		for (i2=1; i2!=3; i2++)
		{
			for (i=2; i!=8; i++)
			{
				motor[i].position(pgm_read_word(&(PohybyOstaniMotory[(i-2)][i2])));
			}
			cekej();
		}
		otevri();
		if (naber)
		{
			zavri();
		}
		for (i=2; i!=8; i++)
		{
			motor[i].position(pgm_read_word(&(PohybyOstaniMotory[(i-2)][1])));
		}
		cekej();
	}
}	

void naber(uint8_t c_pozice)
{
	naberpoloz(c_pozice, true);
}

void poloz(uint8_t c_pozice)
{
	naberpoloz(c_pozice, false);
}

/*void naber()
{	
	//otoci se nad figurku
	motor[2].position(605);
	motor[3].position(39);
	motor[4].position(977);
	motor[5].position(688);

	syncWait(3500000);
	//nad chlivkem  otevre celisti
	motor[2].position(605);
	motor[3].position(39);
	motor[4].position(977);
	motor[5].position(688);

	syncWait(1000000);
	//zacne se naklanet
	motor[2].position(460);
	motor[3].position(448);
	motor[4].position(372);
	motor[5].position(170);
	
	syncWait(3000000);
	//nakloni se nad figurku
	motor[2].position(460);
	motor[3].position(448);
	motor[4].position(320);
	motor[5].position(248);

	syncWait(3000000);
	//nad figurkou zavre celisti
	motor[2].position(460);
	motor[3].position(453);
	motor[4].position(320);
	motor[5].position(248);

	syncWait(1000000);
	//narovna rameno
	motor[2].position(500);
	motor[3].position(700);
	motor[4].position(314);
	motor[5].position(248);

	syncWait(3000000);
}*/

void nasad_robot()
{
	otevri();
	if(DOMECEK(0))
	{
		//PoziceM1();
		curr_pos[0]=8;
	}		
	else
	{
		//PoziceM1();
		curr_pos[1]=8;
	}	
	zavri();
	PoziceM1(8);
	otevri();
}

bool check_hraci_pole()
{
	bool vysledek=false;
	for (i=1; i!=32; i++)
	{
		if(CHECKPOLICKO(i)) {i=31; vysledek=true;}
	}
	return vysledek;
}

void zapis_domecek(uint8_t BIT,bool VAL)
{
	if (VAL)
	{
		SETBIT(promena_DOMECEK, BIT);
	}
	else CLEARBIT(promena_DOMECEK, BIT);
}

uint8_t aktualizuj_hraci_pole()	//pøidat další funkci, která zkontroluje, zda hodnoty v curr_pos[] odpovídají skuteènosti
{
	uint8_t temp_pozice = 0;
	for (i=0; i!=4; i++)
	{
		temp_pozice  = pc.get(); 
		pc<<temp_pozice<<endl;
		for (i2=0; i2!=8; i2++)
		{
			if (CHECKBIT(temp_pozice,i2)==1)	{SETBIT  (hraci_pole,i*8+i2);}			
			if (CHECKBIT(temp_pozice,i2)==0)	{CLEARBIT(hraci_pole,i*8+i2);}			 		
			pc<<((temp_pozice & (1 << i2)) != 0)<<"_";
		}
		pc<<hraci_pole<<endl;
	}
	
	for (i=0; i!=1; i++)
	{
		temp_pozice  = pc.get();
		pc<<temp_pozice<<endl;
		for (i2=0; i2!=8; i2++)
		{
			zapis_domecek(i2,((temp_pozice & (1 << i2)) != 0));
			pc<<((temp_pozice & (1 << i2)) != 0)<<"_";
		}
		pc<<promena_DOMECEK<<endl<<endl;
	}
	
	for (i=0; i!=32; i++)
	{
		pc<<CHECKBIT(hraci_pole,i);
	}
	pc<endl;	
	//______________________-=kontrola=-_______________
	uint64_t hraci_pole_kontrola = 0;
	uint64_t curr_pos_kontrola = 0;
	uint8_t cislo_policka_chyba = 0;
		
	hraci_pole_kontrola = (hraci_pole+(promena_DOMECEK*4294967296));	
	for (i=0; i!=4; i++)
	{
		SETBIT(curr_pos_kontrola,curr_pos[i]);
	}
	
	i=0;
	while ((CHECKBIT(curr_pos_kontrola,i)==CHECKBIT(hraci_pole_kontrola,i)) && i!=40)
	{
		i++;
	}	
	if (i!=40)
	{
		cislo_policka_chyba=i;
	}
	else cislo_policka_chyba = 0;
	return cislo_policka_chyba;	
}		
