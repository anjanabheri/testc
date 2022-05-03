# Function: Recursive wildcard
# $1 - Folder name
# $2 - Pattern to search
rwildcard=$(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))

# Function: Recursive wildcard of source files (*.c)
# $1 - Folder name
get_c_files_recurse=$(call rwildcard,$1,*.c)

rwildcard=$(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))

# Function: Recursive wildcard of source files (*.c)
# # $1 - Folder name
get_c_files_recurse=$(call rwildcard,$1/,*.c)
