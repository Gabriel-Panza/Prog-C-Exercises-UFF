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

PilhaEnc* insere(PilhaEnc *p, int num)
{
    PilhaEnc *novo = (PilhaEnc*) malloc(sizeof(PilhaEnc));
    novo->dado = num;
    novo->prox = p;
    return novo;
}
 
PilhaEnc* remover(PilhaEnc *p)
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

    p = insere(p, 1);
    p = insere(p, 2);
    p = insere(p, 3);
    p = insere(p, 4);
    p = insere(p, 5);

    printa(p);

    p = remover(p);

    printa(p);

    p = insere(p,6);

    printa(p);
}