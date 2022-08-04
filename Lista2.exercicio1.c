#include <stdio.h>

void detectaNumPrimo(int num)
{
    if ((num == 1) || ((num % 2)== 0 && num != 2) || ((num % 3)== 0 && num != 3) || ((num % 5)== 0 && num != 5) || ((num % 7)== 0 && num != 7))
        printf("NUMERO NAO PRIMO");
    else
        printf("NUMERO PRIMO");
}
void main()
{
    int n;
    printf("Digite o numero que sera avaliado: ");
    scanf("%d", &n);
    detectaNumPrimo(n);
}
