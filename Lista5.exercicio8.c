#include <stdio.h>
#include <string.h>

int main(){
    char string1[15], string2[15];
    printf("Digite a primeira palavra: ");
    scanf("%s", string1);
    fflush(stdin);

    printf("Digite a segunda palavra: ");
    scanf("%s", string2);
    fflush(stdin);

    if(strcmp(string1,string2)== 0){
        printf("Strings iguais");
    }else if(strcmp(string1,string2)== -1){
        printf("A segunda palavra e uma substring da primeira");
    } else {
        printf("Palavras diferentes e a segunda nao e uma substring da primeira");
    }

    return 0;
}
