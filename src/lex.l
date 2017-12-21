%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "yy.tab.h"

    // global functions
    void moveCursor();

    // global variables
    int cursor = 0;
%}
number -?[0-9]+(\.[0-9]+)?
spaces [ \t]+
operator [\+\-*/^]
end-of-input [\r\nEOF]
%option yylineno
%%
 /* start */
{number} {
    moveCursor();
    yylval.number = atof(yytext);
    return NUMBER;
}

 /* START: Function names */
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

"ecart-type" {
    moveCursor(); 
    return STANDARD_DEVIATION;
}

"min" {
    moveCursor(); 
    return MIN;
}

"max" {
    moveCursor(); 
    return MAX;
}
 /* END: Function names */

 /* escaping spaces */
{spaces}+ { 
    moveCursor(); 
}

 /* handling parenthesis */
"("|")" { 
    moveCursor();
    return yytext[0]; 
}

"," { 
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
    yyerror("Invalid symbol, an arithmetic expression is expected");
}
%%

void moveCursor(){
    cursor += yyleng;
}