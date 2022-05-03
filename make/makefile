
libs=one.a two.a main.a

one.a: 1.o 11.o
	make -f one.mk

two.a: 2.o 22.o
	make -f two.mk

main.a: main.o
	make -f main.mk

foo.exe: one.a two.a main.a
	gcc $^ -o $@

all: foo.exe
clean:
	rm -rf foo.exe $(libs) *.o
