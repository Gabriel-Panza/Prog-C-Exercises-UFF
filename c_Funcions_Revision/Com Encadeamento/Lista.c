#include<stdio.h>
#include<stdlib.h>

typedef struct NO 
{
    int info;
    struct NO *prox;
}LSE;

LSE *inicializa()
{
    return NULL;
}

LSE *insereNoInicio (LSE *L, int elem)
{
    LSE *novo = (LSE*) malloc(sizeof(LSE));
    novo->info = elem;
    novo->prox = L;
    return novo;
}
LSE *insereNoMeio(LSE *ant, LSE *L, int elem, int posicao)
{
    // CASO 1: LISTA VAZIA/NULA
    if(!L) // L == NULL
    {
        L = insereNoInicio(L, elem);
        return L;
    }

    // CASO 2: LISTA NAO VAZIA/NULA
    if (posicao>0)
    {
        L->prox = insereNoMeio(L, L->prox, elem, posicao-1);
        return L;
    }
    // Crio um novo nó com as informaçoes
    LSE *novo = (LSE*) malloc(sizeof(LSE));
    novo->info = elem;

    // Insiro no meio dos 2 ponteiros
    novo->prox = L;
    ant->prox = novo;
    return novo;
}
LSE *insereNoFinal (LSE *L, int elem)
{
    // CASO 1: LISTA VAZIA/NULA
    if(!L) // L == NULL
    {
        L = insereNoInicio(L, elem);
        return L;
    }

    // CASO 2: LISTA NAO VAZIA/NULA
    LSE *LSE_aux = L;
    while(LSE_aux->prox) // Enquanto o proximo de LSE_aux existir (enquanto LSE_aux != NULL)
        LSE_aux = LSE_aux->prox;
    
    LSE *novo = (LSE*) malloc(sizeof(LSE));
    novo->info = elem;
    novo->prox = NULL;
    LSE_aux->prox = novo;
    return L;
}

LSE* busca(LSE *l, int elem)
{
    LSE *percorre = l;
    while((percorre) && (percorre->info != elem)) // enquanto percorre != NULL  e  percorre->info != elem
        percorre = percorre->prox;
    return percorre;
}
LSE* busca_rec(LSE *l, int elem)
{
    if((!l) || (l->info == elem)) // se l == NULL ou l == nó desejado, retorno
        return l;
    return busca_rec(l->prox, elem);
}

LSE* retira(LSE *l, int elem)
{
    LSE *atual = l;
    LSE *ant = NULL;
    while((atual) && (atual->info != elem))
    {
        ant = atual;
        atual = atual->prox;
    }
    // CASO 1: Percorri tudo e nao encontrei
    if(!atual) // atual == NULL
    {
        printf("Nao houve remocao, pois nao encontrei o elemento desejado");
        return l;
    }
    // CASO 2: O elemento que quero remover eh o primeiro da lista
    if(!ant) // ant == NULL
        l = l->prox;
    // CASO 3: Ta no meio/final
    else 
        ant->prox = atual->prox;
    return l;
}
LSE* retira_rec(LSE *l, int elem)
{
    // CASO 1
    if(!l)  // l == NULL
        return l;
    // CASO 2
    if(l->info == elem)
        l = l->prox;
    // CASO 3
    else 
        l->prox = retira_rec(l->prox, elem);
    return l;
}

void printa(LSE *L)
{
    LSE *LE_aux = L;
    while(LE_aux)
    {
        printf("[%d]->", LE_aux->info);
        LE_aux = LE_aux->prox; 
    }
    printf("\n");
}

int main()
{
    LSE *L = inicializa();
    
    L = insereNoFinal (L, 5);
    L = insereNoFinal (L, 4);
    L = insereNoFinal (L, 1);

    L = insereNoMeio(NULL, L, 2, 2);
    L = insereNoMeio(NULL, L, 3, 2);
    printa(L);
    
    L = retira(L,4);
    printa(L);
    
    L = ordena(L, 4);
    printa(L);

    LSE *noDeBusca = busca_rec(L, 5);
    if (noDeBusca)
    {
        printf("Encontrei o no! No: %d", noDeBusca->info);
    }
    else
    {
        printf("No nao encontrado!");
    }
    return 0;
}