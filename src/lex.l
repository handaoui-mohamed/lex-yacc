%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "yy.tab.h"

    int cursor = 0;
    char line[255] = "";
    void moveCursor();
    extern int yyerror(char *s);
%}
identifier [a-z]([a-z]|[0-9])*
cmp [<>=]
spaces [ \t]+
operator [\+\-\*\/^]
end-of-input [\r\nEOF]
parenthesis ["("|")"]
%option yylineno
%%
 /* start */
"exit" moveCursor(); return EXIT;

"temp"[0-9]+ { moveCursor(); yyerror("Variable name is reserved"); }

 /* START: functions */
"moyenne" moveCursor(); return AVERAGE;

"somme" moveCursor(); return SUM;

"produit" moveCursor(); return PRODUCT;

"variance" moveCursor(); return VARIANCE;

"ecart-type" moveCursor(); return STANDARD_DEVIATION;

"min" moveCursor(); return MIN;

"max" moveCursor(); return MAX;

"si" moveCursor(); return IF;

","|";" moveCursor(); return yytext[0];

{cmp} moveCursor(); return yytext[0]; 
 /* END: functions */

{identifier} moveCursor(); return IDENTIFIER;

 /* escaping spaces */
{spaces}+ { moveCursor(); }

 /* handling parenthesis */
{parenthesis} moveCursor(); return yytext[0]; 

{end-of-input} moveCursor(); return EOI;

{operator} moveCursor(); return yytext[0]; 

.  {moveCursor(); yyerror("Caractère inattendu");};
%%

void moveCursor(){
    sprintf(line, "%s%s", line,yytext); 
    cursor += yyleng;
}
