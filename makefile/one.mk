include common.mk

FILES=$(call get_c_files_recurse,one)

#${info BEFORE files: $(FILES)}

#FILTER_OUT=one//fun.c
#FILTER_OUT=$(call get_c_files_recurse,one)
#FILTER_OUT := $(subst //,/,$(FILTER_OUT))
FILES := $(filter-out $(FILTER_OUT),$(FILES))

${info AFTER files: $(FILES)}

all:
	
