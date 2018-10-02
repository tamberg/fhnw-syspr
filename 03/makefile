CC=gcc 
CFLAGS=-std=c99 -pedantic -pedantic-errors -Werror -Wall -Wextra

all: clone clone_v2 cpu_temp dup lseek stdio_buf tmp_file

clone: clone.c
clone_v2: clone_v2.c
cpu_temp: cpu_temp.c
dup: dup.c
lseek: lseek.c
stdio_buf: stdio_buf.c
tmp_file: tmp_file.c

clean:
	rm -f clone
	rm -f clone_v2
	rm -f cpu_temp
	rm -f dup
	rm -f dup.txt
	rm -f lseek
	rm -f temp.csv
	rm -f stdio_buf
	rm -f tmp_file
