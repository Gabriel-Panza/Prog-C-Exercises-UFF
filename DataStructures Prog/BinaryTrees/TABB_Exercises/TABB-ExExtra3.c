#include <stdlib.h>
#include <string.h>
#include "TABB/TABB.c"
#include "TLSE/TLSE.c"

TLSE* ancestrais_aux(TABB *a, int elem, TLSE *l){
    if (!a || a->info == elem) return l;
    if (TABB_busca(a->esq,elem)) return pushStart(ancestrais_aux(a->esq,elem,l),a->info);
    return pushStart(ancestrais_aux(a->dir,elem,l),a->info);
}

TLSE* ancestrais(TABB *a, int elem){
    if (!a || a->info == elem) return NULL;
    if (TABB_busca(a->esq,elem)) return pushStart(ancestrais_aux(a->esq,elem, NULL), a->info);
    return pushStart(ancestrais_aux(a->dir,elem, NULL), a->info);
}

int main(){
    TABB *a = TABB_cria(5, NULL, NULL);
    a = TABB_insere(a, 2);
    a = TABB_insere(a, 1);
    a = TABB_insere(a, 3);
    a = TABB_insere(a, 7);
    a = TABB_insere(a, 6);
    a = TABB_insere(a, 8);
    TABB_imp_ident(a);

    TLSE *lista = ancestrais(a,8);
    if(lista){
        printf("Os ancestrais sao: ");
        TLSE_print(lista);
    }
    else
        printf("Nao possui ancestral.");

    TABB_libera(a);
    freeAll(lista);

    return 0;
}