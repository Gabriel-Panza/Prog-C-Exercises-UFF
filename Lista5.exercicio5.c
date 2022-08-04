#include <stdio.h>
#include <string.h>

int main()
{
    char frase[80] = "o rato roeu a roupa do rei de roma";
    char *p;
    int tamanho = strlen(frase);
    p = frase;
    p[2]='m';
    p[6]='\0';
    printf("%s\n", frase);
    p = p + 3;
    printf("%s\n",p);
    printf("%d\n",tamanho);
}