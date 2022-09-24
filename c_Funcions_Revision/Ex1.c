#include<stdio.h>

void primos(int n, int i)
{
    for(i=2;i<=n;i++)
    {
       if ((i%2!=0) && (i%3!=0) && (i%5!=0) && (i%7!=0))
        {
            printf("%d ",i);
        }
        else if (i==2 || i==3 || i==5 || i==7)
        {
            printf("%d ",i);
        }
    }
}

void main()
{
    int n, i;

    printf("\nDigite o numero limite: ");
    scanf("%d", &n);

    primos(n,i);
}