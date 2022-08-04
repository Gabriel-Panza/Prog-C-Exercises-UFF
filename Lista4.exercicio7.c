#include <stdio.h>
#include<string.h>
#include <stdlib.h>

void transformaEmCamelCase(char *s)
{
    int i;    
    for( i = 0; s[i]!= '\0' ; i++)
    {
        if (s[i] == 32)
        {
            s[i+1] = s[i+1] - 32;        
        }
    }
}

void removeEspacos(char *copiar, char *colar)
{
   while (*copiar != '\0')
    {
        if (*copiar != ' ') 
        {
            *colar = *copiar;
            copiar++;
            colar++;
        } else {
            copiar ++;            
        }
    }
    *colar = '\0';
}

int main()
{
    char palavra[20];
    char colar[20];
            
    printf("Digite o nome da palavra que será convertida para Camel case: ");
    fgets(palavra, 20, stdin);
   
    
    transformaEmCamelCase(palavra);
    removeEspacos(palavra, colar);
    printf(" %s", colar);

    return 0;
}