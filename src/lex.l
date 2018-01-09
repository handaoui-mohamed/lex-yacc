%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "yy.tab.h"

    int cursor = 0;
%}
identifier [a-z]([a-z]|[0-9])*
spaces [ \t]+
operator [\+\-*/^]
end-of-input [\r\nEOF]
%option yylineno
%%
. { cursor++; REJECT; }

 /* start */
"exit" return EXIT;

"temp"[0-9]+ { yyerror("Variable name is reserved"); }

 /* START: functions */
"moyenne" return AVERAGE;

"somme" return SUM;

"produit" return PRODUCT;

"variance" return VARIANCE;

"ecart-type" return STANDARD_DEVIATION;

"min" return MIN;

"max" return MAX;

"," return yytext[0];
 /* END: functions */

{identifier} return IDENTIFIER;

 /* escaping spaces */
{spaces}+ {}

 /* handling parenthesis */
"("|")" return yytext[0]; 


{end-of-input} return EOI;

{operator} return yytext[0]; 

. yyerror("Unexpected character");
%%