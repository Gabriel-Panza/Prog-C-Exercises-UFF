#include <stdio.h>
#include "TAVL/TAVL.h"

void main()
{
    int v1[35] = {61, 34, 78, 19, 47, 64, 87, 15, 29, 42, 53, 76, 84, 13, 17, 32, 1, 65, 12, 18, 66, 38, 95, 58, 59, 70, 68, 39, 62, 60, 43, 16, 67, 36, 35};
    int v2[19] = {35, 34, 67, 16, 42, 60, 62, 39, 68, 70, 59, 58, 95, 38, 66, 18, 12, 64, 1};
    TAVL *a = NULL;
    for (int i=0;i<35;i++)
    {
        a = TAVL_insere(v1[i],a);
    }
    for (int i=0;i<19;i++)
    {
        a = TAVL_retira(v2[i],a);
    }
}