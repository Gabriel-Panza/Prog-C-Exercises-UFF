#include <stdio.h>
#include <stdlib.h>
#include "TG/TG.c"

void percorre(TG *g, int *cont){
    TG *aux_g = g;
    TVIZ *v;
    while (aux_g){
        v = aux_g->prim_viz;
        while (v){
            if (v->id_viz == g->id_no)
                *cont+=1;
            v = v->prox_viz;
        }
        aux_g = aux_g->prox_no;
    }
}

TG *mais_popular(TG *g){
    if (!g) return g;
    int maior=0, cont;
    TG *popular = NULL;
    while (g){
        cont = 0;
        percorre(g, &cont);
        if (maior < cont){
            popular = g;
            maior = cont;
        }
        g = g->prox_no;
    }
    return popular;
}

int main(){
    TG *g = TG_inicializa();
    g=TG_ins_no(g,8, "Renata", 35);
    g=TG_ins_no(g,7, "Bruna", 23);
    g=TG_ins_no(g,6, "Pedro", 20);
    g=TG_ins_no(g,5, "Caio", 20);
    g=TG_ins_no(g,4, "Felipe", 20);
    g=TG_ins_no(g,3, "Marcos", 19);
    g=TG_ins_no(g,2, "Jane", 30);
    g=TG_ins_no(g,1, "Ana", 23);
    g=TG_ins_no(g,0, "Joao", 25);
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

    TG *popular = mais_popular(g);
    if (popular) printf("The most popular person is %s", popular->nome);
    else printf("No one is popular!");


    TG_libera(g);
    return 0;
}