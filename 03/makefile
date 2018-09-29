CC=gcc 
CFLAGS=-std=c99 -pedantic -pedantic-errors -Werror -Wall -Wextra

all: cpu_temp dup file lseek stdio_buf tmp_file

cpu_temp: cpu_temp.c
dup: dup.c
file: file.c
lseek: lseek.c
stdio_buf: stdio_buf.c
tmp_file: tmp_file.c

clean:
	rm -f cpu_temp
	rm -f dup
        rm -f file
	rm -f lseek
	rm -f stdio_buf
	rm -f tmp_file
