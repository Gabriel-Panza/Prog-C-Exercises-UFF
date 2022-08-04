#include <stdio.h>

int main()
{
    int a, b, c;
    int maior, menor;
    float media;

    printf("Digite o primeiro numero: \n");
    scanf("%d", &a);
    printf("Digite o segundo numero: \n");
    scanf("%d", &b);
    printf("Digite o terceiro numero: \n");
    scanf("%d", &c);

    //Pegando os menores//
    if (a <= b && a <= c)
    {
        menor = a;
    }
    else if (b <= a && b <= c)
    {
        menor = b;
    }
    else if (c <= a && c <= b)
    {
        menor = c;
    }

    //Pegando os maiores//
    if (a >= b && a >= c)
    {
        maior = a;
    }
    else if (b >= a && b >= c)
    {
        maior = b;
    }
    else if (c >= a && c >= b)
    {
        maior = c;
    }

    printf("O maior numero e: %d\n", maior);
    printf("O menor numero e: %d\n", menor);

    //Pegando os pares//
    if (a % 2 == 0)
    {
        printf("%d e par\n", a);
    }
    if (b % 2 == 0)
    {
        printf("%d e par\n", b);
    }
    if (c % 2 == 0)
    {
        printf("%d e par\n", c);
    }

    //Calculando a média//
    media = (a + b + c) / 3;

    printf("A media e: %.2f\n", media);

    return 0;
}
