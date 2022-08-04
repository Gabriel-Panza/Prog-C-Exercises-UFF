#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>


struct Usuario {
    char nome[8];
    char senha[8];
};

bool isValidChar(char c) {
    return (c > 47 && c < 58) || (c > 40 && c < 91) || (c > 96 && c < 123);
}

void getNome(struct Usuario *user) {
    int p = 0;
    char c;
    while ((c = getchar()) != '*' && p < 8)
    {
        if (isValidChar(c))
        {
            user->nome[p] = c;
            printf("Cadastrado até agora: %s\n",  user->nome);
            p++;
        }
    }
}

void getPassword(struct Usuario *user) {
    int p = 0;
    char c;
    while ((c = getchar()) != '*' && p < 8)
    {
        if (isValidChar(c))
        {
            user->senha[p] = c;
             p++;
            for (int i = 0; i < p; i++)
            {
                printf("*");
            }
            printf("\n");
        }
    }
}

void isSameUser(struct Usuario *user1 , struct Usuario *user2) {
    if (strcmp(user1->nome, user2->nome) == 0 && strcmp(user1->senha, user2->senha) == 0)
    {
        printf("OK\n");
    } else {
        printf("Acesso negado\n");
    }
    
}

int main() {

    struct Usuario *cadastro = malloc(sizeof(struct Usuario));
    struct Usuario *login = malloc(sizeof(struct Usuario));
    printf("Cadastre um usuario\n");
    getNome(cadastro);
    printf("Cadastre uma senha para o usuario %s\n", cadastro->nome);
    getPassword(cadastro);
    printf("Faça o login de um usuario\n");
    getNome(login);
    printf("Insira a senha para o usuario %s\n", login->nome);
    getPassword(login);
    isSameUser(cadastro, login);
}