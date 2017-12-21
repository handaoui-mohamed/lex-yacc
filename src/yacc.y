%{ 
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include <math.h>
    #include "yy.tab.h"
    #include "error.strings.h"

    // extern functions
    extern void verifyParenthesisCount();
    extern void printCursor();
    extern int cursor;
    extern char* yytext;
    extern int yylineno;
    
    // global variables
    int fileIsOpen = 0;
    
    // global functions
%}
%union {
    struct list{
        double *params;
        int size;
    }list;
    double number;
    int function;
}

/* Tokens */
%token <number> NUMBER EOI MOY

/* precedence */
%left '-' '+'
%left '*' '/'
%right '^'    
%right unary_minus

/* Types definitions */
%type <number> Expr Line Function
%type <function> Name
%type <list> List

/* starting point */
%start Input
%%
Input:
     | Input Line { cursor = 0;}
     ;
    
Line: EOI
    | Expr EOI { printf("%lf \n", $1);}
    ;

Expr: NUMBER        { $$ = $1; }
    | Expr '-' Expr { $$ = $1 - $3; }
    | Expr '+' Expr { $$ = $1 + $3; }
    | Expr '*' Expr { $$ = $1 * $3; }
    | Expr '/' Expr { 
       if($3 == 0) yyerror("division by zero");
       $$ = $1 / $3;
    }
    | Expr '^' Expr { $$ = pow($1, $3); }
    | '-' Expr %prec unary_minus { $$ = -$2; }
    | '(' Expr ')'{ $$ = $2; }
    | Function { $$  = $1 ; }

    /* errors handling */
    | '(' error { yyerror(EXPRESSION_EXPECTED); }
    | '(' error ')' { yyerror(EXPRESSION_EXPECTED); }
    | '(' Expr error { yyerror(CLOSING_PARENTHESIS_EXPECTED); }
    | Expr error { yyerror(OPERATOR_EXPECTED); }
    | Expr '+' error { yyerror(EXPRESSION_EXPECTED); }
    | Expr '-' error { yyerror(EXPRESSION_EXPECTED); }
    | Expr '*' error { yyerror(EXPRESSION_EXPECTED); }
    | Expr '/' error { yyerror(EXPRESSION_EXPECTED); }
    | Expr '^' error { yyerror(EXPRESSION_EXPECTED); }
    ;

Function: Name '(' List ')' {
            int i;
            $$ = 0;
            if($1 == 1){
                for(i=0; i < $3.size; i++){
                    $$ += $3.params[i];
                }
                $$ /= $3.size;
            }
        };

Name: MOY {$$ = 1;}
    ;

List: List ',' Expr { 
        $$.params = $1.params;
        $$.size = $1.size; 
        $$.params[$$.size++] = $3;
    }
    | Expr {
        $$.params = malloc(100); 
        $$.params[0] = $1; 
        $$.size = 1;
    }
    ;


%%
int main(int nbInputs,char **inputs){
    extern FILE *yyin;
    
    if(nbInputs == 2 && (strcmp(inputs[1], "-h") || strcmp(inputs[1], "--help"))){
        printf("To parse file add -f <filename>\n");
        printf("To parse cmd inputs execute with no params\n");
    }

    if(nbInputs == 3 && strcmp(inputs[2], "-f")){
        yyin = NULL;
        yyin = fopen(inputs[2],"r");
        if(yyin) fileIsOpen = 1;
        else {
            printf("Error: unable to open file or file does not existe!\n");
            exit(0);
        }
    }
    yyparse();
    if(fileIsOpen) fclose(yyin);
    return 0;
}

int yyerror(char *s) {
    if(strcmp(s,"syntax error")<-1){
        if(fileIsOpen){
            printf("\nError: %s on line %d at position %d\n\n", s, yylineno, cursor);
        }else {
            printf("%*c^\n",cursor-1,' ');
            printf("Error: %s at position %d\n\n", s, cursor-1);
        }
        exit(0);
    }
}