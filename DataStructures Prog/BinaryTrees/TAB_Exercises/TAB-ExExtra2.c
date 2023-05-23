#include <stdio.h>
#include "TAB/TAB.c"
#include "TLSE/TLSE.c"
#include <limits.h>

void percorrePred(TAB*a, int elem, int *resp){
    if (!a) return;
    if((a->info < elem) && (a->info>(*resp))) (*resp) = a->info;
    percorrePred(a->esq, elem, resp);
    percorrePred(a->dir, elem, resp);
}
int pred(TAB*a, int elem){
    int resp = INT_MIN;
    percorrePred(a,elem,&resp);
    return resp;
}
void percorreSuc(TAB*a, int elem, int *resp){
    if (!a) return;
    if((a->info > elem) && (a->info<(*resp))) (*resp) = a->info;
    percorreSuc(a->esq, elem, resp);
    percorreSuc(a->dir, elem, resp);
}
int suc(TAB*a, int elem){
    int resp = INT_MAX;
    percorreSuc(a,elem,&resp);
    return resp;
}

TLSEINT* ancestrais_aux(TAB *arv, TAB *a, int elem){
    if (!a || a->info == elem || !TAB_busca(a,elem)) return NULL;
    if (TAB_busca(a->esq, elem)) return TLSEINT_insere(ancestrais_aux(arv, a->esq, elem), pred(arv, a->info),suc(arv, a->info));
    return TLSEINT_insere(ancestrais_aux(arv, a->dir, elem), pred(arv, a->info),suc(arv, a->info));
}

TLSEINT* ancestrais(TAB *a, int elem){
    return ancestrais_aux(a, a, elem);
}

int main()
{
    TAB *a;
    a = TAB_cria(3,TAB_cria(5,TAB_cria(1,NULL,NULL),TAB_cria(2,TAB_cria(4,NULL,NULL),TAB_cria(6,NULL,NULL))),TAB_cria(8,TAB_cria(7,NULL,NULL),TAB_cria(9,NULL,NULL)));
    TAB_imp_ident(a);
    printf("\n\n");
    
    TLSEINT *listaAnc = ancestrais(a,4);
    if (listaAnc) TLSE_print(listaAnc);
    TAB_libera(a);
    TLSE_freeAll(listaAnc);

    return 0;
}