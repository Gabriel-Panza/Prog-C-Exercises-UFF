#include <stdio.h>
#include "TAB/TAB.c"

TAB* Vet2ab(int *vet, int n){
    if (n<=0) return 0;
    return TAB_cria(vet[n/2], Vet2ab(vet,n/2), Vet2ab(&vet[(n/2)+1], n-(n/2)-1));
}
int maior (int x, int y){
    if(x>=y) return x;
    return y;
}
int calc_alt(TAB* ab){
    if(!ab) return -1;
    return 1 + maior(calc_alt(ab->esq),calc_alt(ab->dir));
}
int main(){
    int vet[10] = {1,2,3,4,5,6,7,8,9,10};
    TAB *ab = Vet2ab(vet,10);
    TAB_imp_ident(ab);
    printf("\n%d",calc_alt(ab));

    TAB_libera(ab);

    return 0;
}