#include<stdio.h>
#include<stdlib.h>
int testa_PA (int n, int* v){
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
    int n,i, pa;
    int* v;
    scanf("%d",&n);
    v=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++){
        scanf("%d", &v[i]);
    }
    pa=testa_PA(n,v);
    printf("%d", pa);
    return 0;
}
