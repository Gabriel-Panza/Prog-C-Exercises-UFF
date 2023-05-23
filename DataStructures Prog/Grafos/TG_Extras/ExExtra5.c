#include <stdio.h>
#include <stdlib.h>
#include "TG/TG.c"

int segue_mais_velho(TG *g, int imprime){
    if (!g) return -1;
    int cont = 0, pessoas = 0;
    TVIZ *seguindo;
    while (g){
        seguindo = g->prim_viz;
        while (seguindo){
            if (seguindo->idade > g->idade){
                cont+=1;
                imprime = 1;
                seguindo = seguindo->prox_viz;
            }
            else{
                cont = 0;
                imprime = 0;
                break;
            }
        }
        if (imprime!=0){
            printf("%s\n", g->nome);
            imprime = 0;
            pessoas+=1;
        }
        g = g->prox_no;
    }
    return pessoas;
}

int main(){
    TG *g = TG_inicializa();
    g=TG_ins_no(g,8, "Renata", 35);
    g=TG_ins_no(g,7, "Bruna", 23);
    g=TG_ins_no(g,6, "Pedro", 20);
    g=TG_ins_no(g,5, "Caio", 20);
    g=TG_ins_no(g,4, "Felipe", 20);
    g=TG_ins_no(g,3, "Marcos", 19);
    g=TG_ins_no(g,2, "Jane", 30);
    g=TG_ins_no(g,1, "Ana", 23);
    g=TG_ins_no(g,0, "Joao", 25);
    TG_ins_um_sentido(g,0,1);
    TG_ins_um_sentido(g,0,5);
    TG_ins_um_sentido(g,0,6);
    TG_ins_um_sentido(g,1,0);
    TG_ins_um_sentido(g,1,2);
    TG_ins_um_sentido(g,2,3);
    TG_ins_um_sentido(g,2,6);
    TG_ins_um_sentido(g,2,7);
    TG_ins_um_sentido(g,3,4);
    TG_ins_um_sentido(g,3,8);
    TG_ins_um_sentido(g,4,3);
    TG_ins_um_sentido(g,4,8);
    TG_ins_um_sentido(g,6,5);
    TG_ins_um_sentido(g,6,2);
    TG_ins_um_sentido(g,6,3);
    TG_ins_um_sentido(g,6,7);
    TG_ins_um_sentido(g,7,8);

    int mais_velho = segue_mais_velho(g,0);
    if (mais_velho>=0) printf("There are %d people who only follow people older than themselves", mais_velho);
    else printf("None follow people older them themselves!");

    TG_libera(g);
    return 0;
}