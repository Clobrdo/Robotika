/*
 * pohyby.h
 *
 * Created: 22.9.2012 20:35:06
 *  Author: jirka1
*/

#include <avr/delay.h>

#define	rychlost_motoru		250
#define pocet_motoru		6
#define	speed_koef			0,8

uint8_t i=0;		//promnìná do smyèek
uint8_t i2=0;		//-------||----------
uint8_t kostka_h=0;

const uint16_t hodnoty_pozice[7][33] PROGMEM =
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

const uint16_t hodnoty_rychlost[7][1] PROGMEM =
{
{1023},	//1
{rychlost_motoru},	//2
{rychlost_motoru},	//3
{1023},				//4
{rychlost_motoru},	//5
{rychlost_motoru},	//6
{rychlost_motoru}	//7
};

bool hodnoty_pole[5][8] = 
{//1	2		3		4		5		6		7		8
{false,	false,	false,	false,	false,	false,	false,	false	},	//1
{false,	false,	false,	false,	false,	false,	false,	false	},	//2
{false,	false,	false,	false,	false,	false,	false,	false	},	//3
{false,	false,	false,	false,	false,	false,	false,	false	},	//4
{false,	false,	false,	false,	false,	false,	false,	false	}	//5
};

void kostka()
{
	do 
	{
	}while(buttons.isStart()==true);
	do 
	{
		kostka_h++;
		if(kostka_h!=7) {kostka_h=1;}
	} while (buttons.isStart()==true);
}

void cekej()
{
i=1;
_delay_ms(150);
	do 
	{
		if (motor[i].present_speed()<1)	{i++;}
		//else {i++;}
	} while (i!=pocet_motoru);
}

//void nastav_rychlost_m()

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
		motor[i].position(pgm_read_word(&(hodnoty_pozice[(i-1)][0])));
	}
cekej();
}

void pozice(uint8_t c_pozice)
{
	for(i=1; i!=pocet_motoru; i++)
	{
		motor[i].position(pgm_read_word(&(hodnoty_pozice[(i-1)][c_pozice])));
	}
}

void uchop()
{
	
}

