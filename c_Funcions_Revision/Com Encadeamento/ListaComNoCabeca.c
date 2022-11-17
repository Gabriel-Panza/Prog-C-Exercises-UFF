#include<stdio.h>
#include<stdlib.h>

typedef struct NO 
{
    int dado;
    struct NO *prox;
}LSE;

LSE *inicializa()
{
    LSE *L = (LSE*) malloc(sizeof(LSE));
    L->prox = NULL;
    return L;
}

LSE *insereNoInicio (LSE *L, int elem)
{
    LSE *novo = (LSE*) malloc(sizeof(LSE));
    novo->dado = elem;
    novo->prox = L->prox;
    L->prox = novo;
    return L;
}
LSE *insereNoMeio(LSE *ant, LSE *L, int elem, int posicao)
{
    // CASO 1: LISTA VAZIA/NULA
    if(!L->prox || posicao == 0) // L->prox == NULL
    {
        L = insereNoInicio(L, elem);
        return L;
    }

    // CASO 2: LISTA NAO VAZIA/NULA
    LSE * atual = L;
    if (posicao>1)
    {
        L->prox = insereNoMeio(L, L->prox, elem, posicao-1);
        return L;
    }
    ant = atual;
    atual = atual->prox;
    
    // Crio um novo nó com as informaçoes
    LSE *novo = (LSE*) malloc(sizeof(LSE));
    novo->dado = elem;

    // Insiro no meio dos 2 ponteiros
    novo->prox = atual;
    ant->prox = novo;
    return novo;
}
LSE *insereNoFinal (LSE *L, int elem)
{
    // CASO 1: LISTA VAZIA/NULA
    if(!L->prox) // L->prox == NULL
    {
        L = insereNoInicio(L, elem);
        return L;
    }

    // CASO 2: LISTA NAO VAZIA/NULA
    LSE *LSE_aux = L->prox;
    while(LSE_aux->prox) // Enquanto o proximo de LSE_aux existir (enquanto LSE_aux != NULL)
        LSE_aux = LSE_aux->prox;
    
    LSE *novo = (LSE*) malloc(sizeof(LSE));
    novo->dado = elem;
    novo->prox = NULL;
    LSE_aux->prox = novo;
    return L;
}

LSE* busca(LSE *l, int elem)
{
    LSE *percorre = l->prox;
    while((percorre) && (percorre->dado != elem)) // enquanto percorre != NULL  e  percorre->info != elem
        percorre = percorre->prox;
    return percorre;
}

LSE* retira(LSE *l, int elem)
{
    LSE *atual = l->prox;
    LSE *ant = l;
    while((atual) && (atual->dado != elem))
    {
        ant = atual;
        atual = atual->prox;
    }
    // CASO 1: Percorri tudo e nao encontrei
    if(!atual) // atual == NULL
        return l;
    // CASO 2: O elemento que quero remover eh o primeiro da lista
    if(ant == l) // ant == NULL
        l->prox = atual->prox;
    // CASO 3: Ta no meio/final
    else 
        ant->prox = atual->prox;
    return l;
}

int main()
{
    LSE *L = inicializa();
    int tam, elem;
    printf("Digite o tamanho da lista: ")
    scanf("%d", &tam);
    
    for (int i=0;i<tam;i++)
    {
        printf("Digite qual elemento deseja adicionar a lista: ")
        scanf("%d", &elem);
        L = insereNoFinal (L, elem);
    }

    L = insereNoMeio(NULL, L, 2, 2);
    printa(L);
    
    printf("Digite qual elemento deseja retirar da lista: ")
    scanf("%d", &elem);
    L = retira(L,elem);
    printa(L);

    printf("Digite qual elemento deseja buscar na lista: ")
    scanf("%d", &elem);
    LSE *noDeBusca = busca(L, elem);
    if (noDeBusca)
        printf("Encontrei o no! No: %d", noDeBusca->dado);
    else
        printf("No nao encontrado!");
    return 0;
}