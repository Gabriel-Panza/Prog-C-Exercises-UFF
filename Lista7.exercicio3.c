#include <stdio.h>
#include <stdlib.h>

int preenche(int *vet, int n)
{
    int i;
    for (i=1;i<=n;i++)
        vet[i-1]=5*i;
}
void printa (int *vet, int n)
{
    int i;
    for (i=0;i<n;i++)
        printf("%d ", vet[i]);
}
void main()
{
    int tam = 10;
    int *v = (int *) malloc (tam*sizeof(int));
    if (v==NULL)
    {
        exit(1);
    }
    preenche(v,tam);
    printa(v,tam);
}
