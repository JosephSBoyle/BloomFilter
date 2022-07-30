#ifndef BITARRAY_H_
#define BITARRAY_H_

#include <stdbool.h>
#include <stddef.h>

#define BITARRAY_SIZE 1000
#define BITS_PER_CHAR 8
#define BITS_PER_LONG BITS_PER_CHAR * sizeof(long)

typedef struct Bitarray
{
	// add 1 because integer division always rounds down
	long data[1 + (BITARRAY_SIZE / BITS_PER_LONG)];
} Bitarray;

Bitarray init_zeroed_bitarray(void);
void write_bit(Bitarray*, size_t indx, bool bit);
bool read_bit(const Bitarray*, size_t indx);

#endif
