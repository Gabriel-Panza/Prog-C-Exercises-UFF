#include<stdio.h>
void calcula_corrida(float dist, float *b1, float *b2){
    float bandeirada = 4.95;
    float ban1,ban2;
    *b1=bandeirada+(2.5*dist);
    *b2=bandeirada+(3*dist);
}
int main(){
    float dist, ban1=0, ban2=0;
    scanf("%f",&dist );
    calcula_corrida(dist,&ban1,&ban2);
    printf("bandeira 1: %.2f\nbandeira 2: %.2f", ban1,ban2);
    return 0;
}