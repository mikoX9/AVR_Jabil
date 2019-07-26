#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "d_led.h"


/*******************************************************
* Wyswietlacz wspolna katoda,
* anody -> PORTD
* katody -> PORTC
* anody laczone po kolei A->PD0
* diody od gory i od lewej
* katody 1->PC0 ...
*******************************************************/

#define DELAY 50


//conflict

int main(void)
{
	int zmienna_repo_git;
	
	d_led_init();

	cy1= 0;
	cy2= 0;
	cy3= 0;
	cy4= 0;

	sei();
	
	uint16_t licznik = 0;
			
	while(1)
	{
		cy1= licznik/1000;
		cy2= (licznik%1000)/100;
		cy3= (licznik%100)/10;
		cy4= licznik%10;
		licznik++;
		
<<<<<<< HEAD
		if(licznik==10000)
			licznik=1;
=======
		if(licznik == 10000)
		      licznik = 0;
>>>>>>> a4ad56d6fe80de5cc89a00c5bad993d8c083ec1c
		
		_delay_ms(DELAY);
		
	}

}
