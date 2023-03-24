#include<stdio.h>
#include<stdlib.h>

int MDC(int n1, int n2)
{
    int i, higherDiv, div;
    if (n1 <= n2)
        higherDiv = n1;
    else
        higherDiv = n2;

    div = higherDiv;
    for (i=0;i<div;i++)
    {
        if ((n1%higherDiv || n2%higherDiv) != 0)
        {
            higherDiv--;
        }
    }
    return higherDiv;
}

void main()
{
    int num1, num2;
    printf("Type the first number: ");
    scanf("%d", &num1);
    fflush(stdin);
    printf("Type the second number: ");
    scanf("%d", &num2);
    printf("%d", MDC(num1, num2));
}
