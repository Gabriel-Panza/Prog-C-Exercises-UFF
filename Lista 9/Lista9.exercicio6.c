#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pessoa {
    int codigo;
    char nome[81];
} Pessoa;

void atribui(int indice, Pessoa** vet, int cod, char *nome){
    vet[indice]->codigo = cod;
    strcpy(vet[indice]->nome,nome);
}

void imprime(int indice, Pessoa **vet){
    for(int i =0; i<indice;i++){
        printf("Nome: %s   Codigo: %d\n", vet[i]->nome, vet[i]->codigo);
    }
}

Pessoa* busca(int n, Pessoa** vet, int codigo){
    int inicio = 0;
    int fim = n -1;
    while(inicio <= fim){
        int meio = (inicio+fim)/2;
        if (codigo < vet[meio]->codigo){
            fim = meio -1;
        } else if(codigo > vet[meio]->codigo){
            inicio = meio + 1;
        } else {
            return vet[meio];
        }
    }
    return NULL;
}
int main(){
    Pessoa **vetor;
    Pessoa *pessoaEncontrada;
    int n = 3, i, codigo;

    vetor = (Pessoa **) malloc(n*sizeof(Pessoa *));
    if(vetor[i] == NULL) { printf("Sem memoria para alocacao.\n"); exit(1); }
    for ( i=0 ; i<n ; i++) {
        vetor[i] = (Pessoa *) malloc(sizeof(Pessoa));
        if(vetor[i] == NULL) { printf("Sem memoria para alocacao.\n"); exit(1); }

    }

    atribui(0, vetor,100, "Teco");
    atribui(1, vetor,200, "Tico");
    atribui(2,vetor,300, "Ciclano");

    imprime(n, vetor);

    printf("Digite o codigo da pessoa que deseja procurar: ");
    scanf("%d", &codigo);

    pessoaEncontrada = busca(n, vetor, codigo);


    if(pessoaEncontrada != NULL){
        printf("Nome e codigo da pessoa buscada: %s %d", pessoaEncontrada->nome, pessoaEncontrada->codigo);
    } else{
        printf("Codigo não encontrado");

    }

    for ( i=0 ; i<n ; i++) {
        free(vetor[i]);
    }

    free(vetor);


    return 0;
}
