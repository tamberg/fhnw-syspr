CC=gcc 
CFLAGS=-std=c99 -pedantic -pedantic-errors -Werror -Wall -Wextra

all: count fib map my_program power scope struct_fun swap

my_program: main.o f.o
	$(CC) $(CFLAGS) -o my_program main.o f.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c
f.o: f.c
	$(CC) $(CFLAGS) -c f.c

nest/home:
	make -C home

count: count.c
fin: fin.c
map: map.c
power: power.c
scope: scope
struct_fun: struct_fun.c
swap: swap.c

clean:
	(cd nest && make clean)
	rm -f *.o
	rm -f count
	rm -f fib
	rm -f map
	rm -f my_program
	rm -f power
	rm -f struct_fun
	rm -f scope
	rm -f swap
