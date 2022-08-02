#ifndef BITARRAY_H_
#define BITARRAY_H_

#include <stdbool.h>
#include <stddef.h>

#define BITARRAY_SIZE 1000
#define BITS_PER_CHAR 8
#define BITS_PER_LONG BITS_PER_CHAR * sizeof(long)

/**
 *	Bitarray is an array of longs such that it can take an arbitrary size
 *	instead of being constrained by the largest register size in the cpu.
 *
 *	read/write is done by first computing the index in the array of longs
 *	and then computing which is the correct bit in that long and then using
 *	bitwise and/or to read/write that bit respectively.
 */
typedef struct Bitarray
{
	// add 1 because integer division always rounds down
	long data[1 + (BITARRAY_SIZE / BITS_PER_LONG)];
} Bitarray;

void set_bit(Bitarray*, size_t indx);
void clear_bit(Bitarray*, size_t indx);
bool read_bit(const Bitarray*, size_t indx);

#endif
