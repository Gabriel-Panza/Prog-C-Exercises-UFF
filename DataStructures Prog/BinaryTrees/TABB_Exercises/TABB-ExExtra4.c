#include <stdlib.h>
#include <string.h>
#include "TABB/TABB.c"

int mi_aux(TABB *a1, TABB *a2){
    if (!a1 && !a2) return 1;
    if(!a1) return 1;
    if(!a2) return 0;
    if (!TABB_busca(a2,a1->info)) return 0;
    return (mi_aux(a1->esq,a2) && mi_aux(a1->dir,a2));
}
int mi(TABB *a1, TABB *a2){
    if (!a1 && !a2) return 1;
    if(!a1 || !a2) return 0; 
    return (mi_aux(a1,a2) && mi_aux(a2,a1));
}

int main(void)
{
    TABB *a1 = TABB_cria(5, NULL, NULL);
    a1 = TABB_insere(a1, 1);
    a1 = TABB_insere(a1, 4);
    a1 = TABB_insere(a1, 2);
    a1 = TABB_insere(a1, 3);
    a1 = TABB_insere(a1, 9);
    a1 = TABB_insere(a1, 6);
    a1 = TABB_insere(a1, 8);
    a1 = TABB_insere(a1, 7);
    TABB_imp_ident(a1);
    TABB *a2 = TABB_cria(5, NULL, NULL);
    a2 = TABB_insere(a2, 1);
    a2 = TABB_insere(a2, 2);
    a2 = TABB_insere(a2, 4);
    a2 = TABB_insere(a2, 3);
    a2 = TABB_insere(a2, 9);
    a2 = TABB_insere(a2, 8);
    a2 = TABB_insere(a2, 6);
    a2 = TABB_insere(a2, 7);
    TABB_imp_ident(a2);

    int mesma_info = mi(a1,a2);
    if(mesma_info == 1) printf("As Arvores tem as mesmas informacoes");
    else printf("As Arvores nao tem as mesmas informacoes");

    TABB_libera(a1);
    TABB_libera(a2);

    return 0;
}