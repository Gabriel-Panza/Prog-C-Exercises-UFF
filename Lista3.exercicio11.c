#include <stdio.h>
#define N 2

int main(){
    char genero[N];
    int idade[N];
    float altura[N];
    int i,contador=0, contHomem=0;
    float total_altura = 0, media_altura,variancia;

    for(i=0;i<N;i++){
        printf("Digite seu genero: M ou F-> ");
        scanf(" %c",&genero[i]);
        printf("Digite sua idade: ");
        scanf("%d",&idade[i]);
        printf("Digite sua altura: ");
        scanf("%f",&altura[i]);
        total_altura +=altura[i];
    }
    media_altura = total_altura/N;
    for(i=0;i<N;i++){

        //printf("genero: %c idade: %d altura: %f\n",genero[i],idade[i],altura[i] );
        if((genero[i]=='F' || genero[i]=='f') && (idade[i]>=20 && idade[i]<=35)){
            contador++;
        }
        else if((genero[i]=='M' || genero[i]=='m') && altura[i]>1.80){
            contHomem++;
        }
        variancia +=((altura[i]-media_altura)*(altura[i]-media_altura));


    }
    variancia /= N - 1;

    printf("Existem %d mulheres com idade entre 20 a 35 anos\nExistem %d homens maiores que 1,80 m de altura\n", contador, contHomem);
    printf("A variancia das alturas eh: %.2f", variancia);
    return 0;
}
