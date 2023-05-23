#include <stdio.h>

int main()
{
    int a, b, c;
    int higher, lower;
    float average;

    printf("Type the first number: \n");
    scanf("%d", &a);
    printf("Type the second number: \n");
    scanf("%d", &b);
    printf("Type the third number: \n");
    scanf("%d", &c);

    if (a <= b && a <= c)
    {
        lower = a;
    }
    else if (b <= a && b <= c)
    {
        lower = b;
    }
    else if (c <= a && c <= b)
    {
        lower = c;
    }

    if (a >= b && a >= c)
    {
        higher = a;
    }
    else if (b >= a && b >= c)
    {
        higher = b;
    }
    else if (c >= a && c >= b)
    {
        higher = c;
    }

    printf("The higher number is: %d\n", higher);
    printf("The lower number is: %d\n", lower);

    if (a % 2 == 0)
    {
        printf("%d is even\n", a);
    }
    if (b % 2 == 0)
    {
        printf("%d is even\n", b);
    }
    if (c % 2 == 0)
    {
        printf("%d is even\n", c);
    }

    average = (a + b + c) / 3;

    printf("The average is: %.2f\n", average);

    return 0;
}
