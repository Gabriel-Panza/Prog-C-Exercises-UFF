#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void transformCamelCase(char *s)
{
    int i;    
    for( i = 0; s[i]!= '\0' ; i++)
    {
        if (s[i] == 32)
        {
            s[i+1] = s[i+1] - 32;        
        }
    }
}

void removeSpaces(char *copy, char *paste)
{
   while (*copy != '\0')
    {
        if (*copy != ' ') 
        {
            *paste = *copy;
            copy++;
            paste++;
        } else {
            copy ++;            
        }
    }
    *paste = '\0';
}

int main()
{
    char word[20];
    char paste[20];
            
    printf("Type the word that will be converted to Camel case: ");
    fgets(word, 20, stdin);
   
    
    transformCamelCase(word);
    removeSpaces(word, paste);
    printf(" %s", paste);

    return 0;
}