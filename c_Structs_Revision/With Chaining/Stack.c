#include<stdio.h>
#include<stdlib.h>

typedef struct STACK_CHAINING
{
    int data;
    struct STACK_CHAINING *next;
}StackChain;

StackChain* initialize()
{
    return NULL;
}

StackChain* push(StackChain *p, int num)
{
    StackChain *novo = (StackChain*) malloc(sizeof(StackChain));
    novo->data = num;
    novo->next = p;
    return novo;
}
 
StackChain* pop(StackChain *p)
{
    if (!p) // p==NULL
        return p;
    return p->next;
}

void print(StackChain *p)
{
    StackChain *aux = p;
    while(aux) // aux != NULL
    {
        printf("[%d]->", aux->data);
        aux = aux->next;
    }
    printf("\n");
}

void freeAll(StackChain *p)
{
    if (p->next) // p->next==NULL
        freeAll(p->next);
    
    free(p);
}

int main()
{
    StackChain *p = initialize();

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