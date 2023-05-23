#include <stdio.h>
#include <string.h>

int main()
{
    char sentence[80] = "the rat bite the rome king";
    char *p;
    int size = strlen(sentence);
    p = sentence;
    p[2]='m';
    p[6]='\0';
    printf("%s\n", sentence);
    p = p + 3;
    printf("%s\n",p);
    printf("%d\n",size);
}