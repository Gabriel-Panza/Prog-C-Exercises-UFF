#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool matriz(int **matriz, int linha, int coluna)
{
    int i,j,soma=0;
    int v[linha];

    for (i=0;i<linha;i++)
    {
        for (j=0;j<coluna;j++)
        {
            soma += matriz[i][j];
        }
        v[i]=soma;
        soma=0;
    }
    for (i=0;i<(linha-1);i++)
    {
        if (v[i]==v[i+1])
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    free(v);
    return true;
}
void main()
{
    int i,j,m,n;

    printf("Digite o numero de linhas: ");
    scanf("%d", &m);
    printf("Digite o numero de colunas: ");
    scanf("%d", &n);

    printf("Preencha o vetor %d x %d: ", m,n);
    int **mat = (int **) malloc(m*sizeof(int *));
    if (mat==NULL)
    {
        exit(1);
    }
    for (i=0;i<m;i++)
    {
        mat[i]= (int *) malloc(n*sizeof(int));
        if (mat[i]==NULL)
        {
            exit(1);
        }
    }

    for (i=0;i<m;i++)
    {
        for (j=0;j<n;j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
    bool soma = matriz(mat,m,n);
    if (soma == true)
        printf("True! A soma de todas as linhas eh a mesma.");
    else
        printf("False! A soma das linhas eh diferente.");

    free(mat);
}
