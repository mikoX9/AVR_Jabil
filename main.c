#include <avr/io.h>
#include <avr/delay.h>

#include "klawiatura.h"


int main(void)
{

  klawiatura_init();

	while(1)
	{

    obsluga_przyciskow();

	}

}
