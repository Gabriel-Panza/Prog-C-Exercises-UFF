#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

int *aprovados(int n, int *mat, float *grades, int *size);

int main(){
    int size = 1, size_general;
    int* mat;
    float* grades;
    int* ap;

    setlocale(LC_ALL, "Portuguese");

    printf("Type the quantity of students registered: ");
    scanf("%d", &size_general);

    mat = (int*) malloc(size_general * sizeof(int));
    grades = (float*) malloc(size_general * sizeof(float));


    if(mat == NULL || grades == NULL){
        printf("ERROR LOCATION");
        exit(1);
    }

    for(int i = 0; i < size_general; i++){
        printf("Type a matriculation: ");
        scanf("%d", &mat[i]);
        printf("Type a grade: ");
        scanf("%f", &grades[i]);
    }

    free(mat);
    free(grades);
    free(ap);

    return 0;
}

int *aprovados(int n, int *mat, float *grades, int *size){

    int* ap;
    int cont = 0;

    for(int j = 0; j < n; j++){
        if(grades[j] >= 5.0){
            cont++;
        }
    }

    *size = cont;

    ap = (int*) malloc(cont * sizeof(int));

    if( ap == NULL ){printf("ERROR");exit(1);}

    for(int i = 0; i < n; i++){
        if(grades[i] >= 5.0){
            ap[i] = mat[i];
        }
    }

    return ap;
}