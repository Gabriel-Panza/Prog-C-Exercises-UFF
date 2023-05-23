#include<stdio.h>
#include<stdlib.h>

int main(){
    char word[20];
    char word2[20];
    char ok;
    int i,j=0;
    printf("Type a word: ");
    scanf("%20[^\n]", word);
    printf("Type the letter you want to remove: ");
    fflush(stdin);
    scanf("%c", &ok);
    for(i=0;i<strlen(word);i++){
        if(word[i]!=ok){
            word2[j]=word[i];
            j++;
        }
    }
    printf("%s", word2);
    return 0;
}
