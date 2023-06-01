#include <stdio.h>
#include "TAB/TAB.c"

TAB *retira_x(TAB *arv, int x){
  if(!arv)
    return arv;
  arv->esq = retira_x(arv->esq,x);
  arv->dir = retira_x(arv->dir,x);
  if(arv->info == x){
    if(!arv->esq && !arv->dir){ /*caso 1: o nó é uma folha*/
      TAB_libera(arv);     
      arv = TAB_inicializa();
    } else if (!arv->esq || !arv->dir){ /*caso 2: o nó so tem 1 filho*/
      TAB *aux = arv;
      if(!arv->esq) arv = arv->dir;
      else arv = arv->esq;
      TAB_libera(aux);
    } else if (arv->esq && arv->dir){ /*caso 3: o nó tem 2 filhos*/
      TAB *aux = arv->esq;
      while(aux->dir)
        aux = aux->dir;
      int temp = arv->info;
      arv->info = aux->info;
      aux->info = temp;
      arv = retira_x(arv, x);
    }
  }
  return arv;
}

int main()
{
    TAB *a, *semX;

    int x1 = 10, x2=4, x3=16, x4=5, x5=15, x6=5, x7=5;
    a = TAB_cria(x1,TAB_cria(x2,NULL,TAB_cria(x4,NULL,TAB_cria(x6,NULL,NULL))),TAB_cria(x3,TAB_cria(x5,NULL,NULL),TAB_cria(x7,NULL,NULL)));
    TAB_imp_ident(a);

    printf("\n\n\n");

    semX = retira_x(a, 5);
    TAB_imp_ident(semX);

    TAB_libera(a);
    TAB_libera(semX);

    return 0;
}