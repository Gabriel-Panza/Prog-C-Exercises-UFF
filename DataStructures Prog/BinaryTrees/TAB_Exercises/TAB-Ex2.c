#include <stdio.h>
#include "TAB/TAB.c"

TAB* espelho (TAB *a)
{
    if (!a)
        return a;
    return TAB_cria(a->info,espelho(a->dir),espelho(a->esq));
}
int main()
{
    TAB *a, *esp;

    int x1 = 10, x2=4, x3=16;
    a = TAB_cria(x1,TAB_cria(x2,NULL,NULL),TAB_cria(x3,NULL,NULL));
    TAB_imp_ident(a);

    esp = espelho(a);
    TAB_imp_ident(esp);

    TAB_libera(a);
    TAB_libera(esp);

    return 0;
}