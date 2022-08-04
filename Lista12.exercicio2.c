#include <stdio.h>
#include <stdlib.h>

int somaImpares (int *v, int soma, int tam)
{
    if ((v[0] % 2 != 0) && tam>0)
    {
        tam-=1;
        return v[0] + somaImpares(&v[1],soma,tam);
    }

    else if ((v[0] % 2 == 0) && tam>0)
    {
        tam-=1;
        return somaImpares(&v[1],soma,tam);
    }

    else
    {
        return soma;
    }
}
void main()
{
    int i, tam, soma=0;
    printf("Diga o tamanho do vetor: ");
    scanf(" %d", &tam);
    int *v = (int*) malloc(tam*sizeof(int));
    if (v==NULL)
    {
        printf("Error!");
        exit(1);
    }

    printf("Preencha o vetor de %d inteiros:\n", tam);
    for (i=0;i<tam;i++)
    {
        scanf(" %d", &v[i]);
    }

    int somaImpar = somaImpares(v,soma,tam);
    printf("A soma dos impares do vetor eh: %d", somaImpar);
    free(v);
}
