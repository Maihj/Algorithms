OBJS=quicksort.o test.o
CC=gcc
CFLAGS=-O -g -Wall

test:$(OBJS)
	$(CC) $(OBJS) -o test

quickheap.o:quicksort.c quicksort.h
	$(CC) $(CFLAGS) -c quicksort.c -o quicksort.o

test.o:test.c quicksort.h
	$(CC) $(CFLAGS) -c test.c -o test.o

clean:
	rm -rf *.o test