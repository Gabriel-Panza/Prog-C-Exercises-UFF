#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void **createTransposed(int **matrix, int **matrixTrans, int lines, int col)
{
    int i,j;
    if(lines==col)
    {
        for (i=0;i<lines;i++)
        {
            for (j=0;j<col;j++)
            {
                matrixTrans[j][i]=matrix[i][j];
            }
        }
    }

    else
        printf("The matrix is not quadratic, so it is not symmetrical");
}
bool **verifySym(int **matrix, int **matrixTrans, int lines, int col)
{
    int i,j;

    for (i=0;i<lines;i++)
    {
        for (j=0;j<col;j++)
        {
            if (matrixTrans[i][j] == matrix[i][j])
                continue;
            else
                return false;
        }
    }

    return true;
}
void main()
{
    int i,j,m,n;

    printf("Type the number of the lines: ");
    scanf("%d", &m);
    printf("Type the number of the col: ");
    scanf("%d", &n);

    int **mat = (int **) malloc(m*sizeof(int *));
    if (mat==NULL)
    {
        exit(1);
    }
    int **matT = (int **) malloc(m*sizeof(int *));
    if (matT==NULL)
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
        matT[i]= (int *) malloc(n*sizeof(int));
        if (matT[i]==NULL)
        {
            exit(1);
        }
    }
    printf("Fill a matrix %d x %d to be transposed: ", m, n);
    for (i=0;i<m;i++)
    {
        for (j=0;j<n;j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }

    createTranspost(mat,matT,m,n);
    if (matT[0][0]==mat[0][0])
    {
        bool verifica = verifySym(mat,matT,m,n);
        if (verifica == true)
            printf("Both matrix are symmetrical");
        else
            printf("Both matrix are not symmetrical");
    }

    free(mat);
    free(matT);
}
