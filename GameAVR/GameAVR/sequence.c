/*
 * sequence.c
 *
 * Created: 25/04/2018 18:58:38
 *  Author: Dima
 */ 

#include "sequence.h"

sequence_t	sequence_create()
{
	sequence_t seq = (sequence_t)malloc(sizeof(sequence_t));
	seq->random_pattern = malloc(sizeof(int) * 1); // start with level 1;
	
	return seq; 
}
void  sequence_destroy(sequence_t seq)
{
	free(seq);
	return;
}

void	fill_random_sequence(sequence_t self, int size)
{
	free(self->random_pattern);
	srand(time(NULL));
	self->random_pattern = malloc(sizeof(int)*size);
	
	for(int i = 0; i < size; i++)
		*(self->random_pattern + i) = rand()%7;

	return;
}
