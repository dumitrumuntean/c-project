/*
 * test.c
 *
 * Created: 19/04/2018 09:05:20
 *  Author: Dima
 */

 
 #include <avr/io.h>
 #include <stdio.h>
 #include <avr/interrupt.h>
 #include "atmega2560_drivers.h"
 #include "minunit.h"
 #include "game.h"
 
 int tests_run = 0;
 
 static char * display_create_test()
 {
	 DDRA = 0Xff;
	 display_t result = display_create(&PORTA);
//	  mu_assert(destroy_display("destroy_display(&PORTA) == null"), result != NULL );
	  return 0;
 } 
static char * light_up_no_Test()
{
	DDRA = 0xff;
	int n = 0;
	PORTA = n;
	display_t self = display_create(&PORTA);
//	mu_assert(light_up_led("light_up_led(self,n) != 1"), n == 0);
	return 0;
}
static char * light_Off_led_Test()
{
		int n = 1;
		PORTA = n;
		display_t self = display_create(&PORTA);
//		mu_assert(light_off_led("light_off_led(self,n) != 0"), n == 1);
		return 0;
}
static char * light_up_led_Test()
{
	int n = 0;
	PORTA = n;
	display_t self = display_create(&PORTA);
//	mu_assert(light_up_led("light_up_led(self,n) != 1"), n == 0);
	return 0;
}
static char * destroy_display_test()
{
	DDRA = 0X00;
//	display_t result = destroy_display(&PORTA);
//	mu_assert(destroy_display("destroy_display(&PORTA) != null"), result == NULL );
	return 0;
} 
static char * light_off_all_Test()
{
	DDRA = 0X00;
	display_t result = display_create(&PORTA);
//	mu_assert(light_off_all("light_off_all(&PORTA) != null"), result == NULL);
	return 0;	
}
 static char *all_tests()
 {
	 display_create_test();
	 destroy_display_test();
	 light_up_led_Test();
	 light_Off_led_Test();
	 light_off_all_Test();
	 light_up_no_Test();
	 return 0;
 }

 int _main()
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
 