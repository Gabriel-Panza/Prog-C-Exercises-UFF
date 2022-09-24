#include <stdio.h>

int main()
{
    int numero = 1000;

    while(numero <= 9999){
        if(numero == (((numero/100)+(numero%100))*((numero/100)+(numero%100))))
            printf("%d: %d + %d = %d -> %d ^ 2 = %d \n",numero,numero/100,numero%100,(numero/100)+(numero%100),(numero/100)+(numero%100),numero);
        numero++;
    }

    return 0;
}