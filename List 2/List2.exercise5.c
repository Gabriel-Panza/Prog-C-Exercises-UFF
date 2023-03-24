#include <stdio.h>

int main(){
    int x, z, t, i=1;
    printf("Type a value of x ");
    scanf("%d",&x);
    t = x;
    printf("Type a value of z ");
    scanf("%d",&z);
    while (z<x){
        printf("Type a new value of z ");
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