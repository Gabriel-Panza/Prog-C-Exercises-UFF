#include<stdio.h>
void respOtim(int *vetor, int *prespOti){
    int i;
    int rOtim = *prespOti;
    for(i=0;i<100;i++){
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
    for (i=0;i<100;i++){
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
    for(i=0;i<100;i++){
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
    for(i=0;i<100;i++){
        if(vetor[i]==5){
            cont++;
            if(idadeV[i]>maior){
                maior=idadeV[i];
            }
        }
    }
    printf("Higher is: %d", maior);
    percent= (100*cont)/100;
    *pporc = percent;
    *pmaiorIda=maior;
}
void DifMaiorIdaOtimRuim (int *vetor, int *idadeV, int *difMaiorIda){
    int i, maiorIdaOtim=0, maiorIdaRuim=0, difIda=0;
    difIda = *difMaiorIda;
    for(i=0;i<100;i++){
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
    int i, op,respOti=0, maiorIda=0, difMaiorIdaOtimaRuim = 0;
    int v[100];
	int age[100];
    float difPer, medRuim, porc;

    for(i=0; i<100;i++){
        printf("Type your age: ");
        scanf("%d",&age[i]);

        printf("Type your opinion about the film:\n1=great\n2=good\n3=regular\n4=bad\n5=worst\n");
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
    for(i=0;i<100;i++){
        printf("vector[%d] age: %d \nvector[%d] opiniao: %d",i,age[i],i,v[i]);
    }
    respOtim(v,&respOti);
    PercentBomReg(v, &difPer);
    medRu(v,age,&medRuim);
    PorcPessMaiorIda(v, age, &porc, &maiorIda);
    DifMaiorIdaOtimRuim(v, age, &difMaiorIdaOtimaRuim);
    //A
    printf("\nA) The quantity of great opinions are: %d", respOti);
    //B
    printf("\nB) The percentual difference between the good and regular opinions is: %.2f", difPer);
    //C
    printf("\nC) The average age of the people that choose worst is: %.2f", medRuim);
    //D
    printf("\nD) The percentual of worst anwsers is: %.2f \n Higher age that choose this option: %d" ,porc, maiorIda);
    //E
    printf("\nE) The age difference between the oldest that vote great and bad is: %d", difMaiorIdaOtimaRuim);
    return 0;
}