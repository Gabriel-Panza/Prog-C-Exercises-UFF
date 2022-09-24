#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool in (int *v, int n, int x)
{
    int i;

    for(i=0;i<n;i++)
    {
        if (v[i] == x)
            return true;
    }

    return false;
}

int *repeticao(int *vet, int tam, int *n)
{
    int i, j, cont=0;
    int *vf = (int *) malloc(tam*sizeof(int));
    if (vf==NULL)
    {
        exit(1);
    }

    for (i=0;i<tam;i++)
    {
        for (j=(i+1);j<tam;j++)
        {
            if ((vet[i]==vet[j]) && (!in(vf,cont,vet[j])))
            {
                    vf[cont] = vet[j];
                    cont++;
            }
        }
    }

    *n = cont;

    return vf;
}

void main()
{
    int i, n, nFinal;
    int *v;

    printf("Informe o tamanho do vetor: ");
    scanf("%d", &n);

    v = (int *) malloc(n*sizeof(int));
    if (v==NULL)
    {
        exit(1);
    }

    printf("Preencha o vetor:");
    for (i=0;i<n;i++)
    {
        scanf("%d", &v[i]);
        while ((v[i]>9) || (v[i]<0))
        {
            printf("Erro! Digite um numero entre 0 e 9");
            scanf("%d", &v[i]);
        }
    }

    int *vetFinal = repeticao(v,n,&nFinal);

    printf("O vetor final eh: ");
    for (i=0;i<nFinal;i++)
    {
        printf("%d ", vetFinal[i]);
    }

    free(v);
    free(vetFinal);
}
