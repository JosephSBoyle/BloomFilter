CC=gcc
CFLAGS=-I.

bloomfilter: main.o bloomfilter.o
	$(CC) -o main main.o bloomfilter.o