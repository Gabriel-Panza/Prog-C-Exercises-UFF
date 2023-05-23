#include <stdio.h>
#include <stdlib.h>

int run(int *v, int size)
{
    int i=0, j=size;

    while (i<j)
    {
        printf("%d",i);
        i++;
        printf("%d",j);
        j--;
    }

    return i;
}

void main()
{
    int size = rand();
    int vetor[size];
    int middle;

    if (size%2 != 0)
        size+=1;

    middle = run(vetor,size);
    printf("\n%d", size);
    if (size % 2 == 0)
        printf("\nThe middle position is between: %d and %d", middle,middle+1);
    else
        printf("\nThe middle position is: %d", middle);
}
