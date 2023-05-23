#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 15

char last(char *cad, int size){
    int i, total=0;
    for(i=0; i<size;i++){
        if(i==size-1){
            return cad[i];
        }
    }
}

int totalSize(char *cad){
    int i, total=0;
    for(i=0; cad[i]!= '\0';i++){
        total +=1;
    }
    return total;
}

int main(){
    char word[MAX];
    int size;

    printf("Type a word: ");
    scanf("%[^\n]", word);
    fflush(stdin);

    size = totalSize(word);

    printf("The first letter: %c\n", word[0]);
    printf("The last letter: %c\n", last(word, size));
    printf("Size of the word: %d\n", size);

    return 0;
}