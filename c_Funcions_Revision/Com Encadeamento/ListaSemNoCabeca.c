#include<stdio.h>
#include<stdlib.h>

typedef struct NO 
{
    int dado;
    struct NO *prox;
}LSE;

LSE *inicializa()
{
    return NULL;
}

LSE *insereNoInicio (LSE *L, int elem)
{
    LSE *novo = (LSE*) malloc(sizeof(LSE));
    novo->dado = elem;
    novo->prox = L;
    return novo;
}
LSE *insereNoMeio(LSE *ant, LSE *L, int elem, int posicao)
{
    // CASO 1: LISTA VAZIA/NULA
    if(!L || posicao == 0) // L == NULL
    {
        L = insereNoInicio(L, elem);
        return L;
    }

    // CASO 2: LISTA NAO VAZIA/NULA
    LSE* atual = L;
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
    novo->dado = elem;
    novo->prox = NULL;
    LSE_aux->prox = novo;
    return L;
}

LSE* busca(LSE *l, int elem)
{
    LSE *percorre = l;
    while((percorre) && (percorre->dado != elem)) // enquanto percorre != NULL  e  percorre->info != elem
        percorre = percorre->prox;
    return percorre;
}
LSE* busca_rec(LSE *l, int elem)
{
    if((!l) || (l->dado == elem)) // se l == NULL ou l == nó desejado, retorno
        return l;
    return busca_rec(l->prox, elem);
}

LSE* retira(LSE *l, int elem)
{
    LSE *atual = l;
    LSE *ant = NULL;
    while((atual) && (atual->dado != elem))
    {
        ant = atual;
        atual = atual->prox;
    }
    // CASO 1: Percorri tudo e nao encontrei
    if(!atual) // atual == NULL
        return l;
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
    if(l->dado == elem)
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
        printf("[%d]->", LE_aux->dado);
        LE_aux = LE_aux->prox; 
    }
    printf("\n");
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
    
    L = retira(L,4);
    printa(L);

    LSE *noDeBusca = busca_rec(L, 5);
    if (noDeBusca)
        printf("Encontrei o no! No: %d", noDeBusca->dado);
    else
        printf("No nao encontrado!");
    return 0;
}