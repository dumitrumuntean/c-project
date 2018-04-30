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

int _main(void)
{
	DDRA = 0xff;
	DDRB = 0x00;

	srand(time(NULL));
	game_t game = game_create(&PORTA, &PINB);
	
	game_run(game);
	
    while (1) 
    {
    }
}

