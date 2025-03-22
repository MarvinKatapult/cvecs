CC=gcc
CFLAGS=-Wall -Wextra -pedantic -pedantic-errors -std=c99 -I./
BIN=example

all: example

example: cvecs.c cvecs.h example.c
	$(CC) $(CFLAGS) -o $(BIN) cvecs.c example.c

clean:
	rm -rf $(BIN)
