#include <stdio.h>
#include "TARVB/TARVB.c"

void retira_pares_aux(TARVB* arv, TARVB* node_raiz){
    if (!arv) return;
    int i=0;
    while (i<arv->nchaves){
        if(arv->chave[i]%2 == 0) {
            node_raiz = TARVB_Retira(node_raiz,arv->chave[i],2);
        }
        retira_pares_aux(arv->filho[i], arv);
        i++;
    }
    retira_pares_aux(arv->filho[i], arv);
}

TARVB* retira_pares(TARVB* arv){
    retira_pares_aux(arv,arv);
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

    TARVB_Libera(b);
    
    return 0;
}