#include<stdio.h>

void respOtim(int *vetor, int *prespOti){
    int i;
    int rOtim = *prespOti;
    for(i=0;i<20;i++){
        if(vetor[i]==1){
            rOtim++;
        }
    }
    *prespOti = rOtim;
}

void PercentBomReg(int *vetor, float *pdifPer){
    int i;
    float cont_b=0, cont_reg=0,dif;
    dif=*pdifPer;
    for (i=0;i<20;i++){
        if(vetor[i]==2){
            cont_b++;
        }
        if(vetor[i]==3){
            cont_reg++;
        }
    }
    dif= (cont_reg/100)-(cont_b/100);
    if(dif<0){
    	dif=dif*(-1);
	}
	*pdifPer=dif;
}
void medRu(int *vetor, int *idadeV, float *pmedRuim){
    float med;
    int i, soma=0, cont=0;
    med=*pmedRuim;
    for(i=0;i<20;i++){
        if(vetor[i]==4){
            soma=soma+idadeV[i];
            cont++;
        }
    }
    med=soma/cont;
    *pmedRuim=med;
}
void PorcPessMaiorIda(int *vetor, int *idadeV, float *pporc, int *pmaiorIda){
    int i, cont=0, maior=0;
    float percent;
    percent=*pporc;
    maior=*pmaiorIda;
    for(i=0;i<20;i++){
        if(vetor[i]==5){
            cont++;
            if(idadeV[i]>maior){
                maior=idadeV[i];
            }
        }
    }
    printf("maior eh: %d", maior);
    percent= (20*cont)/100;
    *pporc = percent;
    *pmaiorIda=maior;
}
void DifMaiorIdaOtimRuim (int *vetor, int *idadeV, int *difMaiorIda){
    int i, maiorIdaOtim=0, maiorIdaRuim=0, difIda=0;
    difIda = *difMaiorIda;
    for(i=0;i<20;i++){
        if(vetor[i]==1){
            if (idadeV[i]> maiorIdaOtim){
                maiorIdaOtim = idadeV[i];
            }
        }
        if(vetor[i]==4){
            if (idadeV[i]> maiorIdaRuim){
                maiorIdaRuim = idadeV[i];
            }
        }
    }
    difIda = maiorIdaOtim - maiorIdaRuim;
    if (difIda < 0){
        difIda *= -1;
    }
    *difMaiorIda = difIda;
}
int main(){
    int i, op,respOti=0, maiorIda=0, difMaiorIdaOR = 0;
    int v[20];
	int idade[20];
    float difPer, medRuim, porc;

    for(i=0; i<20;i++){
        printf("digite sua idade: ");
        scanf("%d",&idade[i]);

        printf("Digite sua opinião sobre o filme:\n1=otimo\n2=bom\n3=regular\n4=ruim\n5=pessimo\n");
        scanf("%d",&op);
        switch(op){
            case 1:
                v[i]=1;
                break;
            case 2:
                v[i]=2;
                break;
            case 3:
                v[i]=3;
                break;
            case 4:
                v[i]=4;
                break;
            case 5:
                v[i]=5;
                break;
        }
    }
    for(i=0;i<20;i++){
        printf("vetor[%d] idade: %d \nvetor[%d] opiniao: %d",i,idade[i],i,v[i]);
    }
    respOtim(v,&respOti);
    PercentBomReg(v, &difPer);
    medRu(v,idade,&medRuim);
    PorcPessMaiorIda(v, idade, &porc, &maiorIda);
    DifMaiorIdaOtimRuim(v, idade, &difMaiorIdaOR);
    //A
    printf("\nA) A quantidade de opinioes otimas sao: %d", respOti);
    //B
    printf("\nB) A diferença de percentual entre as opinioes boas e regulares eh: %.2f", difPer);
    //C
    printf("\nC) A media de idades das pessoas que escolheram pessimas eh: %.2f", medRuim);
    //D
    printf("\nD) A porcetagem de respostas pessimas eh: %.2f \n Maior Idade que escolheu essa opcao eh: %d" ,porc, maiorIda);
    //E
    printf("\nE) A diferença de idade entre os mais velhos que opinaram otimo e ruim eh: %d", difMaiorIdaOR);
    return 0;
}
