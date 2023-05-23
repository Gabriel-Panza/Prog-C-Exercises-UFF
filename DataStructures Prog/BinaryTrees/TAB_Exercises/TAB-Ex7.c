#include <stdio.h>
#include "TAB/TAB.c"

void colore_aux(TAB* pai, TAB* a){
    if (!a) return;
    a->cor = !(pai->cor);
    colore_aux(a, a->esq);
    colore_aux(a, a->dir);
}
void colore(TAB* a){
    if (!a) return;
    a->cor = 1;
    colore_aux(a, a->esq);
    colore_aux(a, a->dir);
}


// void colore (TAB* arv)
// {
//     if (!arv)
//         return;
//     colore(arv->esq);
//     colore(arv->dir);
//     if (arv->esq || arv->dir){
//         if (arv->esq){
//             if (arv->esq->cor == 1) 
//                 arv->cor = 0;
//             else 
//                 arv->cor = 1;
//         }else{
//             if (arv->dir->cor == 1) 
//                 arv->cor = 0;
//             else 
//                 arv->cor = 1;
//         }
//     }
//     else
//         arv->cor = 1;
// }

int main()
{
    TAB *a;

    a = TAB_cria(7,TAB_cria(5,NULL,TAB_cria(8,TAB_cria(2,NULL,NULL),TAB_cria(3,TAB_cria(4,NULL,TAB_cria(6,NULL,NULL)),NULL))),TAB_cria(2,TAB_cria(1,TAB_cria(10,NULL,NULL),TAB_cria(4,NULL,NULL)),TAB_cria(9,TAB_cria(8,NULL,NULL),TAB_cria(0,TAB_cria(3,NULL,NULL), NULL))));

    colore(a);    
    TAB_imp_ident(a);
    TAB_libera(a);

    return 0;
}