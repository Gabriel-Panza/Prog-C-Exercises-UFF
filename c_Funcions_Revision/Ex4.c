#include<stdio.h>
#include<string.h>
#include<stdbool.h>
bool ehPalindromo(char* a)
{
    int tamA = strlen(a);
    for (int i=0;i<tamA;i++)
    {
        if (a[i]!=a[tamA-1-i])
            return false;
    }
    return true;
}
void main()
{
    char a[100];
    do
    {
        printf("Digite um número: ");
        printf("\na: ");
        scanf("%s", a);
        if (a[0] == '-')
            break;
        
        if (ehPalindromo(a))
            printf("O numero %s eh palindromo", a);
        else
            printf("O numero %s nao eh palindromo", a);
    } while (1);
}