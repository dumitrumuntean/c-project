/*
 * test.c
 *
 * Created: 19/04/2018 09:05:20
 *  Author: Dima
 */
#include "test.h"
 
 int tests_run = 0;
 
 static char * display_create_test()
 {
	 DDRA = 0Xff;
	 display_t result = display_create(&PORTA);
	 mu_assert("display_create(&PORTA) == null", result != NULL);
	 return 0;
 } 
 
static char * light_up_no_5Test()
{
	DDRA = 0xff;
	volatile uint8_t* res = &PORTA;
	display_t display = display_create(res);
	light_off_all(display);
	light_up_no(display, 5);
	mu_assert("light_up_no(display,5) != 0b11111010", *res == 0b11111010);
	return 0;
}

static char * light_up_no_3Test()
{
	DDRA = 0xff;
	volatile uint8_t* res = &PORTA;
	display_t display = display_create(res);
	light_off_all(display);
	light_up_no(display, 3);
	mu_assert("light_up_no(display,3) != 0b11111010", *res == 0b11111100);
	return 0;
}
static char * light_Off_led_0Test()
{
	DDRA = 0xff;
	volatile uint8_t* res = &PORTA;
	display_t display = display_create(res);
	light_off_all(display);
	light_up_no(display, 255);
	light_off_led(display, 0);
	mu_assert("light_off_led(display, 0); != 0b00000001", *res == 0b00000001);
	return 0;
}

static char * light_Off_led_7Test()
{
	DDRA = 0xff;
	volatile uint8_t* res = &PORTA;
	display_t display = display_create(res);
	light_off_all(display);
	light_up_no(display, 255);
	light_off_led(display, 7);
	mu_assert("light_off_led(display, 7); != 0b10000000", *res == 0b10000000);
	return 0;
}

static char * light_up_led_3Test()
{
	DDRA = 0xff;
	volatile uint8_t* res = &PORTA;
	display_t display = display_create(res);
	light_off_all(display);
	light_up_led(display, 3);
	mu_assert("light_up_led(display,3) != 0b11110111", *res == 0b11110111);
	return 0;
}

static char * light_off_all_Test()
{
	DDRA = 0xff;
	volatile uint8_t* res = &PORTA;
	display_t display = display_create(res);
	light_up_no(display, 255);
	light_off_all(display);
	mu_assert("light_off_led(display, 7); != 0b11111111", *res == 0b11111111);
	return 0;
}

 static char * all_tests()
 {
	mu_run_test(display_create_test);
	mu_run_test(light_up_no_5Test);
	mu_run_test(light_up_no_3Test);
	mu_run_test(light_Off_led_0Test);
	mu_run_test(light_Off_led_7Test);
	mu_run_test(light_up_led_3Test);
	mu_run_test(light_off_all_Test);
	
	return 0;
 }

 int main()
 {
	 init_stdio(0, 10000000L);
	 sei();
	 
	DDRA = 0Xff;
	
	 char *result = all_tests();
	 if (result != 0) {
		 printf("error: %s\n", result);
	 }
	 else {
		 printf("ALL TESTS PASSED\n");
	 }

	 printf("Tests run: %d\n", tests_run);

	 while(1);
	 return result != 0;
 }
 