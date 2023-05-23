#include <stdio.h>
#include <stdlib.h>
#include "TG/TG.c"

int seguidores(TG *g, char *nome, int imprime){
    if (!g) return -1;
    int cont = 0;
    TVIZ *seguindo;
    while (g){
        seguindo = g->prim_viz;
        while (seguindo){
            if (seguindo->nome == nome){
                cont+=1;
                imprime = 1;
            }
            seguindo = seguindo->prox_viz;
        }
        if (imprime!=0){
            printf("%s\n", g->nome);
            imprime = 0;
        }
        g = g->prox_no;
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
    int seguido = seguidores(g,nome,0);
    if (seguido>=0) printf("The person %s is followed by %d people", nome, seguido);
    else printf("Person not found!");

    TG_libera(g);
    return 0;
}