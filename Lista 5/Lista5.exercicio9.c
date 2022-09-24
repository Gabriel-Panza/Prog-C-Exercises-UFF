#include <stdio.h>
#include <string.h>

int main(){
    char nome[30], endereco[30], telefone[20], informacoes[80]="";

    printf("Digite o nome: ");
    scanf(" %[^\n]", nome);
    fflush(stdin);

    printf("Digite o endereco: ");
    scanf("%[^\n]", endereco);
    fflush(stdin);

    printf("Digite o telefone: ");
    scanf("%[^\n]", telefone);
    fflush(stdin);

    strcat(informacoes, nome);
    strcat(informacoes, endereco);
    strcat(informacoes, telefone);

    printf("%s", informacoes);

    return 0;
}
