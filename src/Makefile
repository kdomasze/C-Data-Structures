CC = gcc
CFLAGS = -ansi -Wall
LGLAGS = -Wall -lm

OBJ_DIR = ../obj
BIN_DIR = ../bin
EXEC = structs

all: $(OBJ_DIR)/main.o $(OBJ_DIR)/linkedlist.o $(OBJ_DIR)/linkedlist_test.o
	$(CC) $(CFLAGS) $(OBJ_DIR)/main.o $(OBJ_DIR)/linkedlist.o $(OBJ_DIR)/linkedlist_test.o -o $(BIN_DIR)/$(EXEC) -g

$(OBJ_DIR)/main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o $(OBJ_DIR)/main.o -g

$(OBJ_DIR)/linkedlist.o: ./structures/linkedlist.c ./structures/linkedlist.h
	$(CC) $(CFLAGS) -c ./structures/linkedlist.c -o $(OBJ_DIR)/linkedlist.o -g

$(OBJ_DIR)/linkedlist_test.o: ./tests/linkedlist_test.c ./tests/linkedlist_test.h
	$(CC) $(CFLAGS) -c ./tests/linkedlist_test.c -o $(OBJ_DIR)/linkedlist_test.o -g

clean:
	rm -f $(OBJ_DIR)/*.o

cleanall: clean
	rm -f $(BIN_DIR)/struct

run: all
	$(BIN_DIR)/$(EXEC)
