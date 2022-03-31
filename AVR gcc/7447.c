#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>

int main (void)
{
	bool A=0,B=0,C=0,D=0,a,b,c,d,e,f,g,W=0,X=0,Y=0,Z=0;
        DDRD = 0b11111111;
	DDRB = 0b00100001;
	PORTD = 0b00000000;
	PORTB = 0b00000000;
        while(1)
	{
		a=(!D&&!C&&!B&&A)||(!D&&C&&!B&&!A); 
		b=(!D&&C&&!B&&A)||(!D&&C&&B&&!A); 
		c=(!D&&!C&&B&&!A); 
		d=(!D&&!C&&!B&&A)||(!D&&C&&!B&&!A)||(!D&&C&&B&&A); 
		e=(!D&&!C&&!B&&A)||(!D&&!C&&B&&A)||(!D&&C&&!B&&!A)||(!D&&C&&!B&&A)||(!D&&C&&B&&A)||(D&&!C&&!B&&A); 
		f=(!D&&!C&&!B&&A)||(!D&&!C&&B&&!A)||(!D&&!C&&B&&A)||(!D&&C&&B&&A); 
		g=(!D&&!C&&!B&&!A)||(!D&&!C&&!B&&A)||(!D&&C&&B&&A); 
		A = !W;  
		B = (!Z&&!X&&W)||(X&&!W);  
		C = (!Y&&X&&W)||(Y&&!X)||(Y&&!W);  
		D = (W&&X&&Y)||(!W&&Z);
		PORTD = (a << PD1);
                PORTD |= (b << PD2);
                PORTD |= (c << PD3);
                PORTD |= (d << PD4);
		PORTD |= (e << PD5);
		PORTD |= (f << PD6);
		PORTD |= (g << PD7);
		_delay_ms (1000L);
		W=A;  
		X=B;  
		Y=C;  
		Z=D;

	}
        return 0;
}
