/*
 * display.c
 *
 * Created: 24/04/2018 11:17:35
 *  Author: Dima
 */ 


#include "display.h"

struct display
{
	volatile uint8_t *port;
};

display_t display_create(volatile uint8_t *port)
{
    //*(port-1) = 0xff; a little to clever...
    *port = 0xff;
    display_t new_display = (display_t)malloc(sizeof(struct display));
    new_display->port = port;
    return new_display;
}

void destroy_display(display_t display){
	free(display);
}


void light_up_led(display_t self, int led_no)
{
	*(self->port) &= ~(1<<led_no);
	return;
}

void light_off_led(display_t self, int led_no)
{
	*(self->port) |= (1 << led_no);
	return;
}

void light_up_no(display_t self, int no)
{
	*(self->port) = ~(no<<PA0);
}

void light_off_all(display_t self)
{
	*(self->port)  = 0xff;
}