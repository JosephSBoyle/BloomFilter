#ifndef BLOOMFILTER_H_
#define BLOOMFILTER_H_

#include "bitarray.h"
#include <stdbool.h>

#define k 3    // the number of hash functions

bool check_string(const Bitarray* bloom_filter, const char string[]);
void add_string(Bitarray* bloom_filter, const char string[]);

#endif
