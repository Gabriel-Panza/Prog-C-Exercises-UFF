#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int bb_arq(char *narq, int elem){
    FILE *fp = fopen(narq,"rb");
    if (!fp) exit(1);

    int ini = 0, meio, fim, elem_meio;
    fseek(fp, 0L, SEEK_END);
    fim = ftell(fp);

    while(ini<=fim){
        meio = (((ini+fim) / sizeof(int)) / 2) * sizeof(int);
        fseek(fp, meio, SEEK_SET);
        fread(&elem_meio, sizeof(int), 1, fp);
        if(elem_meio == elem) return meio;
        if(elem_meio < elem) ini = meio+sizeof(int);
        else fim = meio-sizeof(int);
    }
    return -1;
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
    printf("What number I should try to find?");
    scanf("%d", &elem);
    fp = fopen(argv[1], "rb");
    int pos = bb_arq(fp, elem);
    rewind(fp);
    int resp[n];
    fread(resp, sizeof(int), n, fp);
    for(i = 0; i < n; i++) printf("%d ", resp[i]);
    printf("\n");
    fclose(fp);
    printf("%d e o %lld-esimo elemento do meu arquivo (%d)\n", elem, pos/sizeof(int) + 1, pos);
    if (pos >= 0) printf("%d e o %ld-esimo elemento do meu arquivo (Position %d inside the file)\n", elem, pos/sizeof(int) + 1, pos);
    else printf("Element not found!");
    return 0;
}