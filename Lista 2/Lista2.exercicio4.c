#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main (void){
    char letra, sorteio;
    printf("Digite qual letra voce acha que foi sorteada: ");
    scanf("%c", &letra);
    sorteio= 'a' + (char)(rand()%26);
    if (((int)letra) == ((int)sorteio))
        printf("Parabéns! Voce acertou a letra sorteada");
    else if (((int)letra) > ((int)sorteio))
        printf("Esta letra eh maior que a sorteada");
    else
        printf("Esta letra eh menor que a sorteada");
}
