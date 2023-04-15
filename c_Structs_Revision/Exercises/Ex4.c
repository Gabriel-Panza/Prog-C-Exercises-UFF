#include <stdio.h>
#include <stdlib.h>
#include "TLSE.c"

TLSE* copy (TLSE* l){
    if (!l)
        return l;
    TLSE *copy = initialize(), *aux=l;
    while (aux){
        copy = pushEnd(copy, aux->info);
        aux=aux->next;
    }
    return copy;
}

int main(){
    TLSE *l = initialize();
    l = pushStart(l, 1);
    l = pushStart(l, 2);
    l = pushStart(l, 3);
    l = pushStart(l, 4);
    l = pushStart(l, 5);
    print_rec(l);

    TLSE *l2 = copy(l);
    print_rec(l2);
}