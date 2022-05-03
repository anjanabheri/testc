

all: math.a

math.a: math.o
	ar -rv $@ $^

share: math.o
	gcc -fPIC -shared -o maths.so math.o
