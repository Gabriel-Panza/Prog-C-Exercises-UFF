#include <stdio.h>
#include "TAVL/TAVL.h"

void main()
{
    int v1[20] = {1, 64, 12, 18, 66, 38, 95, 58, 59, 70, 68, 39, 62, 7, 60, 43, 16, 67, 34, 35};
    int v2[5] = {50, 95, 70, 60, 35};
    TAVL *a = NULL;
    a = TAVL_insere(50,a);
    for (int i=0;i<20;i++)
    {
        a = TAVL_insere(v1[i],a);
    }
    for (int i=0;i<5;i++)
    {
        a = TAVL_retira(v2[i],a);
    }
}