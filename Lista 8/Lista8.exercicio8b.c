#include <stdio.h>
#include <stdlib.h>

void *ordenacao(char *vChar, int n)
{
    if (n>1)
    {
        int x=vChar[0];
        int ini=1,fim=n-1;
        char temp;

        do
        {
            while (ini < n && vChar[ini] <= x)
                ini++;
            while (vChar[fim] > x)
                fim--;
            if (ini<fim)
            {
                temp = vChar[ini];
                vChar[ini] = vChar[fim];
                vChar[fim] = temp;
                ini++;
                fim--;
            }
        }while (ini<=fim);
        vChar[0]=vChar[fim];
        vChar[fim]=x;

        ordenacao(vChar,fim);
        ordenacao(&vChar[ini],(n-ini));
    }
    return vChar;
}

void main()
{
    int i;
    char palavra[100];
    puts("Digite a palavra a ser ordenada: ");
    gets(palavra);

    int tam = strlen(palavra);
    char *vetChar = ordenacao(palavra,tam);

    printf("A palavra ordenada eh: ");
    for (i=0;i<tam;i++)
    {
        printf("%c", vetChar[i]);
    }
}
