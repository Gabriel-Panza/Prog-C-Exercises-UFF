#include <stdio.h>
#include <stdlib.h>
#define N 4

int menor_caminho(int n, int m[N][N], int k, int p) {
    int visitados[n];
    int distancia[n];
    int fila[n];
    int inicio_fila = 0, final_fila = 0;

    // Inicializa visitados e distancia
    for (int i = 0; i < n; i++) {
        visitados[i] = 0;
        distancia[i] = -1;
    }

    // Inicia a partir do nó de origem
    visitados[k] = 1;
    distancia[k] = 0;
    fila[final_fila] = k;
    final_fila += 1;

    while (inicio_fila < final_fila) {
        int atual = fila[inicio_fila++];

        for (int i = 0; i < n; i++) {
            if (m[atual][i] == 1 && !visitados[i]) {
                visitados[i] = 1;
                distancia[i] = distancia[atual] + 1;
                fila[final_fila] = i;
                final_fila += 1;

                // Se alcançar o destino, retorna a distância
                if (i == p) {
                    return distancia[i];
                }
            }
        }
    }

    // Retorna -1 se não houver caminho
    return -1;
}

int main() {
    int m[N][N] = {
        {0, 1, 1, 1},
        {0, 1, 0, 0},
        {1, 0, 1, 1},
        {0, 0, 1, 1}
    };
    printf("Digite o valor da cidade inicial k (entre 0 e 3): ");
    scanf("%d", &k);
    printf("\nDigite o valor da cidade final p (entre 0 e 3):: ");
    scanf("%d", &p);

    int result = menor_caminho(N, m, k, p);
    if (result != -1) {
        printf("Menor caminho de %d para %d é de %d passo(s).\n", k, p, result);
    } else {
        printf("Não há caminho de %d para %d.\n", k, p);
    }

    return 0;
}