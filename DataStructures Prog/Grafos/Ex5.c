#include <stdio.h>
#include <stdlib.h>
#include "TG/TG.c"

int ig(TG *g1, TG *g2)
{
    if (!g1 && !g2) return 1;
    while(g1 || g2){
        if (!g1 || !g2) return 0;
        if (g1->id_no == g2->id_no) {
            TVIZ *v1 = g1->prim_viz, *v2 = g2->prim_viz;
            while (v1 || v2){
                if (v1->id_viz != v2->id_viz) return 0;
                v1 = v1->prox_viz;
                v2 = v2->prox_viz;
            }
            g1 = g1->prox_no;
            g2 = g2->prox_no;
        }
        else return 0;
    }
    return 1;
}

int main()
{
    TG *g1 = TG_inicializa(), *g2 = TG_inicializa();
    for (int i=0;i<10;i++)
    {
        g1 = TG_ins_no(g1,i);
        if (i>0)
            TG_ins_aresta(g1,i-1,i);    
    }
    for (int i=0;i<10;i++)
    {
        g2 = TG_ins_no(g2,i);
        if (i>0)
            TG_ins_aresta(g2,i-1,i);    
    }

    int iguais = ig(g1,g2);
    if (iguais) printf("The graphs are the same!");
    else printf("The graphs are not the same!");

    TG_libera(g1);
    TG_libera(g2);
    return 0;
}