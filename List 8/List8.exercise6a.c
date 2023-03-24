#include <stdio.h>

void main()
{
    int c1,c2;
    int distances[5][5]={{00,15,30,05,12},{15,00,10,17,28},{30,10,00,03,11},{05,17,03,00,80},{12,28,11,80,00}};

    printf("Type from and what city do you want to go: \n");
    printf("(Your options are: 1,2,3,4,5) \n");

    do
    {
        printf("City 1: \n");
        scanf("%d", &c1);
        printf("City 2: \n");
        scanf("%d", &c2);

        if (((1<=c1) && (c1<=5)) && ((1<=c2)&&(c2<=5)))
        {
            printf("The distance is %d km\n", distances[c1-1][c2-1]);
            continue;
        }
        else if ((c1<0 && c1>5) && (c2<0 && c2>5))
        {
            printf("Error! Cities not found!\n");
            continue;
        }
    }while (c1!=0 && c2!=0);
}
