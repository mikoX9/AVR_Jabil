/*
 * main.c
 *
 *  Created on: Feb 14, 2018
 *      Author: mikol
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include "d_led.h"

int main(void)
{

	d_led_init();

	cy1= 7;
	cy2= 8;
	cy3= 9;
	cy4= 0;

	sei();

	while(1)
	{


	}

}
