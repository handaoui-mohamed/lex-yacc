#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char st[100][10];
int top = 0;
int tempNumber = 0;
int lineNumber = 1;
char temp[10] = "";
char string[20] = "";
extern char *yytext;
extern int printToFile;
extern FILE *yyout;

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

/* quadrulpet generation functions */

void printQuadruplet(char *codeOp, char *op1, char *op2, char *dest)
{
    if (printToFile)
        fprintf(yyout, "%03d   %s,%s,%s,%s\n", lineNumber++, codeOp, op1, op2, dest);
    else
        printf("%03d   %s,%s,%s,%s\n", lineNumber++, codeOp, op1, op2, dest);
}

void push()
{
    strcpy(st[++top], yytext);
}

void generateSumQuadruplet()
{
    sprintf(temp, "temp%d", tempNumber++);
    printQuadruplet("+", st[top - 2], st[top], temp);
    // printf("%03d   %s := %s + %s\n", lineNumber++, temp, st[top - 2], st[top]);
    top -= 2;
    strcpy(st[top], temp);
}

void generateProductQuadruplet()
{
    sprintf(temp, "temp%d", tempNumber++);
    printQuadruplet("*", st[top - 2], st[top], temp);
    // printf("%03d   %s := %s * %s\n", lineNumber++, temp, st[top - 2], st[top]);
    top -= 2;
    strcpy(st[top], temp);
}

void generateAverageQuadruplet(int size)
{
    sprintf(temp, "temp%d", tempNumber++);
    printf("%03d   %s := %s / %d\n", lineNumber++, temp, st[top], size);
    strcpy(st[top], temp);
}

void generateInitVarianceQuadruplet()
{
    sprintf(temp, "temp%d", tempNumber++);
    printf("%03d   %s := %s * %s\n", lineNumber++, temp, st[top], st[top]);
    sprintf(temp, "temp%d", tempNumber++);
    printf("%03d   %s := %s\n", lineNumber++, temp, st[top]);
    top--;
    // strcpy(st[top], temp);
}

void generatePreVarianceQuadruplet(int size)
{
    tempNumber++;
    sprintf(temp, "temp%d", tempNumber - size);
    printf("%03d   %s := %s * %s\n", lineNumber++, temp, st[top], st[top]);
    char prevTemp[10] = "";
    sprintf(prevTemp, "temp%d", tempNumber - (size + 1));
    printf("%03d   %s := %s + %s\n", lineNumber++, prevTemp, prevTemp, st[top]);
    sprintf(prevTemp, "temp%d", tempNumber - (size + 2));
    printf("%03d   %s := %s + %s\n", lineNumber++, prevTemp, prevTemp, temp);
    top--;
    // strcpy(st[top], temp);
}

void generateVarianceQuadruplet(int size)
{
    char prevTemp[10] = "";
    sprintf(prevTemp, "temp%d", tempNumber - size - 1);
    printf("%03d   %s := %s / %d\n", lineNumber++, prevTemp, prevTemp, size);
    char prevTemp2[10] = "";
    sprintf(prevTemp2, "temp%d", tempNumber - size);
    printf("%03d   %s := %s / %d\n", lineNumber++, prevTemp2, prevTemp2, size);
    printf("%03d   %s := %s * %s\n", lineNumber++, prevTemp2, prevTemp2, prevTemp2);
    sprintf(temp, "temp%d", tempNumber++);
    printf("%03d   %s := %s - %s\n", lineNumber++, prevTemp2, prevTemp2, prevTemp);
    tempNumber -= size + 1;
    sprintf(temp, "temp%d", tempNumber);
    top -= size - 2;
    strcpy(st[top], temp);
}

void generateDeviationQuadruplet()
{
    char temp1[10] = "";
    sprintf(temp1, "temp%d", tempNumber++); // n
    char temp2[10] = "";
    sprintf(temp, "temp%d", tempNumber++);  //sqt
    sprintf(temp2, "temp%d", tempNumber++); // temp
    printf("%03d   %s := %s / 2\n", lineNumber++, temp, temp1);
    printf("%03d   %s := 0\n", lineNumber++, temp2);
    printf("%03d   COMP %s %s\n", lineNumber++, temp, temp2); // while
    printf("%03d   JE GOTO %d\n", lineNumber++, lineNumber + 6);
    printf("%03d   %s := %s\n", lineNumber++, temp2, temp);
    printf("%03d   %s := %s / %s\n", lineNumber++, temp, temp1, temp2);
    printf("%03d   %s := %s + %s\n", lineNumber++, temp, temp, temp2);
    printf("%03d   %s := %s / 2\n", lineNumber++, temp, temp);
    printf("%03d   JMP GOTO %d\n", lineNumber++, lineNumber - 6);
    strcpy(st[top], temp);
}

void generateQuadruplet()
{
    sprintf(temp, "temp%d", tempNumber++);
    // printQuadruplet(st[top - 1], st[top - 2], st[top], temp);
    printf("%03d   %s := %s %s %s\n", lineNumber++, temp, st[top - 2], st[top - 1], st[top]);
    top -= 2;
    strcpy(st[top], temp);
}

void generatePowQuadruplet()
{
    int saveTempNumber = tempNumber;
    sprintf(temp, "temp%d", tempNumber++);
    printf("%03d   %s := %s\n", lineNumber++, temp, st[top]);
    printf("%03d   JNZ %s GOTO %d\n", lineNumber++, temp, lineNumber + 3);
    sprintf(temp, "temp%d", tempNumber++);
    printf("%03d   %s := 1\n", lineNumber++, temp);
    printf("%03d   JMP GOTO %d \n", lineNumber++, lineNumber + 4);
    printf("%03d   %s := %s * %s\n", lineNumber++, temp, temp, st[top - 2]);
    sprintf(temp, "temp%d", saveTempNumber);
    printf("%03d   %s := %s - 1\n", lineNumber++, temp, temp);
    printf("%03d   JNZ %s GOTO %d\n", lineNumber++, temp, lineNumber - 2);
    top -= 2;
    sprintf(temp, "temp%d", tempNumber - 1);
    strcpy(st[top], temp);
}

void generateQuadrupletUnaryMinus()
{
    sprintf(temp, "temp%d", tempNumber++);
    // printQuadruplet("-", st[top], "\0", temp);
    printf("%03d   %s := -%s\n", lineNumber++, temp, st[top]);
    top--;
    strcpy(st[top], temp);
}

void generateInitMinMaxQuadruplet()
{
    sprintf(temp, "temp%d", tempNumber++);
    // printQuadruplet("=", "\0", st[top], temp);
    printf("%03d   %s := %s\n", lineNumber++, temp, st[top]);
    top--;
    strcpy(st[top], temp);
}

void generatePreMinQuadruplet()
{
    // printQuadruplet("COMP", temp, st[top], "\0");
    // sprintf(string, "%d", lineNumber + 2);
    // printQuadruplet("JL", "\0", "\0", string);
    // printQuadruplet("=", st[top], "\0", temp);
    printf("%03d   COMP %s %s\n", lineNumber++, st[top], st[top - 2]);
    printf("%03d   JL %d\n", lineNumber++, lineNumber + 2);
    printf("%03d   %s := %s\n", lineNumber++, st[top - 2], st[top]);
    top--;
    strcpy(st[top], temp);
}

void generateMinQuadruplet()
{
    sprintf(temp, "temp%d", tempNumber - 2);
    strcpy(st[top - 1], temp);
}

void generatePreMaxQuadruplet()
{
    // printQuadruplet("COMP", temp, st[top], "\0");
    // sprintf(string, "%d", lineNumber + 2);
    // printQuadruplet("JL", "\0", "\0", string);
    // printQuadruplet("=", st[top], "\0", temp);
    printf("%03d   COMP %s %s\n", lineNumber++, st[top], st[top - 2]);
    printf("%03d   JG %d\n", lineNumber++, lineNumber + 2);
    printf("%03d   %s := %s\n", lineNumber++, st[top - 2], st[top]);
    top--;
    strcpy(st[top], temp);
}

void generateMaxQuadruplet()
{
    sprintf(temp, "temp%d", tempNumber - 2);
    strcpy(st[top - 1], temp);
}
