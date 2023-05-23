#include <stdio.h>
#include <stdlib.h>
int verify(int *vector, int number, int len){
    int i, j;
    for(i=0;i<len;i++){
        if(vector[i]==number){
            return 1;
        }
    }
    return 0;
}
int main() {
    int x[5];
    int R[5];
    int S[10];
    int i, j, cont=0;
    for (i = 0; i < 5; i++) {
        x[i]=NULL;
    }
    printf("Type 5 integers numbers: \n");
    for (i = 0; i < 5; i++) {
        scanf("%d", &R[i] );
    }
    printf("Type 10 integers numbers: \n");
    for (i = 0; i < 10; i++) {
        scanf("%d", &S[i] );
    }
    for(i=0;i<5;i++){
        if(verify(S,R[i], 10)){
            if(!verify(x,R[i], 5)){
                x[cont]=R[i];
                cont++;
            }
        }
    }
    for(i=0;i<5;i++){
        if(x[i]!=NULL)
            printf("\n%d\n",x[i]);
    }
    return 0;
}
