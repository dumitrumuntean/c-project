/*
 * game.c
 *
 * Created: 17/04/2018 10:43:09
 *  Author: Dima
 */ 

#include "game.h"

struct game
{
	keyboard_t keyb; //keyboard
	display_t disp;  // display
	sequence_t seq;  // sequence
	bool isRunning;
	int level;	
};

game_t game_create(volatile uint8_t *displat_port, volatile uint8_t *keyboard_port)
{
	game_t new_game		= (game_t)malloc(sizeof(game_t));
	
	new_game->level		= 1;
	new_game->isRunning	= true;
	new_game->keyb		= keyboard_create(keyboard_port);
	new_game->disp		= display_create(displat_port);
	sequence_t a		= sequence_create();
	new_game->seq		= a;	
	
	return new_game;
}

void game_destroy(game_t realgame)
{
	free(realgame);
	return;
}

void game_start_pattern(game_t self)
{
	unsigned char pattern = 0b01010101;
	
	while(pressed_button(self->keyb) == -1)
	{
		light_up_no(self->disp, pattern);
		_delay_ms(100);
		pattern = ~pattern;
	}
	
	light_off_all(self->disp);
	return;
}
void game_lost_pattern(game_t self)
{	
	
	for(int i = 0; i < 8; i++)
	{
		light_up_led(self->disp, i);
		_delay_ms(500);
	}
	
	light_off_all(self->disp);
	return;
}
void win_level_pattern(game_t self)
{
	unsigned char pattern = 0b11111111;
	int i = 0;
	while(i < 6)
	{
		light_up_no(self->disp, pattern);
		_delay_ms(300);
		pattern = ~pattern;
		i++;
	}
	
	return;
}

void next_level(game_t self)
{
	self->level++;
}

void restart_game(game_t self)
{
	self->level = 1;
}

void game_run(game_t self)
{
	game_start_pattern(self);
		
	while(self->level < 3 && self->isRunning == true)
	{
		fill_random_sequence(self->seq, self->level);
		
		for(int i = 0; i < self->level; i++)
		{
			int b = (self->seq)->random_pattern[i];
				light_up_led(self->disp, b);
		}
	}
}
