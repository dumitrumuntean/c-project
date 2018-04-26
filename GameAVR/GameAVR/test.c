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
 
 static char * display_create(&PORTA)
 {
	 DDRA = 0Xff;
	 display_t result = display_create(&PORTA);
	  mu_assert(display_create("display_create(&PORTA) == null"), result != NULL );
	  return 0;
 } 
 
 static char * all_tests()
 {
	 display_create(&PORTA);

	 return 0;
 }

 #ifdef TEST
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
 