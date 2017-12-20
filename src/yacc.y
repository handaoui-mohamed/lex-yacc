%{ 
    #include <stdlib.h>
    #include <stdio.h>
    #include <math.h>
    // extern function
    extern void verifyParenthesisCount();
    extern int cursor;
    
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
Line: Expr EOI { printf("%lf \n", $1); exit(0);}
      ;
Expr:  Expr '-' Expr { $$ = $1 - $3; }
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
int main(){
    yyparse();
}
yyerror(char *s){
    verifyParenthesisCount();
}

void printDivisionError(){
    printf("%*c^\n",cursor-2,' '); 
    printf("Error: division by zero\n"); 
    exit(0);
}
