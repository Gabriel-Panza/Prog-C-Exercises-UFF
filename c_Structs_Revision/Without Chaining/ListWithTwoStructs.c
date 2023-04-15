#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PRODUCT
{
    int code;
    char name[21];
    float price;
}Prod;

typedef struct StaticList
{
    Prod *products;
    int total;
}SL;

SL initialize(SL l, int size)
{
    Prod *prodAux = (Prod*) malloc(size * sizeof(Prod));
    l.products = prodAux;
    return l;
}

int search (SL *L, int elem, int *pos)
{
    if (L->total>0)
    {
        while (*pos<L->total && L->products[*pos].code != elem)
            *pos+=1;
        
        if (*pos<L->total)
            return 1;

        return -1;
    }
    return -1;
}

void push(SL *list, int newCode, char *newName, float newPrice, int size)
{
    if (list->total < size)
    {
        int pos=0;
        if(search(list, newCode, &pos) != 1)
        {
            Prod prodAux;
            prodAux.code = newCode;
            strcpy(prodAux.name,newName);
            prodAux.price = newPrice;
            
            list->products[list->total] = prodAux;
            list->total++;
        }
    }
    else
    {
        printf("Error! List is full!");
    }
}

void pop (SL *list, int newCode)
{
    int positionOfTheElementWantRemove=0;
    if (search(list, newCode, &positionOfTheElementWantRemove) != -1)
    {
        for (int i=positionOfTheElementWantRemove;i<(list->total-1);i++)
        {
            list->products[i] = list->products[i+1];
        }
        list->total-=1;
    }
    else
        printf("There isnt a product with this code: %d", newCode);
}

void print(SL *L)
{
    for (int i = 0; i<L->total; i++)
    {
        printf("\nProduct %d:\n", i+1);
        printf("%d\n", L->products[i].code);
        printf("%s\n", L->products[i].name);
        printf("%.2f\n", L->products[i].price);
    }
    printf("\n");
}

int main()
{
    char *nome;
    float price;
    int size, codigo;
    printf("Type how many products do you wanna buy: ");
    scanf("%d", &size);

    SL listaDeProdutos = initialize(listaDeProdutos,size);
    listaDeProdutos.total=0;

    for (int i=0;i<size;i++)
    {
        printf("Type the code: ");
        scanf("%d", &codigo);
        fflush(stdin);
        printf("Type the name of the product: ");
        gets(nome);
        fflush(stdin);
        printf("Type the price: ");
        scanf("%f", &price);
        fflush(stdin);
        push(&listaDeProdutos,codigo,nome,price,size);
    }
    print(&listaDeProdutos);

    printf("\nType the code you wanna remove: ");
    scanf("%d", &codigo);
    fflush(stdin);
    pop(&listaDeProdutos, codigo);
    print(&listaDeProdutos);

    return 0;
}