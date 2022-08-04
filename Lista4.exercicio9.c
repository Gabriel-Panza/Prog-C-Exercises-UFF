#include <stdio.h>

void mudandoValoresVetor (int *v, int n, int *vf)
{
    int i, soma=0;

    for (i=0;i<n;i++)
    {
        soma += v[i];
        vf[i] = soma;
    }
}

int procuraValor (int *v, int n)
{
    int i, valor;

    printf("\nQual valor quieres procurar? ");
    scanf("%d", &valor);

    for (i=0;i<n;i++)
        if (v[i] == valor)
            return i;
    return -1;
}

void main()
{
    int i, tamanho = 7;
    int v[tamanho];
    int vf[tamanho];

    for (i=0;i<tamanho;i++)
    {
        printf("\nDigite o valor de posicao %d do vetor: ", i);
        scanf("%d", &v[i]);
    }

    for (i=0;i<tamanho;i++)
    {
        printf("\nPosicao %d do vetor = %d", i,v[i]);
    }

    int encontrouPos = procuraValor(v,tamanho);
    printf("\n%d\n", encontrouPos);

    mudandoValoresVetor(v,tamanho,vf);
    for (i=0;i<tamanho;i++)
        printf("%d ", vf[i]);
}
