%{ 
    #include <stdlib.h>
    #include <stdio.h>
    #include <math.h>
    #include "yy.tab.h"
    #include "error.strings.h"

    // extern functions
    extern int cursor;
    extern char* yytext;
    extern int yylineno;
    
    // global variables
    int fileIsOpen = 0;
    
    // global functions
    void help();
%}
%union {
    struct list{
        double value;
        double sqr_value;
        int size;
    } list;
    double number;
    int function;
}

/* Tokens */
%token <number> NUMBER EOI
%token <number> AVERAGE SUM PRODUCT VARIANCE STANDARD_DEVIATION MIN MAX IF

/* precedency */
%left '-' '+'
%left '*' '/'
%right '^'    
%right unary_minus

/* Types definitions */
%type <number> Test Expr Line Function
%type <list> AVERAGE_List PRODUCT_List MIN_List MAX_List VARIANCE_List

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
    | IF '(' Test ';' Expr ';' Expr ')' { $$ = $3 ? $5 : $7; }

    /* basic arithmetic errors handling */
    | '(' error { yyerror(EXPRESSION_EXPECTED); }
    | '(' error ')' { yyerror(EXPRESSION_EXPECTED); }
    | '(' Expr error { yyerror(CLOSING_PARENTHESIS_EXPECTED); }
    | Expr '+' error { yyerror(EXPRESSION_EXPECTED); }
    | Expr '-' error { yyerror(EXPRESSION_EXPECTED); }
    | Expr '*' error { yyerror(EXPRESSION_EXPECTED); }
    | Expr '/' error { yyerror(EXPRESSION_EXPECTED); }
    | Expr '^' error { yyerror(EXPRESSION_EXPECTED); }
    ;

Test: Expr '>' Expr { $$ = $1 > $3; }
    | Expr '<' Expr { $$ = $1 < $3; }
    | Expr '=' Expr { $$ = $1 == $3; }
    ;

Function: AVERAGE '(' AVERAGE_List ')' {  $$ = $3.value / $3.size; }
        | SUM '(' AVERAGE_List ')' { $$ = $3.value; }
        | PRODUCT '(' PRODUCT_List ')' { $$ = $3.value; }
        | MIN '(' MIN_List ')' { $$ = $3.value; }
        | MAX '(' MAX_List ')' { $$ = $3.value; }
        | VARIANCE '(' VARIANCE_List ')' { $$ = ($3.sqr_value / $3.size) - pow($3.value / $3.size,2); }
        | STANDARD_DEVIATION '(' VARIANCE_List ')' { $$ = sqrt(($3.sqr_value / $3.size) - pow($3.value / $3.size,2)); }

        /* functions errors handling */
        | AVERAGE '(' error { yyerror(FUNCTION_PARAMS_EXPECTED); }
        | SUM '(' error { yyerror(FUNCTION_PARAMS_EXPECTED); }
        | PRODUCT '(' error { yyerror(FUNCTION_PARAMS_EXPECTED); }
        | MIN '(' error { yyerror(FUNCTION_PARAMS_EXPECTED); }
        | MAX '(' error { yyerror(FUNCTION_PARAMS_EXPECTED); }
        | VARIANCE '(' error { yyerror(FUNCTION_PARAMS_EXPECTED); }
        | STANDARD_DEVIATION '(' error { yyerror(FUNCTION_PARAMS_EXPECTED); }
        | AVERAGE '(' Expr error { yyerror(COMMA_EXPECTED); }
        | SUM '(' Expr error { yyerror(COMMA_EXPECTED); }
        | PRODUCT '(' Expr error { yyerror(COMMA_EXPECTED); }
        | MIN '(' Expr error { yyerror(COMMA_EXPECTED); }
        | MAX '(' Expr error { yyerror(COMMA_EXPECTED); }
        | error { yyerror(FUNCTION_OPENING_PARENTHESIS_EXPECTED); }
        ;

AVERAGE_List: AVERAGE_List ',' Expr { $$.value = $1.value + $3; $$.size = $1.size + 1; }
            | Expr { $$.value = $1; $$.size = 1; }
            | AVERAGE_List error { yyerror(COMMA_EXPECTED); }
            | Expr error { yyerror(COMMA_EXPECTED); }
            ;

PRODUCT_List: PRODUCT_List ',' Expr { $$.value = $1.value * $3; }
            | Expr { $$.value = $1; }
            | PRODUCT_List error { yyerror(COMMA_EXPECTED); }
            | Expr error { yyerror(COMMA_EXPECTED); }
            ;

MIN_List: MIN_List ',' Expr { if ( $3 < $1.value) $$.value = $3; }
        | Expr { $$.value = $1; }
        | MIN_List error { yyerror(COMMA_EXPECTED); }
        | Expr error { yyerror(COMMA_EXPECTED); }
        ;

MAX_List: MAX_List ',' Expr { if ( $3 > $1.value) $$.value = $3; }
        | Expr { $$.value = $1; }
        | MAX_List error { yyerror(COMMA_EXPECTED); }
        | Expr error { yyerror(COMMA_EXPECTED); }
        ;

VARIANCE_List: VARIANCE_List ',' Expr { 
                $$.value = $1.value + $3; 
                $$.sqr_value = $1.sqr_value + pow($3,2);
                $$.size = $1.size + 1; 
             }
             | Expr { $$.value = $1; $$.sqr_value = pow($1,2); $$.size = 1; }
            | VARIANCE_List error { yyerror(COMMA_EXPECTED); }
            | Expr error { yyerror(COMMA_EXPECTED); }
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
            if(cursor-1 != 0) printf("%*c^\n",cursor-1,' '); else printf("^\n");
            printf("Error: %s at position %d\n\n", s, cursor);
        }
        exit(0);
    }
}

void help()
{
    printf(" _    _          _   _ _____          ____  _    _ _____                       \n");
    printf("| |  | |   /\\   | \\ | |  __ \\   /\\   / __ \\| |  | |_   _|                      \n");
    printf("| |__| |  /  \\  |  \\| | |  | | /  \\ | |  | | |  | | | |                        \n");
    printf("|  __  | / /\\ \\ | . ` | |  | |/ /\\ \\| |  | | |  | | | |                        \n");
    printf("| |  | |/ ____ \\| |\\  | |__| / ____ \\ |__| | |__| |_| |_                       \n");
    printf("|_|  |_/_/    \\_\\_| \\_|_____/_/    \\_\\____/ \\____/|_____|                      \n");
    printf(" __  __       _                              _                                 \n");
    printf("|  \\/  |     | |                            | |                                \n");
    printf("| \\  / | ___ | |__   __ _ _ __ ___   ___  __| |                                \n");
    printf("| |\\/| |/ _ \\| '_ \\ / _` | '_ ` _ \\ / _ \\/ _` |                                \n");
    printf("| |  | | (_) | | | | (_| | | | | | |  __/ (_| |                                \n");
    printf("|_|  |_|\\___/|_| |_|\\__,_|_| |_| |_|\\___|\\__,_|                                \n");
    printf(" _______ _____     _____ ____  __  __ _____ _____ _         _____ _____ _      \n");
    printf("|__   __|  __ \\   / ____/ __ \\|  \\/  |  __ \\_   _| |       / ____|_   _| |     \n");
    printf("   | |  | |__) | | |   | |  | | \\  / | |__) || | | |      | (___   | | | |     \n");
    printf("   | |  |  ___/  | |   | |  | | |\\/| |  ___/ | | | |       \\___ \\  | | | |     \n");
    printf("   | |  | |      | |___| |__| | |  | | |    _| |_| |____   ____) |_| |_| |____ \n");
    printf("   |_|  |_|       \\_____\\____/|_|  |_|_|   |_____|______| |_____/|_____|______|\n\n\n");

    printf("Pour analyser un fichier ajouter -f <filename>\n");
    printf("Pour analyser les entrées cmd, exécutez sans paramètre\n");
    printf("Fonctions disponibles : \n");
    printf("\t1- somme.\n");
    printf("\t2- produit.\n");
    printf("\t3- moyenne.\n");
    printf("\t4- variance.\n");
    printf("\t5- ecart-type.\n");
    printf("\t5- min.\n");
    printf("\t5- max.\n");
}