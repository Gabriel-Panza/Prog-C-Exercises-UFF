#include <stdio.h>
#include "TARVB/TARVB.c"

void len(TARVB*a, int *tam, int N, int M){
    if (!a) return;
    int i=0;
    while (i<a->nchaves){
        if (a->chave[i]>N && a->chave[i]<M) ++*tam;
        len(a->filho[i],tam,N,M);
        i++;
    }
    len(a->filho[i],tam,N,M);
}
void add_no_vetor(TARVB*a, int *vet, int N, int M, int *pos){
    if (!a) return;
    int i=0;
    while (i<a->nchaves){
        add_no_vetor(a->filho[i],vet,N,M,pos);
        if(a->chave[i]>N && a->chave[i]<M) {
            vet[*pos] = a->chave[i];
            ++*pos;
        }
        i++;
    }
    add_no_vetor(a->filho[i],vet,N,M,pos);
}
int *mN(TARVB*a, int N, int M, int *tam){
    if (!a) return NULL;
    len(a,tam,N,M);
    int *vet = (int*) malloc((*tam)*sizeof(int));
    int pos=0;
    add_no_vetor(a,vet,N,M,&pos);
    return vet;
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
    b = TARVB_Insere(b,7,2);
    b = TARVB_Insere(b,70,2);

    int tam=0;
    int *lista = mN(b,30,70,&tam);
    TARVB_Imprime(b);
    TARVB_Libera(b);
    printf("\n----------------------------------\n");
    for(int index=0; index<tam; index++){
        printf("[%d]", lista[index]);
    }
    free(lista);
    return 0;
}