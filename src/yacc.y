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
    extern char line[255];
    extern char* yytext;
    extern int yylineno;
    extern FILE *yyin;
    extern FILE *yyout;
    extern int lineNumber;
    extern int tempNumber;
    extern char result[100];
    
    // global variables
    int fileIsOpen = 0;
    int printToFile = 0;

    // global functions
    void openInputFile(char *input);
    void openOutputFile(char *input);
    void closeFiles();
%}
%union { int number; }

/* Tokens */
%token <number> IDENTIFIER IF EOI EXIT
%token <number> SUM PRODUCT AVERAGE VARIANCE STANDARD_DEVIATION MIN MAX

/* precedency */
%left '-' '+'
%left '*' '/'
%right '^'    
%right unary_minus

/* Types definitions */
%type <number> Expr Test PRODUCT_List SUM_List VARIANCE_List MIN_List MAX_List

/* starting point */
%start Input
%%
Input:
     | Input Line {  cursor = 0; strcpy(line,""); }
     | EXIT { closeFiles(); }
     ;
    
Line: EOI
    | EXIT { closeFiles(); }
    | Expr EOI { printQuadruplets(); }
    ;

Expr: Expr '-' { push(); } Expr { generateArithmeticQuadruplet(); }
    | Expr '+' { push(); } Expr { generateArithmeticQuadruplet(); }
    | Expr '/' { push(); } Expr { generateArithmeticQuadruplet(); }
    | Expr '*' { push(); } Expr { generateArithmeticQuadruplet(); }
    | Expr '^' { push(); } Expr { generatePowQuadruplet(); }
    | '-' { push(); } Expr %prec unary_minus { generateQuadrupletUnaryMinus(); }
    | '(' Expr ')' {}
    | IDENTIFIER { push(); }
    | Function {}
    | IF '(' Test { $3 = lineNumber; } ';' Expr { generateTempQuadruplet(); $6 = lineNumber; } ';' Expr ')' { generateIfQuadruplet($3, $6); }


    // /* errors handling */
    | '(' error { yyerror(EXPRESSION_EXPECTED); }
    | '(' error ')' { yyerror(EXPRESSION_EXPECTED); }
    | '(' Expr error { yyerror(CLOSING_PARENTHESIS_EXPECTED); }
    | Expr error '+' { yyerror(EXPRESSION_EXPECTED); }
    | Expr error '-' { yyerror(EXPRESSION_EXPECTED); }
    | Expr error '*' { yyerror(EXPRESSION_EXPECTED); }
    | Expr error '/' { yyerror(EXPRESSION_EXPECTED); }
    | Expr error '^' { yyerror(EXPRESSION_EXPECTED); }
    | error '+' { yyerror(EXPRESSION_EXPECTED); }
    | error '-' { yyerror(EXPRESSION_EXPECTED); }
    | error '*' { yyerror(EXPRESSION_EXPECTED); }
    | error '/' { yyerror(EXPRESSION_EXPECTED); }
    | error '^' { yyerror(EXPRESSION_EXPECTED); }
    | IF '(' Expr error { yyerror(TEST_EXPECTED); }
    | Expr error { yyerror(OPERATOR_EXPECTED); } Expr
    ;

Test: Expr '<' { push(); } Expr { generateTestQuadruplet(); }
    | Expr '>' { push(); } Expr { generateTestQuadruplet(); }
    | Expr '=' { push(); } Expr { generateTestQuadruplet(); }
    ;

Function: SUM '(' SUM_List ')'
        | AVERAGE '(' SUM_List ')' { generateAverageQuadruplet($3); } 
        | PRODUCT '(' PRODUCT_List ')'
        | VARIANCE '(' VARIANCE_List ')' { generateVarianceQuadruplet($3); }
        | STANDARD_DEVIATION '(' VARIANCE_List ')' { generateVarianceQuadruplet($3); generateDeviationQuadruplet($3); }
        | MIN '(' MIN_List ')' { generateMinQuadruplet(); }
        | MAX '(' MAX_List ')' { generateMaxQuadruplet(); }


        // /* errors handling */
        | MIN { yyerror(FUNCTION_OPENING_PARENTHESIS_EXPECTED); } error
        | MAX { yyerror(FUNCTION_OPENING_PARENTHESIS_EXPECTED); } error
        | STANDARD_DEVIATION { yyerror(FUNCTION_OPENING_PARENTHESIS_EXPECTED); } error
        | VARIANCE { yyerror(FUNCTION_OPENING_PARENTHESIS_EXPECTED); } error
        | PRODUCT { yyerror(FUNCTION_OPENING_PARENTHESIS_EXPECTED); } error
        | AVERAGE { yyerror(FUNCTION_OPENING_PARENTHESIS_EXPECTED); } error
        | SUM { yyerror(FUNCTION_OPENING_PARENTHESIS_EXPECTED); } error
        | Expr error { yyerror(CLOSING_PARENTHESIS_EXPECTED); }
        ;

SUM_List: SUM_List { push(); } ',' Expr { generateSumQuadruplet(); $$++; } 
        | Expr { $$ = 1;}


        // /* errors handling */
        | error { yyerror(EXPRESSION_EXPECTED); }
        ;

PRODUCT_List: PRODUCT_List { push(); } ',' Expr { generateProductQuadruplet(); }
            | Expr {}


            // /* errors handling */
            | error { yyerror(EXPRESSION_EXPECTED); }
            ;

VARIANCE_List: VARIANCE_List { push(); } ',' Expr { generatePreVarianceQuadruplet($$++); }
             | Expr { generateInitVarianceQuadruplet(); $$ = 1; }


             // /* errors handling */
             | error { yyerror(EXPRESSION_EXPECTED); }
             ;

MIN_List: MIN_List { push(); } ',' Expr { generatePreMinQuadruplet(); }
        | Expr { generateInitMinMaxQuadruplet();}


        // /* errors handling */
        | error { yyerror(EXPRESSION_EXPECTED); }
        ;

MAX_List: MAX_List { push(); } ',' Expr { generatePreMaxQuadruplet(); }
        | Expr { generateInitMinMaxQuadruplet();}


        // /* errors handling */
        | error { yyerror(EXPRESSION_EXPECTED); }
        ;
%%
int main(int nbInputs,char **inputs){
    if(nbInputs == 2 && (!strcmp(inputs[1], "-h") || !strcmp(inputs[1], "--help"))){
        help();
        exit(0);
    }

    if(nbInputs > 2){ 
        if (!strcmp(inputs[1], "-f")){
            openInputFile(inputs[2]);
        }
        else if (!strcmp(inputs[1], "-o")){
            openOutputFile(inputs[2]);
        }
        
    }

    if(nbInputs > 3){
        if (!strcmp(inputs[3], "-o")){
             openOutputFile(inputs[4]);
        }
        else if (!strcmp(inputs[3], "-f")){
            openInputFile(inputs[4]);
        }
    }

    yyparse();
    closeFiles();
    return 0;
}

void closeFiles(){
    if(yyin != NULL && fileIsOpen) 
        fclose(yyin);
    if(yyout != NULL && printToFile)
        fclose(yyout);
    exit(0);
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
        printf("Error: unable to open or create file!\n");
        exit(0);
    }
}

int yyerror(char *s) {
    if(strcmp(s,"syntax error")<-1){
        if(fileIsOpen){
            printf("*** %s\n%*c^\n",line,cursor+3,' ');
            printf("Erreur: %s dans la ligne %d à la position %d\n\n", s, yylineno, cursor);
        }else {
            if(cursor-1 != 0) printf("%*c^\n",cursor-1,' '); else printf("^\n");
            printf("Erreur: %s à la position %d\n\n", s, cursor);
        }
        exit(0);
    }
}