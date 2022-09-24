#include <stdio.h>
void Fibonacci(int num)
{
    int i, proxTermo, numAnterior=1, numFinal=1, somaFib=2;

    if (num==1)
        printf("%d", numFinal);

    if (num==2)
    {
        printf("%d ", numFinal);
        printf("%d ", numAnterior);
    }
    else if (num>=3)
    {
        printf("%d ", numFinal);
        printf("%d ", numAnterior);
        for (i=2;i<num;i++)
        {
            somaFib = numFinal + numAnterior;
            numAnterior = numFinal;
            numFinal = somaFib;
            printf("%d ", somaFib);
        }
    }
}
void main()
{
    int n;
    printf("Digite quantos numeros a sequencia de Fibonacci deve ter: ");
    scanf("%d", &n);
    Fibonacci(n);
}
