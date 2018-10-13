CC=gcc
CFLAGS=-std=c99 -pedantic -pedantic-errors -Werror -Wall -Wextra

all: environ heap pid segments size

environ: environ.c
heap: heap.c
pid: pid.c
segments: segments.c
	$(CC) $(CFLAGS) -Wno-unused-variable -o segments segments.c
size: size.c

clean:
	rm -f environ
	rm -f heap
	rm -f pid
	rm -f segments
	rm -f size
