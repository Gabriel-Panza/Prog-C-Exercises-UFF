#include <stdio.h>
#include <stdlib.h>
#include "TLSE.c"

TLSE* rotate (TLSE* l, int n){
    if (l == NULL || n == 0) 
        return l;

    if (n % 2 == 0) { // even
        TLSE* last = l;
        while (last->next != NULL) {
            last = last->next;
        }

        last->next = l;
        l = l->next;
        last->next->next = NULL;

        return l;
    } // odd
    TLSE* first = l;
    TLSE* before_last = l;
    while (before_last->next->next != NULL) {
        before_last = before_last->next;
    }

    TLSE *temp = before_last->next;
    before_last->next = NULL;
    temp->next = first;

    return temp;
}

int main(){
    TLSE *l = initialize();
    l = pushStart(l, 1);
    l = pushStart(l, 2);
    l = pushStart(l, 3);
    l = pushStart(l, 4);
    l = pushStart(l, 5);
    print_rec(l);

    l = rotate(l,2);
    print_rec(l);
    l = rotate(l,1);
    print_rec(l);
}