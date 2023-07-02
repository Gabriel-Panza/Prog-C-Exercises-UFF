#include <stdio.h>
#include "TARVB/TARVB.c"

TARVB* retira_pares(TARVB* arv){
    if (!arv) return NULL;
    int i=0;
    while (i<arv->nchaves){
        if(arv->chave[i]%2 == 0) arv = TARVB_Retira(arv,arv->chave[i],2);
        arv->filho[i] = retira_pares(arv->filho[i]);
        i++;
    }
    arv->filho[i] = retira_pares(arv->filho[i]);
    return arv;
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
    TARVB_Imprime(b);

    b = retira_pares(b);
    TARVB_Imprime(b);

    return 0;
}