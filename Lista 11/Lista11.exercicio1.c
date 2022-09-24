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

Elemento* filtra (Elemento* lst, float min, float max)
{
    Elemento* ant = lst;
    if (ant == NULL)
    {
        return ant;
    }
    Elemento* atual = ant->prox;
    if (atual == NULL)
    {
        if (ant->info < min || ant->info > max)
        {
            ant = NULL;
            return ant;
        }
        else
        {
            return ant;
        }
    }
    if ((ant!=NULL) && (ant->info<min || ant->info>max))
    {
        Elemento *temp = ant;
        ant = ant->prox;
        lst = ant;
        free(temp);
    }
    while (atual!=NULL)
    {
        if (atual->info < min || atual->info > max)
        {
            Elemento *temp = atual;
            ant->prox = atual->prox;
            atual = atual->prox;
            free(temp);
        }
        else
        {
            ant = atual;
            atual = atual->prox;
        }
    }
    return lst;
}

void main()
{
    int tam,Novotam=0;
    int i, indice=0;
    float min, max;
    printf("Digite a quantidade de nodes: ");
    scanf(" %d", &tam);
    printf("Digite um valor minimo qualquer: ");
    scanf(" %f", &min);
    printf("Digite um valor maximo qualquer: ");
    scanf(" %f", &max);

    Elemento *lista = NULL;

    for (i=0;i<tam;i++)
    {
        lista = preenche(lista, i);
    }

    lista = filtra(lista,min,max);
    Elemento *pos = lista;
    while (pos!= NULL)
    {
        Novotam++;
        pos=pos->prox;
    }
    
    while (lista!=NULL)
    {
        printf("\nInfo %d do vetor de structs: ", indice+1);
        printf(" %f", lista->info);
        Elemento *temp = lista;
        lista = lista->prox;
        free(temp);
        indice+=1;
    }
}