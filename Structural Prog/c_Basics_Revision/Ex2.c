#include<stdio.h>

void main()
{
    int n, cont;
    do
    {
        printf("\nType how many prime numbers do you want to see, after the given number: ");
        scanf("%d", &n);
        if (n<=0)
            break;
        
        cont=n+1;
        while (n>0)
        {
            if ((cont%2!=0) && (cont%3!=0) && (cont%5!=0) && (cont%7!=0))
            {
                printf("%d, ",cont);
                cont++;
                n--;
            }
            else if (cont==2 || cont==3 || cont==5 || cont==7)
            {
                printf("%d, ",cont);
                cont++;
                n--;
            }
            else
                cont++;
        }
    } while (1);
}