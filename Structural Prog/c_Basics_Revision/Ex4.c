#include<stdio.h>

void main()
{
    int F1, F2, cont=1, mmc;
    do
    {
        printf("\nType how many figures Ricardo e Vicente have (separated by blank spaces): ");
        scanf("%d %d", &F1, &F2);
        if (F1<1 || F2<1)
        {
            break;
        }
        while (cont<=F1 || cont<=F2)
        {
            if (F1%cont==0 && F2%cont==0)
            {
                mmc = cont;
                cont++;
            }
            else
            {
                cont++;
            }
        }
        printf("%d", mmc);
        cont=1;
    } while (1);
}