#include <stdio.h>
#include "TARVB/TARVB.c"

TARVB* copia_aux(TARVB* a, int tam) {
    if (!a) return NULL;
    TARVB* aux = TARVB_Cria(tam);
    int i=0;
    while (i<a->nchaves) {
        aux = TARVB_Insere(aux, a->chave[i], tam);
        aux->filho[i] = copia_aux(a->filho[i],tam);
        i++;
    }
    aux->filho[i] = copia_aux(a->filho[i],tam);
    return aux;
}
TARVB* copia (TARVB *a){
    if (!a) return NULL;
    return copia_aux(a,2);
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

    TARVB *b_copia = copia(b);
    TARVB_Imprime(b);
    TARVB_Libera(b);
    printf("\n----------------------------------\n");
    TARVB_Imprime(b_copia);
    TARVB_Libera(b_copia);
    return 0;
}