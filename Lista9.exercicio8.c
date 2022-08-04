#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data {
    int dd, mm, aa; /* Dia, mes e ano */
};
typedef struct data Data;

struct compromisso {
    char descricao[81]; /* Descricao do compromisso */
    Data dta; /* Data do compromisso */
};
typedef struct compromisso Compromisso;

Compromisso* busca(int n, Compromisso** vet, int d, int m, int a){
    int inicio = 0;
    int fim = n-1;
    while( inicio <= fim){
        int meio = (inicio + fim)/2;
        if(a <= vet[meio]->dta.aa && m <= vet[meio]->dta.mm && d < vet[meio]->dta.dd){
            fim = meio-1;
        } else if(a >= vet[meio]->dta.aa && m >= vet[meio]->dta.mm && d > vet[meio]->dta.dd){
            inicio = meio + 1;
        } else{
            return vet[meio];
        }
    }
    return NULL;
}
