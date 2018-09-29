CC=gcc 
CFLAGS=-std=c99 -pedantic -pedantic-errors -Werror -Wall -Wextra

all: count errno fib garbage map my_program nest/home power scope static struct struct_v2 swap

my_program: main.o f.o
	$(CC) $(CFLAGS) -o my_program main.o f.o
main.o: main.c
	$(CC) $(CFLAGS) -c main.c
f.o: f.c
	$(CC) $(CFLAGS) -c f.c

garbage: garbage.c
	$(CC) -o garbage garbage.c
#	$(CC) $(CFLAGS) -o garbage garbage.c

nest/home:
	$(MAKE) -C nest

count: count.c
errno: errno.c
fin: fin.c
map: map.c
power: power.c
scope: scope.c
static: static.c
struct: struct.c
struct_v2: struct_v2.c
swap: swap.c

clean:
	(cd nest && make clean)
	rm -f *.o
	rm -f count
	rm -f errno
	rm -f fib
	rm -f garbage
	rm -f map
	rm -f my_program
	rm -f power
	rm -f scope
	rm -f static
	rm -f struct
	rm -f struct_v2
	rm -f swap
