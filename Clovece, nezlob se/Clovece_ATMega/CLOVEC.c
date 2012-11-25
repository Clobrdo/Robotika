#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "../kubas_avrlib/queue.h"
#include "../kubas_avrlib/rs232new-basic.h"
#include "../kubas_avrlib/format_rs232.h"

using namespace kubas;

format_t pc;

int main()
{
	rs232.init(57600);
	sei();
	_delay_ms(1);
	uint8_t tlacitka[5] = {0,0,0,0,0};
	uint8_t tlacitka2[5] = {0,0,0,0,0};
	bool zmena = false;
	//pc << "Hello world!" << endl;
	//pc.wait();


	DDRD = 0b11100000;
	PORTC = 0xff;
	//pc.base(2);
	pc.align(5);
	//pc.division(1);
	//pc.fill('0');

	for(;;)
	{			
		for(int i=0; i!=5; ++i)
		{
			DDRA = (1<<i);
			_delay_us(10);
			tlacitka[i] = ~PINC;
			if (tlacitka[i] != tlacitka2[i])
			{
				zmena = true;
			}
			tlacitka2[i] = tlacitka[i]; 
		}
		if (zmena == true)
		{
			for (int i=0; i!=5; ++i)
			{
				pc.send_char(tlacitka[i]);
			}
		
			//pc<<endl;	
			pc.wait();
			zmena = false;
			PORTD = PORTD|0b10000000;
			_delay_ms(100);
			PORTD &= ~(1<<7);
		}
	}
}















/*

PORTD = PORTD|0b10000000;
		_delay_ms (250);
		PORTD = PORTD|0b00100000;
		_delay_ms (250);
		PORTD = PORTD|0b01000000;
		_delay_ms (250);
		PORTD = PORTD&0b01111111;
		_delay_ms (250);
		PORTD = PORTD&0b11011111;
		_delay_ms (250);
		PORTD = PORTD&0b10111111;
		_delay_ms (250);

*/

/*
	if((PINC & (1<<0))!=0)
		{	
			PORTD |= (1<<7);				
		}
		else
		{
			PORTD &= ~(1<<7);
		}

		if((PINC & (1<<1))!=0)
		{
			PORTD |= (1<<6);
		} 
		else 
		{
			PORTD &= ~(1<<6);
		}

		if((PINC &(1<<3))!=0)
		{
			PORTD |= (1<<5);
		}
		else
		{
			PORTD &= ~(1<<5);
`		}
*/	
