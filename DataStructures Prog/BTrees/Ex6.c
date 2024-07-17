#include <stdio.h>
#include "TARVB/TARVB.c"

// função em C que, dada uma árvore qualquer, retire todos os elementos pares da
// árvore original. A função deve ter o seguinte protótipo: TARVB* retira_pares
// (TARVB* a);

TARVB* retira_pares (TARVB* a){
    if(!a) return NULL;
    int i = 0;
    while(i < a->nchaves){
        if(a->chave[i] % 2 == 0) 
            a = TARVB_Retira(a, a->chave[i], 2);
        else 
            i += 1; //so incrementa o i se não tirou ngm, se tirou tem q ver de novo o nó
    }
    if(!a->folha){
        i = 0;
        while(i <= a->nchaves){
            a->filho[i] = retira_pares(a->filho[i]);
            i++;
        }
    }
    return a;
}

int main(){
    TARVB *b = TARVB_Inicializa();
    int t;
    printf("Digite o grau minimo. Se o valor digitado for menor que 2, t sera considerado igual a 2...\n");
    scanf("%d", &t);
    if(t < 2) t = 2;
    b = TARVB_Cria(t);
    b = TARVB_Insere(b,20,t);
    b = TARVB_Insere(b,50,t);
    b = TARVB_Insere(b,60,t);
    b = TARVB_Insere(b,1,t);
    b = TARVB_Insere(b,64,t);
    b = TARVB_Insere(b,12,t);
    b = TARVB_Insere(b,18,t);
    b = TARVB_Insere(b,66,t);
    b = TARVB_Insere(b,38,t);
    b = TARVB_Insere(b,7,t);
    b = TARVB_Insere(b,70,t);
    TARVB_Imprime(b);

    TARVB *aux = retira_pares(b);
    TARVB_Imprime(aux);

    TARVB_Libera(b);

    return 0;
}