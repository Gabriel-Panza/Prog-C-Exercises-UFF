#include<stdio.h>
#include<string.h>
#include<stdbool.h>

bool ehPermutation(char* a, char* b)
{
    int c[10] = {0,0,0,0,0,0,0,0,0,0};
    int sizeA = strlen(a), sizeB = strlen(b);
    if (sizeA == sizeB)
    {
        for (int i=0;i<sizeA;i++)
        {
            c[a[i]-'0'] += 1;
            c[b[i]-'0'] -= 1;
        }
        for (int i=0;i<10;i++)
        {
            if (c[i]!= 0)
                return false;
        }
    }
    else
        return false;
    return true;
}
void main()
{
    char a[9], b[9];

    printf("Type two numbers separated by space: ");
    printf("\na: ");
    scanf("%s", &a);
    printf("\nb: ");
    scanf("%s", &b);

    if (ehPermutacao(a,b))
        printf("The number %s is a permutation of %s", a, b);
    else
        printf("The number %s is not a permutation of %s", a, b);
}