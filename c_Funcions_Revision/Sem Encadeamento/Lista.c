#include<stdio.h>
#define MAX 5

typedef struct LISTA 
{
    int dado[MAX];
    int total;
}lista;

void insere (lista *L, int elem)
{
    if (L->total<MAX)
    {
        L->dado[L->total] = elem;
        L->total++;
    }
    else
    {
        printf("Nao foi possivel inserir, pois a lista esta cheia!");
    }
}

int busca (lista *L, int elem, int *pos)
{
    if (L->total>0)
    {
        while (*pos<L->total && L->dado[*pos] != elem)
        {
            *pos+=1;
        }
        
        if (*pos<L->total)
        {
            printf("\nEncontrei o elemento!\n")
            return L->dado[*pos];
        }
        printf("\nElemento nao encontrado para busca\n");
        return -1;
    }
    printf("\nElemento nao encontrado para busca, pois lista esta vazia\n");
    return -1;
}

int busca_binaria(lista *L, int elem, int inicio, int final)
{
    int meio = (inicio+final)/2;
    if (L->dado[inicio] == elem) 
    {
        printf("Encontrei o elemento!");
        return inicio;
    }
    if (L->dado[final] == elem)
    {            
        printf("Encontrei o elemento!");
        return final;
    }

    if (inicio != meio && final != meio)
    {
        if (L->dado[meio] == elem)
            printf("Encontrei o elemento!");
            return meio;
        if (L->dado[meio] < elem)
        {
            inicio = meio;
            busca_binaria(L, elem, inicio, final);
        }
        if (L->dado[meio] > elem)
        {
            final = meio;
            busca_binaria(L, elem, inicio, final);
        }
    }
    printf("Elemento nao encontrado!");
    return -1;
}

void remover (lista *L, int elem)
{
    int pos=0;
    if (busca(L,elem,&pos) != -1)
    {
        for (int i=pos;i<(L->total-1);i++)
        {
            L->dado[i] = L->dado[i+1];
        }
        L->dado[pos+1] = -1;
        L->total -= 1;
    }
}

void printa(lista *L)
{
    for (int i = 0; i<L->total; i++)
    {
        printf("%d,", L->dado[i]);
    }
    printf("\n");
}

void ordena(lista *L)
{
    for(int i = 0; i<L->total; i++)
    {
        for(int j = 0; j<(L->total-1); j++)
        {
            if (L->dado[j] > L->dado[j+1])  
            {  
                int aux = L->dado[j];
                L->dado[j] = L->dado[j+1];
                L->dado[j+1] = aux;
            }
        }
    }
}

int main()
{
    lista L;
    L.total=0;
    int elem = 1, pos = 0;

    insere (&L, elem);
    insere (&L, elem+1);
    insere (&L, elem+2);
    
    busca (&L, elem+1, &pos);
    printa(&L);

    busca_binaria (&L, elem+4, 0, L.total-1);
    printa(&L);

    return 0;
}