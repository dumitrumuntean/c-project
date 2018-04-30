/*
 * display.h
 *
 * Created: 24/04/2018 11:17:18
 *  Author: Dima
 */ 

#ifndef DISPLAY_H_
#define DISPLAY_H_

typedef struct display * display_t;
 #include <avr/io.h>

/*
	Creates a variable of display_t type
	with a given port as argument;
*/
display_t	display_create(volatile uint8_t *port);

/*
	Clean up the memory which is occupied by 
	display given as argument;
*/
void		destroy_display(display_t display);

/*
	Light up one led;
	@display_t self  : display structure
	@led_no : the led no [0,1,2,3,4,5,6,7]
	The led should be counted from right to left
*/
void light_up_led(display_t self, int led_no);

/*
	Switch off one led;
	@display_t self  : display structure
	@led_no : the led no [0,1,2,3,4,5,6,7]
	The led should be counted from right to left
*/
void light_off_led(display_t self, int led_no);

/*
	Light up one number in binary form;
	@display_t self  : display structure
	@int no : the number to be displayed
	the number will be converted to binary form;
*/
void light_up_no(display_t self, int no);

/*
	Switch off all led
	@display_t self  : display structure
*/
void light_off_all(display_t self);

#endif