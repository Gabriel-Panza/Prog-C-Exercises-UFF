#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inverter(char *string);

int main(){
    char cadeia[21];

    printf("Digite a string: ");
    scanf(" %[^\n]", cadeia);
    fflush(stdin);

    inverter(cadeia);

    return 0;
}

void inverter(char *string){
    int i, inicio =0;
    char  newString[21];

    for(i=(strlen(string)); i>0; i--){
        newString[i] = string[inicio];
        inicio++;
    }
    printf("Palavra invertida:  %s", newString);
}
