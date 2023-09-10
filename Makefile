CC = gcc
# CFLAGS = -g -Wall -DDEBUG
CFLAGS = -g -Wall

# Name of executable
DEST = compile

# Header files
HFILES = error.h  global.h  protos.h symbol-table.h  syntax-tree.h

# Source code files
CFILES = error.c \
	lex.yy.c \
	main.c\
	print.c \
	process_syntax_tree.c \
	symbol-table.c\
        syntax-tree.c \
	util.c\
	y.tab.c

# Output files (change .c files to .o files)
OFILES = $(CFILES:.c=.o)


.c.o :
	$(CC) $(CFLAGS) -c $<

# Make rule for executable, dependencies are the .o files
$(DEST) : $(OFILES)
	$(CC) -o $(DEST) $(OFILES) -ll


# Create error.o, with following dependencies.
error.o : error.h global.h syntax-tree.h error.c y.tab.h

# Create main.o, with following dependencies.
main.o : global.h main.c

# Create symbol-table.o, with following dependencies.
symbol-table.o : global.h symbol-table.h symbol-table.c

# `make clean` rule
.PHONY: clean
clean :
	/bin/rm -f *.o $(DEST)