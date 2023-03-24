#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c;
    float delta, x1, x2;

    printf("Type the value of 'a' in the equation: a*x^2 + b*x + c = 0\t");
    scanf("%f", &a);
    printf("Type the value of 'b' in the equation: a*x^2 + b*x + c = 0\t");
    scanf("%f", &b);
    printf("Type the value of 'c' in the equation: a*x^2 + b*x + c = 0\t");
    scanf("%f", &c);

    delta = pow(b,2) - 4*a*c;

    if(delta == 0) // Case 1
    {
        x1 = (-b)/(2*a);
        printf("There is 1 squareRoot = %.2f", x1);
    }
    else if (delta > 0) // Case 2
    {
        x1 = (-b + sqrt(delta))/(2*a);
        x2 = (-b - sqrt(delta))/(2*a);
        printf("There are 2 squareRoot:\n x1 = %.2f\n x2 = %.2f", x1, x2);
    }
    else if (delta < 0) // Case 3
    {
        printf("There isnt a real squareRoot");
    }

    return 0;
}
