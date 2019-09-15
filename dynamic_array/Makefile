CC=gcc
CFLAGS=-I.
DEPS=dynamic_array.h


%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)


import_test: import_test.o dynamic_array.o
	$(CC) -o import_test import_test.o dynamic_array.o
