#include <stdio.h>
#include "TH/TH.h"

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

int main(void){
  int m;
  printf("Digite o tamanho da hash... ");
  scanf("%d", &m);

  if(m <= 1) return 0;

  char nome_dados[31], nome_hash[31];
  printf("Digite nome do arquivo de dados... ");
  scanf("%s", nome_dados);
  printf("Digite nome do arquivo de hash... ");
  scanf("%s", nome_hash);

  TH_inicializa(nome_hash, nome_dados, m);

  int mat;
  float cr;
  do{
    printf("Digite a matricula e o cr...\n");
    scanf("%d", &mat);
    scanf("%f", &cr);
    if(mat <= 0) break;
    TH_insere(nome_hash, nome_dados, m, mat, cr);
  }while(1);
  TH_imprime(nome_hash, nome_dados, m);

  char resp;
  do{
    printf("Digite a matricula a ser removida... ");
    scanf("%d", &mat);
    cr = TH_retira(nome_hash, nome_dados, m, mat);
    if(cr != -1) printf("%d %f saiu\n", mat, cr);
    printf("Quer continuar? ");
    scanf(" %c", &resp);
  }while((resp != 'N') && (resp != 'n'));
  TH_imprime(nome_hash, nome_dados, m);

  return 0;
}