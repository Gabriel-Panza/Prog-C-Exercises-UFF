#include<stdio.h>
#include<string.h>
#include<stdbool.h>
bool ehPalindrome(char* a)
{
    int sizeA = strlen(a);
    for (int i=0;i<sizeA;i++)
    {
        if (a[i]!=a[sizeA-1-i])
            return false;
    }
    return true;
}
void main()
{
    char a[100];
    do
    {
        printf("Type a number: ");
        printf("\na: ");
        scanf("%s", a);
        if (a[0] == '-')
            break;
        
        if (ehPalindrome(a))
            printf("The number %s is palindrome", a);
        else
            printf("The number %s is not palindrome", a);
    } while (1);
}