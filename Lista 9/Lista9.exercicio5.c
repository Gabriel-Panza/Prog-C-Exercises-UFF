#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct endereco {
    char rua[100]; /* Nome da rua */
    int numero; /* Numero do imovel */
} Endereco;
typedef struct notas {
    float p1, p2, p3; /* Notas nas provas */
} Notas;
typedef struct aluno {
    int mat; /* Matricula do aluno */
    char nome[81]; /* Nome do aluno */
    Notas nota; /* Notas nas provas */
    Endereco *end; /* Endereco do aluno */
} Aluno;

Aluno ** alocaAlunos(int n){
    int i;
    Aluno **aluno;
    aluno = (Aluno**) malloc(n*sizeof(Aluno*));
    for(i = 0; i < n; i++) {
        aluno[i] = (Aluno *) malloc(sizeof(Aluno));
        if(aluno[i] == NULL) { printf("Sem memoria para alocacao.\n"); exit(1); }
    }
    for(int i = 0; i < n; i++) {
        aluno[i]->end = (Endereco *) malloc(sizeof(Endereco));
        if(aluno[i]->end == NULL) { printf("Sem memoria para alocacao.\n"); exit(1); }
    }

    return aluno;
}

void atribui(Aluno ** a, int indice, int matricula, char *nome, float
nota1, float nota2, float nota3, char *nomeRua, int numero){
    a[indice]->mat = matricula;
    strcpy(a[indice]->nome, nome);
    a[indice]->nota.p1 = nota1;
    a[indice]->nota.p2 = nota2;
    a[indice]->nota.p3 = nota3;
    strcpy(a[indice]->end->rua, nomeRua);
    a[indice]->end->numero = numero;
}
void imprime(Aluno **a, int indice){
    for (int i=0;i<indice;i++){
        printf("Matricula: %d\n", a[i]->mat);
        printf("Nome: %s\n", a[i]->nome);
        printf("Nota1: %.1f\n", a[i]->nota.p1);
        printf("Nota2: %.1f\n", a[i]->nota.p2);
        printf("Nota3: %.1f\n", a[i]->nota.p3);
        printf("Rua: %s\n", a[i]->end->rua);
        printf("Numero da casa: %d\n", a[i]->end->numero);
    }
}

void liberaAlunos(){
    void liberaAlunos(Aluno **a, int n) {
    for(int i = 0; i < n; i++) {
        free(a[i][0].end);
        free(a[i]);
    }

    free(a);
    }
}

main(){
    Aluno **alunos;
    alunos = alocaAlunos(3);
    atribui(alunos,0,10,"Um",1,1,1,"Getulio Vargas",100);
    atribui(alunos,1,20,"Dois",8,8,8,"Amaral Peixoto",200);
    atribui(alunos,2,30,"Tres",9,9,9,"Ouro Verde",300);
    imprime(alunos, 3);
}

