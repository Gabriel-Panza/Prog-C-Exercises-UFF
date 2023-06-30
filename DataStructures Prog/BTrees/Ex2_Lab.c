#include <stdio.h>
#include "TARVB/TARVB.c"
#include "TLSE/TLSE.c"
#include <limits.h>

TLSEINT* misc(TARVB *a, int elem){
    if (!a) return NULL;
    int i=0, j=0, inferior = INT_MIN, superior = INT_MAX;
    while (i<a->nchaves && a->chave[i]< elem) i++;
    while (j<a->nchaves){
        if(a->chave[j]>inferior && a->chave[j]<elem) inferior = a->chave[j];
        if(a->chave[j]<superior && a->chave[j]>elem) superior = a->chave[j];
        j++;
    }
    if(a->folha) return TLSEINT_insere_ini(NULL, inferior, superior);
    return TLSEINT_insere_ini(misc(a->filho[i], elem), inferior, superior);
}

int main(){
    TARVB *b = TARVB_Cria(2);
    b = TARVB_Insere(b,20,2);
    b = TARVB_Insere(b,50,2);
    b = TARVB_Insere(b,60,2);
    b = TARVB_Insere(b,1,2);
    b = TARVB_Insere(b,64,2);
    b = TARVB_Insere(b,12,2);
    b = TARVB_Insere(b,18,2);
    b = TARVB_Insere(b,66,2);
    b = TARVB_Insere(b,38,2);
    b = TARVB_Insere(b,7,2);
    TARVB_Imprime(b);

    TLSEINT* l = misc(b, 6);
    TLSE_print(l);
    return 0;
}