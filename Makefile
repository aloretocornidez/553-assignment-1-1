CC = gcc
CFLAGS = -g -Wall -DDEBUG -Wno-unused-variable
CFLAGS = -g -Wall -Wno-unused-variable -Werror -Wfatal-errors -DEBUG

DEST = compile

HFILES = error.h  global.h  protos.h symbol-table.h  syntax-tree.h 

CFILES = error.c \
homework0.c \
intermediate-language.c \
lex.yy.c \
main.c \
print.c \
process_syntax_tree.c \
symbol-table.c \
syntax-tree.c \
util.c \
y.tab.c \
	

OFILES = $(CFILES:.c=.o)

.c.o :
	$(CC) $(CFLAGS) -c $<

$(DEST) : $(OFILES)
	$(CC) -o $(DEST) $(OFILES) -lfl
	# $(CC) -o $(DEST) $(OFILES) -ll

error.o : error.h global.h syntax-tree.h error.c y.tab.h

main.o : global.h main.c

symbol-table.o : global.h symbol-table.h symbol-table.c

syntax-tree.o : global.h syntax-tree.h syntax-tree.c

util.o : global.h util.h util.c

lex.yy.o : global.h error.h syntax-tree.h symbol-table.h lex.yy.c

y.tab.c : parser.y 
	yacc -d -v parser.y

lex.yy.c : y.tab.h scanner.l 
	flex scanner.l

y.tab.h : parser.y
	yacc -d -v parser.y

.PHONY: clean
clean :
	/bin/rm -f *.o $(DEST) *.BAK lex.yy.c y.tab.* y.output
