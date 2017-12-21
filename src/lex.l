%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "yy.tab.h"
    void moveCursor();
    int cursor = 0;
%}
number -?[0-9]+(\.[0-9]+)?
spaces [ \t]+
operator [\+\-*/^]
end-of-input (\r|\n|EOF)
%option yylineno
%%
 /* start */
{number} {
    moveCursor();
    yylval.number = atof(yytext);
    return NUMBER;
}

 /* escaping spaces */
{spaces}+ { 
    moveCursor(); 
}

 /* handling parenthesis */
"("|")" { 
    moveCursor();
    return yytext[0]; 
}

{end-of-input} { 
    moveCursor();
    return EOI;
}

{operator} {
    moveCursor(); 
    return yytext[0]; 
}

. { 
    moveCursor();
    yyerror("Expression expected");
}
%%

void moveCursor(){
    cursor += yyleng;
}