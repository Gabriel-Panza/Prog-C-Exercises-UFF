#include <stdio.h>

void main()
{
    int i,j;
    int distancias[5][5]={{00,15,30,05,12},{15,00,10,17,28},{30,10,00,03,11},{05,17,03,00,80},{12,28,11,80,00}};

    for (i=0;i<5;i++)
    {
        for (j=(i+1);j<5;j++)
        {
            printf("A distancia entre as cidades %d e %d eh: ", i+1,j+1);
            printf("%d km\n", distancias[i][j]);
        }
    }
}
