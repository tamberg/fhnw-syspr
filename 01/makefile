all: args arr_ptr arrays basics expr hello odd sizeof strings structs switch typedef 

args: args.c
	gcc -std=c99 -pedantic -pedantic-errors -Werror -Wall -Wextra -o args args.c

arr_ptr: arr_ptr.c
	gcc -std=c99 -pedantic -pedantic-errors -Werror -Wall -Wextra -o arr_ptr arr_ptr.c

arrays: arrays.c
	gcc -std=c99 -pedantic -pedantic-errors -Werror -Wall -Wextra -o arrays arrays.c

CC=gcc 
CFLAGS=-std=c99 -pedantic -pedantic-errors -Werror -Wall -Wextra

basics: basics.c
expr: expr.c
hello: hello.c
odd: odd.c
sizeof: sizeof.c
strings: strings.c
structs: structs.c
switch: switch.c
typedef: typedef.c

clean:
	rm -f args
	rm -f arr_ptr
	rm -f arrays
	rm -f basics
	rm -f expr
	rm -f hello
	rm -f odd
	rm -f sizeof
	rm -f strings
	rm -f structs
	rm -f switch
	rm -f typedof

