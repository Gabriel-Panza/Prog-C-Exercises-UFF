#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inverse(char *string);

int main(){
    char word[21];

    printf("Type a string: ");
    scanf(" %[^\n]", word);
    fflush(stdin);

    inverse(word);

    return 0;
}

void inverse(char *string){
    int i, start =0;
    char  newString[21];

    for(i=(strlen(string)); i>0; i--){
        newString[i] = string[start];
        start++;
    }
    printf("Inverse Word:  %s", newString);
}
