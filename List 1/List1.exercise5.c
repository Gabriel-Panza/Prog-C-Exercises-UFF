#include <stdio.h>

int main()
{
    char operator;
    int a1 = 3, b1 = a1/2, c1 = b1+3.1;
    float a2 = 3, b2 = a2/2, c2 = b2+3.1;
    float a3 = 3, b3 = a1/2, c3 = b3+3.1;

    printf("Temos a=3\n b=a/2\n c = b+3.1\n");
    printf("Type 'i' if you want operations between integers\n 'f' if you want operations between floats\n 'm' if you want mixed operations\n");
    scanf("%c", &operator);

    switch(operator)
    {
        case 'i':
        printf("The value of c = %d, bcs we have a division and an addition of integers (3/2 = 1 e 1+3.1 = 4)", c1);
        break;

        case 'f':
        printf("The value of c = %g, bcs we have a division and an addition of floats (3/2 = 1.5 e 1.5+3.1 = 4.6)", c2);
        break;

        case 'm':
        printf("The value of c = %g, bcs we have a division of integers with an addition of floats (3/2 = 1 e 1+3.1 = 4.1)", c3);
        break;
    }
    return 0;
}
