#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include "d_led.h"

volatile uint8_t cy1;	
volatile uint8_t cy2;		
volatile uint8_t cy3;
volatile uint8_t cy4;


const uint8_t liczby[11] PROGMEM=                 //zapisywanie do pamieci FLASH, tablica ustalona anod
{
		(1<< 0)+(1<< 1)+(1<< 2)+(1<< 4)+(1<< 5)+(1<< 6),			//0
		(1<< 2)+(1<< 5),											//1
		(1<< 0)+(1<< 2)+(1<< 3)+(1<< 4)+(1<< 6),					//2
		(1<< 0)+(1<< 2)+(1<< 3)+(1<< 5)+(1<< 6),					//3
		(1<< 1)+(1<< 2)+(1<< 3)+(1<< 5),							//4
		(1<< 0)+(1<< 1)+(1<< 3)+(1<< 5)+(1<< 6),					//5
		(1<< 0)+(1<< 1)+(1<< 3)+(1<< 4)+(1<< 5)+(1<< 6),			//6
		(1<< 0)+(1<< 2)+(1<< 5),									//7
		(1<< 0)+(1<< 1)+(1<< 2)+(1<< 3)+(1<< 4)+(1<< 5)+(1<< 6),	//8
		(1<< 0)+(1<< 1)+(1<< 2)+(1<< 3)+(1<< 5)+(1<< 6)				//9
};


void d_led_init(void)
{
	LED_DATA_DIR = 0xFF;  //port anod jako wyjscia
	LED_DATA = 0x00;      //stan niski na katodach, czyli zgaszenie

	KATODY_DIR |= CA1 | CA2 | CA3 | CA4;   //4 piny katod jako wyjscia
	KATODY_PORT |= CA1 | CA2 | CA3 | CA4;	//wygaszenie wszystkich wyswietlaczy

	//ustawienia timera

	TCCR0A |=(1<<WGM01);	//tryb ctc
	TCCR0B |= (1<<CS00) | (1<<CS02);	//preskaler 1024
	OCR0A = 38;		//dodatkowy podzia� przez 38
	TIMSK0 |= (1<<OCIE0A);	//zezwolenie na przerwania od porownania z rejestrem OCR0A
}


ISR(TIMER0_COMPA_vect)
{
	static uint8_t licznik = 1;			//static- zmienna raz tworzona
	
	KATODY_PORT = ~ licznik;

	if(licznik == 1) LED_DATA=(pgm_read_byte( &liczby[cy1]));          //odczytywanie z pamieci FLASHh
	else if(licznik == 2) LED_DATA=(pgm_read_byte( &liczby[cy2]));
	else if(licznik == 4) LED_DATA=(pgm_read_byte( &liczby[cy3]));
	else if(licznik == 8) LED_DATA=(pgm_read_byte( &liczby[cy4]));

	licznik <<=1;

	if(licznik > 8) licznik =1;
}
