#include <stdio.h>
#include "TAB/TAB.c"

void len(TAB *a, int N, int *cont)
{
    if (!a) return;
    if(a->info > N) ++*cont;
    len(a->esq,N,cont);
    len(a->dir,N,cont);
}

void add_no_vetor(int* vetor, TAB* a, int N, int *posNoVetor)
{
    if(!a) return;
    if(a->info > N) {
        vetor[*posNoVetor] = a->info;
        ++*posNoVetor;
    }
    add_no_vetor(vetor, a->esq, N, posNoVetor);
    add_no_vetor(vetor, a->dir, N, posNoVetor);
}

int *mN(TAB*a, int N, int *tam)
{
    int *vetor = (int *)malloc((*tam)*sizeof(int));
    int posNoVetor = 0;
    add_no_vetor(vetor, a, N, &posNoVetor);
    return vetor;
}

int main()
{
    TAB *a;
    a = TAB_cria(7,TAB_cria(5,NULL,TAB_cria(8,TAB_cria(2,NULL,NULL),TAB_cria(3,TAB_cria(4,NULL,TAB_cria(6,NULL,NULL)),NULL))),TAB_cria(2,TAB_cria(1,TAB_cria(10,NULL,NULL),TAB_cria(4,NULL,NULL)),TAB_cria(9,TAB_cria(8,NULL,NULL),TAB_cria(0,TAB_cria(3,NULL,NULL), NULL))));
    TAB_imp_ident(a);
    printf("\n\n");
    
    int N;
    printf("Digite o valor de N: ");
    scanf("%d", &N);
    printf("\n\n");

    int tam = 0;
    len(a,N,&tam);
    
    int *vetor_menores = mN(a, N, &tam);
    printf("Os elementos maiores sao: ");
    for(int i=0; i<tam; i++){
        printf(" %d ", vetor_menores[i]);
    }
    TAB_libera(a);
    free(vetor_menores);
    
    return 0;
}