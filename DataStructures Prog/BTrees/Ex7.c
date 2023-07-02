#include <stdio.h>
#include "TARVB/TARVB.c"

void contanodes(TARVB *a, int *cont){
    if (!a) return;
    int i=0;
    while(i<a->nchaves) {
        if (!a->folha) *(++cont);
        contanodes(a->filho[i],cont);
        i++;
    }
    contanodes(a->filho[i],cont);
}
int ni(TARVB *a){
    int cont = 0;
    if (!a) return cont;
    contanodes(a,&cont);
    return cont;
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

    int nodes = ni(b);
    printf("A quantidade de nodes internos sao: %d", nodes);
    return 0;
}