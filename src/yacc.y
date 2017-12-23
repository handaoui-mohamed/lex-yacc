%{ 
    #include <stdlib.h>
    #include <stdio.h>
    #include <math.h>
    #include <string.h>
    #include "yy.tab.h"
    #include "error.strings.h"

    // extern functions
    extern int cursor;
    extern char* yytext;
    extern int yylineno;
    extern FILE *yyin;
    extern FILE *yyout;
    
    // global variables
    int fileIsOpen = 0;
    
    // global functions
    void help();
    
    // quadruplet
    char st [100][10];
    int top = 0;
    int tempNumber = 0;
    int lineNumber = 1;
    char temp[10] = "";
    void push();
    void generateQuadruplet();
    void generateQuadrupletUnaryMinus();
    void generatePowQuadruplet();
    void generateSumQuadruplet();
    void generateProductQuadruplet();
    void generateAverageQuadruplet();
    void generateVarianceQuadruplet();
    void generateInitVarianceQuadruplet();
    void generatePreVarianceQuadruplet();
    void generateDeviationQuadruplet();
%}
%union { int number; }

/* Tokens */
%token <number> IDENTIFIER EOI
%token <number> SUM PRODUCT AVERAGE VARIANCE STANDARD_DEVIATION

/* precedency */
%left '-' '+'
%left '*' '/'
%right '^'    
%right unary_minus

/* Types definitions */
%type <number> Expr PRODUCT_List AVERAGE_List VARIANCE_List

/* starting point */
%start Input
%%
Input:
     | Input Line { cursor = 0; tempNumber = 0; printf("\n"); lineNumber = 1;}
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

































































































































%%
int main(int nbInputs,char **inputs){       
    if(nbInputs == 2 && (strcmp(inputs[1], "-h") || strcmp(inputs[1], "--help"))){
        help();
        exit(0);
    }

    if(nbInputs == 3 && strcmp(inputs[2], "-f")){
        yyin = NULL;
        yyout = NULL;
        yyin = fopen(inputs[2],"r"); 
        yyout = fopen("output","w");
        if(yyin) fileIsOpen = 1;
        else {
            printf("Error: unable to open file or file does not existe!\n");
            exit(0);
        }
        if(yyout == NULL){
            printf("Error: unable to open file or file does not existe!\n");
            exit(0);
        }
    }
    yyparse();
    if(fileIsOpen) {
        fclose(yyin);
        fclose(yyout);
    }
    return 0;
}

int yyerror(char *s) {
    printf("errror\n");
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


void push(){
    strcpy(st[++top],yytext);
}

void generateSumQuadruplet(){
    sprintf(temp, "temp%d",tempNumber++);
    printf("%03d   %s := %s + %s\n",lineNumber++,temp,st[top-2],st[top]);
    top -= 2;
    strcpy(st[top], temp);
}

void generateProductQuadruplet(){
    sprintf(temp, "temp%d",tempNumber++);
    printf("%03d   %s := %s * %s\n",lineNumber++,temp,st[top-2],st[top]);
    top -= 2;
    strcpy(st[top], temp);
}

void generateAverageQuadruplet(int size){
    sprintf(temp, "temp%d",tempNumber++);
    printf("%03d   %s := %s / %d\n",lineNumber++,temp,st[top],size);
    strcpy(st[top], temp);
}

void generateInitVarianceQuadruplet(){
    sprintf(temp, "temp%d",tempNumber++);
    printf("%03d   %s := %s * %s\n",lineNumber++,temp,st[top],st[top]);
    sprintf(temp, "temp%d",tempNumber++);
    printf("%03d   %s := %s\n",lineNumber++,temp,st[top]);
    top --;
    // strcpy(st[top], temp);
}

void generatePreVarianceQuadruplet(int size){
    tempNumber++;
    sprintf(temp, "temp%d",tempNumber-size);
    printf("%03d   %s := %s * %s\n",lineNumber++,temp,st[top],st[top]);
    char prevTemp[10] = "";
    sprintf(prevTemp, "temp%d",tempNumber-(size + 1));
    printf("%03d   %s := %s + %s\n",lineNumber++,prevTemp,prevTemp,st[top]);
    sprintf(prevTemp, "temp%d",tempNumber-(size + 2));
    printf("%03d   %s := %s + %s\n",lineNumber++,prevTemp,prevTemp,temp);
    top --;
    // strcpy(st[top], temp);
}

void generateVarianceQuadruplet(int size){
    char prevTemp[10] = "";
    sprintf(prevTemp, "temp%d",tempNumber-size-1);
    printf("%03d   %s := %s / %d\n",lineNumber++,prevTemp,prevTemp,size);
    char prevTemp2[10] = "";
    sprintf(prevTemp2, "temp%d",tempNumber-size);
    printf("%03d   %s := %s / %d\n",lineNumber++,prevTemp2,prevTemp2,size);
    printf("%03d   %s := %s * %s\n",lineNumber++,prevTemp2,prevTemp2,prevTemp2);
    sprintf(temp, "temp%d",tempNumber++);
    printf("%03d   %s := %s - %s\n",lineNumber++,prevTemp2,prevTemp2,prevTemp);
    tempNumber -= size + 1;
    sprintf(temp, "temp%d",tempNumber);
    top -= size - 2;
    strcpy(st[top], temp);
}

void generateDeviationQuadruplet(){
    printf("%03d   %s := CALL SQRT %s ????\n",lineNumber++,temp,temp);
}

void generateQuadruplet(){
    sprintf(temp, "temp%d",tempNumber++);
    printf("%03d   %s := %s %s %s\n",lineNumber++,temp,st[top-2],st[top-1],st[top]);
    top -= 2;
    strcpy(st[top], temp);
}

void generatePowQuadruplet(){
    int saveTempNumber = tempNumber;
    sprintf(temp, "temp%d",tempNumber++);
    printf("%03d   %s := %s\n",lineNumber++,temp,st[top]);
    sprintf(temp, "temp%d",tempNumber++);
    printf("%03d   %s := %s * %s\n",lineNumber++,temp,temp,st[top-2]);
    sprintf(temp, "temp%d",saveTempNumber);
    printf("%03d   %s := %s - 1\n",lineNumber++,temp,temp);
    printf("%03d   JNZ %s GOTO %d\n",lineNumber++,temp,lineNumber-2);
    top -= 2;
    sprintf(temp, "temp%d",tempNumber-1);
    strcpy(st[top], temp);
}

void generateQuadrupletUnaryMinus(){
    sprintf(temp, "temp%d",tempNumber++);
    printf("%03d   %s := -%s\n",lineNumber++,temp,st[top]);
    top--;
    strcpy(st[top], temp);
}