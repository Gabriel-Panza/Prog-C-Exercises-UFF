#include <stdio.h>
#include "TARVB/TARVB.c"
#include "TLSE/TLSE.c"

TLSE *insere_ordenado(TLSE *L, int elem) {
    if (!L || elem < L->info) L = insertStart(L, elem);
    if (elem > L->info) L->next = insere_ordenado(L->next, elem);
    return L;
}

TLSE *insere_arvoreB_na_lista(TARVB *b, TLSE *L) {
    if (!b) return L;
    int i;
    for (i = 0; i < b->nchaves; i++) {
        // Inserir os elementos da subárvore esquerda da chave atual
        L = insere_arvoreB_na_lista(b->filho[i], L);
        // Inserir a chave atual
        L = insere_ordenado(L, b->chave[i]);
    }
    // Inserir elementos da última subárvore (após a última chave)
    L = insere_arvoreB_na_lista(b->filho[i], L);
    return L;
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
    printf("\n----------------------------------\n");

    TLSE* l = initialize();
    l = insere_arvoreB_na_lista(b,l);
    TLSE_print(l);
    printf("\n----------------------------------\n");
    TARVB_Libera(b);
    freeAll(l);
    return 0;
}