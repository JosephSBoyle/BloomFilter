#include <stdio.h>
#include "bloomfilter.h"

/* Create a bloom filter from the first `n` arguments and
 * then check if the last argument is filtered by the bloom filter and print the result.
 */
int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Error: at least 2 args are required.\n");
        return 1;
    }
    int bloom_filter[M] = {0};

    for (int i = 1; i < argc - 1; i++)
    {
        add_string(bloom_filter, argv[i]);
    }

    char *last_string = argv[argc - 1];
    bool match = check_string(bloom_filter, last_string);
    printf("Is the last string: '%s' in the set of first strings?\n", last_string);

    (match == true) ? printf("probably\n") : printf("definitely not\n");
}
