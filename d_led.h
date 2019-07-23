#ifndef D_LED_H_
#define D_LED_H_


#define LED_DATA	PORTD
#define LED_DATA_DIR	 DDRD
#define ANODY_PORT	PORTB
#define ANODY_DIR	DDRB

#define CA1 (1<<PB0)
#define CA2 (1<<PB1)
#define CA3 (1<<PB2)
#define CA4 (1<<PB3)

extern volatile uint8_t cy1;	//extern- powoduje ze te zmienne beda dostepne we wszystkich modulach
extern volatile uint8_t cy2;	//ktore maja dolaczony plik tej biblioteki
extern volatile uint8_t cy3;
extern volatile uint8_t cy4;

//extern volatile uint8_t liczby[];

void d_led_init(void);

#endif /* D_LED_H_ */
