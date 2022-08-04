/*
3. Crie uma lista encadeada onde cada elemento contém informações de um aluno. Crie
funções para o gerenciamento da lista: imprimir, excluir, incluir e alterar.
Aplique essas funções a partir de uma lista carregado do arquivo.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    char nome[30];
    int mat;
    float nota;
    struct node *prox;
};

typedef struct node Node;



void inicia(Node *lst);
void incluir(Node *lst, char *nome, int mat, float nota);
void imprime(Node *lst);
void exlcui(Node *lst);
int vazia(Node *lst);
void alterar(Node *lst);

int main(){

    Node *lst = (Node*) malloc(sizeof(Node));
    if(!lst)exit(1);
    inicia(lst);

    char info[121];
    char c, nome[30];
    int mat;
    float nota;

    FILE *f = fopen("input2.txt", "rt");
    if(!f){
        printf("ERRO");
        exit(1);
    }
    

    while((fgets(info, 121, f) != NULL)){
        int n = sscanf(info,"%c %s %i %f", &c, &nome, &mat, &nota);// split da info
        if( n > 0){// num de info lidas   
            switch (c){
                case 'i':
                    //printf("%s %i %.1f\n", nome, mat, nota);
                    incluir(lst, &nome, mat, nota);
                    printf("Incluido com sucesso.\n");
                    break;
                case 'p':
                    imprime(lst);
                    break;
                case 'a':
                    alterar(lst);
                    break;
                case 'e':
                    break;
                default:
                    printf("Entrada invalida");
                    break;
            }
            
        }
    }   
    
    fclose(f);
    return 0;
}

void inicia(Node *lst){
    lst->prox = NULL;
}

int vazia(Node *lst){
    if( lst->prox == NULL){
        return 1;
    }else return 0;
}

void incluir(Node *lst, char *nome, int mat, float nota){
    Node *novo = (Node*) malloc(sizeof(Node));
    if(!novo) exit(1);

    strcpy(novo->nome, nome);
    novo->mat = mat;
    novo->nota = nota;

    Node *aux = lst->prox;
    lst->prox = novo;
    novo->prox = aux;
}

void imprime(Node *lst){
    if(vazia(lst)){
        printf("Vazia");
        return;
    }
    Node *tmp = lst->prox;

    while (tmp != NULL)
    {
        printf("|A: %s M: %i N: %.1f| ->", tmp->nome,tmp->mat, tmp->nota);
        tmp = tmp->prox;
    }
    printf("NULL\n\n");
}

void alterar(Node *lst){
    char aluno[30];
    int mat;
    float nota;
    char nome_n[30];
    Node *aux;
    printf("\nQual aluno deseja alterar? ");
    scanf("%d", &mat);

    for(aux = lst; aux != NULL; aux = aux->prox ){
        if(aux->mat == mat){
            printf("Nome do aluno %s, digite o novo nome:", aux->nome);
            scanf("%s", &nome_n);
            strcpy(aux->nome, nome_n);

            printf("Matricuala do aluno %d, digite a nova matricula:", aux->mat);
            scanf("%d", &mat);
            aux->mat = mat;

            printf("Nota do aluno %.1f, digite a nova nota:", aux->nota);
            scanf("%f", &nota);
            aux->nota = nota;
            break;
        }
    }
    printf("Alteracao feita com sucesso!\n");
    printf("A: %s M: %i N: %.1f\n\n", aux->nome,aux->mat, aux->nota);
}

void exclui(Node *lst){
    /**/
}