#include <stdio.h>
#include <stdlib.h>
#include <string.h>

vezesCaracter(char c, char *cad){
    int i, total=0;
    for(i=0;i<strlen(cad);i++){
        if(cad[i]== c){
            total +=1;
        }
    }
    return total;
}

int main(){
    char cadeia[21], caractere;
    int total;

    printf("Digite a cadeia de caractere: ");
    scanf("%20[^\n]", cadeia);
    fflush(stdin);

    printf("Digite o caractere: ");
    scanf("%c", &caractere);
    fflush(stdin);

    total = vezesCaracter(caractere, cadeia);

    printf("total de vezes do caractere a : %d", total);


    return 0;
}
