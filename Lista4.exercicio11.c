#include <stdio.h>

void main()
{
    int i;
    int v1[20];
    int v2[20];
    char v3[20];
    int v4[20];

    for(i=0;i<20;i++)
    {
        v1[i] = rand()%1000;
        v2[i] = rand()%1000;
    }

    for (i=0;i<20;i++)
    {
        printf("Digite qual operacao deve ser feita nos valores de posicao %d:\n", i);
        printf("obs: mais:(+) menos:(-) divisao:(/) multiplicacao:(*)\n");
        scanf("\n%c", &v3[i]);

        while (v3[i] != '+' && v3[i] != '-' && v3[i] != '/' && v3[i] != '*')
        {
            printf("Erro! Sinal invalido! ");
            printf("Digite um simbolo valido:\n");
            scanf("\n%c", &v3[i]);
        }
    }

    for (i=0;i<20;i++)
    {
        if (v3[i] == "+")
        {
            v4[i] = v1[i]+v2[i];
        }
        if (v3[i] == "-")
        {
            v4[i] = v1[i]-v2[i];
        }
        if (v3[i] == "/")
        {
            v4[i] = v1[i]/v2[i];
        }
        if (v3[i] == "*")
        {
            v4[i] = v1[i]*v2[i];
        }
    }
    for (i=0;i<20;i++)
        printf("%d", v4[i]);
}
