#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int main(){

    int numeroSorteado, tentativasDeAcerto = 0, palpite;

    srand(time(NULL));


    numeroSorteado = rand() % 100;//

    do{
        printf("Type what number do you think will be randomized: ");
        scanf("%d", &palpite);
        if(palpite != numeroSorteado){
                tentativasDeAcerto++;
                if(palpite > numeroSorteado){
                    printf("The number randomized is lower\n");

                }else{
                    printf("The number randomized is higher\n");
                }
        }
    }while(palpite != numeroSorteado);

    tentativasDeAcerto++;
    printf("Number of tries you had: %d", tentativasDeAcerto);

    return 0;
}