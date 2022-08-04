#include <stdio.h>
void SomadosImpares(int num)
{
    printf("%d", (num*num));
}
void main()
{
    int n;
    printf("Digite quantos numeros impares deverao ser somados: ");
    scanf("%d", &n);
    SomadosImpares(n);
}
