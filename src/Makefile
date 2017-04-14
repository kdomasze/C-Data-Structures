CC = gcc
CFLAGS = -ansi -Wall
LGLAGS = -Wall -lm

all: main.o linkedlist.o linkedlist_test.o
	$(CC) $(CFLAGS) main.o linkedlist.o linkedlist_test.o -o ../bin/structs -g

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o -g

linkedlist.o: ./structures/linkedlist.c ./structures/linkedlist.h
	$(CC) $(CFLAGS) -c ./structures/linkedlist.c -o linkedlist.o -g

linkedlist_test.o: ./tests/linkedlist_test.c ./tests/linkedlist_test.h
	$(CC) $(CFLAGS) -c ./tests/linkedlist_test.c -o linkedlist_test.o -g
