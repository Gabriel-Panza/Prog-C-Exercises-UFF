#include <stdio.h>
#include <string.h>
#define MAX 50
int main (void)
{
    char text[MAX +2], temp;
    int size , i;
    gets(text);
    size = strlen (text);
    for (i=0;i<size;i++)
    {
        temp = text[i];
        text[i] = text[size-1-i];
        text[strlen(text)-1-i] = temp ;
    }
    puts (text);
    return 0;
}
