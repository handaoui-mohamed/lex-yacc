default: clean-binaries prog clear-screen

all: clean-binaries prog

lex:
	flex -o ./bin/lex.yy.c ./src/lex.l
	
yacc: error.strings.h
	bison -o ./bin/yy.tab.c -dy ./src/yacc.y

prog: lex yacc quadruplets
	gcc -o prog ./bin/quadruplet.o ./bin/yy.tab.c ./bin/lex.yy.c -lm -ll -ly -I./src

error.strings.h:
	cp ./src/error.strings.h ./bin/error.strings.h

quadruplets:
	gcc -c ./src/quadruplet.c -o ./bin/quadruplet.o

clean-binaries:
	touch ./bin/temp
	rm -rf ./bin/*
	touch prog
	rm prog

clear-screen:
	clear