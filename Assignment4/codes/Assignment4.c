#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>

int main (void)
{
	bool u,v,x,y;
        DDRD = 0b11110011;
	DDRB = 0b00100011;
	
        while(1)
	{
		u=(PIND &(1 << PIND2))==(1 << PIND2);
		v=(PIND &(1 << PIND3))==(1 << PIND3);
		x = (!u&&!v)||(!u&&v)||(u&&v);
		PORTB |=(x << PB0);
		y= ((!u)||v);
		PORTB |=(y << PB1);
		if(x==y)
		{
			PORTB |= (1 << PB5);
		}
		else
		{
			PORTB |= (0 << PB5);
		}
	}
        return 0;
}
