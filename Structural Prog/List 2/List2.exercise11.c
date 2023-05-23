#include<stdio.h>
#include<math.h>


int main(){

    int number1, number2, result;

    scanf("%d", &number1);
    scanf("%d", &number2);

    result = pow(number1, number2);

    printf("%d", result);

    return 0;
}