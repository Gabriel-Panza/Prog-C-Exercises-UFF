#include <stdio.h>

void changingVectorValues (int *v, int n, int *vf)
{
    int i, add=0;

    for (i=0;i<n;i++)
    {
        add += v[i];
        vf[i] = add;
    }
}

int searchingValue (int *v, int n)
{
    int i, value;

    printf("\nWhat value do you want search? ");
    scanf("%d", &value);

    for (i=0;i<n;i++)
        if (v[i] == value)
            return i;
    return -1;
}

void main()
{
    int i, size = 7;
    int v[size];
    int vf[size];

    for (i=0;i<size;i++)
    {
        printf("\nType a value in the position %d of the vector: ", i);
        scanf("%d", &v[i]);
    }

    for (i=0;i<size;i++)
    {
        printf("\nPosition %d of the vector = %d", i,v[i]);
    }

    int foundPos = searchingValue(v,size);
    printf("\n%d\n", foundPos);

    changingVectorValues(v,size,vf);
    for (i=0;i<size;i++)
        printf("%d ", vf[i]);
}
