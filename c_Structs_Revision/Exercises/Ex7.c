#include <stdio.h>
#include <stdlib.h>
#include "TLSE.c"

void i_p (TLSE *l){
    TLSE *odd = initialize(), *even = initialize();
    TLSE *aux = l;
    while (aux){
        if (aux->info%2==0)
            even = pushEnd(even, aux->info);
        else
            odd = pushEnd(odd, aux->info);
        aux = aux->next;
    }
    while (even){
        odd = pushEnd(odd, even->info);
        even = even->next;
    }
    *l = *odd;
}

int main(){
    TLSE *l = initialize();
    l = pushStart(l, 1);
    l = pushStart(l, 2);
    l = pushStart(l, 3);
    l = pushStart(l, 4);
    l = pushStart(l, 5);
    print_rec(l);

    i_p(l);
    print_rec(l);
    freeAll_rec(l);

    return 0;
}
