/*
 * 7SegmentLEDCode.c
 *
 * Created: 24/11/2019 08:19:40
 * Author : olive
 */ 

#include <avr/io.h>
#define  F_CPU 8000000UL
#include <avr/interrupt.h>
#include <util/delay.h>
void displayLED(int digit);

ISR(INT2_vect)
{
	void displayLED();
	PORTC ^= 1<<PC0;
}

int main(void)
{
	
	DDRB = 0;
	DDRD = 0xFF;
	PORTD = 0xFF;
	PORTB = 1<<PB2; // Activate the pull-up resistor
	DDRC = 1<<PC0;
	
	// Trigger some interrupt activity
	GICR = 1<<INT2;
	MCUCSR = 1<<ISC2;
    sei();

    /* Replace with your application code */
    while (1) 
    {		
    }
}
void displayLED(int digit)
{	
	   
	    char numbers[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
      	digit = 10;
       
		for (int i = 0;i<digit;i++)
		{
			if (i<digit)
			{
				 PORTD = numbers[i];
				 //_delay_ms(1000);
			}
			 
		} 
		
}

