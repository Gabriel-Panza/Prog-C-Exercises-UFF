#include <stdio.h>

int main(){
    int x, z, t, i=1;
    printf("Digite um valor para x ");
    scanf("%d",&x);
    t = x;
    printf("Digite um valor para z ");
    scanf("%d",&z);
    while (z<x){
        printf("Digite um novo valor para z ");
        scanf("%d",&z);
    }
    if (z==x){
        printf("1");
    }else
        while (z>=t){
            t= t+(x+i);
            i+=1;
            if (z<=t){
                printf("%d ", i);
        }
    }

    return 0;
}