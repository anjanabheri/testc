
#libs: math.a

all: main.o
	ld -o main.exe main.o math.a
	
math.a: math.o
	ar -rv $@ $^

share: main.o
	cc -o mains.exe main.o maths.so

clean:
	rm -rf $(libs) *.o *.exe *.a *.so
