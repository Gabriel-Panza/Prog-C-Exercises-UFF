#include<stdio.h>
#include<stdlib.h>

#define MAX 5

typedef struct PILHA {
 int dado[MAX];
 int indiceTopo;
}pilha; 

void push(pilha *P, int num)
{
    if (P->indiceTopo < MAX) 
    {
        P->dado[P->indiceTopo] = num;
        P->indiceTopo++;
    }
    else
        printf("Pilha cheia!");
}

int pop(pilha *P)
{
    int num;
    if(P->indiceTopo>=0)
    {
        num = P->dado[P->indiceTopo];
        P->indiceTopo--;
    }
    return num;
}

void libera(pilha *p)
{
    if (p->indiceTopo>=0)
    {
        free(p->dado);
        p->indiceTopo=0;
    }
}

void printa(pilha *p)
{
    int cont = p->indiceTopo;
    while(cont>=0) // aux != NULL
    {
        printf("[%d]->", p->dado[cont]);
        cont--;
    }
    printf("\n");
}

int main()
{
    pilha p;
    p.indiceTopo = 0;

    push(&p,1);
    push(&p,2);
    push(&p,3);
    push(&p,4);
    push(&p,5);
    printa(&p);
    int n = pop(&p);
    printa(&p);
    libera(&p);
    
    return 0;
}