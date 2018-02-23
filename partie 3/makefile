src = ./src/
bin = ./bin/
input-yacc = $(src)yacc.y
input-lex = $(src)lex.l
input-quad = $(src)quadruplet.c
output-yacc = $(bin)yy.tab.c
output-lex = $(bin)lex.yy.c
output-quad = $(bin)quadruplet.o 
prog-name = prog

default: all clear-screen

all: clean-binaries prog

lex:
	flex -o $(output-lex) $(input-lex)
	
yacc:
	bison -o $(output-yacc) $(input-yacc) -dy

prog: lex yacc quadruplets
	gcc -o $(prog-name) $(output-quad) $(output-yacc) $(output-lex) -lm -ll -ly -I$(src)

quadruplets:
	gcc -c $(input-quad) -o $(output-quad)

clean-binaries:
	touch $(bin)temp
	rm -rf $(bin)*
	touch $(prog-name)
	rm $(prog-name)

clear-screen:
	clear