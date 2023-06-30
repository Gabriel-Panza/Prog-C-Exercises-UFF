#include <stdio.h>
#include "TARVB/TARVB.c"

void len(TARVB*a, int N, int *cont)
{
    if (!a) return;
    int i=0;
    while (i<=a->nchaves) {
        if(a->chave[i] > N) ++*cont;
        len(a->filho[i],N,cont);
        i++;
    }
}

void add_no_vetor(int* vetor, TARVB* a, int N, int *posNoVetor)
{
    if(!a) return;
    for (int i=0; i<=a->nchaves;i++){
        if(a->chave[i] > N) {
            vetor[*posNoVetor] = a->chave[i];
            ++*posNoVetor;
        }
        add_no_vetor(vetor, a->filho[i], N, posNoVetor);
    }
}

int* mN(TARVB*a, int N, int *tam){
    if (!a) return NULL;
    len(a,N,tam);
    int *vetor = (int *)malloc((*tam)*sizeof(int));
    int posNoVetor = 0;
    add_no_vetor(vetor, a, N, &posNoVetor);
    return vetor;
}

int main(){
    TARVB *b = TARVB_Cria(2);
    b = TARVB_Insere(b,20,2);
    b = TARVB_Insere(b,50,2);
    b = TARVB_Insere(b,60,2);
    b = TARVB_Insere(b,1,2);
    b = TARVB_Insere(b,64,2);
    b = TARVB_Insere(b,12,2);
    b = TARVB_Insere(b,18,2);
    b = TARVB_Insere(b,66,2);
    b = TARVB_Insere(b,38,2);
    b = TARVBM_insere(b,7,2);

    int tam=0;
    int *v = mN(b,20,&tam);
    for(int i=0;i<tam;i++){
        printf("%d,", v[i]);
    }
    return 0;
}