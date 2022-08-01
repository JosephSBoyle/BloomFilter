CC=gcc
CFLAGS=-I.

bloomfilter: main.o bloomfilter.o bitarray.o
	$(CC) -o main main.o bloomfilter.o bitarray.o
