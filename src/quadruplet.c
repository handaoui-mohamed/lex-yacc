#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char st[100][10];
int top = 0;
int tempNumber = 0;
int lineNumber = 1;
char temp[10] = "";
char result[100] = "";
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

void printQuadruplet()
{
    if (printToFile)
    {
        fprintf(yyout, "%03d   %s\n", lineNumber++, result);
    }
    printf("%03d   %s\n", lineNumber++, result);
}

void push()
{
    strcpy(st[++top], yytext);
}

void generateSumQuadruplet()
{
    sprintf(temp, "temp%d", tempNumber++);
    sprintf(result, "%s := %s + %s", temp, st[top - 2], st[top]);
    printQuadruplet();
    top -= 2;
    strcpy(st[top], temp);
}

void generateProductQuadruplet()
{
    sprintf(temp, "temp%d", tempNumber++);
    sprintf(result, "%s := %s * %s", temp, st[top - 2], st[top]);
    printQuadruplet();
    top -= 2;
    strcpy(st[top], temp);
}

void generateAverageQuadruplet(int size)
{
    sprintf(temp, "temp%d", tempNumber++);
    sprintf(result, "%s := %s / %d", temp, st[top], size);
    printQuadruplet();
    strcpy(st[top], temp);
}

void generateInitVarianceQuadruplet()
{
    sprintf(temp, "temp%d", tempNumber++);
    sprintf(result, "%s := %s * %s", temp, st[top], st[top]);
    printQuadruplet();
    sprintf(temp, "temp%d", tempNumber++);
    sprintf(result, "%s := %s", temp, st[top]);
    printQuadruplet();
    top--;
}

void generatePreVarianceQuadruplet(int size)
{
    tempNumber++;
    sprintf(temp, "temp%d", tempNumber - size);
    sprintf(result, "%s := %s * %s", temp, st[top], st[top]);
    printQuadruplet();
    char prevTemp[10] = "";
    sprintf(prevTemp, "temp%d", tempNumber - (size + 1));
    sprintf(result, "%s := %s + %s", prevTemp, prevTemp, st[top]);
    printQuadruplet();
    sprintf(prevTemp, "temp%d", tempNumber - (size + 2));
    sprintf(result, "%s := %s + %s", prevTemp, prevTemp, temp);
    printQuadruplet();
    top--;
}

void generateVarianceQuadruplet(int size)
{
    char prevTemp[10] = "";
    sprintf(prevTemp, "temp%d", tempNumber - size - 1);
    sprintf(result, "%s := %s / %d", prevTemp, prevTemp, size);
    printQuadruplet();
    char prevTemp2[10] = "";
    sprintf(prevTemp2, "temp%d", tempNumber - size);
    sprintf(result, "%s := %s / %d", prevTemp2, prevTemp2, size);
    printQuadruplet();
    sprintf(result, "%s := %s * %s", prevTemp2, prevTemp2, prevTemp2);
    printQuadruplet();
    sprintf(temp, "temp%d", tempNumber++);
    sprintf(result, "%s := %s - %s", prevTemp2, prevTemp2, prevTemp);
    printQuadruplet();
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
    sprintf(result, "%s := %s / 2", temp, temp1);
    printQuadruplet();
    sprintf(result, "%s := 0", temp2);
    printQuadruplet();
    sprintf(result, "COMP %s %s", temp, temp2); // while
    printQuadruplet();
    sprintf(result, "JE GOTO %d", lineNumber + 6);
    printQuadruplet();
    sprintf(result, "%s := %s", temp2, temp);
    printQuadruplet();
    sprintf(result, "%s := %s / %s", temp, temp1, temp2);
    printQuadruplet();
    sprintf(result, "%s := %s + %s", temp, temp, temp2);
    printQuadruplet();
    sprintf(result, "%s := %s / 2", temp, temp);
    printQuadruplet();
    sprintf(result, "JMP GOTO %d", lineNumber - 6);
    printQuadruplet();
    strcpy(st[top], temp);
}

void generateQuadruplet()
{
    sprintf(temp, "temp%d", tempNumber++);
    sprintf(result, "%s := %s %s %s", temp, st[top - 2], st[top - 1], st[top]);
    printQuadruplet();
    top -= 2;
    strcpy(st[top], temp);
}

void generatePowQuadruplet()
{
    int saveTempNumber = tempNumber;
    sprintf(temp, "temp%d", tempNumber++);
    sprintf(result, "%s := %s", temp, st[top]);
    printQuadruplet();
    sprintf(result, "JNZ %s GOTO %d", temp, lineNumber + 3);
    printQuadruplet();
    sprintf(temp, "temp%d", tempNumber++);
    sprintf(result, "%s := 1", temp);
    printQuadruplet();
    sprintf(result, "JMP GOTO %d ", lineNumber + 4);
    printQuadruplet();
    sprintf(result, "%s := %s * %s", temp, temp, st[top - 2]);
    printQuadruplet();
    sprintf(temp, "temp%d", saveTempNumber);
    sprintf(result, "%s := %s - 1", temp, temp);
    printQuadruplet();
    sprintf(result, "JNZ %s GOTO %d", temp, lineNumber - 2);
    printQuadruplet();
    top -= 2;
    sprintf(temp, "temp%d", tempNumber - 1);
    strcpy(st[top], temp);
}

void generateQuadrupletUnaryMinus()
{
    sprintf(temp, "temp%d", tempNumber++);
    sprintf(result, "%s := -%s", temp, st[top]);
    printQuadruplet();
    top--;
    strcpy(st[top], temp);
}

void generateInitMinMaxQuadruplet()
{
    sprintf(temp, "temp%d", tempNumber++);
    sprintf(result, "%s := %s", temp, st[top]);
    printQuadruplet();
    top--;
    strcpy(st[top], temp);
}

void generatePreMinQuadruplet()
{
    sprintf(result, "COMP %s %s", st[top], st[top - 2]);
    printQuadruplet();
    sprintf(result, "JL %d", lineNumber + 2);
    printQuadruplet();
    sprintf(result, "%s := %s", st[top - 2], st[top]);
    printQuadruplet();
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
    sprintf(result, "COMP %s %s", st[top], st[top - 2]);
    printQuadruplet();
    sprintf(result, "JG %d", lineNumber + 2);
    printQuadruplet();
    sprintf(result, "%s := %s", st[top - 2], st[top]);
    printQuadruplet();
    top--;
    strcpy(st[top], temp);
}

void generateMaxQuadruplet()
{
    sprintf(temp, "temp%d", tempNumber - 2);
    strcpy(st[top - 1], temp);
}
