#include <stdio.h>
#include <stdlib.h>

/*
void inverte_vetor(int *v1, int *v2, int n)
{
    if (n>0)
    {
        v2[0] = v1[n-1];
        inverte_vetor(v1,v2+1,n-1);
    }
}
void main()
{
    int v1[5] = {1,2,3,4,5};
    int v2[5] = {0,0,0,0,0};
    inverte_vetor(v1,v2,5);

    for (int i=0;i<5;i++)
        printf("%d", v2[i]);
}
*/

/*
void printavetor(int* v, int p)
{
    printf("[");
    for (int i=0;i<p;i++){
        printf("%d ",v[i]);
    }
    printf("]");
}

int bubblesort(int* v, int k)
{
    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            if(v[j]>v[j+1]){
                int temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
            }
        }
    }
}

void merge(int *v1, int *v2, int t1, int t2)
{
    int contador = 0;
    int* v = (int*) malloc((t1+t2)*sizeof(int));
    for(int i=0;i<t1;i++){
        v[i] = v1[i];
        contador += 1;
    }
    for(int i=0;i<t2;i++){
        v[i+contador] = v2[i];
    }

    bubblesort(v,16);
    printavetor(v,16);
}


int main() {
    int a[8] = {1,9,2,8,3,7,6,5};
    int b[8] = {20,19,18,17,16,15,14,13};
    merge(a,b,8,8);
}
*/

/*
void printavetor(int* v, int tam)
{
    for (int i=0;i<tam;i++)
    {
        printf("%d ",v[i]);
    }
}

void merge(int* a , int* b , int tam_A, int tam_B)
{
    int i, j, k=0;
    int* v = (int*)malloc((tam_A + tam_B)*sizeof(int));

    for(i=0, j=0; i<tam_A || j<tam_B;)
    {
        if (a[i]<b[j])
            v[k++] = a[i++];
        else
            v[k++] = b[j++];
    }
    printavetor(v3,tam_A+tam_B);
}

int main()
{
    int n , m;
    printf("Digite o tamanho dos vetores: ");
    scanf("%d %d" , &n , &m);
    int* v1 = (int*)malloc(n*sizeof(int));
    int* v2 = (int*)malloc(m*sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d" , &v1[i]);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d" , &v2[i]);
    }
    merge(v1,v2,n,m);
}
*/

/*
typedef struct terreno
{
    int alt;
    int larg;
    float **elevacao;
}Terreno;

typedef struct coord
{
    int i;
    int j;
}Coord;

void detecta_picos_locais(Terreno *t, int k, Coord *v, int *n_picos)
{

}

void main()
{
    Terreno* t = (Terreno*) malloc(sizeof(Terreno));
    Coord* v = (Coord*) malloc(sizeof(Coord));
    int* n_picos = (int*) malloc(sizeof(int));
    int k;
    printf("Digite a dimensao do terreno: ")
    scanf("%d", &k)

    detecta_picos_locais(t,k,v,n_picos)
}
*/

/*
typedef struct fichaMedica
{
    char nome[81];
    int idade;
    char doenca[81];
}Ficha;

void main()
{
    Ficha *f = (Ficha*) malloc(5*sizeof(Ficha));

    for (int i=0;i<5;i++)
    {
        printf("Informe o nome do paciente %d: ", i+1);
        gets(f[i].nome);
        printf("Informe a idade do paciente %d: ", i+1);
        scanf("%d", &f[i].idade);
        printf("Informe a doenca do paciente %d: ", i+1);
        gets(f[i].doenca);
    }
    for (int i=0;i<5;i++)
    {
        printf("Paciente %d: %s, %d, %s \n", i+1, f[i].nome, f[i].idade, f[i].doenca);
    }
    free(f);
}
*/

void main()
{
    int linha, coluna;
    scanf("%dx%d", &linha, &coluna);
    int **matriz = (int**) malloc(linha*sizeof(int*));

    for (int i=0; i<linha; i++)
    {
        matriz[i] = (int*) malloc(coluna*sizeof(int));
    }

    for (int i=0; i<linha; i++)
    {
        for (int j=0; j<coluna; j++)
        {
            scanf("%d", &matriz[i][j]);
        }
    }
}