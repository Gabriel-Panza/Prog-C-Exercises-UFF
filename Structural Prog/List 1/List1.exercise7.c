#include <stdio.h>
#include <math.h>

int main()
{
    float x,x_decimal;
    printf("The value of x = ");
    scanf("%f", &x);

    x_decimal = x - (int)x;

    if (x_decimal >= 0.5)
    {
        printf("Ceiling the value, we have: x = %.g\n", ceil(x));
    }
    else
    {
        printf("Flooring the value, we have: x = %.g\n", floor(x));
    }

    return 0;
}
