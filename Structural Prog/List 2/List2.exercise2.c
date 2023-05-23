#include <stdio.h>

void OddMultiplication(int num)
{
    printf("%d", (num*num));
}
void main()
{
    int n;
    printf("Type what odd number will be multiplied to itself: ");
    scanf("%d", &n);
    OddAddition(n);
}
