CC=gcc
CFLAGS=-std=c99 -pedantic -pedantic-errors -Werror -Wall -Wextra

all: execlp fork fffork #TODO sync

execlp: execlp.c
fork: fork.c
fffork: fffork.c
#TODO sync: sync.c
#TODO	$(CC) $(CFLAGS) -Wno-unused-parameter -Wno-unused-variable -o sync sync.c

clean:
	rm -f execlp
	rm -f fork
	rm -f fffork
	rm -f sync
