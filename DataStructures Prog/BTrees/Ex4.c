#include <stdio.h>
#include "TARVB/TARVB.c"

TARVB* menor(TARVB *a){
    if (!a) return NULL;
    if (a->folha) return a;
    return menor(a->filho[0]);
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

    TARVB_Imprime(menor(b));
    return 0;
}