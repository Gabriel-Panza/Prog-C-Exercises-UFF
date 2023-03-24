#include<stdio.h>
#include<stdlib.h>

typedef struct NO 
{
    int data;
    struct NO *next;
}CL;

CL *initialize()
{
    return NULL;
}

CL *pushStart (CL *L, int elem)
{
    CL *new = (CL*) malloc(sizeof(CL));
    new->data = elem;
    new->next = L;
    return new;
}
CL *pushMiddle(CL *old, CL *L, int elem, int position)
{
    // CASE 1: empty/null List
    if(!L || position == 0) // L == NULL
    {
        L = pushStart(L, elem);
        return L;
    }

    // CASE 2: not empty/null List
    CL* atual = L;
    if (position>1)
    {
        L->next = pushMiddle(L, L->next, elem, position-1);
        return L;
    }
    old = atual;
    atual = atual->next;

    // Create a new node with the info
    CL *new = (CL*) malloc(sizeof(CL));
    new->data = elem;

    // Add in the middle of 2 nodes
    new->next = atual;
    old->next = new;
    return old;
}
CL *pushEnd (CL *L, int elem)
{
    // CASE 1: empty/null List
    if(!L) // L == NULL
    {
        L = pushStart(L, elem);
        return L;
    }

    // CASE 2: not empty/null List
    CL *LSE_aux = L;
    while(LSE_aux->next) // while LSE_aux->next != NULL)
        LSE_aux = LSE_aux->next;
    
    CL *new = (CL*) malloc(sizeof(CL));
    new->data = elem;
    new->next = NULL;
    LSE_aux->next = new;
    return L;
}

CL* search(CL *l, int elem)
{
    CL *aux = l;
    while((aux) && (aux->data != elem)) // while aux != NULL and ...
        aux = aux->next;
    return aux;
}
CL* search_rec(CL *l, int elem)
{
    if((!l) || (l->data == elem)) // while l == NULL or l == node wanted, return
        return l;
    return search_rec(l->next, elem);
}

CL* pop(CL *l, int elem)
{
    CL *atual = l;
    CL *old = NULL;
    while((atual) && (atual->data != elem))
    {
        old = atual;
        atual = atual->next;
    }
    // CASE 1: I didnt find the element
    if(!actual) // actual == NULL
        return l;
    // CASE 2: Its the first of the list
    if(!old) // old == NULL
        l = l->next;
    // CASE 3: Its in the middle/final
    else 
        old->next = actual->next;
    return l;
}
CL* pop_rec(CL *l, int elem)
{
    // CASE 1
    if(!l)  // l == NULL
        return l;
    // CASE 2
    if(l->data == elem)
        l = l->next;
    // CASE 3
    else 
        l->next = pop_rec(l->next, elem);
    return l;
}

void print(CL *L)
{
    CL *LE_aux = L;
    while(LE_aux)
    {
        printf("[%d]->", LE_aux->data);
        LE_aux = LE_aux->next; 
    }
    printf("\n");
}

int main()
{
    CL *L = initialize();
    int size, elem;
    printf("Type what is the size of the list: ")
    scanf("%d", &size);
    
    for (int i=0;i<size;i++)
    {
        printf("Type what element do you want to add: ")
        scanf("%d", &elem);
        L = pushEnd (L, elem);
    }

    L = pushMiddle(NULL, L, 2, 2);
    print(L);
    
    L = pop(L,4);
    print(L);

    CL *noDeBusca = search_rec(L, 5);
    if (noDeBusca)
        printf("Node found! Node: %d", noDeBusca->data);
    else
        printf("Node not found!");
    return 0;
}