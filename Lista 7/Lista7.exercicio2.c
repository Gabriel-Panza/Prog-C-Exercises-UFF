#include <stdio.h>
#include <string.h>

int main (void)
{
    char *frase = "Otimo teste"; // Criamos nossa cadeia de characteres com uma frase
    char *p , misterio[80]; // Criamos um ponteiro de character e outra cadeia de characteres, porem vazia dessa vez
    int i = 0; // Inicializamos nossa primeira variavel que ser� usada no loop
    int j = 0; // Inicializamos nossa segunda variavel que ser� usada no loop
    p = frase + strlen(frase) - 1; // Definimos nosso ponteiro de character inicializado acima
    while (*p != ' ')  // Enquanto nao for encontrado um espa�o em branco no meio do meu ponteiro de character
    {
        misterio[i] = *p; // Adicionamos o valor do ponteiro de character dentro da cadeia de characteres vazia criada no inicio do programa
        i ++; p --; // Percorremos a cadeia at� o loop terminar
    }
    misterio[i] = ' '; i ++; //  Definimos o ultimo termo da cadeia
    while ( frase[j] != ' ') // Enquanto nao for encontrado um espa�o em branco no meio da minha cadeia de characteres com a frase
    {
        misterio [i] = frase[j]; // Trocamos o characetr da frase pelo da cadeia preenchida no loop anterior
        j ++; i ++; // Percorremos a cadeia at� o loop terminar
    }
    misterio[i] = '\0 '; // Definimos o ultimo termo da cadeia
    puts (misterio); // Grava a cadeia de characteres armazenada em Misterio para stdout, sem incluir o character nulo
    return 0;
}
