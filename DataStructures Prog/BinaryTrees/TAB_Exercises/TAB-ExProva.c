#include <stdio.h>
#include "TAB/TAB.c"

int nivel_par(TAB *a);
int nivel_impar(TAB *a);

int nivel_impar(TAB *a){
    if (!a->esq && !a->dir) return 0;
    if (a->esq && a->dir) return 0;
    if (a->esq) return nivel_par(a->esq);
    return nivel_par(a->dir);
}
int nivel_par(TAB *a){
    if (!a) return 1;
    if (!a->esq && !a->dir) return 1;
    if (a->esq && a->dir) return (nivel_impar(a->esq) && nivel_impar(a->dir));
    return 0;    
}
int arv_tipo_x(TAB *a){
    return nivel_par(a);
}

int main()
{
    TAB *a;
    a = TAB_cria(7,TAB_cria(5,NULL,TAB_cria(8,TAB_cria(11,TAB_cria(13,NULL,NULL),NULL),TAB_cria(3,TAB_cria(4,NULL,NULL),NULL))),TAB_cria(2, NULL,TAB_cria(9,TAB_cria(8,TAB_cria(4,NULL,NULL),NULL),TAB_cria(0,TAB_cria(3,NULL,NULL), NULL))));
    TAB_imp_ident(a);

    printf("\n\n");
    
    int resp = arv_tipo_x(a);
    if (resp) printf("Arvore eh do tipo x!");
    else printf("Arvore nao eh do tipo x!"); 

    return 0;
}