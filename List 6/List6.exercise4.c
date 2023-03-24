#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

int *premiered(int n, int *inscr, float *t1, int p1,float *t2, int p2, int *size);

int main(){
    int n, p1, p2, size;
    int *inscr, *class;
    float *t1, *t2;


    setlocale(LC_ALL, "Portuguese");

    //size of vector
    printf("Digite o número de participantes: ");
    scanf("%d", &n);

    printf("%d\n", n);

    //alloc vectors
    inscr = (int*) malloc(n * sizeof(int));
    t1 = (float*) malloc(n * sizeof(float));
    t2 = (float*) malloc(n * sizeof(float));

    if( inscr == NULL ){
        printf("ERROR ALLOC");
        exit(1);
    }  
    if( t1 == NULL ){
        printf("ERROR ALLOC");
        exit(1);
    }  
    if( t2 == NULL ){
        printf("ERROR ALLOC");
        exit(1);
    }            

    //fill inscr
    for(int i = 0; i < n; i++){
        printf("Digite o número da inscrição %d: ", i);
        scanf("%d", &inscr[i]);
    }
    
    //print inscr
    for (int i = 0; i < n; i++){
        printf("I%d\n", inscr[i]);
    }

    //weight
    printf("Type a weight to T1: ");
    scanf("%d", &p1);
    printf("Type a weight to T2: ");
    scanf("%d", &p2);

    //T1 e T2
    for (int i = 0; i < n; i++){
        printf("Type a note to test 1 of student %d:  ", i);
        scanf("%f", &t1[i]);
        printf("Type a note to test 2 of student %d:  ", i);
        scanf("%f", &t2[i]);
    }

    class = premiered(n, inscr, t1, p1, t2, p2, &size);
   
    free(inscr);
    free(t1);
    free(t2);
    free(premiered);
    free(class);

    return 0;
}

int *premiered(int n, int *inscr, float *t1, int p1,float *t2, int p2, int *size){

    int* premiered;
    int cont_premiado = 0, cont = 0;
    float med = 0, * average;

    //average
    average = (float*) malloc(n * sizeof(float));
    if( average == NULL ){
        printf("ERROR ALLOC");
        exit(1);
    } 

    for (int i = 0; i < n; i++){
        average[i] = (t1[i]*p1 + t2[i]*p2) / p1 + p2;
        med += average[i];
    }

    //average general
    med /= n;
    
    //P1 e P2
    for (int i = 0; i < n; i++){
        if(average[i]>=med){
            cont_premiado++;
        }
    }
    *size = cont_premiado;

    //alloc classified
    premiered = (int*) malloc(cont_premiado * sizeof(int));
    
    if ( premiered == NULL ){
        printf("ERROR ALOC");
        exit(1);
    } 
    
    
    //classificação
    for (int j = 0; j < n; j++){
        if(average[j] >= med){
            premiered[cont] = inscr[j];
            cont++;
        }
    }

    free(average);
    
    return premiered;
}