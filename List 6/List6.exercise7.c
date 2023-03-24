#include <stdio.h>
#include <stdlin.h>

void repetition(int *vet, int size)
{
    int i, j;
    int *vf;

    vf = (int *) malloc(size*sizeof(int));
    if (vf==NULL)
    {
        exit(1);
    }

    for (i=0;i<size;i++)
    {
        vf[i] = NULL;
    }

    for (i=0;i<size;i++)
    {
        for (j=0;j<size;j++)
        {
            if ((vet[i]==vet[j]) && (i!=j))
            {
                vf[i] = vet[j];
            }
        }
    }

    printf("The final vector is: ");
    for (i=0;i<size;i++)
    {
        for (j=1;j<size;j++)
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

    printf("Type the size of the vector: ");
    scanf("%d", &n);

    v = (int *) malloc(n*sizeof(int));
    if (v==NULL)
    {
        exit(1);
    }

    printf("Fill the vector:");
    for (i=0;i<n;i++)
    {
        scanf("%d", &v[i]);
        while (v[i]>9 || (v[i]<0))
        {
            printf("Error! Type a number between 0 and 9");
            scanf("%d", &v[i]);
        }
    }

    repetition(v,n);

    free(v);
}
