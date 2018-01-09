#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char stack[100][10];
char quadStack[100][100];
int top = 0;
int tempNumber = 0;
int lineNumber = 1;
char temp[10] = "";
char result[100] = "";
extern char *yytext;
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
    printf("   |_|  |_|       \\_____\\____/|_|  |_|_|   |_____|______| |_____/|_____|______|\n\n");

    printf("Pour analyser les entrées cmd, exécutez sans paramètre :\n\t ./prog\n");
    printf("Pour analyser un fichier :\n\t ./prog -f <filename>\n");
    printf("Pour enregister le resultat d'analyse dans un fichier :\n\t ./prog -o <filename>\n");
    printf("Fonctions disponibles : \n");
    printf("\t1- operations arithmetique.\n");
    printf("\t2- somme.\n");
    printf("\t3- produit.\n");
    printf("\t4- moyenne.\n");
    printf("\t5- variance.\n");
    printf("\t6- ecart-type.\n");
    printf("\t7- min.\n");
    printf("\t8- max.\n");
}

/* quadrulpet generation functions */

void printQuadruplets()
{
    int i;
    for (i = 1; i <= lineNumber; i++)
    {
        fprintf(yyout, "%s", quadStack[i]);
    }
    fprintf(yyout, "%03d   END\n\n", lineNumber);
    lineNumber = 1;
    tempNumber = 0;
}

void generateQuadruplet()
{
    char quadrulpet[100] = "";
    sprintf(quadrulpet, "%03d   %s\n", lineNumber++, result);
    strcpy(quadStack[lineNumber], quadrulpet);
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
    sprintf(result, "JE GOTO %d", lineNumber + 6);
    generateQuadruplet();
    sprintf(result, "%s := %s", temp2, temp);
    generateQuadruplet();
    sprintf(result, "%s := %s / %s", temp, temp1, temp2);
    generateQuadruplet();
    sprintf(result, "%s := %s + %s", temp, temp, temp2);
    generateQuadruplet();
    sprintf(result, "%s := %s / 2", temp, temp);
    generateQuadruplet();
    sprintf(result, "JMP GOTO %d", lineNumber - 6);
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
    sprintf(result, "JNZ %d", lineNumber + 3);
    generateQuadruplet();
    sprintf(temp, "temp%d", tempNumber++);
    sprintf(result, "%s := 1", temp);
    generateQuadruplet();
    sprintf(result, "JMP %d ", lineNumber + 4);
    generateQuadruplet();
    sprintf(result, "%s := %s * %s", temp, temp, stack[top - 2]);
    generateQuadruplet();
    sprintf(temp, "temp%d", saveTempNumber);
    sprintf(result, "%s := %s - 1", temp, temp);
    generateQuadruplet();
    sprintf(result, "JNZ %d", lineNumber - 2);
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
    top--;
    strcpy(stack[top], temp);
}

void generatePreMinQuadruplet()
{
    sprintf(result, "COMP %s %s", stack[top], stack[top - 2]);
    generateQuadruplet();
    sprintf(result, "JL %d", lineNumber + 2);
    generateQuadruplet();
    sprintf(result, "%s := %s", stack[top - 2], stack[top]);
    generateQuadruplet();
    top--;
    strcpy(stack[top], temp);
}

void generateMinQuadruplet()
{
    sprintf(temp, "temp%d", tempNumber - 2);
    strcpy(stack[top - 1], temp);
}

void generatePreMaxQuadruplet()
{
    sprintf(result, "COMP %s %s", stack[top], stack[top - 2]);
    generateQuadruplet();
    sprintf(result, "JG %d", lineNumber + 2);
    generateQuadruplet();
    sprintf(result, "%s := %s", stack[top - 2], stack[top]);
    generateQuadruplet();
    top--;
    strcpy(stack[top], temp);
}

void generateMaxQuadruplet()
{
    sprintf(temp, "temp%d", tempNumber - 2);
    strcpy(stack[top - 1], temp);
}
