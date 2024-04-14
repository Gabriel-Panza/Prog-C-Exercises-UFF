#include<stdio.h>
#include<stdlib.h>

typedef struct list 
{
    int info;
    struct list *next;
}TLSE;

TLSE *initialize()
{
    return NULL;
}

TLSE *insertStart(TLSE *L, int elem)
{
    TLSE *new = (TLSE*) malloc(sizeof(TLSE));
    new->info = elem;
    new->next = L;
    return new;
}
TLSE *insertMiddle(TLSE *old, TLSE *L, int elem, int position) // Only works with valid positions
{
    // CASE 1: empty/null List
    if(!L || position == 0) // L == NULL
    {
        L = insertStart(L, elem);
        return L;
    }

    // CASE 2: not empty/null List
    TLSE* atual = L;
    if (position>1)
    {
        L->next = insertMiddle(L, L->next, elem, position-1);
        return L;
    }
    old = atual;
    atual = atual->next;

    // Create a new node with the info
    TLSE *new = (TLSE*) malloc(sizeof(TLSE));
    new->info = elem;

    // Add in the middle of 2 nodes
    new->next = atual;
    old->next = new;
    return old;
}
TLSE *insertEnd(TLSE *L, int elem)
{
    TLSE *new = insertStart(NULL,elem);
    // CASE 1: empty/null List
    if(!L) // L == NULL
        return new;

    // CASE 2: not empty/null List
    TLSE *LSE_aux = L;
    while(LSE_aux->next) // while (LSE_aux->next != NULL)
        LSE_aux = LSE_aux->next;
    
    LSE_aux->next = new;
    return L;
}
TLSE *pushEnd_rec(TLSE *L, int elem)
{
    if (!L)
        return insertStart(L,elem);
    L->next = pushEnd_rec(L->next,elem);
    return L;
}
TLSE *pushSorted(TLSE *L, int elem) // Only works with sorted lists
{
    TLSE *aux_old = NULL;
    TLSE *aux_actual = L;
    while(aux_actual && aux_actual->info < elem)
    {
        aux_old = aux_actual;
        aux_actual = aux_actual->next;
    }

    // CASE 1: empty/null List
    if (aux_old==NULL)
        return insertStart(NULL,elem);
    // CASE 2: not empty/null List
    aux_old->next = insertStart(aux_actual,elem);
    return L;
    
}
TLSE *pushSorted_rec(TLSE *L, int elem) // Only works with sorted lists
{
    if((!L) || (L->info >= elem))
        return insertStart(L,elem);
    L->next = pushSorted_rec(L->next,elem);
    return L;
}

TLSE* search(TLSE *l, int elem)
{
    TLSE *aux = l;
    while((aux) && (aux->info != elem)) // while aux != NULL and ...
        aux = aux->next;
    return aux;
}
TLSE* search_rec(TLSE *l, int elem)
{
    if((!l) || (l->info == elem)) // while l == NULL or l == node wanted, return
        return l;
    return search_rec(l->next, elem);
}

TLSE* pop(TLSE *l, int elem)
{
    TLSE *actual = l;
    TLSE *old = NULL;
    while((actual) && (actual->info != elem))
    {
        old = actual;
        actual = actual->next;
    }
    // CASE 1: I didnt find the element
    if(!actual) // actual == NULL
        return l;
    // CASE 2: Its the first of the list
    if(!old) // old == NULL
        l = l->next;
    // CASE 3: Its in the middle/final
    else {
        TLSE* lixo = actual;
        old->next = actual->next;
        free(lixo);
    }
    return l;
}
TLSE* pop_rec(TLSE *l, int elem)
{
    // CASE 1
    if(!l)  
        return l;
    // CASE 2
    if(l->info == elem)
        l = l->next;
    // CASE 3
    else 
        l->next = pop_rec(l->next, elem);
    return l;
}

void freeAll(TLSE *L)
{
    TLSE *aux = L;
    TLSE *temp;
    while(aux!=NULL)
    {
        temp = aux;
        aux=aux->next;
        free(temp);
    }
}
void freeAll_rec(TLSE *L)
{
    if(L)
    {
        freeAll_rec(L->next);
        free(L);
    }
}

void TLSE_print(TLSE *L)
{
    TLSE *aux = L;
    while(aux)
    {
        printf("[%d]->", aux->info);
        aux = aux->next; 
    }
    printf("NULL\n");
}
void TLSE_print_rec(TLSE *L)
{
    if(L)
    {
        printf("[%d]->", L->info);
        TLSE_print_rec(L->next);
    }
    printf("\n");
}
void print_inv(TLSE *L)
{
    TLSE *aux = L;
    TLSE *L_aux = initialize();
    while(aux)
    {
        L_aux = insertStart(L_aux, aux->info);
        aux = aux->next;
    }
    TLSE_print(L_aux);
    freeAll(L_aux);
}
void print_inv_rec(TLSE *L)
{
    if (L->next)
        print_inv_rec(L->next);
    printf("<-[%d]", L->info);
}