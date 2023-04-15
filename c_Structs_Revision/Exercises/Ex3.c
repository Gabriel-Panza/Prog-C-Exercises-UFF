#include <stdio.h>
#include <stdlib.h>
#include "TLSE.c"

TLSE* desloca (TLSE* l, int n){
    if (l == NULL || n == 0) 
        return l;

    if (n % 2 == 0) { // even
        TLSE* ultimo = l;
        while (ultimo->prox != NULL) {
            ultimo = ultimo->prox;
        }

        ultimo->prox = l;
        l = l->prox;
        ultimo->prox->prox = NULL;

        return l;
    } // odd
    TLSE* primeiro = l;
    TLSE* penultimo = l;
    while (penultimo->prox->prox != NULL) {
        penultimo = penultimo->prox;
    }

    TLSE *temp = penultimo->prox;
    penultimo->prox = NULL;
    temp->prox = primeiro;

    return temp;
}

int main(){
    TLSE *l = initialize();
    l = pushStart(l, 1);
    l = pushStart(l, 2);
    l = pushStart(l, 3);
    l = pushStart(l, 4);
    l = pushStart(l, 5);
    print_rec(l);

    l = desloca(l,2);
    print_rec(l);
    l = desloca(l,1);
    print_rec(l);
}