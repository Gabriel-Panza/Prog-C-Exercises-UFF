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
    int i,j,k;
	struct timeval start, end;
	double time_taken;

    // Inicializa Matrizes

	for(i = 0; i < SIZE; i++){
        for(j = 0; j < SIZE; j++) {
         	A[i][j] = (double)rand()/ (double)RAND_MAX;
			B[i][j] = (double)rand()/ (double)RAND_MAX;
			C[i][j] = 0.0;
        }
	}
    //Inicializa arquivo de saída dos acesso
    //Utilizada para Dinero
    //acessos = fopen("./tijk.din", "w");
    // Inicializa timer
   	gettimeofday(&start, NULL);
   	for(i = 0; i < SIZE; i++){
		for(j = 0; j < SIZE; j++) {
  			sum = 0.0;
           	for(k=0; k < SIZE; k++) {
               		sum  += A[i][k] * B[k][j];
				// utilizada para Dinero
                    	//fprintf(acessos, "0 %p\n", &A[i][k]);
			  	//fprintf(acessos, "0 %p\n", &B[k][j]);
			}
			C[i][j] +=sum;
			// utilizada para Dinero
			// fprintf(acessos, "1 %p\n", &C[i][j]);
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