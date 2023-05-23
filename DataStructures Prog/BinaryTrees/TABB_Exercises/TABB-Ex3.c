#include <stdio.h>
#include "TABB/TABB.c"

TABB* retira_impares (TABB* arv)
{
    if (!arv)
        return arv;
    arv->esq = retira_impares(arv->esq);
    arv->dir = retira_impares(arv->dir);
    if (arv->info%2!=0)
        arv = TABB_retira(arv,arv->info);
    return arv; 
}

int main()
{
    TABB *a, *semImpar;

    int x1 = 10, x2=4, x3=16, x4=5, x5=15;
    a = TABB_cria(x1,NULL,NULL);
    a = TABB_insere(a,x2);
    a = TABB_insere(a,x3);
    a = TABB_insere(a,x4);
    a = TABB_insere(a,x5);
    TABB_imp_ident(a);

    semImpar = retira_impares(a);
    TABB_imp_ident(semImpar);

    TABB_libera(a);
    TABB_libera(semImpar);

    return 0;
}