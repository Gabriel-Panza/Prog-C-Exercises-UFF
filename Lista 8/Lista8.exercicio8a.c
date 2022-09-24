#include <stdio.h>
#include <stdlib.h>

void *ordenacao(char *vChar, int n)
{
    int i,j;
    char temp;

    for (i=0;i<n;i++)
    {
        for (j=0;j<(n-1);j++)
            if (vChar[j]>vChar[j+1])
            {
                temp = vChar[j];
                vChar[j] = vChar[j+1];
                vChar[j+1] = temp;
            }
    }

    printf("A palavra ordenada eh: ");
    for (i=0;i<n;i++)
    {
        printf("%c", vChar[i]);
    }
}

void main()
{
    char palavra[100];
    puts("Digite a palavra a ser ordenada: ");
    gets(palavra);

    int tam = strlen(palavra);
    ordenacao(palavra,tam);
}
