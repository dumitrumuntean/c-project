/*
 * sequence.h
 *
 * Created: 25/04/2018 18:58:24
 *  Author: Dima
 */ 

#ifndef SEQUENCE_H_
#define	SEQUENCE_H_

#include<stdlib.h>

typedef struct sequence *sequence_t;

sequence_t	sequence_create();
void		sequence_destroy(sequence_t seq);

void	fill_random_sequence(sequence_t self, int size);

#endif