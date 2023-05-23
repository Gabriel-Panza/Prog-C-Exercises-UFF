#include <stdio.h>
#include "TAB/TAB.c"

void contaNodesFolhas(TAB *a, int *cont){
    if (a){
        if(!(a->esq) && !(a->dir)){
            ++*cont;
        }
        contaNodesFolhas(a->esq, cont);
        contaNodesFolhas(a->dir, cont);
    }
}
int ni(TAB *a){
    int cont=0; 
    if (!a) 
        return cont;
    contaNodesFolhas(a, &cont);
    return cont;
}

int main()
{
    TAB *a;
    a = TAB_cria(7,TAB_cria(5,NULL,TAB_cria(8,TAB_cria(2,NULL,NULL),TAB_cria(3,TAB_cria(4,NULL,TAB_cria(6,NULL,NULL)),NULL))),TAB_cria(2,TAB_cria(1,TAB_cria(10,NULL,NULL),TAB_cria(4,NULL,NULL)),TAB_cria(9,TAB_cria(8,NULL,NULL),TAB_cria(0,TAB_cria(3,NULL,NULL), NULL))));
    TAB_imp_ident(a);
    printf("\n\n");

    int qntdNodesFolhas= ni(a);
    printf("A Arvore tem %d nodes folhas", qntdNodesFolhas);

    TAB_libera(a);
    
    return 0;
}