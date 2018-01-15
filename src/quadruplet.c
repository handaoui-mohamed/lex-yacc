#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char stack[100][10];
char quadStack[100][100];
int top = 0;
int tempNumber = 0;
int lineNumber = 0;
char temp[10] = "";
char result[100] = "";
extern int fileIsOpen;
extern char *yytext;
extern FILE *yyout;
extern char line[255];

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
    printf("   |_|  |_|       \\_____\\____/|_|  |_|_|   |_____|______| |_____/|_____|______|\n\n");

    printf("Pour analyser les entrées cmd, exécutez sans paramètre :\n\t ./prog\n");
    printf("Pour analyser un fichier :\n\t ./prog -f <filename>\n");
    printf("Pour enregister le resultat d'analyse dans un fichier :\n\t ./prog -o <filename>\n");
    printf("Fonctions disponibles : \n");
    printf("\t1- operations arithmetique.\n");
    printf("\t2- somme(expr1, expr2, expr3, ...).\n");
    printf("\t3- produit(expr1, expr2, expr3, ...).\n");
    printf("\t4- moyenne(expr1, expr2, expr3, ...).\n");
    printf("\t5- variance(expr1, expr2, expr3, ...).\n");
    printf("\t6- ecart-type(expr1, expr2, expr3, ...).\n");
    printf("\t7- min(expr1, expr2, expr3, ...).\n");
    printf("\t8- max(expr1, expr2, expr3, ...).\n");
    printf("\t9- si(test, expr1, expr2).\n");
}

/* quadrulpet generation functions */

void printQuadruplets()
{
    int i;
    if (fileIsOpen)
    {
        printf("%s\n", line);
    }
    for (i = 1; i <= lineNumber; i++)
    {
        fprintf(yyout, "%03d   %s\n", i, quadStack[i]);
    }
    fprintf(yyout, "%03d   END\n\n", lineNumber + 1);
    lineNumber = 0;
    tempNumber = 0;
}

void generateQuadruplet()
{
    sprintf(quadStack[++lineNumber], "%s", result);
}

void setJumpAddress(int quadNumber, int address)
{
    sprintf(quadStack[quadNumber], "%s %d", quadStack[quadNumber], address);
}

void push()
{
    strcpy(stack[++top], yytext);
}

void generateSumQuadruplet()
{
    sprintf(temp, "temp%d", tempNumber++);
    sprintf(result, "%s := %s + %s", temp, stack[top - 2], stack[top]);
    generateQuadruplet();
    top -= 2;
    strcpy(stack[top], temp);
}

void generateProductQuadruplet()
{
    sprintf(temp, "temp%d", tempNumber++);
    sprintf(result, "%s := %s * %s", temp, stack[top - 2], stack[top]);
    generateQuadruplet();
    top -= 2;
    strcpy(stack[top], temp);
}

void generateAverageQuadruplet(int size)
{
    sprintf(temp, "temp%d", tempNumber++);
    sprintf(result, "%s := %s / %d", temp, stack[top], size);
    generateQuadruplet();
    strcpy(stack[top], temp);
}

void generateInitVarianceQuadruplet()
{
    sprintf(temp, "temp%d", tempNumber++);
    sprintf(result, "%s := %s * %s", temp, stack[top], stack[top]);
    generateQuadruplet();
    sprintf(temp, "temp%d", tempNumber++);
    sprintf(result, "%s := %s", temp, stack[top]);
    generateQuadruplet();
    top--;
}

void generatePreVarianceQuadruplet(int size)
{
    tempNumber++;
    sprintf(temp, "temp%d", tempNumber - size);
    sprintf(result, "%s := %s * %s", temp, stack[top], stack[top]);
    generateQuadruplet();
    char prevTemp[10] = "";
    sprintf(prevTemp, "temp%d", tempNumber - (size + 1));
    sprintf(result, "%s := %s + %s", prevTemp, prevTemp, stack[top]);
    generateQuadruplet();
    sprintf(prevTemp, "temp%d", tempNumber - (size + 2));
    sprintf(result, "%s := %s + %s", prevTemp, prevTemp, temp);
    generateQuadruplet();
    top--;
}

void generateVarianceQuadruplet(int size)
{
    char prevTemp[10] = "";
    sprintf(prevTemp, "temp%d", tempNumber - size - 1);
    sprintf(result, "%s := %s / %d", prevTemp, prevTemp, size);
    generateQuadruplet();
    char prevTemp2[10] = "";
    sprintf(prevTemp2, "temp%d", tempNumber - size);
    sprintf(result, "%s := %s / %d", prevTemp2, prevTemp2, size);
    generateQuadruplet();
    sprintf(result, "%s := %s * %s", prevTemp2, prevTemp2, prevTemp2);
    generateQuadruplet();
    sprintf(temp, "temp%d", tempNumber++);
    sprintf(result, "%s := %s - %s", prevTemp2, prevTemp2, prevTemp);
    generateQuadruplet();
    tempNumber -= size + 1;
    sprintf(temp, "temp%d", tempNumber);
    top -= size - 2;
    strcpy(stack[top], temp);
}

void generateDeviationQuadruplet()
{
    char temp1[10] = "";
    sprintf(temp1, "temp%d", tempNumber++); // n
    char temp2[10] = "";
    sprintf(temp, "temp%d", tempNumber++);  //sqt
    sprintf(temp2, "temp%d", tempNumber++); // temp
    sprintf(result, "%s := %s / 2", temp, temp1);
    generateQuadruplet();
    sprintf(result, "%s := 0", temp2);
    generateQuadruplet();
    sprintf(result, "COMP %s %s", temp, temp2); // while
    generateQuadruplet();
    sprintf(result, "JE %d", lineNumber + 7);
    generateQuadruplet();
    sprintf(result, "%s := %s", temp2, temp);
    generateQuadruplet();
    sprintf(result, "%s := %s / %s", temp, temp1, temp2);
    generateQuadruplet();
    sprintf(result, "%s := %s + %s", temp, temp, temp2);
    generateQuadruplet();
    sprintf(result, "%s := %s / 2", temp, temp);
    generateQuadruplet();
    sprintf(result, "JMP %d", lineNumber - 5);
    generateQuadruplet();
    strcpy(stack[top], temp);
}

void generateArithmeticQuadruplet()
{
    sprintf(temp, "temp%d", tempNumber++);
    sprintf(result, "%s := %s %s %s", temp, stack[top - 2], stack[top - 1], stack[top]);
    generateQuadruplet();
    top -= 2;
    strcpy(stack[top], temp);
}

void generatePowQuadruplet()
{
    int saveTempNumber = tempNumber;
    sprintf(temp, "temp%d", tempNumber++);
    sprintf(result, "%s := %s", temp, stack[top]);
    generateQuadruplet();
    sprintf(temp, "temp%d", tempNumber++);
    sprintf(result, "%s := 1", temp);
    generateQuadruplet();
    sprintf(result, "CMP %s", stack[top]);
    generateQuadruplet();
    sprintf(result, "JZ %d", lineNumber + 5);
    generateQuadruplet();
    sprintf(result, "%s := %s * %s", temp, temp, stack[top - 2]);
    generateQuadruplet();
    sprintf(temp, "temp%d", saveTempNumber);
    sprintf(result, "%s := %s - 1", temp, temp);
    generateQuadruplet();
    sprintf(result, "JNZ %d", lineNumber - 1);
    generateQuadruplet();
    top -= 2;
    sprintf(temp, "temp%d", tempNumber - 1);
    strcpy(stack[top], temp);
}

void generateQuadrupletUnaryMinus()
{
    sprintf(temp, "temp%d", tempNumber++);
    sprintf(result, "%s := -%s", temp, stack[top]);
    generateQuadruplet();
    top--;
    strcpy(stack[top], temp);
}

void generateInitMinMaxQuadruplet()
{
    sprintf(temp, "temp%d", tempNumber++);
    sprintf(result, "%s := %s", temp, stack[top]);
    generateQuadruplet();
    // top--;
    strcpy(stack[top], temp);
}

void generatePreMinQuadruplet()
{
    sprintf(result, "COMP %s %s", stack[top], stack[top - 2]);
    generateQuadruplet();
    sprintf(result, "JL %d", lineNumber + 3);
    generateQuadruplet();
    sprintf(result, "%s := %s", stack[top - 2], stack[top]);
    generateQuadruplet();
    top -= 2;
    // strcpy(stack[top], stack[top]);
}

void generateMinQuadruplet()
{
    // sprintf(temp, "temp%d", tempNumber - 2);
    // strcpy(stack[top], temp);
}

void generatePreMaxQuadruplet()
{
    sprintf(result, "COMP %s %s", stack[top], stack[top - 2]);
    generateQuadruplet();
    sprintf(result, "JG %d", lineNumber + 3);
    generateQuadruplet();
    sprintf(result, "%s := %s", stack[top - 2], stack[top]);
    generateQuadruplet();
    // top--;
    top -= 2;
    // strcpy(stack[top], stack[top - 1]);
}

void generateMaxQuadruplet()
{
    // sprintf(temp, "temp%d", tempNumber - 2);
    // strcpy(stack[top - 1], temp);
}

void generateTempQuadruplet()
{
    lineNumber++;
    sprintf(quadStack[lineNumber], "%s", stack[top]);
    sprintf(result, "JMP");
    generateQuadruplet();
    // top--;
    // strcpy(stack[top], temp);
}

void generateTestQuadruplet()
{
    sprintf(result, "CMP %s %s", stack[top - 2], stack[top]);
    generateQuadruplet();
    switch (stack[top - 1][0])
    {
    case '<':
        sprintf(result, "JGE");
        break;
    case '>':
        sprintf(result, "JLE");
        break;
    case '=':
        sprintf(result, "JNE");
        break;
    }
    generateQuadruplet();
    top -= 2;
    strcpy(stack[top], temp);
}

void generateIfQuadruplet(int testAddress, int exprAddress)
{
    setJumpAddress(testAddress, exprAddress + 1);
    if (strstr(stack[top], "temp") == NULL)
    {
        setJumpAddress(exprAddress, lineNumber + 2);
        sprintf(temp, "temp%d", tempNumber++);
        sprintf(result, "%s := %s", temp, stack[top]);
        generateQuadruplet();
        strcpy(stack[top], temp);
    }
    else
    {
        setJumpAddress(exprAddress, lineNumber + 1);
    }

    char quadrulpet[100] = "";
    sprintf(quadrulpet, "%s = %s", stack[top], quadStack[exprAddress - 1]);
    strcpy(quadStack[exprAddress - 1], quadrulpet);
    sprintf(result, "JMP");

    // if (strcmp(quadStack[exprAddress - 1], "temp") < -1)
    // {
    //     sprintf(quadStack[exprAddress], "%s := %s", temp, quadStack[exprAddress]);
    // }
    // else
    // {
    //     sprintf(quadStack[exprAddress - 1], "%s = %s", stack[top], quadStack[exprAddress - 1]);
    // }
    top -= 2;
    strcpy(stack[top], temp);
}