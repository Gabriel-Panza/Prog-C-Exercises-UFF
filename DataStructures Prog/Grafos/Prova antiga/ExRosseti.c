#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "TG/TG.c"

// Função recursiva para calcular o menor caminho
int define_menor_caminho(TG *g, int k, int p, int visitados[], int menor_caminho[]) {
    // Se alcançar o destino, o custo é 0 porque não precisa se mover mais
    if (k == p) return 0;

    // Se já visitou este nó, retornar o caminho mínimo já encontrado
    if (visitados[k] != -1) return menor_caminho[k];

    visitados[k] = 1;  // Marca como visitado
    TG *node = TG_busca_no(g, k);
    int min_dist = INT_MAX;

    for (TVIZ *v = node->prim_viz; v != NULL; v = v->prox_viz) {
        if (visitados[v->id_viz] == -1 || menor_caminho[v->id_viz] > menor_caminho[k]) {
            int dist = define_menor_caminho(g, v->id_viz, p, visitados, menor_caminho);
            if (dist != INT_MAX) {
                if (min_dist > (v->peso_aresta + dist))
                    min_dist = v->peso_aresta + dist;
            }
        }
    }

    visitados[k] = -1;  // Desmarca como visitado
    menor_caminho[k] = min_dist;  // Atualiza o caminho mínimo para este nó
    return menor_caminho[k];
}

// Função para iniciar a busca do menor caminho
int procura_menor_caminho(TG *g, int k, int p) {
    int n = 0; // Número de nós no grafo
    TG *temp = g;
    while (temp) {
        temp = temp->prox_no;
        n++;
    }
    int visitados[n];
    int menor_caminho[n];
    for (int i = 0; i < n; i++) {
        visitados[i] = -1;
        menor_caminho[i] = INT_MAX;
    }

    return define_menor_caminho(g, k, p, visitados, menor_caminho);
}

int main()
{
    TG *g = TG_inicializa();
    int k,p;

    // Inserção de nós e arestas
    for (int i=0;i<10;i++){
        g=TG_ins_no(g,i);  
    }
    TG_ins_aresta(g, 0, 1, 2);
    TG_ins_aresta(g, 0, 3, 6);
    TG_ins_aresta(g, 1, 4, 3);
    TG_ins_aresta(g, 1, 2, 1);
    TG_ins_aresta(g, 2, 5, 5);
    TG_ins_aresta(g, 2, 3, 2);
    TG_ins_aresta(g, 3, 6, 8);
    TG_ins_aresta(g, 4, 5, 3);
    TG_ins_aresta(g, 5, 7, 1);
    TG_ins_aresta(g, 6, 7, 3);
    TG_ins_aresta(g, 7, 8, 6);
    TG_ins_aresta(g, 8, 9, 3);
    TG_ins_aresta(g, 9, 7, 7);
    
    printf("Digite o valor do nó de inicio: ");
    scanf("%d", &k);
    printf("\nDigite o valor do nó final: ");
    scanf("%d", &p);

    int result = procura_menor_caminho(g,k,p);
    if (result == INT_MAX) {
        printf("\nNão existe caminho de %d para %d.\n", k, p);
    } else {
        printf("\nMenor caminho de %d para %d é %d.\n", k, p, result);
    }

    TG_libera(g);
    return 0;
}