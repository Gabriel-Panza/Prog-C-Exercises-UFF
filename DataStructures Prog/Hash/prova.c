#include <stdio.h>
#include <stdlib.h>
#include "TH.h"

int mi(char* arq1, char* arq2){
    FILE *f1 = fopen(arq1, "rb+");
    if (!f1) exit(1);
    FILE *f2 = fopen(arq1, "rb+");
    if (!f2) exit(1);
    char *hash, *dados;
    TH_inicializa(hash,dados,7);
    TNUM aux;
    while(fread(&aux,sizeof(TNUM),1,f1) == 1){
        TH_insere(hash,dados,7,aux.elem);
    }
    while(fread(&aux,sizeof(TNUM),1,f2) == 1){
        if (TH_busca(hash,dados,7,aux.elem)==1) break;
    }
    if (fread(&aux,sizeof(TNUM),1,f2) != 1) return 1;
    else return 0;
}