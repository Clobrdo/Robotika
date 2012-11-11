#include "bioloid_v2.2.h"
#include <avr/delay.h>
void cekej()
{
	uint8_t icekej=5;
	_delay_ms(170);
	while(icekej!=12)
	{
		_delay_ms(170);
		if (motor[icekej].present_speed()==0)	
		{	
			if (icekej==7)
			{
				icekej=9;
			} 
			else
			{
				icekej++;
			}
		}
	}	
}

void dopredu()
{
	motor[1].speed(1023);
	motor[2].speed(1023);
	motor[3].speed(1023+1024);
	motor[4].speed(1023+1024);
}
void dozadu()
{
	motor[1].speed(1023+1024);
	motor[2].speed(1023+1024);
	motor[3].speed(1023);
	motor[4].speed(1023);
}
void doprava()
{
	motor[1].speed(1023);
	motor[2].speed(1023);
	motor[3].speed(1023);
	motor[4].speed(1023);
}
void doleva()
{
	motor[1].speed(1023+1024);
	motor[2].speed(1023+1024);
	motor[3].speed(1023+1024);
	motor[4].speed(1023+1024);
}
void stop()
{
	for(int i=1;i<5;i++)
	motor[i].speed(0);
}
void vychozi()
{
	for(int i=5;i<12;i++)
	{
		if(i==8) 
		{
			i=9;
		}		
	motor[i].speed(100);
	motor[5].position(577);
	motor[6].position(836);
	motor[7].position(566);
	motor[9].position(577);
	motor[10].position(836);
	motor[11].position(566);
	}
}
void krok1()
{
	motor[5].position(941);
	motor[6].position(333);
	motor[7].position(413);
	motor[9].position(577);
	motor[10].position(836);
	motor[11].position(566);
}
void krok2()
{
	motor[5].position(941);
	motor[6].position(333);
	motor[7].position(413);
	motor[9].position(950);
	motor[10].position(300);
	motor[11].position(560);
}
void krok3()
{
	motor[5].position(577);
	motor[6].position(836);
	motor[7].position(566);
	motor[9].position(950);
	motor[10].position(300);
	motor[11].position(560);
}

void krok4()
{
	motor[5].position(577);
	motor[6].position(836);
	motor[7].position(566);
	motor[9].position(577);
	motor[10].position(836);
	motor[11].position(566);

}
void prekazka()												//pøekonávání pøekážky
{
	int pomoc=0;
	int r1;
	int strana=1;
	r1 = sensor[101].rightDistance();
	bool again = true;
	stop();
	krok1();
	cekej();
	dopredu();
	wait(1000000);
	stop();
	krok2();
	krok3();
	cekej();
	dopredu();
	wait(500000);
	stop();
	krok4();
	cekej();
	
	//again:
	while(again)
	{
		while(r1>=252)												// když mìøí sensor 252 a víc tak mùže jet dál dokud nedojede ke konci pøekážky *2
		{
			r1 = sensor[101].rightDistance();
			dopredu();
		}
		if(r1<252 && r1>150)										// *2, když sensor zmìøí 151-251 tak mùže bezpeènì sjet z pøekážky
		{
			dopredu();
			wait(2000000);
			pomoc=1;
			
		}
		if(r1<=150)													// když sensor zmìøí 150 a ménì, tak nemùže sjet, couvne a otoèí se doprava
		{
			dozadu();
			wait(500000);
			stop();
			switch(strana)										
			{
				case '1':										// když bude jedna, tak se otoèí o 90° doprava
							dozadu();
							wait(500000);
							stop();
							doprava();
							strana=2;
				break;
				case '2':	dozadu();							// když bude dva, tak se otoèí o 180°
							wait(1000000);
							stop();
							doleva();
							strana=3;
				break;
				case '3':	dozadu();							// když bude tøi, tak se otoèí o 90° doleva, tzn tam odkud dojel
							wait(500000);
							stop();
							doleva();
							strana=1;
				break;
			}					
			//goto again;											// smyèka, dokud nenajde místo ke sjetí - NEBUDE SE POUŽÍVAT GOTO!!!
		}
		if(pomoc==1)
		{
			again = false;
			stop();
		}
		stop();
	
	}
	
	
	
	
	
	
/*	stop();
	krok1();
	wait(1200000);
	krok2();
	wait(800000);
	dopredu();
	wait(900000);
	stop();
	krok3();
	wait(1000000);
	krok4();
	wait(1000000);
	dopredu();
	wait(1000000);
	stop();
	vychozi();
	wait(500000);
	dopredu();
	wait(1500000);
	stop();*/
}
int c0, s0, c1,r1, s1, c2, s2, c3, s3;
void mer()
{
	c0 = sensor[100].centerDistance();
	s0 = sensor[100].rightDistance();
	c1 = sensor[101].centerDistance();
	r1 = sensor[101].rightDistance();
	s1 = sensor[101].leftDistance();
	c2 = sensor[102].centerDistance();
	s2 = sensor[102].rightDistance();
	c3 = sensor[103].centerDistance();
	s3 = sensor[103].leftDistance();
	//pc<<c0<<","<<s0<<","<<c1<<","<<s1<<","<<c2<<","<<s2<<","<<c3<<","<<s3;
}

void mer2()
{
	pc<<"sensor :"<< sensor[101].rightDistance() <<endl;
}
void pozice()
{
	int poz = 0;
	for(int i=5;i<12;i++)
	{
		if(i==8)
		{
			++i;
		}
		
		pc<<"Motor cislo "<<i << ".  "<< motor[i].position() <<endl;
	}
}
void vypni()
{
	for(int i=5;i<12;i++)
	{
		if(i==8)
		{
			i=9;
		}
		motor[i].torqueLimit(0);
	}
}
void zapni()
{
	for(int i=5;i<12;i++)
	{
		if(i==8)
		{
			i=9;
		}
		motor[i].torqueLimit(1023);
	}
}
void jizda()
{
for(;;)
{
	c1 = sensor[101].centerDistance();
	pc<<"sensor "<< sensor[101].centerDistance() <<endl;
	while(c1<255)
		{
			dopredu();
			c1 = sensor[101].centerDistance();
			pc<<"sensor :"<< sensor[101].centerDistance() <<endl;
			_delay_ms(75);
		}
	if(c1=255)
		{
		prekazka();
		}
}		
	
/*	while(true)
	{
		mer();
		while((s0==255)&&(s1==255)&&(s2==255)&&(s3==255)&&(c0<150)&&(c1<200)&&(c2<200)&&(c3<200))
		{
			mer();
			dopredu();
		}
		while((s2!=255)||(c2>=200))
		{
			mer();
			dopredu();
		}
		while((s1!=255)||(c1>=200))
		{
			mer();
			doprava();
		}
		while((s3!=255)||(c3>=200))
		{
			mer();
			doleva();
		}

		if(c0>=150)
		{
			krok();
		}
		if((s0!=255))
		{
			while((s0!=255)||(c0>=200))
			{
				mer();
				dozadu();
				
			}
			doleva();
			wait(250000);
		}
		stop();
	}*/
}
void run()
{
	vychozi();
	char x;
	while(true)
	{
/*		if(buttons.isStart())
		jizda();*/
		x=pc.get();
		pc<<x;
		switch(x)
		{
			case 'w': dopredu();
				break;
			case 's': dozadu();
				break;
			case 'a': doleva();
				break;
			case 'd': doprava();
				break;
			case 'q': stop();
				break;
			case 'f': jizda();
				break;
			case 'g': mer();
				break;
			case 'v': vypni();
				break;
			case 'y': zapni();
				break;
			case 'b': 
					pc<<endl<<"Motor cislo 5.  "<< motor[5].position() <<endl;
					pc<<"Motor cislo 6.  "<< motor[6].position() <<endl;
					pc<<"Motor cislo 7.  "<< motor[7].position() <<endl;
					pc<<"Motor cislo 9.  "<< motor[9].position() <<endl;
					pc<<"Motor cislo 10.  "<< motor[10].position() <<endl;
					pc<<"Motor cislo 11.  "<< motor[11].position() <<endl;
				
				break;
			case 'j': vychozi();
				break;
			case 'o': mer2();
				break;
			case 'k': prekazka();
				break;
			case '1': krok1();
				break;
			case '2': krok2();
				break;
			case '3': krok3();
				break;
			case '4': krok4();
				break;
			
		}
	}
}

