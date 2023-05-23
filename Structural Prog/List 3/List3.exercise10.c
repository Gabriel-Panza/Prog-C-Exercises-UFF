#include<stdio.h>
void greatAnwser(int *vector, int *pGreatAnwser){
    int i;
    int rOtim = *pGreatAnwser;
    for(i=0;i<100;i++){
        if(vector[i]==1){
            rOtim++;
        }
    }
    *pGreatAnwser = rOtim;
}
void PercentGoodReg(int *vector, float *pdifPer){
    int i;
    float cont_b=0, cont_reg=0,dif;
    dif=*pdifPer;
    for (i=0;i<100;i++){
        if(vector[i]==2){
            cont_b++;
        }
        if(vector[i]==3){
            cont_reg++;
        }
    }
    dif= (cont_reg/100)-(cont_b/100);
    if(dif<0){
    	dif=dif*(-1);
	}
	*pdifPer=dif;
}
void AverageBad(int *vector, int *ageV, float *pAverageBad){
    float average;
    int i, add=0, cont=0;
    average=*pAverageBad;
    for(i=0;i<100;i++){
        if(vector[i]==4){
            add=add+ageV[i];
            cont++;
        }
    }
    average=add/cont;
    *pAverageBad=average;
}
void PercWorstBiggerAge(int *vector, int *ageV, float *pperc, int *pBiggerAge){
    int i, cont=0, bigger=0;
    float percent;
    percent=*pperc;
    bigger=*pBiggerAge;
    for(i=0;i<100;i++){
        if(vector[i]==5){
            cont++;
            if(ageV[i]>bigger){
                bigger=ageV[i];
            }
        }
    }
    printf("Higher is: %d", bigger);
    percent= (100*cont)/100;
    *pperc = percent;
    *pBiggerAge=bigger;
}
void DifBiggerAgeGreatBad (int *vector, int *ageV, int *difBiggerAge){
    int i, biggerAgeGreat=0, biggerAgeBad=0, difAge=0;
    difAge = *difBiggerAge;
    for(i=0;i<100;i++){
        if(vector[i]==1){
            if (ageV[i]> biggerAgeGreat){
                biggerAgeGreat = ageV[i];
            }
        }
        if(vector[i]==4){
            if (ageV[i]> biggerAgeBad){
                biggerAgeBad = ageV[i];
            }
        }
    }
    difAge = biggerAgeGreat - biggerAgeBad;
    if (difAge < 0){
        difAge *= -1;
    }
    *difBiggerAge = difAge;
}
int main(){
    int i, op,greatAnwser=0, biggerAge=0, difBiggerAgeGreatBad = 0;
    int v[100];
	int age[100];
    float difPer, averageBad, perc;

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
    greatAnwser(v,&greatAnwser);
    PercentGoodReg(v, &difPer);
    AverageBad(v,age,&averageBad);
    PercWorstBiggerAge(v, age, &perc, &biggerAge);
    DifBiggerAgeGreatBad(v, age, &difBiggerAgeGreatBad);
    //A
    printf("\nA) The quantity of great opinions are: %d", greatAnwser);
    //B
    printf("\nB) The percentual difference between the good and regular opinions is: %.2f", difPer);
    //C
    printf("\nC) The average age of the people that choose worst is: %.2f", averageBad);
    //D
    printf("\nD) The percentual of worst anwsers is: %.2f \n Higher age that choose this option: %d" ,perc, biggerAge);
    //E
    printf("\nE) The age difference between the oldest that vote great and bad is: %d", difBiggerAgeGreatBad);
    return 0;
}