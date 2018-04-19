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

static char * test_add_zeroAndZero()
{
	int result = add(0,0);
	mu_assert("add(0,0) != 0", result == 0);
	return 0;
}

static char * test_add_fiveAndEight()
{
	int result = add(5, 8);
	mu_assert("add(5,8) != 13", result == 13);
	return 0;
}

static char * test_add_minusFiveAndThree()
{
	int result = add(-5, 3);
	mu_assert("add(-5,3) != -2", result == -2);
	return 0;
}

static char * test_add_250and10()
{
	int result = add(250, 10);
	mu_assert("add(250,10) != 260", result == 260);
	return 0;
}

static char * all_tests()
{
	mu_run_test(test_add_zeroAndZero);
	mu_run_test(test_add_fiveAndEight);
	mu_run_test(test_add_minusFiveAndThree);
	mu_run_test(test_add_250and10);
	return 0;
}

int main()
{
	init_stdio(0, 10000000L);
	sei();

	char *result = all_tests();
	if (result != 0) {
		printf("error: %s\r\n", result);
	}
	else {
		printf("ALL TESTS PASSED\n");
	}

	printf("Tests run: %d\r\n", tests_run);

	while(1);
	return result != 0;
}
