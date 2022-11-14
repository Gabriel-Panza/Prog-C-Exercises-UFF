#include<stdio.h>
#include<stdlib.h>

typedef struct PILHA_ENCADEADA
{
    int dado;
    struct PILHA_ENCADEADA *prox;
}PilhaEnc;

PilhaEnc* inicializa()
{
    return NULL;
}

PilhaEnc* push(PilhaEnc *p, int num)
{
    PilhaEnc *novo = (PilhaEnc*) malloc(sizeof(PilhaEnc));
    novo->dado = num;
    novo->prox = p;
    return novo;
}
 
PilhaEnc* pop(PilhaEnc *p)
{
    if (!p) // p==NULL
        return p;
    return p->prox;
}

void printa(PilhaEnc *p)
{
    PilhaEnc *aux = p;
    while(aux) // aux != NULL
    {
        printf("[%d]->", aux->dado);
        aux = aux->prox;
    }
    printf("\n");
}

int main()
{
    PilhaEnc *p = inicializa();

    p = push(p, 1);
    p = push(p, 2);
    p = push(p, 3);
    p = push(p, 4);
    p = push(p, 5);

    printa(p);

    p = pop(p);

    printa(p);

    p = push(p,6);

    printa(p);
}