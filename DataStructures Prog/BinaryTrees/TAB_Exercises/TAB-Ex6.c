#include <stdio.h>
#include <stdlib.h>
#include "TAB/TAB.c"

TAB *retira_pares(TAB *arv){
  if(!arv)
    return arv;
  arv->esq = retira_pares(arv->esq);
  arv->dir = retira_pares(arv->dir);
  if(arv->info % 2 == 0){
    if(!arv->esq && !arv->dir){ /*caso 1: o nó é uma folha*/
      free(arv);     
      arv = NULL;
    } else if (!arv->esq || !arv->dir){ /*caso 2: o nó so tem 1 filho*/
      TAB *aux = arv;
      if(!arv->esq) arv = arv->dir;
      else arv = arv->esq;
      free(aux);
    } else if (arv->esq && arv->dir){ /*caso 3: o nó tem 2 filhos*/
      TAB *aux = arv->esq;
      while(aux->dir)
        aux = aux->dir;
      int temp = arv->info;
      arv->info = aux->info;
      aux->info = temp;
      arv = retira_pares(arv);
    }
  }
  return arv;
}

int main()
{
    TAB *a, *semPar;

    int x1 = 10, x2=4, x3=16, x4=5, x5=15;
    a = TAB_cria(x1,TAB_cria(x2,NULL,TAB_cria(x4,NULL,NULL)),TAB_cria(x3,TAB_cria(x5,NULL,NULL),NULL));
    TAB_imp_ident(a);

    printf("\n\n\n");

    semPar = retira_pares(a);
    TAB_imp_ident(semPar);

    TAB_libera(a);
    TAB_libera(semPar);

    return 0;
}