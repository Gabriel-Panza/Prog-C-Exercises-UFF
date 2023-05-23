#include <stdio.h>
#include "TAB/TAB.c"

int main(){
    TAB *ab = TAB_cria(7,TAB_cria(5,NULL,TAB_cria(8,TAB_cria(2,NULL,NULL),TAB_cria(3,TAB_cria(4,NULL,TAB_cria(6,NULL,NULL)),NULL))),TAB_cria(2,TAB_cria(1,TAB_cria(10,NULL,NULL),TAB_cria(4,NULL,NULL)),TAB_cria(9,TAB_cria(8,NULL,NULL),TAB_cria(0,TAB_cria(3,NULL,NULL), NULL))));
    TAB_imp_ident(ab);
    printf("\n");
    TAB_imp_pre(ab);
    printf("\n");
    TAB_imp_sim(ab);
    printf("\n");
    TAB_imp_pos(ab);
    printf("\n");

    TAB_libera(ab);
    
    return 0;
}