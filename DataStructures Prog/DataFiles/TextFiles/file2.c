#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compara(const void *p1, const void *p2){
    int *i1 = (int*)p1, *i2 = (int*)p2;
    if((*i1)>(*i2)) return 1;
    if((*i1)<(*i2)) return -1;
    return 0;
}

int ci(char*in, char*parte, int tamMP){
    FILE *fp = fopen(in, "r");
    if (!fp) exit(1);
    int vet[tamMP],i,resp=1;
    while(1){
        i=0;
        int r = fscanf(fp, "%d", &vet[i]);
        while ((r==1) && (i<tamMP)){
            i++;
            r = fscanf(fp, "%d", &vet[i]);
        }
        if((!i) && (r!=1)) break;
        qsort(vet, i, sizeof(int), compara);
        resp++;
        char nomepart[51],aux[5];
        strcpy(nomepart,parte);
        sprintf(aux, "%d-",resp);
        strcat(nomepart,aux);
        strcat(nomepart,in);
        FILE *out = fopen(nomepart,"w");
        if(!out) exit(1);
        for(int j=0;j<i;j++){
            fprintf(out, "%d\n", vet[j]);
        }
        fclose(out);
    }
    fclose(fp);
    return resp;
}

int main(){
    FILE *fp = fopen("fp.txt", "w");
    if (!fp) exit(1);
    int n;
    scanf("%d", &n);
    if (n<=0) exit(1);
    int i = 1, vet[n], elem;
    scanf("Vet: %d", &vet[0]);
    while(i<n){
        scanf("Vet: %d", &elem);
        if (elem != vet[i-1]) vet[i++] = elem;
    }
    fwrite(vet, sizeof(int), 1, fp);
    fclose(fp);

    printf("Created %d files", ci("fp.txt","part.txt",5));

    return 0;
}