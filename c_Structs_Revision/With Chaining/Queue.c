#include<stdio.h>
#include<stdlib.h>

typedef struct CHAINING_QUEUE
{
    int data;
    struct CHAINING_QUEUE *next;
}QC;

QC* initialize()
{
    return NULL;
}

QC* push(QC *f, int num)
{
    // CASE 1: empty/null Queue
    if (!f) // f==NULL
    {
        QC *new = (QC*) malloc(sizeof(QC));
        new->data = num;
        new->next = NULL;
        return new;
    }

    // CASE 2: not empty/null Queue
    QC *aux = f;
    while(aux->next) // aux->next != NULL
        aux = aux->next;

    // Add all the info into the last element
    QC *new = (QC*) malloc(sizeof(QC));
    new->data = num;
    new->next = NULL;
    // The old last element point to the new last element
    aux->next = new;
    return f;

}

QC* pop(QC *f)
{
    if (!f) // f==NULL
        return f;
    return f->next;
}

void print(QC *f)
{
    QC *aux = f;
    while(aux) // aux != NULL 
    {
        printf("[%d]->", aux->data);
        aux = aux->next;
    }
    printf("\n");
}

int main()
{
    QC *f = initialize();

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