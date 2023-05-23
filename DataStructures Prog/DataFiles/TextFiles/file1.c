#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(char *a1, char *a2, char *resp){
    FILE *fp1 = fopen(a1,"r"), *fp2 = fopen(a2,"r"), *fpr = fopen(resp,"w");
    if ((!fp1) || (!fp2) || (!fpr)) exit(1);

    int n1,n2,r1,r2;
    r1 = fscanf(fp1, "%d", &n1);
    r2 = fscanf(fp2, "%d", &n2);
    while(1){
        if ((r1!=1) && (r2!=1)) break;
        if ((r2!=1) || (n1<=n2)){
            fprintf(fpr, "%d\n", n1);
            r1 = fscanf(fp1, "%d", &n1);
            if (r1!=1) n1 = __INT_MAX__;
        }
        else if ((r1!=1) || (n2<=n1)){
            fprintf(fpr, "%d\n", n2);
            r2 = fscanf(fp2, "%d", &n2);
            if (r2!=1) n2 = __INT_MAX__;
        }
    }
    fclose(fp1);
    fclose(fp2);
    fclose(fpr);
}

int main(){
    FILE *fp = fopen("fp.txt", "w"), *fp2 = fopen("fp2.txt", "w");
    if (!fp || !fp2) exit(1);
    int n;
    scanf("%d", &n);
    if (n<=0) exit(1);
    int i = 1, vet1[n], vet2[n], elem;
    scanf("Vet1: %d", &vet1[0]);
    scanf("Vet2: %d", &vet2[0]);
    while(i<n){
        scanf("Vet1: %d", &elem);
        if (elem > vet1[i-1]) vet1[i++] = elem;
        scanf("Vet2: %d", &elem);
        if (elem > vet2[i-1]) vet2[i++] = elem;
    }
    fwrite(vet1, sizeof(int), 1, fp);
    fclose(fp);
    fwrite(vet2, sizeof(int), 1, fp);
    fclose(fp2);

    merge ("fp.txt", "fp2.txt", "fpr.txt");
    rewind(fp);
    rewind(fp2);
    return 0;
}