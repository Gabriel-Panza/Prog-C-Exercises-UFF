#include <stdio.h>
#include<string.h>
#include <stdlib.h>

char *compactar(char *s)
{
    int contadorInicio = 0;

    while(s[contadorInicio] == ' ') 
    {
        contadorInicio++;
    }

    int contadorFinal = strlen(s) - 1;

    while(s[contadorFinal] == ' ') 
    {
        contadorFinal--;

    }
    int n = strlen(s) - contadorInicio - (strlen(s) - 1 - contadorFinal);
    char *compactado = (char*) malloc(n*sizeof(char));

    if(compactado == NULL)
    {
        printf("ERRO");
        exit(1);
    }
    
    int posicaoNovoVetor = 0;

    for (int i = contadorInicio; i <= contadorFinal; i++) 
    {
        compactado[posicaoNovoVetor] = s[i];
        posicaoNovoVetor++;
    }
    compactado[contadorFinal+1] = '\0';
    
    return compactado;
}

int main()
{
    char cadeiaDeCaracteres[100];
    scanf(" %99[^\n]",cadeiaDeCaracteres);
    char *novaCadeia = compactar(cadeiaDeCaracteres);
    printf("%s",novaCadeia);
    free(novaCadeia);
    return 0;
}



 
 
