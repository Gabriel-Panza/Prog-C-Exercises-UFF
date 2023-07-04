#include<stdio.h>
#include<stdlib.h>

typedef struct listINT 
{
    int lim_inferior,lim_superior;
    struct listINT *next;
}TLSEINT;
typedef struct list
{
    int elem;
    struct list *next;
}TLSE;

TLSE *TLSE_insere_ini(TLSE *L, int elem)
{
    TLSE *new = (TLSE*) malloc(sizeof(TLSE));
    new->elem = elem;
    new->next = L;
    return new;
}

TLSEINT *TLSEINT_insere_ini(TLSEINT *L, int elem1, int elem2)
{
    TLSEINT *new = (TLSEINT*) malloc(sizeof(TLSEINT));
    new->lim_inferior = elem1;
    new->lim_superior = elem2;
    new->next = L;
    return new;
}

void TLSE_freeAll(TLSEINT *L)
{
    TLSEINT *aux = L;
    TLSEINT *temp;
    while(aux!=NULL)
    {
        temp = aux;
        aux=aux->next;
        free(temp);
    }
}
void TLSEINT_freeAll_rec(TLSEINT *L)
{
    if(L)
    {
        TLSEINT_freeAll_rec(L->next);
        free(L);
    }
}
void TLSE_freeAll_rec(TLSE *L)
{
    if(L)
    {
        TLSE_freeAll_rec(L->next);
        free(L);
    }
}

void TLSE_print(TLSEINT *L)
{
    TLSEINT *aux = L;
    while(aux)
    {
        printf("[%d/%d]->", aux->lim_inferior,aux->lim_superior);
        aux = aux->next; 
    }
    printf("NULL\n");
}
void TLSEINT_print_rec(TLSEINT *L)
{
    if(L)
    {
        printf("[%d/%d]->", L->lim_inferior,L->lim_superior);
        TLSEINT_print_rec(L->next);
    }
}
void TLSE_print_rec(TLSE *L)
{
    if(L)
    {
        printf("[%d]->", L->elem);
        TLSE_print_rec(L->next);
    }
}