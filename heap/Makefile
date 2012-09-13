OBJS=heap.o test.o
CC=gcc
CFLAGS=-O -g -Wall

test:$(OBJS)
	$(CC) $(OBJS) -o test

heap.o:heap.c heap.h
	$(CC) $(CFLAGS) -c heap.c -o heap.o

test.o:test.c heap.h
	$(CC) $(CFLAGS) -c test.c -o test.o

clean:
	rm *.o test