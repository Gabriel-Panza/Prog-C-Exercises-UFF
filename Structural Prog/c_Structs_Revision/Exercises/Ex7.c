#include <stdio.h>
#include <stdlib.h>
#include "TLSE.c"

void i_p (TLSE *l){
    TLSE *odd = initialize(), *even = initialize();
    TLSE *aux = l;
    while (aux){
        if (aux->info%2==0)
            even = insertEnd(even, aux->info);
        else
            odd = insertEnd(odd, aux->info);
        aux = aux->next;
    }
    while (even){
        odd = insertEnd(odd, even->info);
        even = even->next;
    }
    aux = odd;
    while(aux){
        l->info = aux->info;
        aux = aux->next;
        l = l->next;
    }
    freeAll_rec(odd);
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
