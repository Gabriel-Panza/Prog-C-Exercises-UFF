#include <stdio.h>
#define N 2

int main(){
    char gender[N];
    int age[N];
    float height[N];
    int i,cont=0, contMen=0;
    float total_height = 0, average_height, variance;

    for(i=0;i<N;i++){
        printf("Type your gender: M or F-> ");
        scanf(" %c",&gender[i]);
        printf("Type your age: ");
        scanf("%d",&age[i]);
        printf("Type your height: ");
        scanf("%f",&height[i]);
        total_height +=height[i];
    }
    average_height = total_height/N;
    for(i=0;i<N;i++){

        //printf("gender: %c age: %d height: %f\n",gender[i],age[i],height[i] );
        if((gender[i]=='F' || gender[i]=='f') && (age[i]>=20 && age[i]<=35)){
            cont++;
        }
        else if((gender[i]=='M' || gender[i]=='m') && height[i]>1.80){
            contMen++;
        }
        variance +=((height[i]-average_height)*(height[i]-average_height));


    }
    variance /= N - 1;

    printf("There are %d women with age between 20 and 35 years \nThere are %d men higher than 1,80 meters\n", cont, contMen);
    printf("The height variance is: %.2f", variance);
    return 0;
}
