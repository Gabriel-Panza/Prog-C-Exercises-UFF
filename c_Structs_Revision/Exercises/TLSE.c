#include<stdio.h>
#include<stdlib.h>

typedef struct list 
{
    int info;
    struct list *prox;
}TLSE;

TLSE *initialize()
{
    return NULL;
}

TLSE *pushStart(TLSE *L, int elem)
{
    TLSE *new = (TLSE*) malloc(sizeof(TLSE));
    new->info = elem;
    new->prox = L;
    return new;
}
TLSE *pushMiddle(TLSE *old, TLSE *L, int elem, int position) // Only works with valid positions
{
    // CASE 1: empty/null List
    if(!L || position == 0) // L == NULL
    {
        L = pushStart(L, elem);
        return L;
    }

    // CASE 2: not empty/null List
    TLSE* atual = L;
    if (position>1)
    {
        L->prox = pushMiddle(L, L->prox, elem, position-1);
        return L;
    }
    old = atual;
    atual = atual->prox;

    // Create a new node with the info
    TLSE *new = (TLSE*) malloc(sizeof(TLSE));
    new->info = elem;

    // Add in the middle of 2 nodes
    new->prox = atual;
    old->prox = new;
    return old;
}
TLSE *pushEnd(TLSE *L, int elem)
{
    TLSE *new = pushStart(NULL,elem);
    // CASE 1: empty/null List
    if(!L) // L == NULL
        return new;

    // CASE 2: not empty/null List
    TLSE *LSE_aux = L;
    while(LSE_aux->prox) // while (LSE_aux->next != NULL)
        LSE_aux = LSE_aux->prox;
    
    LSE_aux->prox = new;
    return L;
}
TLSE *pushEnd_rec(TLSE *L, int elem)
{
    if (!L)
        return pushStart(L,elem);
    L->prox = pushEnd_rec(L->prox,elem);
    return L;
}
TLSE *pushSorted(TLSE *L, int elem) // Only works with sorted lists
{
    TLSE *aux_old = NULL;
    TLSE *aux_actual = L;
    while(aux_actual && aux_actual->info < elem)
    {
        aux_old = aux_actual;
        aux_actual = aux_actual->prox;
    }

    // CASE 1: empty/null List
    if (aux_old==NULL)
        return pushStart(NULL,elem);
    // CASE 2: not empty/null List
    aux_old->prox = pushStart(aux_actual,elem);
    return L;
    
}
TLSE *pushSorted_rec(TLSE *L, int elem) // Only works with sorted lists
{
    if((!L) || (L->info >= elem))
        return pushStart(L,elem);
    L->prox = pushSorted_rec(L->prox,elem);
    return L;
}

TLSE* search(TLSE *l, int elem)
{
    TLSE *aux = l;
    while((aux) && (aux->info != elem)) // while aux != NULL and ...
        aux = aux->prox;
    return aux;
}
TLSE* search_rec(TLSE *l, int elem)
{
    if((!l) || (l->info == elem)) // while l == NULL or l == node wanted, return
        return l;
    return search_rec(l->prox, elem);
}

TLSE* pop(TLSE *l, int elem)
{
    TLSE *actual = l;
    TLSE *old = NULL;
    while((actual) && (actual->info != elem))
    {
        old = actual;
        actual = actual->prox;
    }
    // CASE 1: I didnt find the element
    if(!actual) // actual == NULL
        return l;
    // CASE 2: Its the first of the list
    if(!old) // old == NULL
        l = l->prox;
    // CASE 3: Its in the middle/final
    else {
        TLSE* lixo = actual;
        old->prox = actual->prox;
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
        l = l->prox;
    // CASE 3
    else 
        l->prox = pop_rec(l->prox, elem);
    return l;
}

void freeAll(TLSE *L)
{
    TLSE *aux = L;
    TLSE *temp;
    while(aux!=NULL)
    {
        temp = aux;
        aux=aux->prox;
        free(temp);
    }
}
void freeAll_rec(TLSE *L)
{
    if(L)
    {
        freeAll_rec(L->prox);
        free(L);
    }
}

void print(TLSE *L)
{
    TLSE *aux = L;
    while(aux)
    {
        printf("[%d]->", aux->info);
        aux = aux->prox; 
    }
    printf("\n");
}
void print_rec(TLSE *L)
{
    if(L)
    {
        printf("[%d]->", L->info);
        print_rec(L->prox);
    }
    else
        printf("\n");
}
void print_inv(TLSE *L)
{
    TLSE *aux = L;
    TLSE *L_aux = initialize();
    while(aux)
    {
        L_aux = pushStart(L_aux, aux->info);
        aux = aux->prox;
    }
    print(L_aux);
    freeAll(L_aux);
}
void print_inv_rec(TLSE *L)
{
    if (L->prox)
        print_inv_rec(L->prox);
    printf("[%d]->", L->info);
}