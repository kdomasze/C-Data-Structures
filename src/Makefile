CC = gcc
CFLAGS = -ansi -Wall
LGLAGS = -Wall -lm

OBJ_DIR = ../obj
BIN_DIR = ../bin
EXEC = structs

all: $(OBJ_DIR)/main.o $(OBJ_DIR)/linkedlist.o $(OBJ_DIR)/linkedlist_test.o $(OBJ_DIR)/map.o $(OBJ_DIR)/map_test.o $(OBJ_DIR)/binarysearchtree.o $(OBJ_DIR)/binarysearchtree_test.o $(OBJ_DIR)/stack.o $(OBJ_DIR)/stack_test.o $(OBJ_DIR)/queue.o $(OBJ_DIR)/queue_test.o
	$(CC) $(CFLAGS) $(OBJ_DIR)/main.o $(OBJ_DIR)/linkedlist.o $(OBJ_DIR)/linkedlist_test.o $(OBJ_DIR)/map.o $(OBJ_DIR)/map_test.o $(OBJ_DIR)/binarysearchtree.o $(OBJ_DIR)/binarysearchtree_test.o $(OBJ_DIR)/stack.o $(OBJ_DIR)/stack_test.o $(OBJ_DIR)/queue.o $(OBJ_DIR)/queue_test.o -o $(BIN_DIR)/$(EXEC) -g -lm

$(OBJ_DIR)/main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o $(OBJ_DIR)/main.o -g

$(OBJ_DIR)/linkedlist.o: ./structures/linkedlist.c ./structures/linkedlist.h
	$(CC) $(CFLAGS) -c ./structures/linkedlist.c -o $(OBJ_DIR)/linkedlist.o -g

$(OBJ_DIR)/linkedlist_test.o: ./tests/linkedlist_test.c ./tests/linkedlist_test.h
	$(CC) $(CFLAGS) -c ./tests/linkedlist_test.c -o $(OBJ_DIR)/linkedlist_test.o -g

$(OBJ_DIR)/map.o: ./structures/map.c ./structures/map.h
	$(CC) $(CFLAGS) -c ./structures/map.c -o $(OBJ_DIR)/map.o -g

$(OBJ_DIR)/map_test.o: ./tests/map_test.c ./tests/map_test.h
	$(CC) $(CFLAGS) -c ./tests/map_test.c -o $(OBJ_DIR)/map_test.o -g

$(OBJ_DIR)/binarysearchtree.o: ./structures/binarysearchtree.c ./structures/binarysearchtree.h
	$(CC) $(CFLAGS) -c ./structures/binarysearchtree.c -o $(OBJ_DIR)/binarysearchtree.o -g

$(OBJ_DIR)/binarysearchtree_test.o: ./tests/binarysearchtree_test.c ./tests/binarysearchtree_test.h
	$(CC) $(CFLAGS) -c ./tests/binarysearchtree_test.c -o $(OBJ_DIR)/binarysearchtree_test.o -g

$(OBJ_DIR)/stack.o: ./structures/stack.c ./structures/stack.h
	$(CC) $(CFLAGS) -c ./structures/stack.c -o $(OBJ_DIR)/stack.o -g

$(OBJ_DIR)/stack_test.o: ./tests/stack_test.c ./tests/stack_test.h
	$(CC) $(CFLAGS) -c ./tests/stack_test.c -o $(OBJ_DIR)/stack_test.o -g

$(OBJ_DIR)/queue.o: ./structures/queue.c ./structures/queue.h
	$(CC) $(CFLAGS) -c ./structures/queue.c -o $(OBJ_DIR)/queue.o -g

$(OBJ_DIR)/queue_test.o: ./tests/queue_test.c ./tests/queue_test.h
	$(CC) $(CFLAGS) -c ./tests/queue_test.c -o $(OBJ_DIR)/queue_test.o -g

clean:
	rm -f $(OBJ_DIR)/*.o

cleanall: clean
	rm -f $(BIN_DIR)/struct

run: all
	$(BIN_DIR)/$(EXEC)
