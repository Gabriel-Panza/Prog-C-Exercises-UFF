#include <stdio.h>
#include <stdlib.h>

int percorre(int *v, int tamanho)
{
    int i=0, j=tamanho;

    while (i<j)
    {
    printf("%d",i);
    i++;
    printf("%d",j);
    j--;
    }

    return i;
}

void main()
{
    int tamanho = rand();
    int vetor[tamanho];
    int ini, fim, percorrido;

    if (tamanho%2 != 0)
        tamanho+=1;

    percorrido = percorre(vetor,tamanho);
    printf("\n%d", tamanho);
    printf("\nA posicao do meio do vetor eh entre: %d e %d", percorrido,percorrido+1);
}
