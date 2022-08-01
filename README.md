# Bloomfilter

This project is a simple `C` implementation of a [bloom filter](https://en.wikipedia.org/wiki/Bloom_filter): a probabilistic data structure used to test membership in a set. A basic command line interface is provided to test the implementation.

## Quickstart
To run the project, build and run the executeable:

```bash
$ make
$ ./main
```

## Examples

```
$ ./main bob sally jane tim joe

Is the last string: 'joe' in the set of first strings?
definitely not
```
```
$ ./main bob sally jane tim bob

Is the last string: 'bob' in the set of first strings?
probably
```

Example of a [false positive](https://en.wikipedia.org/wiki/Bloom_filter#Probability_of_false_positives)!
```
$ ./main abc xyz

Is the last string: 'xyz' in the set of first strings?
probably
```

## Example uses of Bloom filters
- A spellchecker
- A 'username is taken' checker
- A profanity filter

    
## Notes
One of the great properties of bloom filters is that you can test for membership within a potentially huge set without storing the entire set. This CLI application doesn't demonstrate this particularly well as adding large numbers of words to the filter is impractical since they must all be typed.

## Contributing
If anybody would like to contribute a PR to improve the project they are welcome to. In particular, I think a method that reads a `.txt` or `.csv` file of words to add to the filter would be a useful addition.
