#include<stdio.h>
#include<stdlib.h>

typedef struct CHAINING_QUEUE
{
    int data;
    struct CHAINING_QUEUE *next;
}QueueChain;

QueueChain* initialize()
{
    return NULL;
}

QueueChain* push(QueueChain *f, int num)
{
    // CASE 1: empty/null Queue
    if (!f) // f==NULL
    {
        QueueChain *new = (QueueChain*) malloc(sizeof(QueueChain));
        new->data = num;
        new->next = NULL;
        return new;
    }

    // CASE 2: not empty/null Queue
    QueueChain *aux = f;
    while(aux->next) // aux->next != NULL
        aux = aux->next;

    // Add all the info into the last element
    QueueChain *new = (QueueChain*) malloc(sizeof(QueueChain));
    new->data = num;
    new->next = NULL;
    // The old last element point to the new last element
    aux->next = new;
    return f;

}

QueueChain* pop(QueueChain *f)
{
    if (!f) // f==NULL
        return f;
    return f->next;
}

void print(QueueChain *f)
{
    QueueChain *aux = f;
    while(aux) // aux != NULL 
    {
        printf("[%d]->", aux->data);
        aux = aux->next;
    }
    printf("\n");
}

int main()
{
    QueueChain *f = initialize();

    f = push(f, 1);
    f = push(f, 2);
    f = push(f, 3);
    f = push(f, 4);
    f = push(f, 5);

    print(f);

    f = pop(f);

    print(f);

    f = push(f,6);

    print(f);
}