#include <stdio.h>
#include "TAB/TAB.c"

void contaNodes(TAB *a, int *cont){
    if(a){
        ++*cont;
        contaNodes(a->esq, cont);
        contaNodes(a->dir, cont);
    }
}
int ni(TAB *a){
    int cont=0; 
    if (!a) 
        return cont;
    contaNodes(a, &cont);
    return cont-1;
}

int main()
{
    TAB *a;
    a = TAB_cria(7,TAB_cria(5,NULL,TAB_cria(8,TAB_cria(2,NULL,NULL),TAB_cria(3,TAB_cria(4,NULL,TAB_cria(6,NULL,NULL)),NULL))),TAB_cria(2,TAB_cria(1,TAB_cria(10,NULL,NULL),TAB_cria(4,NULL,NULL)),TAB_cria(9,TAB_cria(8,NULL,NULL),TAB_cria(0,TAB_cria(3,NULL,NULL), NULL))));
    TAB_imp_ident(a);
    printf("\n\n");
    
    int qntdNodes= ni(a);
    printf("A Arvore tem %d nodes internos", qntdNodes);
    
    TAB_libera(a);
    
    return 0;
}