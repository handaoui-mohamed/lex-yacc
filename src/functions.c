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

double getNextValue(node **p)
{
    if ((*p)->next != NULL)
    {
        node *newNode = NULL;
        newNode = (*p)->next;
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
double average(node *list)
{
    double result = 0;
    int size = 0;
    while (hasNext(list))
    {
        result += getNextValue(&list);
        size++;
    }
    return result /= size;
}

double sum(node *list)
{
    double result = 0;
    while (hasNext(list))
    {
        result += getNextValue(&list);
    }
    return result;
}

double product(node *list)
{
    double result = 0;
    while (hasNext(list))
    {
        result *= getNextValue(&list);
    }
    return result;
}

double variance(node *list)
{
    double result = 0;
    int size = 0;
    double averageValue = average(list);
    while (hasNext(list))
    {
        result += pow((getNextValue(&list) - averageValue), 2);
        size++;
    }
    return result /= size;
}

double standardDeviation(node *list)
{
    return sqrt(variance(list));
}