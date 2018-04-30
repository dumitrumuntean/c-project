
#ifndef KEYBOARD_H_
#define KEYBOARD_H_

#include <util/delay.h>
 #include <avr/io.h>


typedef struct keyboard *keyboard_t;

keyboard_t		keyboard_create(volatile uint8_t *port);
void			destroy_keyboard(keyboard_t self);
int				get_input(keyboard_t self);
int				pressed_button(keyboard_t self);


#endif