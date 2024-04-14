#include <stdio.h>
#include "TAB/TAB.c"
#include "TLSE/TLSE.c"

TLSE *insere_ordenado(TLSE *L, int elem) {
    if (!L || elem < L->info) L = insertStart(L, elem);
    if (elem > L->info) L->next = insere_ordenado(L->next, elem);
    return L;
}

TLSE *insere_arvore_na_lista(TAB *a, TLSE *L) {
    if (a == NULL) return L;
    L = insere_arvore_na_lista(a->esq, L);
    L = insere_ordenado(L, a->info);
    L = insere_arvore_na_lista(a->dir, L);
    return L;
}

int main()
{
    TAB *a;
    a = TAB_cria(7,TAB_cria(5,NULL,TAB_cria(8,TAB_cria(2,NULL,NULL),TAB_cria(3,TAB_cria(4,NULL,TAB_cria(6,NULL,NULL)),NULL))),TAB_cria(2,TAB_cria(1,TAB_cria(10,NULL,NULL),TAB_cria(4,NULL,NULL)),TAB_cria(9,TAB_cria(8,NULL,NULL),TAB_cria(0,TAB_cria(3,NULL,NULL), NULL))));
    TAB_imp_ident(a);
    printf("\n\n");
    
    TLSE* l = initialize();
    l = insere_arvore_na_lista(a, l);
    TLSE_print(l);
    TAB_libera(a);
    freeAll(l);
    
    return 0;
}