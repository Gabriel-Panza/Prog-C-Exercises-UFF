#include <stdio.h>
#include <stdlib.h>

int preenche(char *vet, int n)
{
    int i;
    char ini = 'a';
    for (i=0;i<=n;i++)
    {
        vet[i]= ini;
        ini++;
    }
}
void printa (char *vet, int n)
{
    int i;
    for (i=0;i<n;i++)
        printf("%c ", vet[i]);
}
void main()
{
    int tam = 26;
    char *alfabeto = (char *) malloc (tam*sizeof(char));
    if (alfabeto==NULL)
    {
        exit(1);
    }
    preenche(alfabeto,tam);
    printa(alfabeto,tam);
}
