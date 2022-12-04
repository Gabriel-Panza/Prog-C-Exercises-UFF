#include<stdio.h>
#include<string.h>
#include<stdbool.h>

bool ehPermutacao(char* a, char* b)
{
    int c[10] = {0,0,0,0,0,0,0,0,0,0};
    int tamA = strlen(a), tamB = strlen(b);
    if (tamA == tamB)
    {
        for (int i=0;i<tamA;i++)
        {
            c[a[i]-'0'] += 1;
            c[b[i]-'0'] -= 1;
        }
        for (int i=0;i<10;i++)
        {
            if (c[i]!= 0)
                return false;
        }
    }
    else
        return false;
    return true;
}
void main()
{
    char a[9], b[9];

    printf("Digite dois numeros separados por espaco: ");
    printf("\na: ");
    scanf("%s", &a);
    printf("\nb: ");
    scanf("%s", &b);

    if (ehPermutacao(a,b))
        printf("O numero %s eh permutacao de %s", a, b);
    else
        printf("O numero %s nao eh permutacao de %s", a, b);
}