#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "functions.h"

void allocate(node **p)
{
    *p = (struct node *)malloc(sizeof(struct node));
    (*p)->next = NULL;
    (*p)->value = 0;
}

void setValue(node *p, double value)
{
    p->value = value;
}

void setNext(node *p, node *next)
{
    p->next = next;
}

double getNextValue(node **p, int destroy)
{
    if ((*p)->next != NULL)
    {
        node *newNode = NULL;
        newNode = (*p)->next;
        if (destroy)
            free(*p);
        *p = newNode;
        return newNode->value;
    }
    return 0;
}

void addNext(node **p, double value)
{
    node *new = NULL;
    allocate(&new);
    setValue(new, value);
    if (*p != NULL)
        setNext(*p, new);
    *p = new;
}

int hasNext(node *p)
{
    return p->next == NULL ? 0 : 1;
}

/* Functions */
double averageDefault(node *list, int destroy)
{
    double result = 0;
    int size = 0;
    while (hasNext(list))
    {
        result += getNextValue(&list, destroy);
        size++;
    }
    return result /= size;
}

double average(node *list)
{
    return averageDefault(list, 1);
}

double sum(node *list)
{
    double result = 0;
    while (hasNext(list))
    {
        result += getNextValue(&list, 1);
    }
    return result;
}

double product(node *list)
{
    double result = 1;
    while (hasNext(list))
    {
        result *= getNextValue(&list, 1);
    }
    return result;
}

double variance(node *list)
{
    double result = 0;
    int size = 0;
    node *temp = list;
    double averageValue = averageDefault(temp, 0);
    while (hasNext(list))
    {
        result += pow((getNextValue(&list, 1) - averageValue), 2);
        size++;
    }
    return result /= size;
}

double standardDeviation(node *list)
{
    return sqrt(variance(list));
}

double min(node *list)
{
    double result = 0, nextValue;
    if (hasNext(list))
    {
        result = getNextValue(&list, 1);
        while (hasNext(list))
        {
            nextValue = getNextValue(&list, 1);
            if (nextValue < result)
                result = nextValue;
        }
    }
    return result;
}

double max(node *list)
{
    double result = 0, nextValue;
    if (hasNext(list))
    {
        result = getNextValue(&list, 1);
        while (hasNext(list))
        {
            nextValue = getNextValue(&list, 1);
            if (nextValue > result)
                result = nextValue;
        }
    }
    return result;
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