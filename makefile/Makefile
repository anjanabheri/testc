
include common.mk

FLAGE = SOME ONE TWO
FLAGS = $(foreach d, $(FLAGE), -D$d)

VAR = var2
VAR += var1

${info VAR: $(VAR)}

INT = one
INT := two

include modx/modx.mk

all:
	$(MAKE) -C modx -f modx.mk
	gcc -g $(FLAGS) -include mkinclude.h -I../ main.c

some:
	@echo "some"
	@echo "int=$(INT)"

print-%:
	@echo '$*=$($*)'
	@echo '  origin = $(origin $*)'
	@echo '  flavor = $(flavor $*)'
	@echo '   value = $(value  $*)'
