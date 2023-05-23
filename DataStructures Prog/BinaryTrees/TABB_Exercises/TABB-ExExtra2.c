#include <stdlib.h>
#include <string.h>
#include "TABB/TABB.c"

int est_bin(TABB *a){
    if (!a) return 0;
    if(!a->esq && !a->dir) return 1;
    if(!a->esq || !a->dir) return 0;
    return (est_bin(a->esq) && est_bin(a->dir));
}

int main(void)
{
    TABB *a = TABB_cria(5, NULL, NULL);
    a = TABB_insere(a, 2);
    a = TABB_insere(a, 1);
    a = TABB_insere(a, 3);
    a = TABB_insere(a, 7);
    a = TABB_insere(a, 6);
    a = TABB_insere(a, 8);
    TABB_imp_ident(a);

    int est_binario = est_bin(a);
    if(est_binario == 1)
        printf("A Arvore eh estritamente binaria");
    else
        printf("A Arvore nao eh estritamente binaria");

    TABB_libera(a);

    return 0;
}