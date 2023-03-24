#include <stdio.h>
void **matrix(int **matrix1, int **matrix2, int line, int col)
{
    int i,j;
    int matrix3[line][col];

    for (i=0;i<line;i++)
    {
        for (j=0;j<col;j++)
        {
            matrix3[i][j]=matrix1[i][j] + matrix2[i][j];
        }
    }
    for (i=0;i<line;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("%d ", matrix3[i][j]);
        }
        printf("\n");
    }
    free(matrix3);
}
void main()
{
    int i,j,m,n;

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

    matrix(mat1,mat2,m,n);
    free(mat1);
    free(mat2);
}
