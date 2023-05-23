#include<stdio.h>

void inverte(unsigned int n);

int main(){

    unsigned int numero;

    printf("Type the number you want to invert: ");
    scanf("%u", &numero);

    inverte(numero);

    return 0;
}

void inverte(unsigned int n){
    int inv = 0;
    while (n > 0) {
        inv = 10 * inv + n % 10;
        n /= 10;
    }

    printf("Inverse number: %d", inv);
}

