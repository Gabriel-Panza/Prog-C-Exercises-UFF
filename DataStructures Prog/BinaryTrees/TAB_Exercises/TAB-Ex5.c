#include <stdio.h>
#include "TAB/TAB.c"

int igual (TAB* a1, TAB* a2)
{
    if (!a1 && !a2)
        return 0;
    
    int ehIgual;
    while (a1 && a2){
        if ((a1->info)==(a2->info))
        {
            ehIgual = igual(a1->esq,a2->esq);
            if (ehIgual==1)
                return 1;
            ehIgual = igual(a1->dir,a2->dir);
            if (ehIgual==1)
                return 1;
            return 0;
        }
        return 1;
    }
    return 1;
}
int main()
{
    int ehIgual, x1 = 10, x2=4, x3=16;
    TAB *a, *b;
    a = TAB_cria(x1,TAB_cria(x2,NULL,NULL),TAB_cria(x3,TAB_cria(5,NULL,NULL),NULL));
    b = TAB_cria(x1,TAB_cria(x2,NULL,NULL),TAB_cria(x3,NULL,NULL));


    ehIgual = igual(a, b);
    TAB_imp_ident(a);
    TAB_imp_ident(b);
    if (ehIgual==0)
        printf("Elas sao iguais!");
    else
        printf("Elas nao sao iguais!");

    TAB_libera(a);
    TAB_libera(b);

    return 0;
}