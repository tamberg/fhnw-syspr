CC=gcc
CFLAGS=-std=c99 -pedantic -pedantic-errors -Werror -Wall -Wextra

all: environ pid segments

environ: environ.c
pid: pid.c
segments: segments.c
	$(CC) $(CFLAGS) -Wno-unused-variable -o segments segments.c

clean:
	rm -f environ
	rm -f pid
	rm -f segments
