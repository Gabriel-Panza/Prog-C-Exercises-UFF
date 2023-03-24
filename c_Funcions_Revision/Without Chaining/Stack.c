#include<stdio.h>
#include<stdlib.h>

#define MAX 5

typedef struct STACK {
 int data[MAX];
 int indexTop;
}Stack; 

void push(Stack *P, int num)
{
    if (P->indexTop < MAX) 
    {
        P->data[P->indexTop] = num;
        P->indexTop++;
    }
    else
        printf("Stack full!");
}

int pop(Stack *P)
{
    int num;
    if(P->indexTop>=0)
    {
        num = P->data[P->indexTop];
        P->indexTop--;
    }
    return num;
}

void freeAll(Stack *p)
{
    if (p->indexTop>=0)
    {
        free(p->data);
        p->indexTop=0;
    }
}

void print(Stack *p)
{
    int cont = p->indexTop;
    while(cont>=0) // aux != NULL
    {
        printf("[%d]->", p->data[cont]);
        cont--;
    }
    printf("\n");
}

int main()
{
    Stack p;
    p.indexTop = 0;

    push(&p,1);
    push(&p,2);
    push(&p,3);
    push(&p,4);
    push(&p,5);
    print(&p);
    int n = pop(&p);
    print(&p);
    freeAll(&p);
    
    return 0;
}