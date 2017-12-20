%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "yy.tab.h"
    void moveCursor();
    void printCursor();
    void moveAndPrintCursor();
    void verifyParenthesisCount();
    int cursor = 0;
    int parenthesis = 0;
%}
number [0-9]+(\.[0-9]+)?
spaces [ \t\r]+
operator [\+\-*/^]
end-of-input (\n|EOF)
%%
 /* error handling */

 /* examples
 * {operator}{operator}         => 5+6++
 * {operator}")"                => 5+(8*3+)
 * {operator}{end-of-input}     => 5+6-
 */
{operator}{operator}|{operator}")"|{operator}{end-of-input} { 
    moveAndPrintCursor();
    printf("Error: number expected at position = %d\n",cursor); exit(0);
}

 /* examples
 * Only (-5) or (5) are accepted
 * (+5), (*5) ... are not accepted
 */
"("[^0-9\-] {
    moveAndPrintCursor();
    printf("Error: number or unay minus expected at position = %d\n",cursor); exit(0);
}

 /* examples
 * ")"{number}                   => (5+6)5
 * {number}"("                   => 1+2(5+6)
 * {number}{spaces}+{number}     => 5+6   2
 */
(")"{number}|{number}"("|{number}{spaces}+{number}) {
    moveAndPrintCursor();
    printf("Error: operator expected at position = %d\n",cursor); exit(0);
}

 /* start */
{number} {
    moveCursor();
    yylval.number = atof(yytext);
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
    moveAndPrintCursor();
    printf("Error: expected operator,number or parenthesis at position = %d\n",cursor);
    exit(0);
}
%%

void moveCursor(){
    cursor += yyleng;
}

void printCursor(){
    printf("%*c^\n",cursor-1,' ');
}

void moveAndPrintCursor(){
    moveCursor();
    printCursor();
}

void verifyParenthesisCount(){
    if(parenthesis != 0){
        printCursor();
        if(parenthesis > 0){
            printf("Error: closing parenthesis expected at position = %d\n",cursor);
        }else{
            printf("Error: openning parenthesis expected at position = %d before the closing one \n",cursor-1);
        }
        exit(0);
    }
}