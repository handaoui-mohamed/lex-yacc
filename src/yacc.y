%{ 
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include <math.h>
    #include "yy.tab.h"
    #include "error.strings.h"
    #include "functions.h"

    // extern functions
    extern int cursor;
    extern char* yytext;
    extern int yylineno;
    
    // global variables
    int fileIsOpen = 0;
    
    // global functions
%}
%union {
    struct list{
        struct node *params;
        struct node *current;
    } list;
    double number;
    int function;
}

/* Tokens */
%token <number> NUMBER EOI
%token <number> AVERAGE SUM PRODUCT VARIANCE STANDARD_DEVIATION MIN MAX

/* precedency */
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

    /* basic arithmetic errors handling */
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
            switch($1){
                case 1: $$ = average($3.params); break;
                case 2: $$ = sum($3.params); break;
                case 3: $$ = product($3.params); break;
                case 4: $$ = variance($3.params); break;
                case 5: $$ = standardDeviation($3.params); break;
                case 6: $$ = min($3.params); break;
                case 7: $$ = max($3.params); break;
                default: break;
            }
        };

Name: AVERAGE {$$ = 1;}
    | SUM {$$ = 2;}
    | PRODUCT {$$ = 3;}
    | VARIANCE {$$ = 4;}
    | STANDARD_DEVIATION {$$ = 5;}
    | MIN {$$ = 6;}
    | MAX {$$ = 7;}
    ;

List: List ',' Expr { 
        $$ = $1;
        
        addNext(&($$.current), $3);
    }
    | Expr {
        allocate(&($$.params));
        $$.current = $$.params;
        addNext(&($$.current), $1);
    }
    ;
%%
int main(int nbInputs,char **inputs){
    extern FILE *yyin;
    
    if(nbInputs == 2 && (strcmp(inputs[1], "-h") || strcmp(inputs[1], "--help"))){
        help();
        exit(0);
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
