#include<stdio.h>
#include<stdlib.h>

typedef struct NODE 
{
    int data;
    struct NODE *next;
}CL;

CL *initialize()
{
    CL *L = (CL*) malloc(sizeof(CL));
    L->next = NULL;
    return L;
}

CL *pushStart (CL *L, int elem)
{
    CL *novo = (CL*) malloc(sizeof(CL));
    novo->data = elem;
    novo->next = L->next;
    L->next = novo;
    return L;
}
CL *pushMiddle(CL *old, CL *L, int elem, int posicao)
{
    // CASE 1: empty/null List
    if(!L->next || posicao == 0) // L->next == NULL
    {
        L = pushStart(L, elem);
        return L;
    }

    // CASE 2: not empty/null List
    CL * actual = L;
    if (posicao>1)
    {
        L->next = pushMiddle(L, L->next, elem, posicao-1);
        return L;
    }
    old = actual;
    actual = actual->next;
    
    // Create a new node with the info
    CL *novo = (CL*) malloc(sizeof(CL));
    novo->data = elem;

    // Add in the middle of 2 nodes
    novo->next = actual;
    old->next = novo;
    return novo;
}
CL *pushEnd (CL *L, int elem)
{
    // CASE 1: empty/null List
    if(!L->next) // L->next == NULL
    {
        L = pushStart(L, elem);
        return L;
    }

    // CASE 2: not empty/null List
    CL *LSE_aux = L->next;
    while(LSE_aux->next) // while LSE_aux->next != NULL)
        LSE_aux = LSE_aux->next;
    
    CL *novo = (CL*) malloc(sizeof(CL));
    novo->data = elem;
    novo->next = NULL;
    LSE_aux->next = novo;
    return L;
}

CL *search(CL *l, int elem)
{
    CL *aux = l->next;
    while((aux) && (aux->data != elem)) // while aux != NULL and ...
        aux = aux->next;
    return aux;
}

CL *pop(CL *l, int elem)
{
    CL *actual = l->next;
    CL *old = l;
    while((actual) && (actual->data != elem))
    {
        old = actual;
        actual = actual->next;
    }
    // CASE 1: I didnt find the element
    if(!actual) // actual == NULL
        return l;
    // CASE 2: Its the first of the list
    if(old == l) // old == NO Cabeça
        l->next = actual->next;
    // CASE 3: Its in the middle/final
    else 
        old->next = actual->next;
    return l;
}

int main()
{
    CL *L = initialize();
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
    CL *noDeBusca = search(L, elem);
    if (noDeBusca)
        printf("\nFound Node! Node: %d", noDeBusca->data);
    else
        printf("\nNode not found!");
    return 0;
}