#include <stdio.h>
#include "TARVB/TARVB.c"

TARVB* retira_pares(TARVB* a, int t);

TARVB* retira_pares_aux (TARVB* a, TARVB *arv, int t){
    if(!a) return arv;
    int i = 0;
    while(i < a->nchaves){
        if((a->chave[i] % 2) == 0){
            arv = TARVB_Retira(arv, a->chave[i], t);
            break;
        }
        arv = retira_pares_aux (a->filho[i], arv, t);
        i++;
    }
    if(i != a->nchaves) arv = retira_pares(arv, t);
    else arv = retira_pares_aux(a->filho[i], arv, t);
}

TARVB* retira_pares(TARVB* a, int t){
  if(!a) return a;
  a = retira_pares_aux(a, a, t);
  return a;
} 

int main(){
    int t = 3;
    TARVB *b = TARVB_Cria(t);
    b = TARVB_Insere(b,20,t);
    b = TARVB_Insere(b,50,t);
    b = TARVB_Insere(b,60,t);
    b = TARVB_Insere(b,1,t);
    b = TARVB_Insere(b,64,t);
    b = TARVB_Insere(b,12,t);
    b = TARVB_Insere(b,18,t);
    b = TARVB_Insere(b,66,t);
    b = TARVB_Insere(b,38,t);
    b = TARVB_Insere(b,7,t);
    b = TARVB_Insere(b,70,t);
    TARVB_Imprime(b);

    b = retira_pares(b,t);
    TARVB_Imprime(b);

    TARVB_Libera(b);
    
    return 0;
}