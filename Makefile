CC=gcc
CFLAGS=-Wall -Wextra -std=c99

TARGETS = infinite_product simple_queries gigel_and_the_checkboard another_queries

build: $(TARGETS)

infinite_product: infinite_product.c
	$(CC) $(CFLAGS) infinite_product.c -lm -o infinite_product
simple_queries: simple_queries.c
	$(CC) $(CFLAGS) simple_queries.c -lm -o simple_queries
gigel_and_the_checkboard: gigel_and_the_checkboard.c
	$(CC) $(CFLAGS) gigel_and_the_checkboard.c -lm -o gigel_and_the_checkboard
another_queries: another_queries.c
	$(CC) $(CFLAGS) another_queries.c -lm -o another_queries

clean:
	rm -f $(TARGETS)

