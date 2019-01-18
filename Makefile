CC = gcc
CFLAGS= -Wall --std=c99 -g
OBJECTS = main.o my_string.o generic_vector.o tree.o

hangman: $(OBJECTS)
	$(CC) $(CFLAGS) -o hangman $(OBJECTS)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

my_string.o: my_string.c my_string.h
	$(CC) $(CFLAGS) -c my_string.c -o my_string.o

generic_vector.o: generic.h generic_vector.h generic_vector.c
	$(CC) $(CFLAGS) -c generic_vector.c -o generic_vector.o

tree.o: tree.c tree.h
	$(CC) $(CFLAGS) -c tree.c -o tree.o

clean:
	rm hangman $(OBJECTS)
