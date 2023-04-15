#include <stdio.h>
#include <stdlib.h>
#include "TLSE.c"

TLSE* lists_together (TLSE*l1, TLSE* l2){
    TLSE *aux = l1;
    while (aux->next)
        aux = aux->next;
    aux->next = l2;
    return l1;
}    

int main(){
    TLSE *l1 = initialize(), *l2 = initialize();
    int i = 0;
    while (i<5)
        l1 = pushStart(l1, i++);
    i = 0;
    while (i<5)
        l2 = pushStart(l2, i++);

    TLSE *l3 = lists_together(l1,l2);
    print_rec(l3);

    freeAll_rec(l1);
    freeAll_rec(l2);
    freeAll_rec(l3);

    return 0;
}
