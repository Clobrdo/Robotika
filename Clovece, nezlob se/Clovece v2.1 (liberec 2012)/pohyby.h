/*
 * pohyby.h
 *
 * Created: 22.9.2012 20:35:06
 *  Author: jirka1
*/

#include <util/delay.h>

#define	rychlost_motoru			200
#define pocet_motoru			7
#define kostka					((TCNT0 % 6)+1)
#define SETBIT(ADDRESS,BIT)		(ADDRESS |= (1<<BIT)) 
#define CHECKBIT(ADDRESS,BIT)	((ADDRESS & (1<<BIT))!=0) 
#define CLEARBIT(ADDRESS,BIT)	(ADDRESS &= ~(1<<BIT)) 
#define CHECKPOLICKO(BIT)		CHECKBIT(hraci_pole,BIT)
#define DOMECEK(BIT)			CHECKBIT(promena_DOMECEK,BIT)
#define delka_ramena1			94
#define delka_ramena2			94
#define delka_ramena3			94
#define M_PI_6					0.5235987755983
	
uint8_t i=0;		//promnìná do smyèek
uint8_t i2=0;		//-------||----------
uint32_t hraci_pole=0;			//cudliky na poli
uint8_t promena_DOMECEK=0;		//cudliky v domecku

const uint16_t VychoziPozice[7] PROGMEM =
{
512,
556,
167,	
975,
651,
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
//Klasicke pozice		Nezasahnute pozice		Chlivek_1_R				Domecek_1_R				Domecek 1_R
//NadF	ZacNakl	PolF	NadF	ZacNakl	NadF	NadCH	PolF	...		NadCH	PolF	NadF	NadCH	ZacN	NadF
{351,	334,	290,	610,	610,	747,	241,	241,	241,	559,	559,	652,	605,	592,	415},
{812,	808,	811,	530,	530,	161,	756,	756,	756,	467,	467,	244,	39, 	302,	447},
{201,	270,	270,	689,	689,	760,	393,	393,	295,	202,	202,	346,	977,	411,	477},
{182,	182,	183,	792,	792,	851,	181,	181,	254,	245,	245,	190,	688,	214,	170}
};

/*
const uint16_t PohybyOstaniMotory[4][15] PROGMEM =
{
//Klasicke pozice		Nezasahnute pozice		Chlivek 39, 40			Chlivek 33				Chlivek34
//NadF	ZacNakl	NadF	NadF	ZacNakl	NadF	NadCH	PolF	...		NadCH	PolF	NadF	NadCH	ZacN	NadF
{605,	460,	460,	605,	610,	540,	521,	500,	450,	605,	592,	180,	605,	592,	415},
{39,	488,	448,	39,		530,	621,	459,	440,	440,	39,		302,	415,	39, 	302,	447},
{977,	372,	320,	977,	689,	687,	343,	457,	457,	977,	411,	447,	977,	411,	477},
{688,	170,	248,	688,	792,	715,	287,	180,	190,	688,	214,	170,	688,	214,	170}
};*/

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

void test_pozice()
{
	uint16_t pozice_moturu[7]
	{512,	512,	512,	512,	512,	512,	512};
	for(i=1;i!=7;i++)
	{
		pozice_moturu[i-1]=motor[i].position();
	}
	while(true)
	{
		
		
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
		}
	}	
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

void otevri()							//otevrit celisti
{		
	motor[6].position(486);
	motor[7].position(548);
	cekej();
}

void zavri()							//zavrit celisti
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
		for (i2=3; i2!=6; i2++)
		{
			for (i=2; i!=6; i++)
			{
				motor[i].position(pgm_read_word(&(PohybyOstaniMotory[(i-2)][i2])));
			}
			cekej();
			nastav_rychlost(i2-2);
		}
		otevri();
		if (naber)
		{
			zavri();
		}
		for (i=2; i!=6; i++)
		{
			motor[i].position(pgm_read_word(&(PohybyOstaniMotory[(i-2)][3])));
		}
		cekej();		
	} 
	else
	{
		for (i2=0; i2!=3; i2++)
		{
			for (i=2; i!=6; i++)
			{
				motor[i].position(pgm_read_word(&(PohybyOstaniMotory[(i-2)][i2])));
			}
			cekej();
			nastav_rychlost(i2+1);
		}
		otevri();
		if (naber)
		{
			zavri();
		}
		for (i=2; i!=6; i++)
		{
			motor[i].position(pgm_read_word(&(PohybyOstaniMotory[(i-2)][0])));
		}
		cekej();
	}
	nastav_rychlost(1);
}	

void naber(uint8_t c_pozice)				//nabere figurku na pozici
{
	naberpoloz(c_pozice, true);
}

void poloz(uint8_t c_pozice)				//polozi figurku na pozici
{
	naberpoloz(c_pozice, false);
}

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

void pohyb_na_bod2(float Xt, float Yt, float Zt)
{
	uint16_t pozice_motor0;
	uint16_t pozice_motor1;
	uint16_t pozice_motor2;
	uint16_t pozice_motor3;
	uint16_t B_term;
	int a0_term;
	int a1_term;
	int a2_term;
	int a3_term;
	int a4_term;
	int a5_term;
	int a6_term;
	int a7_term;
	uint16_t B;
	uint16_t B2;
	uint16_t B_22;
	double a0;
	double a1;	
	double a2;
	double a3;	//uhel ramena
	double a4;	//uhel loktu
	double a5;	
	double a6;
	double a7;	//uhel zapesti
	
	B2=sqrt(pow(Xt,2)+pow(Zt,2));
	B=sqrt(pow(B2,2)+pow(Yt,2));
	B_22=pow((B/2),2);
	a0=atan2(Zt,Xt);	
	a1=acos((pow(delka_ramena1,1)-pow(delka_ramena1,2)+B_22)/(2*delka_ramena1*(B/2)));
	a2=atan2(Yt,Xt);
	a3=a1+a2;
	a4=acos((pow(delka_ramena1,2)+pow(delka_ramena2,2)-B_22)/(2*delka_ramena1*delka_ramena1));
	a5=acos((pow(delka_ramena2,2)+pow(delka_ramena2,2)-pow(delka_ramena1,2))/(2*delka_ramena2*delka_ramena2));
	a6=acos((pow(delka_ramena2,2)+pow(delka_ramena2,2)-B_22)/(2*delka_ramena2*delka_ramena3));
	a7=a5+a6;
	
	pozice_motor0=(((((5*M_PI)/6)+a0)*180/M_PI)*3.4133333);
	pozice_motor1=((((M_PI/6)+a3)*180/M_PI)*3.4133333);
	pozice_motor2=((((a4+a5)-(M_PI/6))*180/M_PI)*3.4133333);
	pozice_motor3=(((a7-(M_PI/6))*180/M_PI)*3.4133333);
	
	motor[1].position(pozice_motor0);
	motor[2].position(pozice_motor1);
	motor[3].position(pozice_motor2);
	motor[4].position(pozice_motor3);
	
	
	a0_term=a0*180/M_PI;
	/*a1_term=a1*180/M_PI;
	a2_term=a2*180/M_PI;
	a3_term=a3*180/M_PI;
	a4_term=a4*180/M_PI;
	a5_term=a5*180/M_PI;
	a6_term=a6*180/M_PI;
	a7_term=a7*180/M_PI;
	
	pc<<"B "<<B<<endl;*/
	pc<<"A0 "<<a0_term<<endl;/*
	pc<<"A1 "<<a1_term<<endl;
	pc<<"A2 "<<a2_term<<endl;
	pc<<"A3 "<<a3_term<<endl;
	pc<<"A4 "<<a4_term<<endl;
	pc<<"A5 "<<a5_term<<endl;
	pc<<"A6 "<<a6_term<<endl;
	pc<<"A7 "<<a7_term<<endl;
	
	pc<<"Pozice 1:"<<pozice_motor1<<endl;
	pc<<"Pozice 2:"<<pozice_motor2<<endl;
	pc<<"Pozice 3:"<<pozice_motor3<<endl;*/
}	

/*void pohyb_na_bod2(float Xt, float Yt)
{
	uint16_t pozice_motor1;
	uint16_t pozice_motor2;
	uint16_t pozice_motor3;
	uint16_t B_term;
	int a1_term;
	int a2_term;
	int a3_term;
	int a4_term;
	int a5_term;
	int a6_term;
	int a7_term;
	uint16_t B;
	uint16_t B_22;
	double a1;	
	double a2;
	double a3;	//uhel ramena
	double a4;	//uhel loktu
	double a5;	
	double a6;
	double a7;	//uhel zapesti
	
	B=sqrt(pow(Xt,2)+pow(Yt,2));
	B_22=pow((B/2),2);	
	a1=acos((pow(delka_ramena1,1)-pow(delka_ramena1,2)+B_22)/(2*delka_ramena1*(B/2)));
	a2=atan2(Yt,Xt);
	a3=a1+a2;
	a4=acos((pow(delka_ramena1,2)+pow(delka_ramena2,2)-B_22)/(2*delka_ramena1*delka_ramena1));
	a5=acos((pow(delka_ramena2,2)+pow(delka_ramena2,2)-pow(delka_ramena1,2))/(2*delka_ramena2*delka_ramena2));
	a6=acos((pow(delka_ramena2,2)+pow(delka_ramena2,2)-B_22)/(2*delka_ramena2*delka_ramena3));
	a7=a5+a6;
	
	pozice_motor1=((((M_PI/6)+a3)*180/M_PI)*3.4133333);
	pozice_motor2=((((a4+a5)-(M_PI/6))*180/M_PI)*3.4133333);
	pozice_motor3=(((a7-(M_PI/6))*180/M_PI)*3.4133333);
	
	motor[2].position(pozice_motor1);
	motor[3].position(pozice_motor2);
	motor[4].position(pozice_motor3);
	
	a1_term=a1*180/M_PI;
	a2_term=a2*180/M_PI;
	a3_term=a3*180/M_PI;
	a4_term=a4*180/M_PI;
	a5_term=a5*180/M_PI;
	a6_term=a6*180/M_PI;
	a7_term=a7*180/M_PI;
	
	pc<<"B "<<B<<endl;
	pc<<"A1 "<<a1_term<<endl;
	pc<<"A2 "<<a2_term<<endl;
	pc<<"A3 "<<a3_term<<endl;
	pc<<"A4 "<<a4_term<<endl;
	pc<<"A5 "<<a5_term<<endl;
	pc<<"A6 "<<a6_term<<endl;
	pc<<"A7 "<<a7_term<<endl;
	
	pc<<"Pozice 1:"<<pozice_motor1<<endl;
	pc<<"Pozice 2:"<<pozice_motor2<<endl;
	pc<<"Pozice 3:"<<pozice_motor3<<endl;
}*/

void pohyb_na_bod(float Xt, float Yt)
{
	uint16_t pozice_motor1;
	uint16_t pozice_motor2;
	uint16_t B_term;
	int alfa_term;
	int beta_term;
	int gamma_term;
	int delta_term;
	int B;
	double alfa;
	double beta;
	double gamma;
	double delta;
	
	B=sqrt(pow(Xt,2)+pow(Yt,2));		
	alfa=atan2(Yt,Xt);	
	beta=acos((pow(delka_ramena1,2)-pow(delka_ramena2,2)+pow(B,2))/(2*delka_ramena2*B));	
	gamma=alfa+beta;
	delta=acos((pow(delka_ramena1,2)+pow(delka_ramena2,2)-pow(B,2))/(2*delka_ramena1*delka_ramena2));
	pozice_motor1=((((M_PI/3)+gamma)*180/M_PI)*3.4133333);
	pozice_motor2=(((((M_PI/3)+delta-(M_PI_2))*180/M_PI))*3.4133333);	
	motor[2].position(pozice_motor1);
	motor[3].position(pozice_motor2);
	
	//B_term=B*1000;	
	alfa_term=alfa*180/M_PI;
	beta_term=beta*180/M_PI;
	gamma_term=gamma*180/M_PI;
	delta_term=delta*180/M_PI;
	pc<<B<<endl;
	pc<<"alfa je:"<<alfa_term<<endl;
	pc<<"beta je:"<<beta_term<<endl;
	pc<<"gamma je:"<<gamma_term<<endl;
	pc<<"delta je:"<<delta_term<<endl;
	pc<<"pozice motoru1:"<<pozice_motor1<<endl;
	pc<<"pozice motoru2:"<<pozice_motor2<<endl;
}