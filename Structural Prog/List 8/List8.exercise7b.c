#include <stdio.h>
#include <stdlib.h>

char comparefunc (const void * i, const void * j)
{
   return (*(char*)i - *(char*)j);
}
void main()
{
    int i;
    char word[100];
    puts("Digite a palavra a ser ordenada: ");
    gets(word);

    int size = strlen(word);
    qsort(word, size, sizeof(char), comparefunc);

    printf("The word ordered is: ");
    for (i=0;i<size;i++)
    {
        printf("%c", word[i]);
    }
}
