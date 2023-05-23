#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char word[50];
    int compare[128];
    int i;
    for(i=0;i<128;i++){
       compare[i]=0;
    }
    printf("Type a word: ");
    scanf("%50[^\n]", word);
    for(i=0;i<strlen(word);i++){
        compare[word[i]]++;
    }
    for(i=0;i<128;i++){
        if(compare[i]!=0){
            printf("\n%c: %d",i, compare[i]);
        }
    }
    return 0;
}
