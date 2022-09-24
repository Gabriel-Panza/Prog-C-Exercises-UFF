#include <stdio.h>
#include <locale.h>
#define N 10

float media(int n, float *v){
    float soma = 0;
    for (int i = 0; i < n; i++)
    {
        soma += v[i];
    }
    return soma/n;
}

void main()
{
    float valores[N];

    for (int i = 0; i < N; i++)
    {
        printf("Insira o valor %d:" , i + 1);
        scanf("%f", &valores[i]);
    }

    printf("Calculei! A media desses valores e: %.2f", media(N, valores));
}

