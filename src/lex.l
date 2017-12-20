%{
    #include <string.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include "yy.tab.h"
    void incrementInputLenght();
    void verifyParenthesisCount();
    int totalLength = 0;
    int parenthesis = 0;
%}
number [0-9]+(\.[0-9]+)?
spaces [ \t]+
operator [\+\-*/^]
end-of-input (\n|EOF)
%%
 /* error handling */
{operator}{operator}|{operator}")" { 
    incrementInputLenght();
    printf("Error: number expected at position = %d\n",totalLength); exit(0);
}

"("({number})")" {
    incrementInputLenght();
    printf("Error: number expected at posifkkftion = %d\n",totalLength); exit(0);
}

 /*"("[^(\-{number})] {
    incrementInputLenght();
    printf("Error: number or unay minus expected at position = %d\n",totalLength); exit(0);
 }*/

(")"{number}|{number}"("|{number}{spaces}+{number}) {
    incrementInputLenght();
    printf("Error: operator expected at position = %d\n",totalLength); exit(0);
}

 /* start */
{number} {
    incrementInputLenght();
    double number;
    sscanf(yytext, "%lf", &number);
    yylval.number = number;
    return NUMBER;
}

 /* escaping spaces */
{spaces} { 
    incrementInputLenght(); 
}

 /* handling parenthesis */
"(" { 
    incrementInputLenght(); 
    parenthesis++; 
    return yytext[0]; 
}

 /* improve error here */
")" { 
    incrementInputLenght(); 
    parenthesis--;
    return yytext[0]; 
}

 /* must detect if input is a file or cmd input */
{end-of-input} { 
    incrementInputLenght();
    verifyParenthesisCount();
    return EOI;
}

{operator} {
    incrementInputLenght(); 
    return yytext[0]; 
}

.  { 
    incrementInputLenght(); 
    printf("Error: expected operator,number or parenthesis at position = %d\n",totalLength);
    exit(0);
}
%%

void incrementInputLenght(){
    totalLength += yyleng;
}

void verifyParenthesisCount(){
    if(parenthesis != 0){
        if(parenthesis > 0){
            printf("Error: closing parenthesis expected at position = %d\n",totalLength);
        }else{
            printf("Error: openning parenthesis expected at position = %d before the closing one \n",totalLength-1);
        }
        exit(0);
    }
}