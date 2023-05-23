#include <stdio.h>
#include "TAB/TAB.c"

TAB *achaMenor(TAB *a, TAB *menorNode){
    if (!menorNode) 
        menorNode = TAB_cria(a->info,a->esq,a->dir);
    if (a){
        menorNode = achaMenor(a->esq,menorNode);
        if (a->info < menorNode->info) 
            return a;
        menorNode = achaMenor(a->dir,menorNode);
        if (a->info < menorNode->info) 
            return a;
    }
    return menorNode;
}
TAB* menor (TAB *a){
    if (!a) 
        return a;
    TAB *menorNode = TAB_inicializa(); 
    return achaMenor(a, menorNode);
}

int main()
{
    TAB *a, *menorNode;
    a = TAB_cria(7,TAB_cria(5,NULL,TAB_cria(8,TAB_cria(2,NULL,NULL),TAB_cria(3,TAB_cria(4,NULL,TAB_cria(6,NULL,NULL)),NULL))),TAB_cria(2,TAB_cria(1,TAB_cria(10,NULL,NULL),TAB_cria(4,NULL,NULL)),TAB_cria(9,TAB_cria(8,NULL,NULL),TAB_cria(0,TAB_cria(3,NULL,NULL), NULL))));

    menorNode = menor(a);
    TAB_imp_ident(menorNode);

    TAB_libera(a);
    TAB_libera(menorNode);
    return 0;
}