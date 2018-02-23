%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "yy.tab.h"

    // global functions
    void moveCursor();
    void verifyParenthesisCount();

    int parenthesis = 0;
    // global variables
    int cursor = 0;
%}
number [0-9]+(\.[0-9]+)?
spaces [ \t]+
operator [\+\-*/^]
CMP [><=]
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

"si" {
    moveCursor(); 
    return IF;
}
 /* END: Function names */

 /* escaping spaces */
{spaces}+ { 
    moveCursor(); 
}

 /* handling parenthesis */
"(" { 
    moveCursor();
    parenthesis++;
    return yytext[0]; 
}

")" { 
    moveCursor();
    parenthesis--;
    return yytext[0]; 
}

","|";" { 
    moveCursor();
    return yytext[0]; 
}

{CMP} { 
    moveCursor();
    return yytext[0]; 
}

{end-of-input} { 
    verifyParenthesisCount();
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


void verifyParenthesisCount(){
    if(parenthesis < 0){
        printf("Error: openning parenthesis expected at position = %d before the closing one \n",cursor-1);
        exit(0);
    }
}