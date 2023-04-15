#include<stdio.h>
#include<stdlib.h>

typedef struct list 
{
    int info;
    struct list *prox;
}TLSE;

TLSE *initialize()
{
    TLSE *L = (TLSE*) malloc(sizeof(TLSE));
    L->prox = NULL;
    return L;
}

TLSE *pushStart (TLSE *L, int elem)
{
    TLSE *novo = (TLSE*) malloc(sizeof(TLSE));
    novo->info = elem;
    novo->prox = L->prox;
    L->prox = novo;
    return L;
}
TLSE *pushMiddle(TLSE *old, TLSE *L, int elem, int posicao)
{
    // CASE 1: empty/null List
    if(!L->prox || posicao == 0) // L->next == NULL
    {
        L = pushStart(L, elem);
        return L;
    }

    // CASE 2: not empty/null List
    TLSE * actual = L;
    if (posicao>1)
    {
        L->prox = pushMiddle(L, L->prox, elem, posicao-1);
        return L;
    }
    old = actual;
    actual = actual->prox;
    
    // Create a new node with the info
    TLSE *novo = (TLSE*) malloc(sizeof(TLSE));
    novo->info = elem;

    // Add in the middle of 2 nodes
    novo->prox = actual;
    old->prox = novo;
    return novo;
}
TLSE *pushEnd (TLSE *L, int elem)
{
    // CASE 1: empty/null List
    if(!L->prox) // L->next == NULL
    {
        L = pushStart(L, elem);
        return L;
    }

    // CASE 2: not empty/null List
    TLSE *LSE_aux = L->prox;
    while(LSE_aux->prox) // while LSE_aux->next != NULL)
        LSE_aux = LSE_aux->prox;
    
    TLSE *novo = (TLSE*) malloc(sizeof(TLSE));
    novo->info = elem;
    novo->prox = NULL;
    LSE_aux->prox = novo;
    return L;
}

TLSE *search(TLSE *l, int elem)
{
    TLSE *aux = l->prox;
    while((aux) && (aux->info != elem)) // while aux != NULL and ...
        aux = aux->prox;
    return aux;
}

TLSE *pop(TLSE *l, int elem)
{
    TLSE *actual = l->prox;
    TLSE *old = l;
    while((actual) && (actual->info != elem))
    {
        old = actual;
        actual = actual->prox;
    }
    // CASE 1: I didnt find the element
    if(!actual) // actual == NULL
        return l;
    // CASE 2: Its the first of the list
    if(old == l) // old == NO Cabeça
        l->prox = actual->prox;
    // CASE 3: Its in the middle/final
    else 
        old->prox = actual->prox;
    return l;
}

int main()
{
    TLSE *L = initialize();
    int size, elem;
    printf("Type the size of the list: ");
    scanf("%d", &size);
    
    for (int i=0;i<size;i++)
    {
        printf("Type what element do you want to add: ");
        scanf("%d", &elem);
        L = pushEnd (L, elem);
    }

    L = pushMiddle(NULL, L, 2, 2);
    print(L);
    
    printf("Type what element do you want to remove: ");
    scanf("%d", &elem);
    L = pop(L,elem);
    print(L);

    printf("Type what element do you want to search: ");
    scanf("%d", &elem);
    TLSE *noDeBusca = search(L, elem);
    if (noDeBusca)
        printf("\nFound Node! Node: %d", noDeBusca->info);
    else
        printf("\nNode not found!");
    return 0;
}