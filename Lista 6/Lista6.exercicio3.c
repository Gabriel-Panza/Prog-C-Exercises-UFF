#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

/*
3. O cadastro de uma turma de n alunos é representado por um vetor de inteiros,
contendo a matrícula de cada aluno,

e um vetor de reais, contendo a nota final de cadaaluno,
de tal modo que para uma mesma posição do vetor (mesmo índice),
a matrícula ea nota se referem a um mesmo estudante.

Considere que um aluno está aprovado se
tem nota final maior ou igual a 5,0.

Escreva uma função que recebe como parâmetros o inteiro n,
o ponteiro mat para o vetor de matrículas,
o ponteiro notas para o vetor de notas e
um ponteiro para a variável inteira tam.

A função deve contar o número de alunos aprovados,
criar um novo vetor de inteiros alocado dinamicamente com o tamanho exato para conter apenas a matrícula desses alunos,
e armazenar no novo vetor as matrículas correspondentes.

Finalmente, a função deverá armazenar o tamanho do novo vetor na variável tam e retornar o ponteiro para seu primeiro
elemento.

O protótipo da função é:
int *aprovados(int n, int *mat, float *notas, int *tam);

*/

int *aprovados(int n, int *mat, float *notas, int *tam);


int main(){
    int tam = 1, tam_geral;
    int* mat;
    float* notas;
    int* ap;

    setlocale(LC_ALL, "Portuguese");

    printf("Digite a quantidades de alunos a serem cadastrados: ");
    scanf("%d", &tam_geral);


    //aloca
    mat = (int*) malloc(tam_geral * sizeof(int));
    notas = (float*) malloc(tam_geral * sizeof(float));


    //teste locação
    if(mat == NULL || notas == NULL){
        printf("ERROR LOCAÇÃO");
        exit(1);
    }

    //preenche
    for(int i = 0; i < tam_geral; i++){
        printf("Digite a matrícula: ");
        scanf("%d", &mat[i]);
        printf("Digite a nota: ");
        scanf("%f", &notas[i]);
    }


    //testa se preenchido
    /*
    for(int i = 0; i < tam_geral; i++){
        printf("Matrícula: %d\n", mat[i]);
        printf("Nota: %.1f\n", notas[i]);
    }


    ap = aprovados(tam_geral, mat, notas, &tam);

    //testa se tudo foi enviado corretamente
    for(int i = 0; i < tam; i++){
        printf("Matricula aprovados - %d\n", ap[i]);
    }
    */

    //libera
    free(mat);
    free(notas);
    free(ap);

    return 0;
}

int *aprovados(int n, int *mat, float *notas, int *tam){

    int* ap;
    int cont = 0;

    for(int j = 0; j < n; j++){
        if(notas[j] >= 5.0){
            cont++;//caclula aprovados
        }
    }

    //Atualiza tam
    *tam = cont;

    ap = (int*) malloc(cont * sizeof(int));

    if( ap == NULL ){printf("ERROR");exit(1);}

    for(int i = 0; i < n; i++){
        if(notas[i] >= 5.0){
            ap[i] = mat[i];//atualiza matricula
        }
    }


    //testa vetor ap
    /*
    for(int i = 0; i < cont; i++){
        printf("M - %d", ap[i]);
    }
    */

    return ap;
}
