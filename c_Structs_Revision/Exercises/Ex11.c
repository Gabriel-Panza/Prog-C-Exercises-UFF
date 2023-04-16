#include <stdio.h>
#include <stdlib.h>
#include "TLSE.c"

TLSE * ordena (TLSE* l){
    TLSE *aux = l, *sorted_l = initialize();
    while(aux){
        sorted_l = pushSorted_rec(sorted_l,aux->info);
        aux = aux->next;
    }
    return sorted_l;
}

int main(){
    TLSE *l = initialize();
    l = pushStart(l, 3);
    l = pushStart(l, 1);
    l = pushStart(l, 2);
    l = pushStart(l, 6);
    l = pushStart(l, 4);
    l = pushStart(l, 5);
    print_rec(l);

    TLSE *l2 = ordena(l);
    print_rec(l2);

    return 0;
}