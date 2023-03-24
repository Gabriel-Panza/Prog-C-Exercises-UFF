#include <stdio.h>
int **matrixAdditive(int **matrix1, int **matrix2, int lines, int col)
{
    int i,j;
    int **matrixS = (int **) malloc(lines*sizeof(int *));
    if (matrixS==NULL)
    {
        exit(1);
    }
    for (i=0;i<lines;i++)
    {
        matrixS[i]= (int *) malloc(col*sizeof(int));
        if (matrixS[i]==NULL)
        {
            exit(1);
        }
    }

    for (i=0;i<lines;i++)
    {
        for(j=0;j<col;j++)
        {
            matrixS[i][j]=matrix1[i][j]+matrix2[i][j];
        }
    }
    return matrixS;
}
int **matrixMultiply(int **matrix1, int **matrix2, int lines, int col)
{
    int i,j;
    int **matrizX = (int **) malloc(lines*sizeof(int *));
    if (matrizX==NULL)
    {
        exit(1);
    }
    for (i=0;i<lines;i++)
    {
        matrizX[i]= (int *) malloc(col*sizeof(int));
        if (matrizX[i]==NULL)
        {
            exit(1);
        }
    }

    for (i=0;i<lines;i++)
    {
        for(j=0;j<col;j++)
        {
            matrizX[i][j]=matrix1[i][j]*matrix2[i][j];
        }
    }
    return matrizX;
}
int **matrizSomaDiagonais(int **matrix1, int **matrix2, int lines, int col, int *somaDiag)
{
    int i,j,somaD=0;
    int **matrixD = (int **) malloc(lines*sizeof(int *));
    if (matrixD==NULL)
    {
        exit(1);
    }
    for (i=0;i<lines;i++)
    {
        matrixD[i]= (int *) malloc(col*sizeof(int));
        if (matrixD[i]==NULL)
        {
            exit(1);
        }
    }

    for (i=0;i<lines;i++)
    {
        for(j=0;j<col;j++)
        {
            matrixD[i][j]=NULL;
            if (i==j)
            {
                matrixD[i][j]=matrix1[i][j]+matrix2[i][j];
                somaD+=matrixD[i][j];
            }
        }
    }

    *somaDiag=somaD;
    return matrixD;
}
void main()
{
    int i,j,m,n,addDiagonal=0;

    printf("Type the number of lines: ");
    scanf("%d", &m);
    printf("Type the number of col: ");
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
    printf("Fill matrix1 %d x %d: ", m, n);
    for (i=0;i<m;i++)
    {
        for (j=0;j<n;j++)
        {
            scanf("%d", &mat1[i][j]);
        }
    }
    printf("Fill matrix2 %d x %d: ", m, n);
    for (i=0;i<m;i++)
    {
        for (j=0;j<n;j++)
        {
            scanf("%d", &mat2[i][j]);
        }
    }

    int **matSoma = matrixAdditive(mat1,mat2,m,n);
    int **matMult = matrixMultiply(mat1,mat2,m,n);
    int **matDiag = matrizSomaDiagonais(mat1,mat2,m,n,&addDiagonal);

    printf("Matrix added: \n");
    for (i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ", matSoma[i][j]);
        }
        printf("\n");
    }

    printf("Matrix diagonal added: %d \n", addDiagonal);
    for (i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ", matDiag[i][j]);
        }
        printf("\n");
    }

    printf("Matrix multiplied: \n");
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
