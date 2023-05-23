#include<stdio.h>
void calc_run(float dist, float *b1, float *b2){
    float fixedFlag = 4.95;
    float flag1,flag2;
    *b1=fixedFlag+(2.5*dist);
    *b2=fixedFlag+(3*dist);
}
int main(){
    float dist, flag1=0, flag2=0;
    scanf("%f",&dist );
    calc_run(dist,&flag1,&flag2);
    printf("Flag 1: %.2f \nFlag 2: %.2f", flag1,flag2);
    return 0;
}