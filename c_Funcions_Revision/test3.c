#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef SIZE
#define SIZE 512
#endif

double A[SIZE][SIZE];
double B[SIZE][SIZE];
double C[SIZE][SIZE];


int main() {
    // FILE * acessos; // utilizada para Dinero
    double sum;
    int i,j,k,r;
	struct timeval start, end;
	double time_taken;

    for(i = 0; i < SIZE; ++i){
        for(j = 0; j < SIZE; ++j){
         	A[i][j] = (double)rand()/ (double)RAND_MAX;
         	B[i][j] = (double)rand()/ (double)RAND_MAX;
         	C[i][j] = 0.0;
        }
	}

	//Inicializa arquivo de saída dos acessos
	// utilizada para Dinero
	//acessos = fopen("./tikj.din", "w");

	// inicializa timer.
	gettimeofday(&start, NULL);

	for(i = 0; i < SIZE; ++i){
		for(k = 0; k < SIZE; ++k) {
			r = A[i][k];
			for(j=0; j < SIZE; j++) {
				C[i][j] += r * B[k][j];
				//utilizada para dinero
				//fprintf(acessos,"0 %p\n", &A[i][k]);
				//fprintf(acessos,"0 %p\n", &B[k][j]);
				//fprintf(acessos,"1 %p\n", &C[i][j]);
			}
		}
	}
	// utilizada para Dinero
	// fclose(acessos);
	gettimeofday(&end, NULL);

	// Calculando tempo total de execução do  programa

    time_taken = (end.tv_sec - start.tv_sec) * 1e6;
    time_taken = (time_taken + (end.tv_usec - start.tv_usec))* 1e-6;
    printf ("Tempo de execução: %.6f\n", time_taken);
}