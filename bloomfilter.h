#include <stdbool.h>

#define N 4    // the number of strings
#define T 8    // the number of test words
#define M 1000 // the size of the bloom filter
#define k 3    // the number of hash functions

int modular_hash(const char string[], int seed_1, int seed_2);
bool check_string(const int bloomFilter[M], const char string[]);
void add_string(int bloomFilter[M], const char string[]);