#include <stdlib.h>
#include <string.h>
#include "TABB/TABB.c"

int zz(TABB *a){
    if (!a) return -1;
    if (a->esq && a->dir) return 0;
    if(!a->esq && !a->dir) return 1; 
    if (a->esq) return zz(a->esq);
    return zz(a->dir);
}

int main(void)
{
    TABB *a = TABB_cria(5, NULL, NULL);
    a = TABB_insere(a, 1);
    a = TABB_insere(a, 4);
    a = TABB_insere(a, 2);
    a = TABB_insere(a, 3);
    // a = TABB_insere(a, 9);
    // a = TABB_insere(a, 6);
    // a = TABB_insere(a, 8);
    // a = TABB_insere(a, 7);
    TABB_imp_ident(a);

    int zig = zz(a);
    if(zig) printf("A Arvore eh zig-zague");
    else if(!zig) printf("A Arvore nao eh zig-zague");
    else printf("A Árvore eh nula");
    
    TABB_libera(a);

    return 0;
}