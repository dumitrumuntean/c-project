/*
 * sequence.c
 *
 * Created: 25/04/2018 18:58:38
 *  Author: Dima
 */ 

#include "sequence.h"

struct sequence
{
	int current_index; // current index of the sequence
	int *random_pattern; // an array of integers to be filled up with random numbers
};

sequence_t	sequence_create()
{
	sequence_t seq = (sequence_t)malloc(sizeof(sequence_t)); // allocating memory
	seq->random_pattern =(int) malloc(sizeof(int)); // allocating memory for array
	seq->current_index = 0; //set the index at the beginning of the array
	return seq; 
}

void  sequence_destroy(sequence_t seq)
{
	free(seq);
	return;
}

void	fill_random_sequence(sequence_t self, int size)
{
	//if there is already memory allocated by this pointer
	//clean it up
	if (self->random_pattern)
		free(self->random_pattern);
	
	self->current_index = 0; // set the current index to 0(zero)
	self->random_pattern = malloc(size*sizeof(int)); // allocating necessary memory
	
	//filling up the array with random numbers
	for(int i = 0; i < size; i++)
		self->random_pattern[i] = rand()%7;

	return;
}

int	get_next(sequence_t self)
{
	// return the value at the current index
	//incrementing index afterwards
	return *(self->random_pattern + self->current_index++);
}

void	reset_index(sequence_t self)
{
	//resetting current index to 0 again
	self->current_index = 0;
	
	return;
}
