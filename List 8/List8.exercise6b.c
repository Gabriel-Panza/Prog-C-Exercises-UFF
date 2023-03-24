#include <stdio.h>
#include <stdlib.h>

void main()
{
    int i,nCities,cont=0,add=0,route,oldRoute;
    int distancias[5][5]={{00,15,30,05,12},{15,00,10,17,28},{30,10,00,03,11},{05,17,03,00,80},{12,28,11,80,00}};

    printf("Type how many cities do you want to go: ");
    scanf("%d", &nCities);
    printf("Type from and what city do you want to go: \n");
    printf("(Your options are: 1,2,3,4,5) \n");

    while (nCities>cont)
    {
        scanf("%d", &route);
        if (cont>0)
        {
            add+=distancias[oldRoute-1][route-1];
        }
        oldRoute=route;
        cont++;
        if ((1<=route) && (route<=5))
        {
            continue;
        }
        else
        {
            break;
        }
    }

    if ((1<=route) && (route<=5))
        printf("The route distance is: %d", add);
    else
        printf("Error! Route not found!\n");


}
