#include <stdio.h>
#include "TARVBM/TARVBM.c"

int main(){
    TARVBM* b = TARVBM_cria(2);
    b = TARVBM_insere(b,20,2);
    b = TARVBM_insere(b,50,2);
    b = TARVBM_insere(b,60,2);
    b = TARVBM_insere(b,1,2);
    b = TARVBM_insere(b,64,2);
    b = TARVBM_insere(b,12,2);
    b = TARVBM_insere(b,18,2);
    b = TARVBM_insere(b,66,2);
    b = TARVBM_insere(b,38,2);
    
    b = TARVBM_retira(b,1,2);
    return 0;
}