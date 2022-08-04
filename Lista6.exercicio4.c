#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

/*
4. Todo ano um concurso de programação premia os participantes que obtêm a maior
média ponderada em uma bateria de dois testes. 

Escreva uma função que recebe sete parâmetros: 
- o inteiro n indicando a quantidade de participantes do concurso, 
- o ponteiro inscr para o vetor de inteiros que contém as inscrições desses participantes, 
- o ponteiro t1 para o vetor de reais que contém a nota de cada participante no primeiro teste, 
- o inteiro p1 que indica o peso dessa nota na média ponderada, 
- o ponteiro t2 para o vetor de reais que contém a nota de cada participante no segundo teste, 
- o inteiro p2 que indica o peso dessa nota na média ponderada, 
- e um ponteiro para a variável inteira tam.

A função deve:
● calcular a média ponderada de cada participante;
● criar um novo vetor de inteiros alocado dinamicamente com o tamanho exato
para conter apenas as inscrições dos participantes que obtiveram a maior média (pode
haver empate);
● armazenar no novo vetor as inscrições correspondentes (em qualquer ordem);
● armazenar o tamanho do novo vetor na variável tam; e
● retornar o ponteiro para o novo vetor.

Considere que para uma mesma posição do vetor (mesmo índice), a inscrição e as notas
se referem a um mesmo participante. O protótipo da função é:

int *premiados(int n, int *inscr, float *t1, int p1,float *t2, int p2, int *tam);
*/

int *premiados(int n, int *inscr, float *t1, int p1,float *t2, int p2, int *tam);

int main(){
    int n, p1, p2, tam;
    int* inscr, * class;
    float* t1, * t2;


    setlocale(LC_ALL, "Portuguese");

    //tamanho do vetor inscritos
    printf("Digite o número de participantes: ");
    scanf("%d", &n);

    printf("%d\n", n);

    //aloca vetores
    inscr = (int*) malloc(n * sizeof(int));
    t1 = (float*) malloc(n * sizeof(float));
    t2 = (float*) malloc(n * sizeof(float));

    if( inscr == NULL ){
        printf("ERROR ALOC");
        exit(1);
    }  
    if( t1 == NULL ){
        printf("ERROR ALOC");
        exit(1);
    }  
    if( t2 == NULL ){
        printf("ERROR ALOC");
        exit(1);
    }            

    //preenche inscr
    for(int i = 0; i < n; i++){
        printf("Digite o número da inscrição %d: ", i);
        scanf("%d", &inscr[i]);
    }
    
    //checha preenchimento
    for (int i = 0; i < n; i++){
        printf("I%d\n", inscr[i]);
    }

    //Pesos
    printf("Digite o peso dos T1: ");
    scanf("%d", &p1);
    printf("Digite o peso dos T2: ");
    scanf("%d", &p2);

    //T1 e T2
    for (int i = 0; i < n; i++){
        printf("Digite a nota do teste 1 do inscrito %d:  ", i);
        scanf("%f", &t1[i]);
        printf("Digite a nota do teste 2 do inscrito %d:  ", i);
        scanf("%f", &t2[i]);
    }

    // verifica preench I ( insc ) N (nota do teste)
    /*
    for (int i = 0; i < n; i++){
        printf("T1: I%d - N%.2f \n", i, t1[i]);
        printf("T2: I%d - N%.2f \n", i, t2[i]);
    }
    */

    //ranking
    class = premiados(n, inscr, t1, p1, t2, p2, &tam);

    //printf("TAM - %d", tam);

    //checa tudo ok
    /*
    for(int i = 0; i < tam; i++){
        printf("MP - %d\n", class[i]);
    }
    */
   
    free(inscr);
    free(t1);
    free(t2);
    free(premiados);
    free(class);

    return 0;
}

int *premiados(int n, int *inscr, float *t1, int p1,float *t2, int p2, int *tam){

    int* premiados;
    int cont_premiado = 0, cont = 0;
    float med = 0, * media;

    //media
    media = (float*) malloc(n * sizeof(float));
    if( media == NULL ){
        printf("ERROR ALOC");
        exit(1);
    } 

    //Preenche P1 e P2
    for (int i = 0; i < n; i++){
        media[i] = (t1[i]*p1 + t2[i]*p2) / p1 + p2;
        med += media[i];
    }

    //media geral
    med /= n;
    //printf("MG - %.2f\n", med);

    
    //testa media alocada e gera tam dos classificados
    //P1 e P2
    for (int i = 0; i < n; i++){
        //printf("M%d - %.2f\n", i, media[i]);
        if(media[i]>=med){
            cont_premiado++;
        }
    }
    //Atualizar tam
    *tam = cont_premiado;

    //printf("%d", cont_premiado);

    //aloc class
    premiados = (int*) malloc(cont_premiado * sizeof(int));
    
    if( premiados == NULL ){
        printf("ERROR ALOC");
        exit(1);
    } 
    
    
    //classificação
    for(int j = 0; j < n; j++){
        if(media[j] >= med){
            premiados[cont] = inscr[j];
            cont++;
        }
    }
    /*
    for(int i = 0; i < cont_premiado; i++){
        printf("MP - %d\n", premiados[i]);
    }

    */

    

    free(media);
    
    return premiados;
}