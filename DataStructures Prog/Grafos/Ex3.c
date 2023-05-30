#include <stdio.h>
#include <stdlib.h>
#include "TG/TG.c"

int nao_tem_mesma_cor(TG *g){
    if (!g) return 1;
    TG *p = g;
    while (p){
        TVIZ *v = p->prim_viz;
        while (v){
            TG *aux = TG_busca_no(g,v->id_viz);
            if(p->cor == aux->cor) return 0;
            v=v->prox_viz;
        }
        p = p->prox_no;
    }
    return 1;
}

int main(){
    TG *g = TG_inicializa();
    g=TG_ins_no(g,8, 35);
    g=TG_ins_no(g,7, 23);
    g=TG_ins_no(g,6, 20);
    g=TG_ins_no(g,5, 20);
    g=TG_ins_no(g,4, 20);
    g=TG_ins_no(g,3, 19);
    g=TG_ins_no(g,2, 30);
    g=TG_ins_no(g,1, 3);
    g=TG_ins_no(g,0, 25);
    TG_ins_um_sentido(g,0,1);
    TG_ins_um_sentido(g,0,5);
    TG_ins_um_sentido(g,0,6);
    TG_ins_um_sentido(g,1,0);
    TG_ins_um_sentido(g,1,2);
    TG_ins_um_sentido(g,2,3);
    TG_ins_um_sentido(g,2,6);
    TG_ins_um_sentido(g,2,7);
    TG_ins_um_sentido(g,3,4);
    TG_ins_um_sentido(g,3,8);
    TG_ins_um_sentido(g,4,3);
    TG_ins_um_sentido(g,4,8);
    TG_ins_um_sentido(g,6,5);
    TG_ins_um_sentido(g,6,2);
    TG_ins_um_sentido(g,6,3);
    TG_ins_um_sentido(g,6,7);
    TG_ins_um_sentido(g,7,8);

    int sameColor = nao_tem_mesma_cor(g);
    if (sameColor) printf("Not the same color nodes!");
    else printf("Same color nodes!");

    TG_libera(g);
    return 0;
}