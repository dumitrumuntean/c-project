/*
 * game.h
 *
 * Created: 17/04/2018 10:43:28
 *  Author: Dima
 */ 

#ifndef GAME_H_
#define GAME_H_
#define F_CPU 10000000L

#include <stdbool.h>
#include <util/delay.h>
#include "display.h"
#include "keyboard.h"
#include "sequence.h"

typedef struct game * game_t;

game_t game_create(volatile uint8_t *displat_port, volatile uint8_t *keyboard_port);
void game_destroy(game_t realgame);

void game_start_pattern(game_t self);
void game_lost_pattern(game_t self);
void win_level_pattern(game_t self);
void next_level(game_t self);
void restart_game(game_t self);

void game_run(game_t self);
#endif

