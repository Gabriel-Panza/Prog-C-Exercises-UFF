#include<stdio.h>
#include<stdlib.h>

typedef struct FILA_ENCADEADA
{
    int dado;
    struct FILA_ENCADEADA *prox;
}FilaEnc;

FilaEnc* inicializa()
{
    return NULL;
}

FilaEnc* insere(FilaEnc *f, int num)
{
    // CASO 1: Fila vazia/nula
    if (!f) // f==NULL
    {
        FilaEnc *novo = (FilaEnc*) malloc(sizeof(FilaEnc));
        novo->dado = num;
        novo->prox = NULL;
        return novo;
    }

    // CASO 2: Fila nao vazia/nula
    FilaEnc *aux = f;
    while(aux->prox) // aux->prox != NULL
        aux = aux->prox;

    // PReencho os dados do ultimo elemento
    FilaEnc *novo = (FilaEnc*) malloc(sizeof(FilaEnc));
    novo->dado = num;
    novo->prox = NULL;
    // Faço com que o proximo do antigo ultimo receba o novo ultimo
    aux->prox = novo;
    return f;

}

FilaEnc* remover(FilaEnc *f)
{
    if (!f) // f==NULL
        return f;
    return f->prox;
}

void printa(FilaEnc *f)
{
    FilaEnc *aux = f;
    while(aux) // aux != NULL 
    {
        printf("[%d]->", aux->dado);
        aux = aux->prox;
    }
    printf("\n");
}

int main()
{
    FilaEnc *f = inicializa();

    f = insere(f, 1);
    f = insere(f, 2);
    f = insere(f, 3);
    f = insere(f, 4);
    f = insere(f, 5);

    printa(f);

    f = remover(f);

    printa(f);

    f = insere(f,6);

    printa(f);
}