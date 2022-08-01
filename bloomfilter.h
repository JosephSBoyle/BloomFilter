#ifndef BLOOMFILTER_H_
#define BLOOMFILTER_H_

#include "bitarray.h"
#include <stdbool.h>

#define N 4    // the number of strings
#define T 8    // the number of test words
#define k 3    // the number of hash functions

bool check_string(const Bitarray* bloomFilter, const char string[]);
void add_string(Bitarray* bloomFilter, const char string[]);

#endif
