#include "bloomfilter.h"
#include <stdbool.h>

// Each pair of i'th elements is a seed pair for a 'unique' hash function.
const static int prime_seeds_1[k] = {1103, 761, 83};
const static int prime_seeds_2[k] = {173, 587, 97};

/* Compute the modular hash of a char array.
 * @param a string (char array) to hash
 * @param R: a seed value, should be a prime
 * @param M: a seed value, should also be a prime
 */
int modular_hash(const char string[], int seed_1, int seed_2)
{
    int hash = 0;
    for (const char* character = string; *character != '\0'; character++)
    {
        hash = (seed_1 * hash + *character) % seed_2;
    }
    return hash;
}

/* Add a string to the bloom filter.
 * @param bloomFilter: the filter to modify
 * @param string: the string to add to the bloom filter.
 */
void add_string(bool bloom_filter[M], const char string[])
{
    for (int i = 0; i < k; i++)
    {
        int hash = modular_hash(string, prime_seeds_1[i], prime_seeds_2[i]);
        int position = hash % M;
        bloom_filter[position] = 1;
    }
}

/*  Check if a string is not in the bloom filter.
 *  Return false if the string is definitely not in the bloom filter
 *  Return true if the string is *probably* in the bloom filter
 */
bool check_string(const bool bloom_filter[M], const char string[])
{
    for (int i = 0; i < k; i++)
    {
        int hash = modular_hash(string, prime_seeds_1[i], prime_seeds_2[i]);
        int position = hash % M;

        if (bloom_filter[position])
        {
            return true;
        }
    }
    return false;
}
