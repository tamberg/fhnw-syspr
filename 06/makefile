CC=gcc
CFLAGS=-std=c99 -pedantic -pedantic-errors -Werror -Wall -Wextra -pthread

all: cond eintr iter mutex prod thread thread_arg

cond: cond.c
eintr: eintr.c
iter: iter.c
mutex: mutex.c
thread: thread.c
thread_arg: thread_arg.c

clean:
	rm -f cond
	rm -f eintr
	rm -f iter
	rm -f mutex
	rm -f thread
	rm -f thread_arg
