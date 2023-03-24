#include <stdio.h>
#include <stdlib.h>

int fill(int *vet, int n)
{
    int i;
    for (i=1;i<=n;i++)
        vet[i-1]=5*i;
}
void print (int *vet, int n)
{
    int i;
    for (i=0;i<n;i++)
        printf("%d ", vet[i]);
}
void main()
{
    int size = 10;
    int *v = (int *) malloc (size*sizeof(int));
    if (v==NULL)
    {
        exit(1);
    }
    fill(v,size);
    print(v,size);
}
