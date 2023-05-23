#include <stdio.h>
void Fibonacci(int num)
{
    int i, proxTerm, oldNumber=1, finalNumber=1, addFib=2;

    if (num==1)
        printf("%d", finalNumber);

    if (num==2)
    {
        printf("%d ", finalNumber);
        printf("%d ", oldNumber);
    }
    else if (num>=3)
    {
        printf("%d ", finalNumber);
        printf("%d ", oldNumber);
        for (i=2;i<num;i++)
        {
            addFib = finalNumber + oldNumber;
            oldNumber = finalNumber;
            finalNumber = addFib;
            printf("%d ", addFib);
        }
    }
}
void main()
{
    int n;
    printf("Type how many fibonacci numbers you want to see: ");
    scanf("%d", &n);
    Fibonacci(n);
}
