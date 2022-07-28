#include <stdio.h>
enum
{
    N = 4,    // the number of strings
    T = 8,    // the number of test words
    M = 1000, // the size of the bloom filter
    k = 3,    // the number of hash functions
};
int modularHash(const char string[], int R, int M);
int checkString(const int bloomFilter[M], const char string[]);
void addString(int bloomFilter[M], const char string[]);

int bloomFilter[M] = {0}; // array of zeroes.

// Each pair of i'th elements is a seed pair for a 'unique' hash function.
int RprimeSeeds[k] = {1103, 761, 83};
int MprimeSeeds[k] = {173, 587, 101};

const char *sampleWords[N] = {"fizz", "buzz", "bonk", "zzzz"};
const char *testWords[T] = {
    "fizz",
    "buzz",
    "bonk",
    "zzzz",
    "yyyy", // not in the bloom filter
    "yike", // not in the bloom filter
    "zzyz", // not in the bloom filter
    "wyzz", // not in the bloom filter
};
int main()
{

    for (int i = 0; i < N; i++)
    {
        addString(bloomFilter, sampleWords[i]);
    }
    for (int i = 0; i < M; i++)
    {
        printf("%d", bloomFilter[i]);
    }
    for (int i = 0; i < T; i++)
    {
        printf("%d\n", checkString(bloomFilter, testWords[i]));
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
        int hash = modularHash(string, RprimeSeeds[i], MprimeSeeds[i]);
        int position = hash % M;
        bloomFilter[position] = 1;
    }
}

/*  Check if a string is not in the bloom filter.
 *  Return 0 if the string is definitely not in the bloom filter
 *  Return 1 if the string is *probably* in the bloom filter
 */
int checkString(const int bloomFilter[M], const char string[])
{
    for (int i = 0; i < k; i++)
    {
        int hash = modularHash(string, RprimeSeeds[i], MprimeSeeds[i]);
        int position = hash % M;

        if (bloomFilter[position] == 1)
        {
            return 1;
        }
    }
    return 0;
}

/* Compute the modular hash of a char array.
 * @param string, array of characters to hash
 * @param R: a seed value, should be a prime
 * @param M: a seed value, should also be a prime
 */
int modularHash(const char string[], int R, int M)
{
    int chars = 4; // the number of characters
    int hash = 0;

    int n;
    char s;

    for (int i = 0; i < chars; i++)
    {
        s = string[i];
        n = (int)s;
        hash = (R * hash + n) % M;
    }
    return hash;
}
