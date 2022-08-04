#include <stdio.h>

int mdc_recursiva(int a, int b)
{
    printf("\n%d e %d", a, b);
    if (a % b == 0)
        return b;
    return mdc_recursiva (b, a % b);
}

int main() {
    int a=32, b=18;
    printf("\nResultado=%d",mdc_recursiva(a, b)); // Será printado 2, que eh o maior divisor comum de 32 e 18
}
