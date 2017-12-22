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
    
    // global variables
    int fileIsOpen = 0;
    
    // global functions
    void help();
    
    // quadruplet
    char st [100][10];
    int top = 0;
    char tempNumber[2]="0";
    char temp[5]="temp";
    void push();
    void generateQuadruplet();
    void generateQuadrupletUnaryMinus();
%}
%union { int number; }

/* Tokens */
%token <number> ALPHA EOI

/* precedency */
%left '-' '+'
%left '*' '/'
%right '^'    
%right unary_minus

/* Types definitions */
%type <number> Expr

/* starting point */
%start Input
%%
Input:
     | Input Line { cursor = 0; strcpy(tempNumber, "0"); printf("\n"); }
     ;
    
Line: EOI
    | Expr EOI { }
    ;

Expr: Expr '-' { push(); } Expr { generateQuadruplet(); }
    | Expr '+' { push(); } Expr { generateQuadruplet(); }
    | Expr '/' { push(); } Expr { generateQuadruplet(); }
    | Expr '*' { push(); } Expr { generateQuadruplet(); }
    | Expr '^' { push(); } Expr { generateQuadruplet(); }
    | '-' { push(); } Expr %prec unary_minus { generateQuadrupletUnaryMinus(); }
    | '(' Expr ')' {}
    | ALPHA { push(); }


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
%%
int main(int nbInputs,char **inputs){
    extern FILE *yyin;
    extern FILE *yyout;
    
    yyout = fopen("output","w");
    if(yyout == NULL){
        printf("Error: unable to open file or file does not existe!\n");
        exit(0);
    }
    
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
    fclose(yyout);
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


void push(){
    strcpy(st[++top],yytext);
}

void generateQuadruplet(){
    strcpy(temp, "temp");
    strcat(temp,tempNumber);
    printf("%s := %s %s %s\n",temp,st[top-2],st[top-1],st[top]);
    top -= 2;
    strcpy(st[top], temp);
    tempNumber[0]++;
}

void generateQuadrupletUnaryMinus(){
    strcpy(temp, "temp");
    strcat(temp,tempNumber);
    printf("%s := -%s\n",temp,st[top]);
    top--;
    strcpy(st[top], temp);
    tempNumber[0]++;
}
