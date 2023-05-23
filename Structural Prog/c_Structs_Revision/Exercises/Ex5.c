#include <stdio.h>
#include <stdlib.h>
#include "TLSE.c"

TLSE* rto (TLSE* l, int elem){
    while (search_rec(l,elem)){
        l = pop_rec(l,elem);
    }
    return l;
}

int main(){
    TLSE *l = initialize();
    l = pushStart(l, 1);
    l = pushStart(l, 1);
    l = pushStart(l, 3);
    l = pushStart(l, 1);
    l = pushStart(l, 4);
    l = pushStart(l, 1);
    l = pushStart(l, 1);
    print_rec(l);

    l = rto(l, 1);
    print_rec(l);

    return 0;
}