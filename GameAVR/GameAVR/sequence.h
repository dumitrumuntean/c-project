/*
 * sequence.h
 *
 * Created: 25/04/2018 18:58:24
 *  Author: Dima
 */ 

#ifndef SEQUENCE_H_
#define SEQUENCE_H_

#include <stdlib.h>

typedef struct sequence *sequence_t;

/*
   Creates a seaquence_t structure;
*/
sequence_t	sequence_create();

/*
	Clean up the memory used by sequence_t
	structure given as parameter;
*/
void		sequence_destroy(sequence_t seq);

/*
	Fill up the sequence_t structure given as parameter with 
	random values in the range of [0,1,2,3,4,5,6,7];
	The number of random elements generated depends on the size
	given as a parameter;
	Normally : size is level number;
*/
void	fill_random_sequence(sequence_t self, int size);

/*
	Get the next element from the sequence.
*/
int		get_next(sequence_t self);

/*
	Set the current index of the sequence equal to 0;
*/
void	reset_index(sequence_t self);

#endif