#include<stdio.h>
#include<stdlib.h>

typedef struct STACK_CHAINING
{
    int data;
    struct STACK_CHAINING *next;
}SC;

SC* initialize()
{
    return NULL;
}

SC* push(SC *p, int num)
{
    SC *novo = (SC*) malloc(sizeof(SC));
    novo->data = num;
    novo->next = p;
    return novo;
}
 
SC* pop(SC *p)
{
    if (!p) // p==NULL
        return p;
    return p->next;
}

void print(SC *p)
{
    SC *aux = p;
    while(aux) // aux != NULL
    {
        printf("[%d]->", aux->data);
        aux = aux->next;
    }
    printf("\n");
}

void freeAll(SC *p)
{
    if (p->next) // p->next==NULL
        freeAll(p->next);
    
    free(p);
}

int main()
{
    SC *p = initialize();

    p = push(p, 1);
    p = push(p, 2);
    p = push(p, 3);
    p = push(p, 4);
    p = push(p, 5);

    print(p);

    p = pop(p);

    print(p);

    p = push(p,6);

    print(p);
}