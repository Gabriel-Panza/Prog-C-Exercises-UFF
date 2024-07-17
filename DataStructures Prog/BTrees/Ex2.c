#include <stdio.h>
#include <limits.h>
#include "TARVB/TARVB.c"

int suc (TARVB *a, int elem, int *superior){
    if (!a) return *superior;
    int i=0, j=0;
    while (i<a->nchaves && a->chave[i]<elem) i++;
    while (j<a->nchaves){
        if(a->chave[j]<(*superior) && a->chave[j]>elem) (*superior) = a->chave[j];
        j++;
    }
    return suc(a->filho[i], elem, superior);
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
    b = TARVB_Insere(b,70,2);

    int superior = INT_MAX;
    int sucessor = suc(b,12,&superior);
    if (sucessor==INT_MIN) printf("Arvore Nula");
    TARVB_Imprime(b);
    printf("O primeiro sucessor eh: %d", sucessor);
    return 0;
}