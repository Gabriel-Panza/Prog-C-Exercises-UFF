#include <stdio.h>
#include <stdlib.h>

typedef struct arvbin{
  int info;
  struct arvbin *esq, *dir;
  int cor;
}TAB;

TAB *TAB_inicializa(void);
TAB *TAB_cria(int raiz, TAB *esq, TAB *dir);

void TAB_imp_pre(TAB *a);   //Pre-ordem (R,E,D)
void TAB_imp_sim(TAB *a);   //Simetrico (E,R,D)
void TAB_imp_pos(TAB *a);   //Pos-ordem (E,D,R)
void TAB_imp_ident(TAB *a); //Print identado

void TAB_libera(TAB *a);

TAB *TAB_busca(TAB *a, int elem);
