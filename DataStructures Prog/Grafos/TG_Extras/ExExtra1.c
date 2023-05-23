#include <stdio.h>
#include <stdlib.h>
#include "TG/TG.c"

int completo(TG *g){
    if(!g) return 0;
    TG *aux;
    while (g)
    {
        aux = g;
        while (aux){
            if (!TG_busca_aresta(g, g->id_no, aux->id_no))
                return 0;
            aux = aux->prox_no;
        }
        g = g->prox_no;
    }
    return 1;
}

int main(){
    TG *g = TG_inicializa();
    for (int i=0;i<10;i++){
        g=TG_ins_no(g,i,NULL,0);
    }
    for (int i=0;i<10;i++){
        for (int j=i;j<10;j++){
            TG_ins_aresta(g,i,j);
        }
    }
    int teste = completo(g);
    if(teste) printf("The graph is complete!");
    else printf("The graph is not complete!");
    
    TG_libera(g);
    return 0;
}