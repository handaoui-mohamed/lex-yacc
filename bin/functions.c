#include <stdlib.h>
#include <stdio.h>
#include "functions.h"

void allocate(node **p)
{
    *p = (struct node *)malloc(sizeof(struct node));
    (*p)->next = NULL;
    (*p)->value = 0;
}

void setValue(node *p, double v)
{
    (p->value = v);
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
        printf("new value = %lf\n", newNode->value);
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
    printf("new value = %lf\n", (*p)->value);
}

int hasNext(node *p)
{
    return p == NULL ? 0 : 1;
}

double getValue(node *p)
{
    return p->value;
}