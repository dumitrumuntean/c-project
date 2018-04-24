/*
 * keyboard.h
 *
 * Created: 24/04/2018 11:18:26
 *  Author: Dima
 */ 
#ifndef KEYBOARD_H_
#define KEYBOARD_H_

#include <avr/io.h>
#include <stdlib.h>

typedef struct keyboard * keyboard_t;

keyboard_t		keyboard_create(volatile uint8_t *port);
void			destroy_keyboard(keyboard_t self);
int				get_input(keyboard_t self);
unsigned char	pressed_button(keyboard_t self);


#endif