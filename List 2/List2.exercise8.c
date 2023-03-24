#include <stdio.h>

int main()
{
    int number = 1000;

    while(number <= 9999){
        if(number == (((number/100)+(number%100))*((number/100)+(number%100))))
            printf("%d: %d + %d = %d -> %d ^ 2 = %d \n",number,number/100,number%100,(number/100)+(number%100),(number/100)+(number%100),number);
        number++;
    }

    return 0;
}