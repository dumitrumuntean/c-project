/*
 * GameAVR.c
 *
 * Created: 19/04/2018 09:02:19
 * Author : Dima
 */ 
//#include <avr/io.h>
#include "game.h"
#include<stdlib.h>

 #include <avr/io.h>
 #include <stdio.h>
 #include <avr/interrupt.h>
 #include "atmega2560_drivers.h"
 #include "minunit.h"
 #include "game.h"

int main(void)
{
	
	DDRA = 0xff;
	DDRB = 0x00;
	
	init_stdio(0, 10000000L);
	sei();
//	srand(time(NULL));
	
	//keyboard_t k = keyboard_create(&PINB);
	display_t d = display_create(&PORTA);
	
	game_t game = game_create(&PORTA, &PINB);
//	game_start_pattern(game);
	
//	light_up_no(d, 22);
	
	game_run(game);
	
    while (1) 
    {
	//	printf("%d", get_input(k));
    }
}

