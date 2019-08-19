#
# CS 11: Makefile for C track, assignment 2.
#

CC              = gcc

sorter: sorter.o
	$(CC) sorter.o -o sorter

sorter.o: sorter.c
	$(CC) -Wall -Wstrict-prototypes -ansi -pedantic -c sorter.c

check:
	../c_style_check sorter.c

clean:
	rm -f sorter.o sorter


