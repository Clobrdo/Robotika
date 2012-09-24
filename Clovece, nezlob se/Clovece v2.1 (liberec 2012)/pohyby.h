/*
 * pohyby.h
 *
 * Created: 22.9.2012 20:35:06
 *  Author: jirka1
 */ 

#define	rychlost_motoru		50
#define	speed_koef			0,8

uint8_t i=0;

uint16_t pozice[7][33] =
{
//0		1		2		3		4		5		6		7		8		9		10		11		12		13		14		15		16		17		18		19		20		21		22		23		24		25		26		27		28		29		30		31		32
{512,	50,		14,		587,	554,	510,	468,	428,	1014,	972,	935,	892,	858,	819,	780,	743,	700,	659,	626,	589,	548,	510,	470,	434,	392,	352,	316,	283,	239,	202,	168,	126,	88	},
{512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512	},
{512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512	},
{512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512	},
{512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512	},
{512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512	},
{512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512,	512	},
};


void nastav_rychlost()
{
	for(int i; i!=6; i++)
	{
		motor[i].speed(rychlost_motoru);
	}
}

void zakladni_pozice()
{
	for(int i=1; i!=6; i++)
	{
		motor[i].position(pozice[i][0]);
	}
	
}
