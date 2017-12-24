#include <stdio.h>

void main()

{
    int n;
    float temp, sqt;
    printf("Enter number:");
    scanf("%d", &n);
    sqt = n / 2;
    temp = 0;
    while (sqt != temp)
    {
        temp = sqt;
        sqt = (n / temp + temp) / 2;
    }
    printf("the square root of %d is %f\n", n, sqt);
}