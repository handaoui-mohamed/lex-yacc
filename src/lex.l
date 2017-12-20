%{
    #include <string.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include "yy.tab.h"
    void moveCursor();
    void verifyParenthesisCount();
    int cursor = 0;
    int parenthesis = 0;
%}
number [0-9]+(\.[0-9]+)?
spaces [ \t]+
operator [\+\-*/^]
end-of-input (\n|EOF)
%%
 /* error handling */
{operator}{operator}|{operator}")" { 
    moveCursor();
    printf("Error: number expected at position = %d\n",cursor); exit(0);
}

"("[^0-9\-] {
    if(yytext[0] != '-'){
        moveCursor();
        printf("Error: number or unay minus expected at position = %d\n",cursor); exit(0);
    }
}

(")"{number}|{number}"("|{number}{spaces}+{number}) {
    moveCursor();
    printf("Error: operator expected at position = %d\n",cursor); exit(0);
}

 /* start */
{number} {
    moveCursor();
    double number;
    sscanf(yytext, "%lf", &number);
    yylval.number = number;
    return NUMBER;
}

 /* escaping spaces */
{spaces} { 
    moveCursor(); 
}

 /* handling parenthesis */
"(" { 
    moveCursor(); 
    parenthesis++; 
    return yytext[0]; 
}

 /* improve error here */
")" { 
    moveCursor(); 
    parenthesis--;
    return yytext[0]; 
}

 /* must detect if input is a file or cmd input */
{end-of-input} { 
    moveCursor();
    verifyParenthesisCount();
    return EOI;
}

{operator} {
    moveCursor(); 
    return yytext[0]; 
}

.  { 
    moveCursor(); 
    printf("Error: expected operator,number or parenthesis at position = %d\n",cursor);
    exit(0);
}
%%

void moveCursor(){
    cursor += yyleng;
}

void verifyParenthesisCount(){
    if(parenthesis != 0){
        if(parenthesis > 0){
            printf("Error: closing parenthesis expected at position = %d\n",cursor);
        }else{
            printf("Error: openning parenthesis expected at position = %d before the closing one \n",cursor-1);
        }
        exit(0);
    }
}