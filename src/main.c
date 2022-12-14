#include "bloomfilter.h"
#include "bitarray.h"
#include <stdio.h>
#include <stdbool.h>

/* Create a bloom filter from the first `n` arguments and
 * then check if the last argument is filtered by the bloom filter and print the result.
 */
int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Error: at least 2 args are required.\n\n"
               "Args\n"
               "    arg: [*filter_string]: a sequence of strings to add to the bloom filter.\n"
               "    arg: test_word: a word to check for in the filter\n\n"
               "Usage\n"
               "    $ ./main [*filter_string] test_string\n"
               "    $ ./main filter_string_1 filter_string_2 ... filter_string_n test_word\n");
        return 1;
    }
    Bitarray bloom_filter = {0};

    for (int i = 1; i < argc - 1; i++)
    {
        add_string(&bloom_filter, argv[i]);
    }

    char *last_string = argv[argc - 1];
    bool match = check_string(&bloom_filter, last_string);
    printf("Is the last string: '%s' in the set of first strings?\n", last_string);
    printf(match ? "probably\n" : "definitely not\n");
}
