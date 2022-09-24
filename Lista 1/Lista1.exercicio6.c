#include <stdio.h>
#include <math.h>

int main()
{
    //Variáveis da função principal//
    float a, b, c;
    //Variáveis do cáculo das raízes//
    float delta, x1, x2;

    printf("Digite o valor para o 'a' na equacao a*x^2 + b*x + c = 0\t");
    scanf("%f", &a);
    printf("Digite o valor para o 'b' na equacao a*x^2 + b*x + c = 0\t");
    scanf("%f", &b);
    printf("Digite o valor para o 'c' na equacao a*x^2 + b*x + c = 0\t");
    scanf("%f", &c);

    delta = pow(b,2) - 4*a*c;

    //Calcula-se os 3 possíveis resultados para o delta
    if(delta == 0)
    {
        //Raizes reais e iguais//
        x1 = (-b)/(2*a);
        printf("So possui uma raiz real = %.2f", x1);
    }
    else if (delta > 0)
    {
        //Raizes reais e distintas//
        x1 = (-b + sqrt(delta))/(2*a);
        x2 = (-b - sqrt(delta))/(2*a);
        printf("Possui 2 raizes, onde:\n x1 = %.2f\n x2 = %.2f", x1, x2);
    }
    else if (delta < 0)
    {
        //Sem raizes reais//
        printf("Nao possui raiz real");
    }

    return 0;
}
