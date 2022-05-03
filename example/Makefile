.PHONY: all clean test

CFLAGS = -ggdb3 -std=c99 -O0

all: main.out

main.out: fun1.a fun2.a
	$(CC) fun1.a -Wl,-wrap,malloc -o main.int

fun1.a:
	ar fun1.a fun1.c

fun2.a:
	ar -rv fun2.a fun2.c

clean:
	rm -f *.o *.out *.a

