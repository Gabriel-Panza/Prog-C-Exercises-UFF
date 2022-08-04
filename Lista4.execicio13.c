#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char palavra[50];
    int compare[128];
    int i;
    for(i=0;i<128;i++){
       compare[i]=0;
    }
    printf("Digite a palavra: ");
    scanf("%50[^\n]", palavra);
    for(i=0;i<strlen(palavra);i++){
        compare[palavra[i]]++;
    }
    for(i=0;i<128;i++){
        if(compare[i]!=0){
            printf("\n%c: %d",i, compare[i]);
        }
    }
    return 0;
}
