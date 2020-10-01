
/*
 * Example9_39.c
 *
 * Created: 02/27/2017 11:44:53
 *  Author: Naimi
 */ 


#include <avr/io.h>

void T0Delay ( );

int main ( )
{
	DDRB = 0xFF;	//PORTB output port

	while (1)
	{
		PORTB = 0x55;	//repeat forever
		T0Delay ( );	//delay size unknown
		PORTB = 0xAA;	//repeat forever
		T0Delay ( );
	}
}

void T0Delay ( )
{
	TCNT0 = 0x20;		//load TCNT0
	
	TCCR0A = 0;
	TCCR0B = 0x01; 		//Timer0, Normal mode, no prescaler
	
	while ((TIFR0&(1<<TOV0))==0);	//wait for Timer0 to roll over
	
	TCCR0B = 0;
	TIFR0 = 1<<TOV0;			//clear TOV0
}
