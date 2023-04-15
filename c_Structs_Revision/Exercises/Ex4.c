#include <stdio.h>
#include <stdlib.h>
#include "TLSE.c"

TLSE* copia (TLSE* l){
    if (!l)
        return l;
    TLSE *copia = initialize(), *aux=l;
    while (aux){
        copia = pushEnd(copia, aux->info);
        aux=aux->prox;
    }
    return copia;
}

int main(){
    TLSE *l = initialize();
    l = pushStart(l, 1);
    l = pushStart(l, 2);
    l = pushStart(l, 3);
    l = pushStart(l, 4);
    l = pushStart(l, 5);
    print_rec(l);

    TLSE *l2 = copia(l);
    print_rec(l2);
}