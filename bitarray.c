#include "bitarray.h"

long get_mask(size_t indx)
{
	// return a long with the only bit set being in the same place as the bit at indx
	unsigned char bit_offset = indx % BITS_PER_LONG;	
	return 1 << bit_offset;
}

void set_bit(Bitarray* bitarray, size_t indx)
{
	size_t long_offset = indx / BITS_PER_LONG;
	long mask = get_mask(indx);

	// 0 OR bit == bit
	// 1 OR bit == 1
	// therefore doing |= on mask will set the bit in question
	// whilst leaving all the other bits unaffected
	bitarray->data[long_offset] |= mask;
}

void clear_bit(Bitarray* bitarray, size_t indx)
{
	size_t long_offset = indx / BITS_PER_LONG;
	long mask = get_mask(indx);

	// 0 AND bit == 0
	// 1 AND bit == bit
	// therefore doing &= on ~mask will clear the bit in question
	// whilst leaving all the other bits unaffected
	bitarray->data[long_offset] &= ~mask;
}

bool read_bit(const Bitarray* bitarray, size_t indx)
{
	size_t long_offset = indx / BITS_PER_LONG;
	long mask = get_mask(indx);

	// if the specified bit is set then the bitwise and will evaluate to a non-zero long
	// otherwise it becomes zero
	return (bitarray->data[long_offset] & mask) != 0;
}
