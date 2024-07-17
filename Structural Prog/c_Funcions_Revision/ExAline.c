#include <stdio.h>
#include <stdlib.h>

int M;

int comp(const void *n1, const void *n2){
    int number1 = *(int *)n1;
    int number2 = *(int *)n2;
    int modn1 = number1 % M,
        modn2 = number2 % M;

    // Caso haja empate
    if(modn1 == modn2){
        int parn1 = (number1 % 2 == 0) ? 1 : 0,
            parn2 = (number2 % 2 == 0) ? 1 : 0;

        if((!parn1) && (parn2)) 
        return -1;
        if((parn1) && (!parn2)) 
        return 1;
        if((!parn1) && (!parn2)) 
        return (number1 < number2) ? 1 : -1;
        if((parn1) && (parn2))
        return (number1 < number2) ? -1 : 1;
    }

    // Caso não haja empate
    return modn1 - modn2;
}

int main()
{
    int N, cont;

    scanf("%d", &N);
    scanf("%d", &M);

    while (N != 0 && M != 0)
    {
        int vetor[N];

        for (cont = 0; cont < N; cont++) {
            scanf("%d", &vetor[cont]);
        }

        qsort(vetor,N, sizeof(int),comp);

        for (cont = 0; cont < N; cont++) {
            printf("%d\n", vetor[cont]);
        }

        scanf("%d", &N);
        scanf("%d", &M);
    }
    printf("0 0\n");

    return 0;
}
