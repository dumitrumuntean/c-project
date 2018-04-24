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
	*pin = 0;
	
	keyboard_t new_keyboard = (keyboard_t)malloc(sizeof(struct keyboard));
	new_keyboard->pin = pin;
	
	return new_keyboard;
}

void destroy_keyboard(keyboard_t self)
{
	free(self);
}

int get_input(keyboard_t self)
{
	int val;
	unsigned char temp = *(self->pin);
	
	while(temp == self->pin);

	if(!(PINB & 0x01))	//1
	val=0;
	else if(!(PINB & 0x02))//2
	val=1;
	else if(!(PINB & 0x04)) //3
	val=2;
	else if(!(PINB & 0x08)) // 4
	val=3;
	else if(!(PINB & 0x10))// 5
	val=4;
	else if(!(PINB & 0x20)) // 6
	val=5;
	else if(!(PINB & 0x40)) // 7
	val=6;
	else if(!(PINB & 0x80)) // 8
	val=7;
	else
	val = -1;
	
	return val;
}

unsigned char pressed_button(keyboard_t self)
{
	return PINB;
}