#include <stdbool.h>

#define N 4    // the number of strings
#define T 8    // the number of test words
#define M 1000 // the size of the bloom filter
#define k 3    // the number of hash functions

bool check_string(const int bloomFilter[M], const char string[]);
void add_string(int bloomFilter[M], const char string[]);