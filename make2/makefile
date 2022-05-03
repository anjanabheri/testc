

# All the generated files (source and header files)
GENERATED := main.c foo.c

# The rules to generate this files
$(GENERATED): one.proto foo.proto
	${info COPYING THE FILES}
	cp one.proto main.c
	cp foo.proto foo.c

# The rules to generate object files from the generated source files
# This could be merge with another rule from your Makefile
GENERATED_SRC := $(filter %.c,$(GENERATED))
GENERATED_OBJ := $(patsubst %.c,%.o,$(GENERATED_SRC))

all: main.c
	${info GENERATED: $(GENERATED)}

clean:
	rm -rf foo.exe *.o

