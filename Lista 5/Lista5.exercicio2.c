#include<stdio.h>
#include<string.h>

main(void)
{
//Estamos pegando uma cadeia de caracteres
    char texto[]= "foi muito facil";
//Criamos a variável responsável pelo loop da cadeia
    int i;
//Percorremos a cadeia de caracteres
    for (i = 0; texto[i]!='\0'; i++)
    {
    // Procura-se um espaço em branco dentro da cadeia
        if (texto[i] == ' ') break;
    }
    // Acrescenta um na variável do loop para encontrarmos o '\0'
    i++;
    for ( ; texto[i]!='\0'; i++)
    {
        //Imprime na tela a cadeia
        printf("%c", texto[i]);
    }
}