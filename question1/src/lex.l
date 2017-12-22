%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "yy.tab.h"

    // global functions
    void moveCursor();

    // global variables
    int cursor = 0;
%}
alpha [a-z]
spaces [ \t]+
operator [\+\-*/^]
end-of-input [\r\nEOF]
%option yylineno
%%
 /* start */
{alpha} {
    moveCursor();
    return ALPHA;
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
    yyerror("Unexpected character");
}
%%

void moveCursor(){
    cursor += yyleng;
}