#include <stdio.h>
#include <string.h>
#include "TAB/TAB.c"
#include "TLSE/TLSE.c"
#include <limits.h>

TLSE* entre_aux(TAB*a,int N, int M){
  TLSE *l = NULL;
  if(!a) return l;
  if (a->esq) l = entre_aux(a->esq,N,M);
  if (a->dir) l = entre_aux(a->dir,N,M);
  if ((a->info<M) && (a->info>N)) return TLSE_insere(l,a->info);
  return l;
}

TLSE* entre(TAB*a,int N, int M){
  TLSE *l = entre_aux(a,N,M);
  TLSE*aux1 = l;
  TLSE*aux2 = l;
  TLSE*resp = NULL;
  while(aux1){
    int maior = INT_MIN;
    aux2 = l;
    while (aux2){
      if (aux2->info>maior) maior = aux2->info;
      aux2 = aux2->prox;
    }
    resp = TLSE_insere(resp,maior);
    l = TLSE_retira(l,maior);
    aux1 = aux1->prox;
  }
  return resp;
}

int main(void){
  int no, pai;
  printf("Digite a raiz da arvore... ");
  scanf("%d", &no);
  TAB *a = TAB_cria(no, NULL, NULL), *resp;
  char repete;
  do{
    char lado[2];
    printf("Quer continuar inserindo nos na árvore (digite N ou n para parar)? ");
    scanf(" %c", &repete);
    if((repete == 'N') || (repete == 'n')) break;
    printf("Digite o pai (que deve existir), o filho a ser inserido e a posição E(ESQ) ou D(DIR)... ");
    scanf("%d%d%s", &pai, &no, lado);
    resp = TAB_busca(a, pai);
    if(!resp){
      TAB_libera(a);
      return 0;
    }
    if(strcmp(lado, "E") == 0) resp->esq = TAB_cria(no, NULL, NULL);
    else resp->dir = TAB_cria(no, NULL, NULL);
  }while(1);
  TAB_imp_ident(a);
  printf("\n");
  
  int n, m;
  printf("Digite n e m... ");
  scanf("%d%d", &n, &m);
  TLSE *l = NULL;
  l = entre(a, n, m);
  TLSE_imprime(l); 
  TLSE_libera(l);
  
  TAB_libera(a);
  return 0;
}