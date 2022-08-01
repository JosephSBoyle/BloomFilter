#include "bloomfilter.h"
#include "bitarray.h"
#include <stdbool.h>
#include <stddef.h>

// Each pair of i'th elements is a seed pair for a 'unique' hash function.
const static int prime_seeds_1[k] = {1103, 761, 83};
const static int prime_seeds_2[k] = {173, 587, 97};

/** Compute the modular hash of a char array.
 *  @param string: a pointer to the first element of a char array.
 *  @param seed_1: a seed value, should be a prime
 *  @param seed_2: a seed value, should also be a prime
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

/** Add a string to the bloom filter.
 *  @param bloom_filter: the filter to modify
 *  @param string: the string to add to the bloom filter.
 */
void add_string(Bitarray* bloom_filter, const char string[])
{
    for (int i = 0; i < k; i++)
    {
        size_t hash = modular_hash(string, prime_seeds_1[i], prime_seeds_2[i]);
        size_t position = hash % BITARRAY_SIZE;
        set_bit(bloom_filter, position);
    }
}

/** Check if a string is not in the bloom filter.
 *  @param Return false if the string is definitely not in the bloom filter
 *  @param Return true if the string is *probably* in the bloom filter
 */
bool check_string(const Bitarray* bloom_filter, const char string[])
{
    for (int i = 0; i < k; i++)
    {
        size_t hash = modular_hash(string, prime_seeds_1[i], prime_seeds_2[i]);
        size_t position = hash % BITARRAY_SIZE;

        if (read_bit(bloom_filter, position))
        {
            return true;
        }
    }
    return false;
}
