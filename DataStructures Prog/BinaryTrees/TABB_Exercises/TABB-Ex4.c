#include <stdlib.h>
#include <string.h>
#include "TABB/TABB.c"

int len(TABB *a, int N)
{
    if (!a) return 0;
    if(a->info < N) return 1 + len(a->esq,N) + len(a->dir,N);
    return len(a->esq,N);
}

void add_no_vetor(int* vetor, TABB* a, int N, int *posNoVetor)
{
    if(!a) return;
    if(a->info >= N) add_no_vetor(vetor, a->esq, N, posNoVetor);
    else{
        add_no_vetor(vetor, a->esq, N, posNoVetor);
        vetor[*posNoVetor] = a->info;
        ++*posNoVetor;
        add_no_vetor(vetor, a->dir, N, posNoVetor);
    }
}

int *mN(TABB*a, int N)
{
    int *vetor = (int *)malloc(len(a,N)*sizeof(int));
    int posNoVetor = 0;
    add_no_vetor(vetor, a, N, &posNoVetor);
    return vetor;
}

int main(void)
{
    TABB *a = TABB_cria(5, NULL, NULL);
    a = TABB_insere(a, 1);
    a = TABB_insere(a, 2);
    a = TABB_insere(a, 3);
    a = TABB_insere(a, 4);
    a = TABB_insere(a, 6);
    a = TABB_insere(a, 7);
    a = TABB_insere(a, 8);
    a = TABB_insere(a, 9);

    int N;
    printf("Digite o valor de N: ");
    scanf("%d", &N);

    int *vetor_menores = mN(a, N);
    printf("Os elementos menores sao: ");
    for(int i=0; i<len(a,N); i++){
        printf(" %d ", vetor_menores[i]);
    }
    TABB_libera(a);
    free(vetor_menores);
}