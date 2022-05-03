
all: foo.exe

vpath %.proto $(PWD)

main.c: one.proto foo.proto
	cp one.proto main.c
	cp foo.proto foo.c

main.o: main.c

foo.exe: main.o foo.o
	gcc $^ -o $@

clean:
	rm -rf foo.exe *.o

