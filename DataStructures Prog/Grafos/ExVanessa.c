#include <stdio.h>
#include <stdlib.h>
#include "TG.h"

TG* TG_busca_no(TG* g, int x){
  if((!g) || (g->id_no == x)) return g;
  return TG_busca_no(g->prox_no, x);
}

TVIZ* TG_busca_aresta(TG *g, int no1, int no2){
  TG *p1 = TG_busca_no(g,no1);
  TG *p2 = TG_busca_no(g,no2);
  if((!p1) || (!p2)) return NULL;
  TVIZ *resp = p1->prim_viz;
  while((resp) && (resp->id_viz != no2)) 
    resp = resp->prox_viz;
  return resp;
}

int TG_verifica_arestas_iguais(TG *g) {
  TG *noA = g;
  
  while (noA) {
    TVIZ *vizA = noA->prim_viz;
    while (vizA) {
      int noB_id = vizA->id_viz;
      int pesoAB = vizA->peso_aresta;
      
      TVIZ *vizB = TG_busca_aresta(g, noB_id, noA->id_no);
      
      if (!vizB || vizB->peso_aresta != pesoAB) {
        return 0; // Se não encontrar a aresta de mesmo peso ou não encontrar nenhuma aresta, retorna falso.
      }
      
      vizA = vizA->prox_viz;
    }
    noA = noA->prox_no;
  }
  
  return 1; // Se todas as arestas de mesmo peso foram encontradas, retorna verdadeiro.
}

int main()
{
    TG *g = TG_inicializa();
    
    /*
    Insere os nós e arestas com pesos aqui
    */

    int resultado = TG_verifica_arestas_iguais(g);
    if (resultado) {
    printf("O grafo possui arestas de mesmo peso entre todos os nós.\n");
    } else {
    printf("O grafo nao possui arestas de mesmo peso entre todos os nós.\n");
    }

    TG_libera(g);
    return 0;
}