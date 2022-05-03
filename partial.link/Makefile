lib1_make: lib1.o
	ar rcu lib1.a lib1.o

lib2_make: lib2.o
	ar rcu lib2.a lib2.o

all: lib1_make lib2_make main.o
	gcc -Wl,-r lib2.a -o one
	gcc main.o one lib1.a -o two
