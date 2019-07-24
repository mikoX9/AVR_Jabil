#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>

#include "klawiatura.h"

#define LED_PIN		5
#define	LED_PORT	B

#define BLINK_DELAY 200

void led_init(void);
void blink_led(void);

int main(void)
{

	klawiatura_init();
	led_init();
	
	sei();
	
	while(1)
	{
		obsluga_przyciskow( blink_led );
	}
}


void led_init(void)
{
	DDR(LED_PORT)   |=  _BV(LED_PIN);
	PORT(LED_PORT)	&=~ _BV(LED_PIN);
}

void blink_led(void)
{
	PORT(LED_PORT)	|= _BV(LED_PIN);
	_delay_ms(BLINK_DELAY);
	PORT(LED_PORT)	&=~ _BV(LED_PIN);
	_delay_ms(BLINK_DELAY);
}