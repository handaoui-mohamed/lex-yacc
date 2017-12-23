%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "yy.tab.h"

    // global functions
    void moveCursor();

    // global variables
    int cursor = 0;
%}
identifier [a-z]+[0-9]*
spaces [ \t]+
operator [\+\-*/^]
end-of-input [\r\nEOF]
%option yylineno
%%
 /* start */
"moyenne" {
    moveCursor(); 
    return AVERAGE;
}

"somme" {
    moveCursor(); 
    return SUM;
}

"produit" {
    moveCursor(); 
    return PRODUCT;
}

"variance" {
    moveCursor(); 
    return VARIANCE;
}

"," { 
    moveCursor();
    return yytext[0]; 
}

{identifier} {
    moveCursor();
    return IDENTIFIER;
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