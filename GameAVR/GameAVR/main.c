/*
 * GameAVR.c
 *
 * Created: 19/04/2018 09:02:19
 * Author : Dima
 */ 
#include <avr/io.h>
#include "game.h"

int _main(void)
{
	DDRA = 0xff;
	DDRB = 0;
	
	game_t game = game_create(&PORTA, &PINB);
	
	
	game_start_pattern(game);	
	
    /* Replace with your application code */
    while (1) 
    {
    }
}

