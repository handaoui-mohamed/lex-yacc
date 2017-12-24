%{ 
    #include <stdlib.h>
    #include <stdio.h>
    #include <math.h>
    #include <string.h>
    #include "yy.tab.h"
    #include "error.strings.h"
    #include "quadruplet.h"

    // extern functions
    extern int cursor;
    extern char* yytext;
    extern int yylineno;
    extern FILE *yyin;
    extern FILE *yyout;
    extern int lineNumber;
    extern int tempNumber;
    
    // global variables
    int fileIsOpen = 0;
    int printToFile = 0;

    // global functions
    void openInputFile(char *input);
    void openOutputFile(char *input);
%}
%union { int number; }

/* Tokens */
%token <number> IDENTIFIER EOI
%token <number> SUM PRODUCT AVERAGE VARIANCE STANDARD_DEVIATION MIN MAX

/* precedency */
%left '-' '+'
%left '*' '/'
%right '^'    
%right unary_minus

/* Types definitions */
%type <number> Expr PRODUCT_List AVERAGE_List VARIANCE_List MIN_List MAX_List

/* starting point */
%start Input
%%
Input:
     | Input Line { printf("%03d   END\n",lineNumber++); cursor = 0; tempNumber = 0; printf("\n"); lineNumber = 1;}
     ;
    
Line: EOI
    | Expr EOI { }
    ;

Expr: Expr '-' { push(); } Expr { generateQuadruplet(); }
    | Expr '+' { push(); } Expr { generateQuadruplet(); }
    | Expr '/' { push(); } Expr { generateQuadruplet(); }
    | Expr '*' { push(); } Expr { generateQuadruplet(); }
    | Expr '^' { push(); } Expr { generatePowQuadruplet(); }
    | '-' { push(); } Expr %prec unary_minus { generateQuadrupletUnaryMinus(); }
    | '(' Expr ')' {}
    | IDENTIFIER { push(); }
    | Function {}


    // /* errors handling */
    | '(' error { yyerror(EXPRESSION_EXPECTED); }
    | '(' error ')' { yyerror(EXPRESSION_EXPECTED); }
    | '(' Expr error { yyerror(CLOSING_PARENTHESIS_EXPECTED); }
    | Expr error '+' { yyerror(EXPRESSION_EXPECTED); }
    | Expr error '-' { yyerror(EXPRESSION_EXPECTED); }
    | Expr error '*' { yyerror(EXPRESSION_EXPECTED); }
    | Expr error '/' { yyerror(EXPRESSION_EXPECTED); }
    | Expr error '^' { yyerror(EXPRESSION_EXPECTED); }
    | Expr error { yyerror(OPERATOR_EXPECTED); } Expr
    ;

Function: SUM '(' AVERAGE_List ')' {}
        | AVERAGE '(' AVERAGE_List ')' { generateAverageQuadruplet($3); } 
        | PRODUCT '(' PRODUCT_List ')' {}
        | VARIANCE '(' VARIANCE_List ')' { generateVarianceQuadruplet($3); }
        | STANDARD_DEVIATION '(' VARIANCE_List ')' { generateVarianceQuadruplet($3); generateDeviationQuadruplet($3); }
        | MIN '(' MIN_List ')' { generateMinQuadruplet(); }
        | MAX '(' MAX_List ')' { generateMaxQuadruplet(); }
        ;

AVERAGE_List: AVERAGE_List { push(); } ',' {} Expr { generateSumQuadruplet(); $$++; } 
            | Expr { $$ = 1;}
            ;

PRODUCT_List: PRODUCT_List { push(); } ',' {} Expr { generateProductQuadruplet(); }
            | Expr {}
            ;

VARIANCE_List: VARIANCE_List { push(); } ',' {} Expr { generatePreVarianceQuadruplet($$++); }
             | Expr { generateInitVarianceQuadruplet(); $$ = 1; }
             ;

MIN_List: MIN_List { push(); } ',' {} Expr { generatePreMinQuadruplet(); }
        | Expr { generateInitMinMaxQuadruplet();}
        ;

MAX_List: MAX_List { push(); } ',' {} Expr { generatePreMaxQuadruplet(); }
        | Expr { generateInitMinMaxQuadruplet();}
        ;
%%
int main(int nbInputs,char **inputs){       
    if(nbInputs == 2 && (strcmp(inputs[1], "-h") || strcmp(inputs[1], "--help"))){
        help();
        exit(0);
    }

    if(nbInputs > 2){
        if (strcmp(inputs[2], "-f"))
             openInputFile(inputs[2]);
        else if (strcmp(inputs[2], "-o"))
             openOutputFile(inputs[2]);
    }

    if(nbInputs > 3){
        if (strcmp(inputs[3], "-o"))
             openOutputFile(inputs[2]);
        else 
            if (strcmp(inputs[2], "-f"))
                openInputFile(inputs[2]);
    }

    yyparse();
    if(fileIsOpen) {
        fclose(yyin);
        fclose(yyout);
    }
    return 0;
}

void openInputFile(char *input){
    yyin = NULL;
    yyin = fopen(input,"r"); 
    if(yyin) fileIsOpen = 1;
    else {
        printf("Error: unable to open file or file does not existe!\n");
        exit(0);
    }
}

void openOutputFile(char *output){
    yyout = NULL;
    yyout = fopen(output,"w");
    if(yyout) printToFile = 1;
    else {
        printf("Error: unable to open file or file does not existe!\n");
        exit(0);
    }
}

int yyerror(char *s) {
    printf("errror\n");
    if(strcmp(s,"syntax error")<-1){
        if(fileIsOpen){
            printf("\nError: %s on line %d at position %d\n\n", s, yylineno, cursor);
        }else {
            if(!printToFile && cursor-1 != 0)
                printf("%*c^\n",cursor-1,' '); else printf("^\n");
            printf("Error: %s at position %d\n\n", s, cursor);
        }
        exit(0);
    }
}