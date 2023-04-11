#include<stdio.h>
#include<stdlib.h>

typedef struct NODE 
{
    int data;
    struct NODE *next;
}CL;

CL *initialize()
{
    return NULL;
}

CL *pushStart(CL *L, int elem)
{
    CL *new = (CL*) malloc(sizeof(CL));
    new->data = elem;
    new->next = L;
    return new;
}
CL *pushMiddle(CL *old, CL *L, int elem, int position) // Only works with valid positions
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
CL *pushEnd(CL *L, int elem)
{
    CL *new = pushStart(NULL,elem);
    // CASE 1: empty/null List
    if(!L) // L == NULL
        return new;

    // CASE 2: not empty/null List
    CL *LSE_aux = L;
    while(LSE_aux->next) // while (LSE_aux->next != NULL)
        LSE_aux = LSE_aux->next;
    
    LSE_aux->next = new;
    return L;
}
CL *pushEnd_rec(CL *L, int elem)
{
    if (!L)
        return pushStart(L,elem);
    L->next = pushEnd_rec(L->next,elem);
    return L;
}
CL *pushSorted(CL *L, int elem) // Only works with sorted lists
{
    CL *LSE_aux_old = NULL;
    CL *LSE_aux = L;
    while(LSE_aux && LSE_aux->data < elem) // while (LSE_aux != NULL and LSE_aux->info < elem)
    {
        LSE_aux_old = LSE_aux;
        LSE_aux = LSE_aux->next;
    }

    // CASE 1: empty/null List
    if (LSE_aux_old==NULL)
        return pushStart(NULL,elem);
    // CASE 2: not empty/null List

    LSE_aux_old->next = pushStart(LSE_aux,elem);
    return L;
    
}
CL *pushSorted_rec(CL *L, int elem) // Only works with sorted lists
{
    if((!L) || (L->data >= elem))
        return pushStart(L,elem);
    L->next = pushSorted_rec(L->next,elem);
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
    CL *actual = l;
    CL *old = NULL;
    while((actual) && (actual->data != elem))
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

void freeAll(CL *L)
{
    CL *aux = L;
    CL *temp;
    while(aux!=NULL)
    {
        temp = aux;
        aux=aux->next;
        free(temp);
    }
}
void freeAll_rec(CL *L)
{
    if(L)
    {
        freeAll(L->next);
        free(L);
    }
}

void print(CL *L)
{
    CL *aux = L;
    while(aux)
    {
        printf("[%d]->", aux->data);
        aux = aux->next; 
    }
    printf("\n");
}
void print_rec(CL *L)
{
    if(L)
    {
        printf("[%d]->", L->data);
        print_rec(L->next);
    }
    printf("\n");
}
void print_inv(CL *L)
{
    CL *aux = L;
    CL *L_aux = initialize();
    while(aux)
    {
        L_aux = pushStart(L_aux, aux->data);
        aux = aux->next;
    }
    print(L_aux);
    freeAll(L_aux);
}
void print_inv_rec(CL *L)
{
    if (L->next)
        print_inv_rec(L->next);
    printf("<-[%d]", L->data);
}

int main()
{
    CL *L = initialize();
    int size, elem;
    printf("Type what is the size of the list: ");
    scanf("%d", &size);
    
    for (int i=0;i<size;i++)
    {
        printf("Type what element do you want to add: ");
        scanf("%d", &elem);
        L = pushEnd (L, elem);
    }

    L = pushMiddle(NULL, L, 2, 2);
    print(L);
    print_inv(L);

    printf("\n\n");

    L = pop(L,0);
    print(L);
    print_inv(L);
    
    CL *noDeBusca = search_rec(L, 4);
    if (noDeBusca)
        printf("\nNode found! Node: %d", noDeBusca->data);
    else
        printf("\nNode not found!");
    
    freeAll(L);
    freeAll(noDeBusca);

    return 0;
}