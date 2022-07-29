#include <stdio.h>
#include <stdbool.h>

#define N 4    // the number of strings
#define T 8    // the number of test words
#define C 4    // the number of characters in the words
#define M 1000 // the size of the bloom filter
#define k 3    // the number of hash functions

// Each pair of i'th elements is a seed pair for a 'unique' hash function.
int prime_seeds_1[k] = {1103, 761, 83};
int prime_seeds_2[k] = {173, 587, 97};

int modularHash(const char string[], int seed_1, int seed_2);
int checkString(const int bloomFilter[M], const char string[]);
void addString(int bloomFilter[M], const char string[]);

int main()
{

    const char *sampleWords[N] = {"fizz", "buzz", "bonk", "zzzz"};
    const char *testWords[T] = {
        // in the bloom filter
        "fizz",
        "buzz",
        "bonk",
        "zzzz",
        // not in the bloom filter
        "yyyy",
        "yike",
        "yzzz",
        "zzyz",
    };

    int bloomFilter[M] = {0}; // array of zeroes.
    for (int i = 0; i < N; i++)
    {
        addString(bloomFilter, sampleWords[i]);
    }

    for (int i = 0; i < M; i++)
    {
        printf("%d", bloomFilter[i]);
    }
    printf("\n");
    for (int i = 0; i < T; i++)
    {
        printf("word: '%s' bloom filter check result: %d\n", testWords[i], checkString(bloomFilter, testWords[i]));
    }
}

/* Add a string to the bloom filter.
 * @param bloomFilter: the filter to modify
 * @param string: the string to add to the bloom filter.
 */
void addString(int bloomFilter[M], const char string[])
{
    for (int i = 0; i < k; i++)
    {
        int hash = modularHash(string, prime_seeds_1[i], prime_seeds_2[i]);
        int position = hash % M;
        bloomFilter[position] = 1;
    }
}

/*  Check if a string is not in the bloom filter.
 *  Return false if the string is definitely not in the bloom filter
 *  Return true if the string is *probably* in the bloom filter
 */
int checkString(const int bloomFilter[M], const char string[])
{
    for (int i = 0; i < k; i++)
    {
        int hash = modularHash(string, prime_seeds_1[i], prime_seeds_2[i]);
        int position = hash % M;

        if (bloomFilter[position] == 1)
        {
            return true;
        }
    }
    return false;
}

/* Compute the modular hash of a char array.
 * @param string, array of characters to hash
 * @param R: a seed value, should be a prime
 * @param M: a seed value, should also be a prime
 */
int modularHash(const char string[], int seed_1, int seed_2)
{
    int hash = 0;
    for (int i = 0; i < C; i++)
    {
        char s = string[i];
        int n = (int)s;
        hash = (seed_1 * hash + n) % seed_2;
    }
    return hash;
}
