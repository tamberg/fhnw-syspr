CC=gcc
CFLAGS=-std=c99 -pedantic -pedantic-errors -Werror -Wall -Wextra -pthread

all: eintr iter iter_mutex prod prod_cond thread thread_arg

eintr: eintr.c
iter: iter.c
iter_mutex: iter_mutex.c
prod: prod.c
prod_cond: prod_cond.c
thread: thread.c
thread_arg: thread_arg.c

clean:
	rm -f eintr
	rm -f iter
	rm -f iter_mutex
	rm -f prod
	rm -f prod_cond
	rm -f thread
	rm -f thread_arg
