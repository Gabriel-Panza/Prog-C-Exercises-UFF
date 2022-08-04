#include <stdio.h>
#include <stdlib.h>

struct elemento
{
    float info; /* Valor real armazenado */
    struct elemento *prox; /* Ponteiro para o proximo elemento */
};
typedef struct elemento Elemento;

Elemento *preenche(Elemento *lst, int indice)
{
    Elemento* pos = lst;
    Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
    if (novo==NULL)
    {
        printf("Error!");
        exit(1);
    }

    if (lst==NULL)
    {
        printf("Digite o elemento %d: ",indice+1);
        scanf(" %f", &novo->info);
        novo->prox = NULL;
        return novo;
    }
    while (pos->prox!=NULL)
    {
        pos = pos->prox;
    }

    Elemento *final = pos;
    final->prox = novo;

    printf("Digite o elemento %d: ",indice+1);
    scanf(" %f", &novo->info);
    novo->prox = NULL;

    return lst;
}

Elemento* copia(Elemento* lst)
{
    Elemento* copiar = lst; 
    return copiar;
}

void main()
{
    int i,indice=0,tam;
    printf("Digite o tamanho da lista: ");
    scanf(" %d", &tam);

    Elemento *lista = NULL;
    for (i=0;i<tam;i++)
    {
        lista = preenche(lista, i);
    }

    Elemento *lstCopiada = copia(lista);
    while (lstCopiada != NULL)
    {
        printf("\nInfo %d do vetor copiado: ", indice+1);
        printf(" %f", lstCopiada->info);
        Elemento *temp = lstCopiada;
        lstCopiada = lstCopiada->prox;
        free(temp);
        indice+=1;
    }
}
