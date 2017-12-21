default: clean-binaries yacc lex prog clear-screen

all: clean-binaries yacc lex prog

lex:
	flex -o ./bin/lex.yy.c ./src/lex.l
	
yacc: error.strings.h
	bison -o ./bin/yy.tab.c -dy ./src/yacc.y

error.strings.h:
	cp ./src/error.strings.h ./bin/error.strings.h

prog:
	gcc -o prog ./bin/yy.tab.c ./bin/lex.yy.c -lm -ll -ly

clean-binaries:
	touch ./bin/temp
	rm -rf ./bin/*
	touch prog
	rm prog

clear-screen:
	clear