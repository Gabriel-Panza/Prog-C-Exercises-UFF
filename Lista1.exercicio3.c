#include <stdio.h>

int main()
{
    float a, b;
    char s;

    printf("Digite um simbolo de operacao: \n");
    scanf("%c", &s);
    printf("Digite um numero: \n");
    scanf("%f", &a);
    printf("Digite outro numero: \n");
    scanf("%f", &b);

    switch(s)
    {
        case '+':
            printf("%.2f\n", a+b);
            break;
        case '-':
            printf("%.2f\n", a-b);
            break;
        case '/':
            printf("%.2f\n", a/b);
            break;
        case '*':
            printf("%.2f\n", a*b);
            break;
        default:
            printf("Esse simbolo e invalido\n");
    }

    return 0;
}
