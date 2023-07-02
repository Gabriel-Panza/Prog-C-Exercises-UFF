#include <stdio.h>
#include "TARVB/TARVB.c"

void igual_aux(TARVB* a1, TARVB* a2, int *igual_num){
    if(!a1 && !a2) return;
    if(!a1 || !a2) {
        *igual_num = 0;
        return;
    }
    int i=0;
    while (i<a1->nchaves && i<a2->nchaves) {
        if (a1->chave[i] != a2->chave[i]) {
            *igual_num = 0;
            return;
        }
        igual_aux(a1->filho[i],a2->filho[i],igual_num);
        i++;
    }
    return igual_aux(a1->filho[i],a2->filho[i],igual_num);
}

int igual(TARVB* a1, TARVB* a2){
    int igual_num=1;
    igual_aux(a1,a2,&igual_num);
    return igual_num;
}

int main(){
    TARVB *b = TARVB_Cria(2); b = TARVB_Insere(b,20,2); b = TARVB_Insere(b,50,2); b = TARVB_Insere(b,60,2); b = TARVB_Insere(b,1,2); b = TARVB_Insere(b,64,2); b = TARVB_Insere(b,12,2); b = TARVB_Insere(b,18,2); b = TARVB_Insere(b,66,2); b = TARVB_Insere(b,38,2); b = TARVB_Insere(b,7,2); b = TARVB_Insere(b,70,2);
    TARVB *b1 = TARVB_Cria(2); b1 = TARVB_Insere(b1,20,2); b1 = TARVB_Insere(b1,50,2); b1 = TARVB_Insere(b1,60,2); b1 = TARVB_Insere(b1,1,2); b1 = TARVB_Insere(b1,64,2); b1 = TARVB_Insere(b1,12,2); b1 = TARVB_Insere(b1,18,2); b1 = TARVB_Insere(b1,66,2); b1 = TARVB_Insere(b1,38,2); b1 = TARVB_Insere(b1,7,2); b1 = TARVB_Insere(b1,70,2);

    if(igual(b,b1)) printf("Equal!");
    else printf("Not Equal!");
    
    TARVB_Libera(b);
    TARVB_Libera(b1);
    
    return 0;
}