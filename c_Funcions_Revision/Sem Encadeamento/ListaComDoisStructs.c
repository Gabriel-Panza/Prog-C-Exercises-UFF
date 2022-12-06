#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct produto
{
    int codigo;
    char nome[21];
    float preco;
}prod;

typedef struct ListaSequencialEstatica
{
    prod *produtos;
    int total;
}LSE;

LSE inicializa(LSE l, int tam)
{
    prod *prodAux = (prod*) malloc(tam * sizeof(prod));
    l.produtos = prodAux;
    return l;
}

int busca (LSE *L, int elem, int *pos)
{
    if (L->total>0)
    {
        while (*pos<L->total && L->produtos[*pos].codigo != elem)
            *pos+=1;
        
        if (*pos<L->total)
            return 1;

        return -1;
    }
    return -1;
}

void insere(LSE *lista, int codigoNovo, char *nomeNovo, float precoNovo, int tam)
{
    if (lista->total < tam)
    {
        int pos=0;
        if(busca(lista, codigoNovo, &pos) != 1)
        {
            prod prodAux;
            prodAux.codigo = codigoNovo;
            strcpy(prodAux.nome,nomeNovo);
            prodAux.preco = precoNovo;
            
            lista->produtos[lista->total] = prodAux;
            lista->total++;
        }
    }
    else
    {
        printf("Nao foi possivel inserir, pois a lista esta cheia!");
    }
}

void remover (LSE *lista, int codigoNovo)
{
    int posicaoDoElementoQueroRemover=0;
    if (busca(lista, codigoNovo, &posicaoDoElementoQueroRemover) != -1)
    {
        for (int i=posicaoDoElementoQueroRemover;i<(lista->total-1);i++)
        {
            lista->produtos[i] = lista->produtos[i+1];
        }
        lista->total-=1;
    }
    else
        printf("Nao tem nenhum produto com este codigo: %d", codigoNovo);
}

void printa(LSE *L)
{
    for (int i = 0; i<L->total; i++)
    {
        printf("\nproduto %d:\n", i+1);
        printf("%d\n", L->produtos[i].codigo);
        printf("%s\n", L->produtos[i].nome);
        printf("%.2f\n", L->produtos[i].preco);
    }
    printf("\n");
}

int main()
{
    char *nome;
    float preco;
    int tam, codigo;
    printf("Informe quantos produtos deseja comprar: ");
    scanf("%d", &tam);

    LSE listaDeProdutos = inicializa(listaDeProdutos,tam);
    listaDeProdutos.total=0;

    for (int i=0;i<tam;i++)
    {
        printf("Informe o codigo: ");
        scanf("%d", &codigo);
        fflush(stdin);
        printf("Informe o nome do produto: ");
        gets(nome);
        fflush(stdin);
        printf("Informe o preco: ");
        scanf("%f", &preco);
        fflush(stdin);
        insere(&listaDeProdutos,codigo,nome,preco,tam);
    }
    printa(&listaDeProdutos);

    printf("\nInforme o codigo que deseja retirar: ");
    scanf("%d", &codigo);
    fflush(stdin);
    remover(&listaDeProdutos, codigo);
    printa(&listaDeProdutos);

    return 0;
}