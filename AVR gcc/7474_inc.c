#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>

int main (void)
{
	bool A,B,C,D;
	bool W=0,X=0,Y=0,Z=0;
        DDRD = 0b00111100;
	DDRB = 0b00100000;
	PORTD = 0b11000000;
	PORTB = 0b00000011;
        while(1){

		PORTB = ((1 <<  PB5));
		_delay_ms (200L);
		A = !W;  
		B = (!Z&&!X&&W)||(X&&!W);  
		C = (!Y&&X&&W)||(Y&&!X)||(Y&&!W);  
		D = (W&&X&&Y)||(!W&&Z); 
                PORTD = (A << 2);
                PORTD |= (B << 3);
                PORTD |= (C << 4);
                PORTD |= (D << 5);
                W = (PIND & (1 << PIND6)) == (1 << PIND6);
                X = (PIND & (1 << PIND7)) == (1 << PIND7);
                Y = (PINB & (1 << PINB0)) == (1 << PINB0);
                Z = (PINB & (1 << PINB1)) == (1 << PINB1);
		PORTB = ((0 <<  PB5));
		 _delay_ms (200L);
	}
        return 0;
}
