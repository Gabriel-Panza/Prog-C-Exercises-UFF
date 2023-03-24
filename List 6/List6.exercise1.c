#include <stdio.h>

float *above_average(int n, float *vect, int *size)
{
    int i,add=0,cont=0,contVect=0;
    float *tempVect;
    float average;

    for (i=0;i<n;i++)
    {
        add += vect[i];
    }
    average = add/n;

    for (i=0;i<n;i++)
    {
        if(vect[i]>average)
        {
            cont++;
        }
    }

    *size=cont;
    tempVect = (float *)malloc((*size)*sizeof(float));
    if (tempVect==NULL)
        exit(1);

    for (i=0;i<n;i++)
    {
        if(vect[i]>average)
        {
            tempVect[contVect] = vect[i];
            contVect++;
        }
    }
    return tempVect;
}

void main()
{
    int i, n;
    float *v;
    int pInt;

    printf("Type the size of the vector: ");
    scanf("%d", &n);

    v = (float *) malloc(n*sizeof(float));
    if (v==NULL)
        exit(1);

    for (i=0;i<n;i++)
    {
        printf("Type the value of index %d from the vector: ", i);
        scanf("%f", &v[i]);
    }

    float *aboveAverage = above_average(n,v,&pInt);

    printf("The final vector is: ");
    for (i=0;i<pInt;i++)
        printf("%d ", aboveAverage[i]);

    free(v);
    free(aboveAverage);
}