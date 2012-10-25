/*
 * pohyby.h
 *
 * Created: 22.9.2012 20:35:06
 *  Author: jirka1
*/

#include <util/delay.h>

#define	rychlost_motoru		250
#define pocet_motoru		6
#define	speed_koef			0,8
#define kostka				((TCNT0 % 6)+1)
#define SETBIT(ADDRESS,BIT) (ADDRESS |= (1<<BIT)) 
#define CHECKBIT(ADDRESS,BIT) ((ADDRESS & (1<<BIT))!=0) 
#define CLEARBIT(ADDRESS,BIT) (ADDRESS &= ~(1<<BIT)) 
#define CHECKPOLICKO(BIT)	CHECKBIT(hraci_pole,BIT)
#define DOMECEK(BIT)	CHECKBIT(promena_DOMECEK,BIT)
	

uint8_t i=0;		//promnìná do smyèek
uint8_t i2=0;		//-------||----------
uint32_t hraci_pole=0;			//cudliky na poli
uint8_t promena_DOMECEK=0;		//cudliky v domecku

const uint16_t hodoty_motoru[pocet_motoru+1][33] PROGMEM =
{
//0		1		2		3		4		5		6		7		8		9		10		11		12		13		14		15		16		17		18		19		20		21		22		23		24		25		26		27		28		29		30		31		32
{512,	50,		14,		587,	554,	510,	468,	428,	1014,	972,	935,	892,	858,	819,	780,	743,	700,	659,	626,	589,	548,	510,	470,	434,	392,	352,	316,	283,	239,	202,	168,	126,	88	},
{512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512	},
{512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512	},
{700,	800,	700,	800,	700,	800,	700,	800,	700,	800,	700,	800,	700,	800,	700,	800,	700,	800,	700,	800,	700,	800,	700,	800,	700,	800,	700,	800,	700,	800,	700,	800,	700	},
{512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512	},
{512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512	},
{512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512	},
};

const uint16_t hodnoty_pohyb[3][2] PROGMEM =
{
{512,	512},
{512,	512},
{512,	512}
};

const uint16_t hodnoty_rychlost[7][1] PROGMEM =
{
{rychlost_motoru},	//1
{rychlost_motoru},	//2
{rychlost_motoru},	//3
{rychlost_motoru},	//4
{rychlost_motoru},	//5
{rychlost_motoru},	//6
{rychlost_motoru}	//7
};

uint8_t curr_pos[1][4]
{
{0,	1,	8,	9	}	
};

void inicializace()
{
	TCCR0 |= (1 << CS00);
}

void cekej()
{
	i=1;
	_delay_ms(150);
	while(i!=pocet_motoru)
	{
		if (motor[i].present_speed()<1)	{i++;}
	} 
}

void nastav_rychlost()
{
	for(i=1; i!=pocet_motoru; i++)
	{
		motor[i].speed(pgm_read_word(&(hodnoty_rychlost[(i-1)][0])));
	}
}

void zakladni_pozice()
{
	for(i=1; i!=pocet_motoru; i++)
	{
		motor[i].position(pgm_read_word(&(hodoty_motoru[(i-1)][0])));
	}
	cekej();
}

void pozice(uint8_t c_pozice)
{
	for(i=1; i!=pocet_motoru; i++)
	{
		motor[i].position(pgm_read_word(&(hodoty_motoru[(i-1)][c_pozice])));
	}
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

void nasad_robot()
{
	otevri();
	if(DOMECEK(0))
	{
		//pozice();
		curr_pos[0][0]=8;
	}		
	else
	{
		//pozice();
		curr_pos[0][1]=8;
	}	
	zavri();
	pozice(8);
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

void aktualizuj_hraci_pole()	//pøidat další funkci, která zkontroluje, zda hodnoty v curr_pos[] odpovídají skuteènosti
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
}
