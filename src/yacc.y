%{ 
    #include <stdlib.h>
    #include <stdio.h>
    #include <math.h>
%}
%union {double number;}
%token <number> NUMBER
%token EOI
%type <number> Expr Ligne
%left '-' '+'
%left '*' '/'
%right '^'    
%right unary_minus
%%
Ligne: Expr EOI { printf("%lf \n", $1); exit(0);}
      ;
Expr:  Expr '-' Expr { $$ = $1 - $3; }
     | Expr '+' Expr { $$ = $1 + $3; }
     | Expr '*' Expr { $$ = $1 * $3; }
     | Expr '/' Expr { $$ = $1 / $3; }
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
    // printf("\nErreur:\n%s\n",s);
}
