%{ 
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include <math.h>
    #include "yy.tab.h"
    // extern function
    extern void verifyParenthesisCount();
    extern int cursor;
    extern char *yytext;
    
    // global function
    void printDivisionError();
%}
%union {double number;}
%token <number> NUMBER
%token EOI
%type <number> Expr Line
%left '-' '+'
%left '*' '/'
%right '^'    
%right unary_minus
%%
Line: Expr EOI { printf("%lf \n", $1); }
    | Line Expr EOI
    ;

Expr: Expr '-' Expr { $$ = $1 - $3; }
    | Expr '+' Expr { $$ = $1 + $3; }
    | Expr '*' Expr { $$ = $1 * $3; }
    | Expr '/' Expr { 
       if($3 == 0) printDivisionError(); /* division by zero */
       $$ = $1 / $3;
    }
    | Expr '^' Expr { $$ = pow($1, $3); }
    | '-' Expr %prec unary_minus { $$ = -$2; }
    | '(' Expr ')'{ $$ = $2; }
    | NUMBER 
    ;
%%
int main(int nbInputs,char **inputs){
    int fileIsOpen = 0;
    extern FILE *yyin;
    
    if(nbInputs == 2 && (strcmp(inputs[1], "-h") || strcmp(inputs[1], "--help"))){
        printf("To parse file add -f <filename>\n");
        printf("To parse cmd inputs execute with no params\n");
        exit(0);
    }

    if(nbInputs == 3 && strcmp(inputs[2], "-f")){
        yyin = NULL;
        yyin = fopen(inputs[2],"r");
        if(yyin) fileIsOpen = 1;
        else exit(0);
    }
    yyparse();
    if(fileIsOpen) fclose(yyin);
    return 0;
}
int yyerror(char *error){
    // verifyParenthesisCount();
    printf("Error: %c\n",yytext[0]);
}

void printDivisionError(){
    printf("%*c^\n",cursor-2,' '); 
    printf("Error: division by zero\n"); 
    exit(0);
}
