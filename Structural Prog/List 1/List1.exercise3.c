#include <stdio.h>

int main()
{
    float a, b;
    char s;

    printf("Type a symbol to the operation: \n");
    scanf("%c", &s);
    printf("Type a number: \n");
    scanf("%f", &a);
    printf("Type another number: \n");
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
            printf("This symbol is invalid\n");
    }

    return 0;
}
