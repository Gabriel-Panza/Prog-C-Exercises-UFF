#include<stdio.h>

void main()
{
    int n, cont=2;
    do
    {
        printf("\nDigite quantos numeros primos deseja ver: ");
        scanf("%d", &n);
        if (n<=0)
            break;
        
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
        cont=2;
    } while (1);
}