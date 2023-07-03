#include <stdio.h>
#include "TH.h"

void f(char *hash, char*dados, int N, int mat, float cr){ 
    FILE *fp = fopen(hash,"rb");
    if(!fp) exit(1);
    int h = hash(mat,N), pos;
    fseek(fp,h*sizeof(int),SEEK_SET);
    fread(&pos,sizeof(int),1,fp);
    fclose(fp);
    if(pos== -1) return;
    fp = fopen(dados,"rb+");
    if(!fp) exit(1);
    TA a;
    while(pos!= -1){
        fseek(fp,pos,SEEK_SET);
        fread(&a,sizeof(TA),1,fp);
        if(a.cr <= cr && a.status){
            a.status = 0;
            fseek(fp,pos,SEEK_SET);
            fwrite(&a,sizeof(TA),1,fp);
        }
        pos = a.prox;
    }
    fclose(fp);
}

int main(){
    return 0;
}