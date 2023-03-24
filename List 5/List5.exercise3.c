#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int repeatCharacter(char c, char *cad){
    int i, total=0;
    for(i=0;i<strlen(cad);i++){
        if(cad[i]== c){
            total +=1;
        }
    }
    return total;
}

int main(){
    char word[21], caractere;
    int total;

    printf("Type a word: ");
    scanf("%20[^\n]", word);
    fflush(stdin);

    printf("Type a char: ");
    scanf("%c", &caractere);
    fflush(stdin);

    total = repeatCharacter(caractere, word);

    printf("Total of times that a character appeard: %d", total);

    return 0;
}
