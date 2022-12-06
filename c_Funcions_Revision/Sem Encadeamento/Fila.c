#include<stdio.h>
#define MAX 5

typedef struct FILA
{
    int dado[MAX];
    int inicio,fim,total;
}fila;

void insere(fila *f, int num)
{
    if (f->total<MAX)
    {
        f->dado[f->fim] = num;
        f->fim+=1;
        f->fim = f->fim%MAX; 
        f->total++;
    }
    else
    {
        printf("fila ta cheia!");
    }
}

int remover(fila *f)
{
    int num;
    if(f->total>0)
    {
        num = f->dado[f->inicio];
        f->inicio+=1;
        f->inicio = f->inicio%MAX; 
        f->total--;
    }
    return num;
}

void printa(fila *f)
{
    for (int i = f->inicio%MAX; i<(f->total + f->inicio); i++)
    {
        printf("%d", f->dado[i%MAX]);
    }
    printf("\n");
}

int main()
{
    int num;
    fila f;
    f.inicio = 0;
    f.fim = 0;
    f.total = 0;

    insere(&f, 1);
    insere(&f, 2);
    insere(&f, 3);
    insere(&f, 4);
    insere(&f, 5);

    printa(&f);

    num = remover(&f);

    printa(&f);

    insere(&f,6);

    printa(&f);
}