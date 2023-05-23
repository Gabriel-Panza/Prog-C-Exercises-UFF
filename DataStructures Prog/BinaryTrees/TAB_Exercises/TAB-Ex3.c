#include <stdio.h>
#include "TAB/TAB.c"

TAB *achaMaior(TAB *a, TAB *maiorNode){
    if (a){
        maiorNode = achaMaior(a->esq,maiorNode);
        if (a->info > maiorNode->info) 
            return a;
        maiorNode = achaMaior(a->dir,maiorNode);
        if (a->info > maiorNode->info) 
            return a;
    }
    return maiorNode;
}
TAB* maior (TAB *a){
    if (!a) 
        return a;
    TAB *maiorNode = a; 
    return achaMaior(a, maiorNode);
}

int main()
{
    TAB *a, *maiorNode;
    a = TAB_cria(7,TAB_cria(5,NULL,TAB_cria(8,TAB_cria(2,NULL,NULL),TAB_cria(3,TAB_cria(4,NULL,TAB_cria(6,NULL,NULL)),NULL))),TAB_cria(2,TAB_cria(1,TAB_cria(10,NULL,NULL),TAB_cria(4,NULL,NULL)),TAB_cria(9,TAB_cria(8,NULL,NULL),TAB_cria(0,TAB_cria(3,NULL,NULL), NULL))));
    TAB_imp_ident(a);

    printf("\n\n");
    
    maiorNode = maior(a);
    TAB_imp_ident(maiorNode);

    TAB_libera(a);
    TAB_libera(maiorNode);

    return 0;
}