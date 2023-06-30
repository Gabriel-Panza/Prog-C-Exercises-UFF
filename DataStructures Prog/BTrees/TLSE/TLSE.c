#include<stdio.h>
#include<stdlib.h>

typedef struct listINT 
{
    int lim_inferior,lim_superior;
    struct listINT *next;
}TLSEINT;

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
void TLSE_freeAll_rec(TLSEINT *L)
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
void TLSE_print_rec(TLSEINT *L)
{
    if(L)
    {
        printf("[%d/%d]->", L->lim_inferior,L->lim_superior);
        TLSE_print_rec(L->next);
    }
    printf("\n");
}