#include <stdio.h>
#include <stdlib.h>
#include "TG/TG.c"

int contavizinhos(TVIZ *v){
    if(!v)
        return 0;
    return 1 + contavizinhos(v->prox_viz);
}
int nv(TG *g)
{
    int cont = 0;
    if (!g) return cont;
    while (g){
        cont += contavizinhos(g->prim_viz);
        g = g->prox_no;
    }
    return cont;
}

int main()
{
    TG *g = TG_inicializa();
    for (int i=0;i<10;i++)
    {
        g=TG_ins_no(g,i);
        if (i>0)
            TG_ins_um_sentido(g,i-1,i);    
    }

    int qnt = nv(g);
    printf("Quantity of edges: %d", qnt);

    TG_libera(g);
    return 0;
}