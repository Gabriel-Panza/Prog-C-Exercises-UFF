/*
1. Faça um programa com uma função que calcule o número de vogais existentes em uma string. A
função recebe a string e atualiza a resposta (número de vogais) em uma variável que foi passada por
referência.
*/

#include <stdio.h>

int main()
{
    char* palavra[100];
    printf("Insira a palavra: \n");
    scanf("%s", palavra);
   

    int contador_vogais = 0;

    for(int i = 0; i < 100; i++)
    {
        if(palavra[i] == 'a' || palavra[i] == 'e' || palavra[i] == 'i' || palavra[i] == 'o' || palavra[i] == 'u')
        {
             vogais ++;
        }
    }

     printf("%d", contador_vogais);
}