#include <stdio.h>

void main()
{
    int i;
    int v1[20];
    int v2[20];
    char v3[20];
    int v4[20];

    for(i=0;i<20;i++)
    {
        v1[i] = rand()%1000;
        v2[i] = rand()%1000;
    }
    for (i=0;i<20;i++)
    {
        printf("Type what operation do you want to see between the values in index %d:\n", i);
        printf("obs: additive:(+) subtraction:(-) division:(/) multiplicative:(*)\n");
        scanf("\n%c", &v3[i]);
        while (v3[i] != '+' && v3[i] != '-' && v3[i] != '/' && v3[i] != '*')
        {
            printf("Error! Invalid Symbol!\n");
            printf("Type a valid symbol:\n");
            scanf("\n%c", &v3[i]);
        }
    }
    for (i=0;i<20;i++)
    {
        if (v3[i] == "+")
        {
            v4[i] = v1[i]+v2[i];
        }
        if (v3[i] == "-")
        {
            v4[i] = v1[i]-v2[i];
        }
        if (v3[i] == "/")
        {
            v4[i] = v1[i]/v2[i];
        }
        if (v3[i] == "*")
        {
            v4[i] = v1[i]*v2[i];
        }
    }
    for (i=0;i<20;i++)
        printf("%d", v4[i]);
}