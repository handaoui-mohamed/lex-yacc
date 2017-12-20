default: clean-binaries yacc lex prog clear-screen

no-cls: clean-binaries yacc lex prog

lex:
	flex -o ./bin/lex.yy.c ./src/lex.l
	
yacc:
	bison -o ./bin/yy.tab.c -dy ./src/yacc.y

prog:
	gcc -o prog ./bin/yy.tab.c ./bin/lex.yy.c -lm -ll -ly

clean-binaries:
	touch ./bin/temp
	rm -rf ./bin/*
	touch prog
	rm prog

clear-screen:
	clear