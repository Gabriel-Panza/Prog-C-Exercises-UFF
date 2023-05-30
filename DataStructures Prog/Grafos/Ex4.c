#include <stdio.h>
#include <stdlib.h>
#include "TG/TG.c"

int contaViz(TG* g){
    TVIZ* v = g->prim_viz;
    int cont = 0;
    while(v){
        cont++;
        v = v->prox_viz;
    }
    return cont;
}

int testek(TG *g, int k){
    if (!g) return 1;
    if (contaViz(g) != k) return 0;
    return testek(g->prox_no,k);
}

int main(){
    TG *g = TG_inicializa();
    for (int i=0;i<10;i++)
    {
        g=TG_ins_no(g,i,i);
        if (i>0)
            TG_ins_um_sentido(g,i-1,i);    
    }

    int teste = testek(g, 2);
    if(teste) printf("All nodes have the same degree!");
    else printf("All nodes dont have the same degree!");
    
    TG_libera(g);
    return 0;
}