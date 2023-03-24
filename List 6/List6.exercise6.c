#include <stdio.h>
#include <stdlib.h>

void main()
{
    int i, j, n;
    int *v;
    int *vf;

    printf("Type the size of the vector: ");
    scanf("%d", &n);
    v = (int *) malloc(n*sizeof(int));
    if (v==NULL)
    {
        exit(1);
    }

    vf = (int *) malloc(n*sizeof(int));
    if (vf==NULL)
    {
        exit(1);
    }

    printf("Fill the vector:");
    for (i=0;i<n;i++)
    {
        vf[i] = NULL;
        scanf("%d", &v[i]);
        while (v[i]>9 || (v[i]<0))
        {
            printf("Error! Type a number between 0 and 9");
            scanf("%d", &v[i]);
        }
    }
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            if ((v[i]==v[j]) && (i!=j))
            {
                vf[i] = v[j];
            }
        }
    }
    printf("The final vector is: ");
    for (i=0;i<n;i++)
    {
        for (j=1;j<n;j++)
        {
            if ((vf[i]==vf[j]) && (i!=j))
                vf[j]=NULL;
        }
        if (vf[i] != NULL)
            printf("%d ", vf[i]);
    }
    free(v);
    free(vf);
}