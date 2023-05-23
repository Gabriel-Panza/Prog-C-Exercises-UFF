#include <stdlib.h>
#include <string.h>
#include "TABB/TABB.c"

TABB* maior(TABB *a){
    if (!a) return a;
    if(!a->dir) return a;
    return maior(a->dir);
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

    TABB *maiorNode = maior(a);
    TABB_imp_ident(maiorNode);

    TABB_libera(a);
    TABB_libera(maiorNode);

    return 0;
}