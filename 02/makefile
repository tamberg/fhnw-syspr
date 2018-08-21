CC=gcc 
CFLAGS=-std=c99 -pedantic -pedantic-errors -Werror -Wall -Wextra

all: my_program power struct_fun swap

my_program: main.o f.o
	$(CC) $(CFLAGS) -o my_program main.o f.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c
f.o: f.c
	$(CC) $(CFLAGS) -c f.c

power: power.c
struct_fun: struct_fun.c
swap: swap.c

clean:
	rm -f *.o
	rm -f my_program
	rm -f power
	rm -f struct_fun
	rm -f swap
