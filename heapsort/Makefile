OBJS=heapsort.o test.o
CC=gcc
CFLAGS=-O -g -Wall

test:$(OBJS)
	$(CC) $(OBJS) -o test

heapsort.o:heapsort.c heapsort.h
	$(CC) $(CFLAGS) -c heapsort.c -o heapsort.o

test.o:test.c heapsort.h
	$(CC) $(CFLAGS) -c test.c -o test.o

clean:
	rm *.o test