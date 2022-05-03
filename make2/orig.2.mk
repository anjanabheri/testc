
all: foo.exe

# All the generated files (source and header files)
GENERATED := main.c foo.c

# The rules to generate this files
$(GENERATED): one.proto foo.proto
	cp one.proto main.c
	cp foo.proto foo.c

# The rules to generate object files from the generated source files
# This could be merge with another rule from your Makefile
GENERATED_SRC := $(filter %.c,$(GENERATED))
GENERATED_OBJ := $(patsubst %.c,%.o,$(GENERATED_SRC))

proto2: $(GENERATED_SRC)
	${info GENERATED: $(GENERATED)}

proto: main.c
	${info GENERATED: $(GENERATED)}

foo.exe: $(GENERATED_OBJ)
	${info gen obj: $(GENERATED_OBJ)}
	gcc $^ -o $@

clean:
	rm -rf foo.exe *.o

