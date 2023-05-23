#include <stdio.h>
#include <stdlib.h>
#include "TG/TG.c"

int nao_tem_mesma_cor(TG *g){
    if (!g) return 1;
    int cor = g->cor;
    TVIZ *v = g->prim_viz;
    while (v){
        if (v->cor == cor) return 0;
        v = v->prox_viz;
    }
    return nao_tem_mesma_cor(g->prox_no);
}

int main(){
    TG *g = TG_inicializa();
    for (int i=0;i<10;i++)
    {
        g=TG_ins_no(g,i);
        if (i>0)
            TG_ins_um_sentido(g,i-1,i);    
    }

    int sameColor = nao_tem_mesma_cor(g);
    if (sameColor) printf("Not the same color nodes!");
    else printf("Same color nodes!");

    TG_libera(g);
    return 0;
}