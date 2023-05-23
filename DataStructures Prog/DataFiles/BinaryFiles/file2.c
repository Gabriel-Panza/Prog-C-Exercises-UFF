#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ob_arq(char *narq){
    FILE *fp = fopen(narq,"rb+");
    if (!fp) exit(1);

    int r1, r2, elem_i, elem_menor, elem_j, i=0, menor, j;
    while (1){
        r1=fread(&elem_i,sizeof(int),1,fp);
        if(r1!=1){
            fclose(fp);
            return;
        }
        elem_menor = elem_i;
        menor = i;
        j=i+sizeof(int);
        while(1){
            r2=fread(&elem_j,sizeof(int),1,fp);
            if(r2!=1) break;
            if(elem_j<elem_menor){
                elem_menor = elem_j;
                menor = j;
            }
            j+=sizeof(int);
        }
        if(menor!=i){
            fseek(fp,i,SEEK_SET);
            fwrite(&elem_menor,sizeof(int), 1, fp);
            fseek(fp,menor,SEEK_SET);
            fwrite(&elem_i,sizeof(int), 1, fp);
        }
        i+=sizeof(int);
        fseek(fp,i,SEEK_SET);
    }
}

int main(int argc, char** argv){
    FILE *fp = fopen(argv[1], "wb");
    if (!fp) exit(1);
    int n;
    scanf("%d", &n);
    if (n<=0) exit(1);
    int i = 1, vet[n], elem;
    scanf("%d", &vet[0]);
    while(i<n){
        scanf("%d", &elem);
        if (elem > vet[i-1]) vet[i++] = elem;
    }
    fwrite(vet, sizeof(int), 1, fp);
    fclose(fp);
    fp = fopen(argv[1], "rb");
    ob_arq(fp);
    fclose(fp);
    return 0;
}