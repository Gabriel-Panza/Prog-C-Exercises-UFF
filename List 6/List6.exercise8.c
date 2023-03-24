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

int *repetition(int *vect, int size, int *n)
{
    int i, j, cont=0;
    int *vf = (int *) malloc(size*sizeof(int));
    if (vf==NULL)
    {
        exit(1);
    }

    for (i=0;i<size;i++)
    {
        for (j=(i+1);j<size;j++)
        {
            if ((vect[i]==vect[j]) && (!in(vf,cont,vect[j])))
            {
                    vf[cont] = vect[j];
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
        while ((v[i]>9) || (v[i]<0))
        {
            printf("Error! Type a number between 0 and 9");
            scanf("%d", &v[i]);
        }
    }

    int *vetFinal = repetition(v,n,&nFinal);

    printf("The final vector is: ");
    for (i=0;i<nFinal;i++)
    {
        printf("%d ", vetFinal[i]);
    }

    free(v);
    free(vetFinal);
}
