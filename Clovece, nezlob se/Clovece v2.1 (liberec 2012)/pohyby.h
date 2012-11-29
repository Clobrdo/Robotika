/*
 * pohyby.h
 *
 * Created: 22.9.2012 20:35:06
 *  Author: jirka1
*/

#include <util/delay.h>

#define	rychlost_motoru			150
#define pocet_motoru			7
#define kostka					((TCNT0 % 6)+1)
#define SETBIT(ADDRESS,BIT)		(ADDRESS |= (1<<BIT)) 
#define CHECKBIT(ADDRESS,BIT)	((ADDRESS & (1<<BIT))!=0) 
#define CLEARBIT(ADDRESS,BIT)	(ADDRESS &= ~(1<<BIT)) 
#define CHECKPOLICKO(BIT)		CHECKBIT(hraci_pole,BIT-1)
#define DOMECEK(BIT)			CHECKBIT(promena_DOMECEK,BIT)
#define delka_ramena1			66
#define delka_ramena2			94
#define delka_ramena3			66
#define delka_ramena4			50
#define M_PI_6					0.5235987755983
	
uint8_t kostka_hod;	
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

const bool ledky[3][6]
{
	{false, false, false, true, true, true},{false, true, true, false, false, true},{true, false, true, false, true, false},
};

const uint16_t Motor_1[41] PROGMEM =
{
//0		1		2		3		4		5		6.587	7.554	8.510	9.468	10		11		12		13		14		15		16		17		18		19		20		21		22		23		24		25		26		27		28		29		30		31		32		chl_R1	chl_R2	dom_R1	domR2	chl_HR1	chl_HR2
512,	168,	126,	88,		50,		14,		1099,	1066,	1022,	468,	428,	1014,	972,	935,	892,	858,	819,	780,	743,	700,	659,	626,	589,	548,	510,	470,	434,	392,	352,	316,	283,	239,	202,	176,	220,	196,	199,	811,	811,	833,	791
};

const uint16_t PohybyOstaniMotory[4][18] PROGMEM =
{
//Klasicke pozice		Nezasahnute pozice		Chlivek					Domecek_dal				Domecek 2_R				Presun
//NadF	ZacNakl	PolF	NadF	ZacNakl	NadF	NadCH	PolF	...		NadCH	PolF	NadF	NadCH	ZacN	NadF
{351,	334,	250,	769,	758,	800,	340,	260,	235,	450,	510,	562,	450,	528,	564,	516,	739,	726},
{812,	808,	811,	167,	201,	201,	723,	765,	766,	474,	544,	446,	474, 	441,	369,	520,	167,	166},
{201,	270,	275,	764,	760,	760,	330,	360,	365,	392,	256,	150,	392,	327,	291,	505,	866,	749},
{182,	182,	187,	817,	780,	779,	203,	204,	210,	164,	161,	311,	164,	169,	251,	200,	166,	860}
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
 33,34,40,39		
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
	bool poradne;
	if (poradne==false)
	{
		motor[6].position(507);
		motor[7].position(517);
	}
	else
	{
		motor[6].position(400);
		motor[7].position(600);			
	}
	cekej();
}

void naberpoloz(uint8_t c_pozice, bool naber)
{
	uint8_t tmp;
	if (naber)
	{
		tmp=c_pozice+kostka_hod;
	} 
	else
	{
		tmp=c_pozice;
	}
	
	if (tmp>=3 && tmp<=16)
	{
		if (motor[2].position()<512)
		{
			PoziceM1(c_pozice+16);	
			nastav_rychlost(3);
			for (i=5; i!=4; i--)
			{
				motor[i].position(pgm_read_word(&(PohybyOstaniMotory[(i-2)][3])));
				cekej();
			}
			motor[2].position(pgm_read_word(&(PohybyOstaniMotory[0][3])));
			motor[3].position(pgm_read_word(&(PohybyOstaniMotory[1][3])));
			motor[4].position(pgm_read_word(&(PohybyOstaniMotory[2][3])));
			cekej();
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
		}
		cekej();
		otevri();
		if (naber)
		{
			cekej();
			zavri();
		}
		for (i=2; i!=6; i++)
		{
			motor[i].position(pgm_read_word(&(PohybyOstaniMotory[(i-2)][3])));
		}
		cekej();
	}
	
	/*if (c_pozice<11 && c_pozice>5)
	{
		PoziceM1(c_pozice);
		if (motor[2].position()<512)
		{
			nastav_rychlost(3);
				for (i=5; i!=4; i--)
				{
					motor[i].position(pgm_read_word(&(PohybyOstaniMotory[(i-2)][3])));
					cekej();
				}
				motor[2].position(pgm_read_word(&(PohybyOstaniMotory[0][3])));
				motor[3].position(pgm_read_word(&(PohybyOstaniMotory[1][3])));
				motor[4].position(pgm_read_word(&(PohybyOstaniMotory[2][3])));
				cekej();
			nastav_rychlost(1);			
						
		}

		pc<<"nezasahnute"<<endl;
		for (i2=3; i2!=6; i2++)
		{
			nastav_rychlost(i2-2);
			for (i=2; i!=6; i++)
			{
				motor[i].position(pgm_read_word(&(PohybyOstaniMotory[(i-2)][i2])));
			}
			cekej();			
		}	
		cekej();
		otevri();
		if (naber)
		{
			cekej();
			zavri();
		}
		for (i=2; i!=6; i++)
		{
			motor[i].position(pgm_read_word(&(PohybyOstaniMotory[(i-2)][3])));
		}
		cekej();		
	} */
	
	else if ((c_pozice>=33 && c_pozice<=34)||(c_pozice>=39 && c_pozice<=40))
	{
		PoziceM1(c_pozice);
		pc<<"domecek"<<endl;
		for (i2=6; i2!=9; i2++)
		{
			nastav_rychlost(i2-2);
			for (i=2; i!=6; i++)
			{
				motor[i].position(pgm_read_word(&(PohybyOstaniMotory[(i-2)][i2])));
			}
			cekej();
		}
		cekej();
		otevri();
		if (naber)
		{
			cekej();
			zavri();
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
			nastav_rychlost(i2-2);
			for (i=2; i!=6; i++)
			{
				motor[i].position(pgm_read_word(&(PohybyOstaniMotory[(i-2)][i2])));
			}
			cekej();
		}
		cekej();
		
		otevri();	
		cekej();
		for (i=2; i!=6; i++)
		{
			motor[i].position(pgm_read_word(&(PohybyOstaniMotory[(i-2)][10])));
		}		
		//_________________________________________________________________________________________
	}
	
	else if(c_pozice==36 || c_pozice==37)
	{
		PoziceM1(c_pozice);
		for (i2=12; i2!=15; i2++)
		{
			nastav_rychlost(i2-2);
			for (i=2; i!=6; i++)
			{
				motor[i].position(pgm_read_word(&(PohybyOstaniMotory[(i-2)][i2])));
			}
			cekej();
		}
		cekej();
		cekej();
		otevri();
		cekej();
		for (i=2; i!=6; i++)
		{
			motor[i].position(pgm_read_word(&(PohybyOstaniMotory[(i-2)][13])));
		}
		//_________________________________________________________________________________________
	}
	
	else
	{
		PoziceM1(c_pozice);		
		if (motor[2].position()>512)
		{
			for(i2=17;i2!=14;i2--)
			{
				for(i=2;i!=6;i++)
				{
					motor[i].position(pgm_read_word(&(PohybyOstaniMotory[(i-2)][i2])));
				}
				cekej();
			}
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
		}
		cekej();
		otevri();
		if (naber)
		{
			cekej();
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

void vyhod(uint8_t c_pozice, uint8_t curr_fig)
{
	naber(c_pozice);
	if(curr_fig<=1)
	{
		if(!DOMECEK(6))
		{
			poloz(39);
		}
		else
		{
			poloz(40);
		}
	}
	else
	{
		if(!DOMECEK(0))
		{
			poloz(33);
		}
		else
		{
			poloz(34);
		}
	}
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

void posun()
{
		for (i=0; i!=32; i++)
		{
			//pc<<CHECKBIT(hraci_pole,i);
		}
	bool bit=false;
	for(i=0; i!=3; i++)
	{
		bit=CHECKBIT(hraci_pole,31);
		hraci_pole/=2;
		if (bit)
		{
			SETBIT(hraci_pole,31);	
		} 
		else
		{
			CLEARBIT(hraci_pole,31);
		}
	}
	
	pc<<endl<<endl;
		for (i=0; i!=32; i++)
		{
			pc<<CHECKBIT(hraci_pole,i);
		}
}

uint8_t aktualizuj_hraci_pole()	//pøidat další funkci, která zkontroluje, zda hodnoty v curr_pos[] odpovídají skuteènosti
{
	pc.sendChar(127);
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
	
	posun();
	

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
	uint16_t pozice_motor0, pozice_motor1,pozice_motor2,pozice_motor3,pozice_motor4,B_term;
	int a0_term,a1_term, a2_term,a3_term,a4_term,a5_term,a6_term,a7_term;
	uint16_t B,B2;
	double a0,a1,a2,a3;	//uhel ramena
	double a4;	//uhel loktu
	double a5,a6,a7;	//uhel zapesti
	
	//alfa=(alfa*(M_PI/180));
	B2=sqrt(pow(Xt,2)+pow(Yt,2));																	//prepocitani do 2d
	//Zt=Zt+(sin(alfa)*delka_ramena4);																//pricteni naklonu
	//B2=B2+(cos(alfa)*delka_ramena4);
	B=sqrt(pow(B2,2)+pow(Zt,2));																	//delka spojnice
	a0=atan2(Yt,Xt);																				//uhel spojnice
	a1=acos((pow(delka_ramena1,1)-pow(delka_ramena1,2)+pow((B/2),2))/(2*delka_ramena1*(B/2)));
	a2=atan2(Zt,Xt);
	a3=a1+a2;
	a4=acos((pow(delka_ramena1,2)+pow(delka_ramena2,2)-pow((B/2),2))/(2*delka_ramena1*delka_ramena1));
	a5=acos((pow(delka_ramena2,2)+pow(delka_ramena2,2)-pow(delka_ramena1,2))/(2*delka_ramena2*delka_ramena2));
	a6=acos((pow(delka_ramena2,2)+pow(delka_ramena2,2)-pow((B/2),2))/(2*delka_ramena2*delka_ramena3));
	a7=a5+a6;
	
	pozice_motor0=(((((5*M_PI)/6)+a0)*180/M_PI)*3.4133333);
	pozice_motor1=(((((M_PI)/6)+a3)*180/M_PI)*3.4133333);
	pozice_motor2=((((a4+a5)-(M_PI/6))*180/M_PI)*3.4133333);
	pozice_motor3=(((a7-(M_PI/6))*180/M_PI)*3.4133333);
	
	motor[1].position(pozice_motor0);
	motor[2].position(pozice_motor1);
	motor[3].position(pozice_motor2);
	motor[4].position(pozice_motor3);
	
	
	/*a0_term=a0*180/M_PI;
	a1_term=a1*180/M_PI;
	a2_term=a2*180/M_PI;
	a3_term=a3*180/M_PI;
	a4_term=a4*180/M_PI;
	a5_term=a5*180/M_PI;
	a6_term=a6*180/M_PI;
	a7_term=a7*180/M_PI;
	
	pc<<"B "<<B<<endl;
	pc<<"A0 "<<a0_term<<endl;
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

/*void pohyb_na_bod2(float Xt, float Zt)
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
	
	B=sqrt(pow(Xt,2)+pow(Zt,2));
	B_22=pow((B/2),2);	
	a1=acos((pow(delka_ramena1,1)-pow(delka_ramena1,2)+B_22)/(2*delka_ramena1*(B/2)));
	a2=atan2(Zt,Xt);
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

void pohyb_na_bod(float Xt, float Zt)
{
	uint16_t pozice_motor1,pozice_motor2,B_term;
	int alfa_term,beta_term,gamma_term,delta_term,B;
	double alfa,beta,gamma,delta;
	
	B=sqrt(pow(Xt,2)+pow(Zt,2));		
	alfa=atan2(Zt,Xt);	
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