
all:
	gcc -c modx.c
	$(MAKE) -C foo -f foo.mk
clean:
	rm -rf *.o
