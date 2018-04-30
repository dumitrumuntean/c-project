/*
 * keyboard.c
 *
 * Created: 24/04/2018 11:17:50
 *  Author: Dima
 */ 
#include "keyboard.h"

struct keyboard
{
	volatile uint8_t *pin;
};

keyboard_t keyboard_create(volatile uint8_t *pin)
{	
	*pin = 0x00;
	
	keyboard_t new_keyboard = (keyboard_t)malloc(sizeof(keyboard_t));	
	new_keyboard->pin = pin;
	
	return new_keyboard;
}

void destroy_keyboard(keyboard_t self)
{
	free(self);
	return;
}

int get_input(keyboard_t self)
{
	int val	= pressed_button(self);
	int temp = val;

	while(val == temp)
			val = pressed_button(self);
	
	return val;
}

int pressed_button(keyboard_t self)
{
	int i = -1;
	
	uint8_t input = ~(PINB);
	
	while(input != 0)
	{
		input = (input>>1);
		i++;
	}

	return i;	
}