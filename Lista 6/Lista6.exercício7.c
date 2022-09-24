#include <stdio.h>
#include <stdlin.h>

void repeticao(int *vet, int tam)
{
    int i, j;
    int *vf;

    vf = (int *) malloc(tam*sizeof(int));
    if (vf==NULL)
    {
        exit(1);
    }

    for (i=0;i<tam;i++)
    {
        vf[i] = NULL;
    }

    for (i=0;i<tam;i++)
    {
        for (j=0;j<tam;j++)
        {
            if ((vet[i]==vet[j]) && (i!=j))
            {
                vf[i] = vet[j];
            }
        }
    }

    printf("O vetor final eh: ");
    for (i=0;i<tam;i++)
    {
        for (j=1;j<tam;j++)
        {
            if ((vf[i]==vf[j]) && (i!=j))
                vf[j]=NULL;
        }
        if (vf[i] != NULL)
            printf("%d ", vf[i]);
    }

    free(vf);
}

void main()
{
    int i, n;
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
        while (v[i]>9 || (v[i]<0))
        {
            printf("Erro! Digite um numero entre 0 e 9");
            scanf("%d", &v[i]);
        }
    }

    repeticao(v,n);

    free(v);
}
