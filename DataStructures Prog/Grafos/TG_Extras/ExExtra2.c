#include <stdio.h>
#include <stdlib.h>
#include "TG/TG.c"

int numero_seguidos(TG *g, char *nome){
    if (!g) return -1;
    TG* pessoa;
    while (g){
        if (g->nome == nome){
            pessoa = g;
            break;
        }
        g = g->prox_no;
    }
    TVIZ *seguindo = pessoa->prim_viz;
    int cont = 0;
    while (seguindo){
        cont+=1;
        seguindo = seguindo->prox_viz;
    }
    return cont;
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

    char *nome = "Pedro";
    int segue = numero_seguidos(g,nome);
    if (segue>=0) printf("The person %s follows %d people", nome, segue);
    else printf("Person not found!");

    TG_libera(g);
    return 0;
}