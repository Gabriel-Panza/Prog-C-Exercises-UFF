#include <stdio.h>
#include <stdlib.h>
#include "TLSE.c"

int inverted (TLSE*l1, TLSE* l2){
    TLSE *aux1 = l1, *aux2 = l2, *aux3 = initialize();
    while(aux2){
        aux3 = pushStart(aux3, aux2->info);
        aux2 = aux2->next;
    }
    while(aux1 && aux3){
        if (aux1->info != aux3->info)
            return 0;
        aux1 = aux1->next;
        aux3 = aux3->next;
    }
    if (aux1 == NULL && aux3 == NULL)
        return 1;
    return 0;
}    

int main(){
    TLSE *l1 = initialize(), *l2 = initialize();
    int i = 0;
    while (i<5)
        l1 = pushStart(l1, i++);
    i = 4;
    while (i>-1)
        l2 = pushStart(l2, i--);

    if(inverted(l1,l2)==1)
        printf("They are inverted");
    else
        printf("They are not inverted");
    
    freeAll_rec(l1);
    freeAll_rec(l2);

    return 0;
}
