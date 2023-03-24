#include<stdio.h>
#include<string.h>

main(void)
{
    char text[]= "Its easy";
    int i;
    for (i = 0; text[i]!='\0'; i++)
    {
        if (text[i] == ' ') 
            break;
    }
    i++;
    for ( ; text[i]!='\0'; i++)
    {
        printf("%c", text[i]);
    }
}