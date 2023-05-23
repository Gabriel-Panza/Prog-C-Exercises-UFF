#include <stdio.h>
#include <stdlib.h>

void *order(char *vChar, int n)
{
    if (n>1)
    {
        int x=vChar[0];
        int ini=1,end=n-1;
        char temp;

        do
        {
            while (ini < n && vChar[ini] <= x)
                ini++;
            while (vChar[end] > x)
                end--;
            if (ini<end)
            {
                temp = vChar[ini];
                vChar[ini] = vChar[end];
                vChar[end] = temp;
                ini++;
                end--;
            }
        }while (ini<=end);
        vChar[0]=vChar[end];
        vChar[end]=x;

        order(vChar,end);
        order(&vChar[ini],(n-ini));
    }
    return vChar;
}

void main()
{
    int i;
    char word[100];
    puts("Type a word to be ordered: ");
    gets(word);

    int tam = strlen(word);
    char *vetChar = order(word,tam);

    printf("The ordered word is: ");
    for (i=0;i<tam;i++)
    {
        printf("%c", vetChar[i]);
    }
}