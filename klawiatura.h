#ifndef KLAWIATURA_H_
#define KLAWIATURA_H_

#include <avr/delay.h>
#include <math.h>

#define  _NIO() asm volatile ("nop")

// *** PORT
#define PORT(x) SPORT(x)
#define SPORT(x) (PORT##x)
// *** PIN
#define PIN(x) SPIN(x)
#define SPIN(x) (PIN##x)
// *** DDR
#define DDR(x) SDDR(x)
#define SDDR(x) (DDR##x)


//definicje rzedow  R->ROW
#define R_1_PIN   PD0
#define R_1_PORT  D
#define R_2_PIN   PD1
#define R_2_PORT  D
#define R_3_PIN   PD2
#define R_3_PORT  D
#define R_4_PIN   PD3
#define R_4_PORT  D
//maski dla rzedow
#define R_1_MASK  (1<<R_1_PIN)
#define R_2_MASK  (1<<R_2_PIN)
#define R_3_MASK  (1<<R_3_PIN)
#define R_4_MASK  (1<<R_4_PIN)

//definicje kolumn C->COLUMN
#define C_1_PIN   PD4
#define C_1_PORT  D
#define C_2_PIN   PD5
#define C_2_PORT  D
#define C_3_PIN   PD6
#define C_3_PORT  D
#define C_4_PIN   PD7
#define C_4_PORT  D
//maski dla kolumn
#define C_1_MASK  (1<<C_1_PIN)
#define C_2_MASK  (1<<C_2_PIN)
#define C_3_MASK  (1<<C_3_PIN)
#define C_4_MASK  (1<<C_4_PIN)


void klawiatura_init(void);

volatile uint16_t przyciski;  //16bit-> kazdy bit odpowiada za jeden przycisk

typedef void( * funkcja )( void );

void obsluga_przyciskow( funkcja mruganie );

#endif
