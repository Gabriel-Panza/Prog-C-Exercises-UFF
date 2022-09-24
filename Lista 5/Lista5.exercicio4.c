#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 15

char ultima(char *cad, int tam){
    int i, total=0;
    for(i=0; i<tam;i++){
        if(i==tam-1){
            return cad[i];
        }
    }
}

int tamanho(char *cad){
    int i, total=0;
    for(i=0; cad[i]!= '\0';i++){
        total +=1;
    }
    return total;
}

int main(){
    char cadeia[MAX];
    int tam;

    printf("Digite a palavra: ");
    scanf(" %[^\n]", cadeia);
    fflush(stdin);

    tam = tamanho(cadeia);

    printf("A primeira letra da palavra: %c\n", cadeia[0]);
    printf("A ultima letra da palavra: %c\n", ultima(cadeia, tam));
    printf("Tamanho da palavra: %d\n", tam);


    return 0;
}
