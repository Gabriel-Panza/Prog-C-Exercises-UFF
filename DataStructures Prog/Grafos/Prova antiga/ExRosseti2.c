#include "TG/TG.h"
#include "TLSE/TLSE.h"

TLSE *checa_caminho(TG* backup, TLSE *l, TLSE *visitados, int origem, int destino){
    if(!backup) return l;
    if (origem == destino) return TLSE_insere(l, origem);

    TG *tmp = TG_busca_no(backup, origem);
    TVIZ *viz = tmp->prim_viz;
    while(viz){
        if (!TLSE_busca(visitados, viz->id_viz)){
            visitados = TLSE_insere(visitados, origem)
            l = checa_caminho(backup, l, visitados, viz->id_viz, destino);
            if (l) return TLSE_insere(l, origem);
        }
        viz = viz->prox_viz;
    }
    return NULL;
}

TLSE *caminho(TG *grafo, int x, int y){
    if(!TG_busca_no(grafo, x) || !TG_busca_no(grafo, y)) return NULL;
    TLSE *l = NULL, *visitados = NULL;
    l = checa_caminho(grafo, l, visitados, x, y);
    //TLSE_imprime(visitados);
    return l;
}

int main(){
    TG *g = TG_inicializa();
    TLSE *l = NULL;
    int tam, entrada, elem, no, a, b;

    printf("digite o numero de nos que deseja inserir no grafo: \n");
    scanf("%d", &tam);
    for(int i = 0; i < tam; i++){
        printf("digite o numero do no: \n");
        scanf("%d", &entrada);
        g = TG_ins_no(g, entrada);
    }

    elem = -1;
    while(elem != 0){
        printf("oii \n");
        printf("digite o no em que ira inserir a aresta: \n");
        scanf("%d", &no);
        printf("digite o valor da aresta: \n");
        scanf("%d", &entrada);
        TG_ins_aresta(g, no, entrada, 0);
        printf("deseja continuar? digite 1 para sim e 0 para nao... \n");
        scanf("%d", &elem);
    }

    printf("digite 2 valores a e b para checar se existe caminho entre eles: \n");
    scanf("%d %d", &a, &b);
    l = caminho(g, a, b);
    if (l) {
        printf("Caminho: ");
        TLSE_imprime(l);
        printf("\n");
    }
    else printf("Não há caminho!\n");

    TG_libera(g);
    TLSE_libera(l);
    return 0;
}
