#include <stdio.h>
#include "TARVB/TARVB.c"

TARVB* copia_aux(TARVB* a, int tam) {
    if (!a) return NULL;
    TARVB* b = TARVB_Cria(tam);
    for (int i = 0; i < a->nchaves; i++) {
        b = TARVB_Insere(b, a->chave[i], tam);
        if (a->filho[i]) {
            TARVB* filho_copiado = copia_aux(a->filho[i],tam);
            b->filho[i] = filho_copiado;
        }
    }
    if (a->filho[a->nchaves]) {
        TARVB* filho_copiado = copia_aux(a->filho[a->nchaves],tam);
        b->filho[a->nchaves] = filho_copiado;
    }
    return b;
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
    printf("\n\n");
    TARVB_Imprime(b_copia);
    return 0;
}