#include <stdio.h>
#include <string.h>

int main (void)
{
    char *sentence = "Great test"; 
    char *p , mistery[80]; 
    int i = 0;
    int j = 0;
    p = sentence + strlen(sentence) - 1; 
    while (*p != ' ') 
    {
        mistery[i] = *p; 
        i ++; p --; 
    }
    mistery[i] = ' '; i ++; 
    while ( sentence[j] != ' ') 
    {
        mistery [i] = sentence[j]; 
        j ++; i ++; 
    }
    mistery[i] = '\0 '; 
    puts (mistery); 
    return 0;
}
