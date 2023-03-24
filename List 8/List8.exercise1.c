#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool matrix(int **matrix, int line, int col)
{
    int i,j,add=0;
    int v[line];

    for (i=0;i<line;i++)
    {
        for (j=0;j<col;j++)
        {
            add += matrix[i][j];
        }
        v[i]=add;
        add=0;
    }
    for (i=0;i<(line-1);i++)
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

    printf("Type the number of lines: ");
    scanf("%d", &m);
    printf("Type the number of col: ");
    scanf("%d", &n);

    printf("Fill the matrix %d x %d: ", m,n);
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
    bool add = matrix(mat,m,n);
    if (add == true)
        printf("True! The addition of all lines are the same.");
    else
        printf("False! The addition of all lines are different.");

    free(mat);
}
