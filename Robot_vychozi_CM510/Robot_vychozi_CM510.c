#include "bioloid_v2.1_cm510.h"
#include <avr/delay.h>

void run()
{
    while(1)
    {
		for (int i=1; i!=5; i++)
		{
			motor[i].position(512);
			_delay_ms(200);
		}
		
		for (int i=1; i!=6; i++)
		{
			motor[i].position(400);
			_delay_ms(200);
		}
					    
	}
}