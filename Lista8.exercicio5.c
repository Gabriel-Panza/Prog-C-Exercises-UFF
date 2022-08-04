#include <stdio.h>
int **matrizSoma(int **matriz1, int **matriz2, int linha, int coluna)
{
    int i,j;
    int **matrizS = (int **) malloc(linha*sizeof(int *));
    if (matrizS==NULL)
    {
        exit(1);
    }
    for (i=0;i<linha;i++)
    {
        matrizS[i]= (int *) malloc(coluna*sizeof(int));
        if (matrizS[i]==NULL)
        {
            exit(1);
        }
    }

    for (i=0;i<linha;i++)
    {
        for(j=0;j<coluna;j++)
        {
            matrizS[i][j]=matriz1[i][j]+matriz2[i][j];
        }
    }
    return matrizS;
}
int **matrizMultiplica(int **matriz1, int **matriz2, int linha, int coluna)
{
    int i,j;
    int **matrizX = (int **) malloc(linha*sizeof(int *));
    if (matrizX==NULL)
    {
        exit(1);
    }
    for (i=0;i<linha;i++)
    {
        matrizX[i]= (int *) malloc(coluna*sizeof(int));
        if (matrizX[i]==NULL)
        {
            exit(1);
        }
    }

    for (i=0;i<linha;i++)
    {
        for(j=0;j<coluna;j++)
        {
            matrizX[i][j]=matriz1[i][j]*matriz2[i][j];
        }
    }
    return matrizX;
}
int **matrizSomaDiagonais(int **matriz1, int **matriz2, int linha, int coluna, int *somaDiag)
{
    int i,j,somaD=0;
    int **matrizD = (int **) malloc(linha*sizeof(int *));
    if (matrizD==NULL)
    {
        exit(1);
    }
    for (i=0;i<linha;i++)
    {
        matrizD[i]= (int *) malloc(coluna*sizeof(int));
        if (matrizD[i]==NULL)
        {
            exit(1);
        }
    }

    for (i=0;i<linha;i++)
    {
        for(j=0;j<coluna;j++)
        {
            matrizD[i][j]=NULL;
            if (i==j)
            {
                matrizD[i][j]=matriz1[i][j]+matriz2[i][j];
                somaD+=matrizD[i][j];
            }
        }
    }

    *somaDiag=somaD;
    return matrizD;
}
void main()
{
    int i,j,m,n,somaDiagonal=0;

    printf("Digite o numero de linhas: ");
    scanf("%d", &m);
    printf("Digite o numero de colunas: ");
    scanf("%d", &n);

    int **mat1 = (int **) malloc(m*sizeof(int *));
    if (mat1==NULL)
    {
        exit(1);
    }
    int **mat2 = (int **) malloc(m*sizeof(int *));
    if (mat2==NULL)
    {
        exit(1);
    }
    for (i=0;i<m;i++)
    {
        mat1[i]= (int *) malloc(n*sizeof(int));
        if (mat1[i]==NULL)
        {
            exit(1);
        }
        mat2[i]= (int *) malloc(n*sizeof(int));
        if (mat2[i]==NULL)
        {
            exit(1);
        }
    }
    printf("Preencha a matriz1 %d x %d: ", m, n);
    for (i=0;i<m;i++)
    {
        for (j=0;j<n;j++)
        {
            scanf("%d", &mat1[i][j]);
        }
    }
    printf("Preencha a matriz2 %d x %d: ", m, n);
    for (i=0;i<m;i++)
    {
        for (j=0;j<n;j++)
        {
            scanf("%d", &mat2[i][j]);
        }
    }

    int **matSoma = matrizSoma(mat1,mat2,m,n);
    int **matMult = matrizMultiplica(mat1,mat2,m,n);
    int **matDiag = matrizSomaDiagonais(mat1,mat2,m,n,&somaDiagonal);

    printf("Soma das matrizes: \n");
    for (i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ", matSoma[i][j]);
        }
        printf("\n");
    }

    printf("Soma das Diagonais das matrizes: %d \n", somaDiagonal);
    for (i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ", matDiag[i][j]);
        }
        printf("\n");
    }

    printf("Multiplicacao das matrizes: \n");
    for (i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ", matMult[i][j]);
        }
        printf("\n");
    }

    free(mat1);
    free(mat2);
}
