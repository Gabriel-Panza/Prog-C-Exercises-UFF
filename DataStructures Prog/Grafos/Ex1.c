#include <stdio.h>
#include <stdlib.h>
#include "TG/TG.c"

int nn(TG *g)
{
    if (!g)
        return 0;
    return 1 + nn(g->prox_no);
}

int main()
{
    TG *g = TG_inicializa();
    for (int i=0;i<10;i++)
    {
        g = TG_ins_no(g,i,i);
    }
    
    int qntd = nn(g);
    printf("Quantity of nodes: %d", qntd);

    TG_libera(g);
    return 0;
}