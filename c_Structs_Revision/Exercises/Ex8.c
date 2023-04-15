#include <stdio.h>
#include <stdlib.h>
#include "TLSE.c"

int same(TLSE *l1, TLSE *l2){
    TLSE *aux1 = l1, *aux2 = l2;
    while(aux1 && aux2){
        if (aux1->info != aux2->info)
            return 0;
        aux1 = aux1->next;
        aux2 = aux2->next;
    }
    if (aux1 == NULL && aux2 == NULL)
        return 1;
    return 0;
}

int main(){
    TLSE *l1 = initialize(), *l2 = initialize();
    int i = 0;
    while (i<6)
        l1 = pushStart(l1, i++);
    i = 0;
    while (i<6)
        l2 = pushStart(l2, i++);

    if(same(l1,l2)==1)
        printf("They are the same");
    else
        printf("They are different");
    
    freeAll_rec(l1);
    freeAll_rec(l2);

    return 0;
}
