#include <avr/io.h>
#include <avr/interrupt.h>
#include "klawiatura.h"



void klawiatura_init(void)
{

//  COLUMN_DDR |= COLUMN_MASK;
//  COLUMN_PORT &=~ COLUMN_MASK;

  //rzedy jak wejscia
  DDR(R_1_PORT)   &=~ R_1_MASK;
  DDR(R_2_PORT)   &=~ R_2_MASK;
  DDR(R_3_PORT)   &=~ R_3_MASK;
  DDR(R_4_PORT)   &=~ R_4_MASK;
  //podciagniecie do VCC
  PORT(R_1_PORT)  |= R_1_MASK;
  PORT(R_2_PORT)  |= R_2_MASK;
  PORT(R_3_PORT)  |= R_3_MASK;
  PORT(R_4_PORT)  |= R_4_MASK;

  //kolumny jak wyjscia
  DDR(C_1_PORT)   |= C_1_MASK;
  DDR(C_2_PORT)   |= C_2_MASK;
  DDR(C_3_PORT)   |= C_3_MASK;
  DDR(C_4_PORT)   |= C_4_MASK;
  //stan na wyjsciach 1
  PORT(C_1_PORT)  |= C_1_MASK;
  PORT(C_2_PORT)  |= C_2_MASK;
  PORT(C_3_PORT)  |= C_3_MASK;
  PORT(C_4_PORT)  |= C_4_MASK;

  //inicjalizacja timera0 + przerwania cykliczne
  // f = F_CPU/preskaler/OCR0A   -> z taka czestotoliwoscia wyzwalane jest przerwanie
  // np f = 16000000/1024/38 =~ 411Hz zalezy jakie F_CPU
  TCCR0A |=(1<<WGM01);	//tryb ctc
	TCCR0B |= (1<<CS00) | (1<<CS02);	//preskaler 1024
	OCR0A = 38;		//dodatkowy podzia� przez 38
  TIMSK0 |=(1<<OCIE0A);
  //TIMSK0 |= (1<<OCIE0A);	//zezwolenie na przerwania od porownania z rejestrem OCR0A



  //inne inicjalizacje

  DDRB = 0xff;
  PORTB = 0x00;
}


void obsluga_przyciskow(){
      PORTB = (uint8_t) przyciski;
}


//przerwanie do obslugi klawiatury
ISR(TIMER0_COMPA_vect)
{
    //podajemy stan niski kolejne kolumny sprawdzajac czy

    PORT(C_1_PORT)  &=~ C_1_MASK;
    PORT(C_2_PORT)  |= C_2_MASK;
    PORT(C_3_PORT)  |= C_3_MASK;
    PORT(C_4_PORT)  |= C_4_MASK;

    if( !( PIN(R_1_PIN) & R_1_MASK )) przyciski |= (1<<0);
    else przyciski &=~ (1<<0);
    if( !( PIN(R_2_PIN) & R_2_MASK )) przyciski |= (1<<4);
    else przyciski &=~ (1<<4);
    if( !( PIN(R_3_PIN) & R_3_MASK )) przyciski |= (1<<8);
    else przyciski &=~ (1<<8);
    if( !( PIN(R_4_PIN) & R_4_MASK )) przyciski |= (1<<12);
    else przyciski &=~ (1<<12);


    PORT(C_1_PORT)  |= C_1_MASK;
    PORT(C_2_PORT)  &=~ C_2_MASK;
    PORT(C_3_PORT)  |= C_3_MASK;
    PORT(C_4_PORT)  |= C_4_MASK;

    if( !( PIN(R_1_PIN) & R_1_MASK )) przyciski |= (1<<1);
    else przyciski &=~ (1<<1);
    if( !( PIN(R_2_PIN) & R_2_MASK )) przyciski |= (1<<5);
    else przyciski &=~ (1<<5);
    if( !( PIN(R_3_PIN) & R_3_MASK )) przyciski |= (1<<9);
    else przyciski &=~ (1<<9);
    if( !( PIN(R_4_PIN) & R_4_MASK )) przyciski |= (1<<13);
    else przyciski &=~ (1<<13);


    PORT(C_1_PORT)  |= C_1_MASK;
    PORT(C_2_PORT)  |= C_2_MASK;
    PORT(C_3_PORT)  &=~ C_3_MASK;
    PORT(C_4_PORT)  |= C_4_MASK;

    if( !( PIN(R_1_PIN) & R_1_MASK )) przyciski |= (1<<2);
    else przyciski &=~ (1<<2);
    if( !( PIN(R_2_PIN) & R_2_MASK )) przyciski |= (1<<6);
    else przyciski &=~ (1<<6);
    if( !( PIN(R_3_PIN) & R_3_MASK )) przyciski |= (1<<10);
    else przyciski &=~ (1<<10);
    if( !( PIN(R_4_PIN) & R_4_MASK )) przyciski |= (1<<14);
    else przyciski &=~ (1<<14);


    PORT(C_1_PORT)  |= C_1_MASK;
    PORT(C_2_PORT)  |= C_2_MASK;
    PORT(C_3_PORT)  |= C_3_MASK;
    PORT(C_4_PORT)  &=~ C_4_MASK;

    if( !( PIN(R_1_PIN) & R_1_MASK )) przyciski |= (1<<3);
    else przyciski &=~ (1<<3);
    if( !( PIN(R_2_PIN) & R_2_MASK )) przyciski |= (1<<7);
    else przyciski &=~ (1<<7);
    if( !( PIN(R_3_PIN) & R_3_MASK )) przyciski |= (1<<11);
    else przyciski &=~ (1<<11);
    if( !( PIN(R_4_PIN) & R_4_MASK )) przyciski |= (1<<15);
    else przyciski &=~ (1<<15);
}
