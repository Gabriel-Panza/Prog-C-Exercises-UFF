#include <stdio.h>
#include <string.h>
#define MAX 50
int main (void)
{
    char texto[MAX +2], temp; // Instancio minhas variaveis characteres
    int tam , i; // Instancio minhas variáveis inteiras
    gets(texto); // O programa pega a string com o meu nome (Gabriel)
    tam = strlen (texto); // Defino tamanho da string
    for (i=0;i<tam;i++) // Inicio o loop
    {
        // Realizo a troca inversa dos characteres pelo método de ordenação
        temp = texto[i];
        texto[i] = texto[tam-1-i];
        texto[strlen(texto)-1-i] = temp ;
    }
    puts (texto); // Gravo o valor final da string texto em stdout, sem incluir o character nulo
    return 0;
}
