/*
 * game.c
 *
 * Created: 17/04/2018 10:43:09
 *  Author: Dima
 */ 

#include "game.h"

struct game
{
	keyboard_t	keyb; //keyboard
	display_t	disp;  // display
	sequence_t	seq;  // sequence
	bool		isRunning;
};

game_t game_create(volatile uint8_t *display_port, volatile uint8_t *keyboard_port)
{
	game_t new_game		= (game_t)malloc(sizeof(game_t));

	new_game->isRunning	=	true;
	new_game->keyb		=	keyboard_create(keyboard_port);
	new_game->disp		=	display_create(display_port);
	new_game->seq		=	sequence_create();	
	
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
		_delay_ms(1000);
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

/*
	A function which runs the game from
	start to the end
*/
void game_run(game_t self)
{
	game_start_pattern(self);	//displaying start game pattern
	
	int current_level = 1;		//level to begin the game from
	bool guessed;				// variable used to check whether 
								// the sequence was guessed or not
	//main loop starts here
	while(current_level < TOTAL_NO_OF_LEVELS)
	{
		//display generated sequence for
		//the current level
		game_display_sequence(self, current_level);
		
		//the point where user is guessing sequence
		guessed = game_guess_sequence(self, current_level);
		
		//if wrong guessed
		if(guessed == false)
		{
			game_lost_pattern(self);	//display pattern which notify the used about loss
			game_run(self);			//start game from the beginning
			return;
		}else
			win_level_pattern(self); //otherwise display a pattern
									//to notify the user about winning	
		//if the sequence was guessed than increase the level
		current_level++;	
	}
	return;
}

void game_display_sequence(game_t self, int level)
{
	int next;
	fill_random_sequence(self->seq, level);
	
	for(int i = 0; i < level; i++)
	{
		next = get_next(self->seq);
		light_up_led(self->disp, next);
		_delay_ms(800);
		light_off_all(self->disp);
		_delay_ms(300);
	}			
	reset_index(self->seq);
}

bool game_guess_sequence(game_t self, int level)
{
		int next;
		int temp;
		bool guessed = true;
		int count = 0;
		
		while(count < level)
		{
			next = get_input(self->keyb);
			light_up_led(self->disp, next);
			temp = next;
			
			while(temp == pressed_button(self->keyb));
						
			light_off_all(self->disp);
			
			if(next != get_next(self->seq))
			{
				guessed = false;
				break;
			}
			count++;
		}
		reset_index(self->seq);		
		
		return guessed;	
}