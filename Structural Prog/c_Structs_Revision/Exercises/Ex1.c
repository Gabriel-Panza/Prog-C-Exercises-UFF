#include <stdio.h>
#include <stdlib.h>
#include "TLSE.c"

void inverte (TLSE* l){
    TLSE *l_inv = initialize(); 
    TLSE *l_aux = l;
    while (l_aux){
        l_inv = pushStart(l_inv, l_aux->info);
        l_aux = l_aux->next;
    }
    l_aux = l_inv;
    while(l_aux){
        l->info = l_aux->info;
        l_aux = l_aux->next;
        l = l->next;
    }
    freeAll_rec(l_inv);
}

int main(){
    TLSE *l = initialize();
    l = pushStart(l, 1);
    l = pushStart(l, 2);
    l = pushStart(l, 3);
    l = pushStart(l, 4);
    l = pushStart(l, 5);
    print_rec(l);

    inverte(l);
    print_rec(l);

    return 0;
}
