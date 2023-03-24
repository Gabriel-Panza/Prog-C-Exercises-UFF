#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

void binary(int n)
{
    int *bin = (int*) malloc(32 * sizeof(int));
    int aux, cont=0;

    while (n>=1)
    {
        bin[cont] = n%2;
        n=n/2;
        cont++;
    }

    for (int i=0;i<cont/2;i++)
    {
        aux = bin[cont-i-1];
        bin[cont-i-1] = bin[i];
        bin[i] = aux;
    }

    for (int i=0;i<cont;i++)
    {    
        printf("%d", bin[i]);
    }
}

void main()
{
    int n, i;

    do
    {
        printf("\nType a number: ");
        scanf("%d", &n);
        if (n<0)
            break;
        
        binary(n);
    } while (1);
    
}