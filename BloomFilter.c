#include <stdio.h>

// Function headers
int modularHash(char string[], int R, int M);
int sh1(char string[]);
int sh2(char string[]);
int sh3(char string[]);

int main()
{
    enum
    {
        N = 3,  // the number of strings
        M = 10, // the size of the bloom filter
        k = 3,  // the number of hash functions
    };

    char *strings[N] = {"abc", "777", "xyz"};

    int bloom_filter[M] = {0}; // array of `n` 0s.

    // array of pointers to hash functions.
    int (*hashers[k])() = {sh1, sh2, sh3};

    // Fill the bloom filter
    for (int j = 0; j < N; j++)
        for (int i = 0; i < k; i++)
        {
            {
                // Compute the hash of string j using the k'th hash function
                // Map the hash to a position in the bloom filter
                // then add this position to the bloom filter.
                int result = hashers[i](strings[j]);
                int position = result % M;
                bloom_filter[position] = 1;
            }
        }

    // Print the bloom filter
    for (int i = 0; i < M; i++)
        printf("%d ", bloom_filter[i]);


    // TODO implement a function for checking a string against the bloom filter.
    return 0;
}

/*
 Compute the modular hash of a char array
    @param string, array of characters to hash
    @param R: a seed value, should be a prime
    @param M: a seed value, should also be a prime
*/
int modularHash(char string[], int R, int M)
{
    int chars = 3; // the number of characters
    int hash = 0;

    char s;
    int n;

    for (int i = 0; i < chars - 1; i++)
        s = string[i];
    n = (int)s;
    hash = (R * hash + n) % M;
    return hash;
}

int sh1(char string[])
{
    int M = 3;
    int R = 31;
    return modularHash(string, M, R);
}

int sh2(char string[])
{
    int M = 47;
    int R = 17;
    return modularHash(string, M, R);
}

int sh3(char string[])
{
    int M = 97;
    int R = 29;
    return modularHash(string, M, R);
}
