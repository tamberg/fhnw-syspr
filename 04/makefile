CC=gcc
CFLAGS=-std=c99 -pedantic -pedantic-errors -Werror -Wall -Wextra

all: environ heap malloc pause pid segments sigint size

environ: environ.c
heap: heap.c
malloc: malloc.c
	$(CC) $(CFLAGS) -Wno-unused-parameter -o malloc malloc.c
pause: pause.c
	$(CC) $(CFLAGS) -Wno-unused-parameter -o pause pause.c
pid: pid.c
segments: segments.c
	$(CC) $(CFLAGS) -Wno-unused-variable -o segments segments.c
sigint: sigint.c
size: size.c

clean:
	rm -f environ
	rm -f heap
	rm -f malloc
	rm -f pause
	rm -f pid
	rm -f segments
	rm -f sigint
	rm -f size
