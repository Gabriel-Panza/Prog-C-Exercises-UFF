#include <stdio.h>
#include <limits.h>
#include "TAB/TAB.c"

int menor(int a, int b){
    if (a < b) return a;
    return b;
}
int sucX(TAB *a, int x){
    if (!a) return INT_MAX;
    if (a->info > x){
        int menor_filho = menor(sucX(a->esq,x), sucX(a->dir,x));
        return menor(a->info, menor_filho);
    }
    return menor(sucX(a->esq,x), sucX(a->dir,x));
}

int main()
{
    TAB *a;
    a = TAB_cria(7,TAB_cria(5,NULL,TAB_cria(8,TAB_cria(11,TAB_cria(13,NULL,NULL),NULL),TAB_cria(3,TAB_cria(4,NULL,NULL),NULL))),TAB_cria(2, NULL,TAB_cria(9,TAB_cria(8,TAB_cria(4,NULL,NULL),NULL),TAB_cria(0,TAB_cria(3,NULL,NULL), NULL))));
    TAB_imp_ident(a);

    printf("\n\n");
    
    int elem = 5;
    int suc = sucX(a, elem);
    if (suc == INT_MAX) printf("Arvore nao tem sucessor do elemento %d!", elem);
    else printf("Arvore tem sucessor do elemento %d: %d", elem, suc); 

    return 0;
}