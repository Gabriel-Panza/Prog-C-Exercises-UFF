#include <stdio.h>
#include <stdlib.h>

char comparafunc (const void * i, const void * j)
{
   return (*(char*)i - *(char*)j);
}
void main()
{
    int i;
    char palavra[100];
    puts("Digite a palavra a ser ordenada: ");
    gets(palavra);

    int tam = strlen(palavra);
    qsort(palavra, tam, sizeof(char), comparafunc);

    printf("A palavra ordenada eh: ");
    for (i=0;i<tam;i++)
    {
        printf("%c", palavra[i]);
    }
}
