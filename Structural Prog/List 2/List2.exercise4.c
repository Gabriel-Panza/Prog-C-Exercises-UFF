#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main (void){
    char letra, sorteio;
    printf("Type what letter do you think will be randomized");
    scanf("%c", &letra);
    sorteio= 'a' + (char)(rand()%26);
    if (((int)letra) == ((int)sorteio))
        printf("Congratulations! You got the letter right");
    else if (((int)letra) > ((int)sorteio))
        printf("The letter randomized is lower");
    else
        printf("The letter randomized is higher");
}
