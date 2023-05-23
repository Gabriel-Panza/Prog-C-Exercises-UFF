#include<stdio.h>
#include<stdlib.h>
int test_AP (int n, int* v){
    int  j, cont=0, dif=0;
    dif=(v[1]-v[0]);
    for(j=0;j<n-1;j++){
        if((v[j+1]-v[j])==dif){
            cont++;
        }
    }

    if(cont==(n-1)){
        return dif;
    }
    else
        return 0;
}
int main(){
    int n,i, ap;
    int* v;
    scanf("%d",&n);
    v=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++){
        scanf("%d", &v[i]);
    }
    ap=test_AP(n,v);
    printf("%d", ap);
    return 0;
}
