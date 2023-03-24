#include <stdio.h>

int main()
{
    char* word[100];
    printf("Type a word: \n");
    scanf("%s", word);
   

    int cont_vowels = 0;

    for(int i = 0; i < 100; i++)
    {
        if(word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u')
        {
             vogais ++;
        }
    }

     printf("%d", cont_vowels);
}