#include <stdio.h>
#include <stdlib.h>
void criptografia(char *fraseNova, int tamanhoNovo)
{
    int i,j;

    for (i=0;i<5;i++)
    {
        for (j=i;j<tamanhoNovo;j+=5)
        {
            fraseNova[j] += (i+1);
        }
    }

    printf("%s", fraseNova);
}
void main()
{
    int i, cont=0;
    char frase[80];
    printf("Digite uma frase de ate 80 characteres: ");
    gets(frase);
    int tam = strlen(frase);
    char *fraseSemEspaco =(char *) malloc(tam*sizeof(char));
    if (fraseSemEspaco == NULL)
    {
        exit(1);
    }

    for (i=0;i<tam;i++)
    {
        if (frase[i] != ' ')
        {
            fraseSemEspaco[cont] = frase[i];
            cont++;
        }
    }
    fraseSemEspaco[cont] = '\0';
    int tamNovo = strlen(fraseSemEspaco);

    criptografia(fraseSemEspaco,tamNovo);
}
