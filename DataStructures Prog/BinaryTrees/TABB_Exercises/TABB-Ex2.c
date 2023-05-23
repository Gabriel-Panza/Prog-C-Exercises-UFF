#include <stdlib.h>
#include <string.h>
#include "TABB/TABB.c"

TABB* menor(TABB *a){
    if (!a) return a;
    if(!a->esq) return a;
    return menor(a->esq);
}

int main(void)
{
    TABB *a = TABB_cria(5, NULL, NULL);
    a = TABB_insere(a, 1);
    a = TABB_insere(a, 2);
    a = TABB_insere(a, 3);
    a = TABB_insere(a, 4);
    a = TABB_insere(a, 6);
    a = TABB_insere(a, 7);
    a = TABB_insere(a, 8);
    a = TABB_insere(a, 9);

    TABB *menorNode = menor(a);
    TABB_imp_ident(menorNode);

    TABB_libera(a);
    TABB_libera(menorNode);
    
    return 0;
}