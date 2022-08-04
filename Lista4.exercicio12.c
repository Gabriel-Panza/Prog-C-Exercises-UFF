#include<stdio.h>
#include<stdlib.h>

int main(){
    char palavra[20];
    char palavra2[20];
    char ok;
    int i,j=0;
    printf("Digite a palavra: ");
    scanf("%20[^\n]", palavra);
    printf("Digite a letra que quer ser removida: ");
    fflush(stdin);
    scanf("%c", &ok);
    for(i=0;i<strlen(palavra);i++){
        if(palavra[i]!=ok){
            palavra2[j]=palavra[i];
            j++;
        }
    }
    printf("%s", palavra2);
    return 0;
}
