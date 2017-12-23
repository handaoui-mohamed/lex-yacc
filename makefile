default: clean-binaries prog clear-screen

all: clean-binaries yacc lex prog

lex:
	flex -o ./bin/lex.yy.c ./src/lex.l
	
yacc: error.strings.h
	bison -o ./bin/yy.tab.c -dy ./src/yacc.y

prog: lex yacc
	gcc -o prog ./bin/yy.tab.c ./bin/lex.yy.c -lm -ll -ly

error.strings.h:
	cp ./src/error.strings.h ./bin/error.strings.h

clean-binaries:
	touch ./bin/temp
	rm -rf ./bin/*
	touch prog
	rm prog

clear-screen:
	clear