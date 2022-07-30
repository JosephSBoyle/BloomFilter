#include "bitarray.h"

Bitarray init_zeroed_bitarray(void)
{
	Bitarray zeroed = {0};
	return zeroed;
}

void write_bit(Bitarray* bitarray, size_t indx, bool bit)
{
	size_t long_offset = indx / BITS_PER_LONG;
	unsigned char bit_offset = indx % BITS_PER_LONG;
	long mask = bit << (BITS_PER_LONG - bit_offset - 1);

	bitarray->data[long_offset] |= mask;
}

bool read_bit(const Bitarray* bitarray, size_t indx)
{
	size_t long_offset = indx / BITS_PER_LONG;
	unsigned char bit_offset = indx % BITS_PER_LONG;
	long mask = 1 << (BITS_PER_LONG - bit_offset - 1);

	return (bitarray->data[long_offset] & mask) != 0;
}
