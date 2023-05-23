#include <stdio.h>
#include<string.h>
#include <stdlib.h>

char *compactar(char *s)
{
    int StartCountdown = 0;

    while(s[StartCountdown] == ' ') 
    {
        StartCountdown++;
    }

    int FinalCountdown = strlen(s) - 1;

    while(s[FinalCountdown] == ' ') 
    {
        FinalCountdown--;

    }
    int n = strlen(s) - StartCountdown - (strlen(s) - 1 - FinalCountdown);
    char *compactado = (char*) malloc(n*sizeof(char));

    if(compactado == NULL)
    {
        printf("ERRO");
        exit(1);
    }
    
    int positionNewVector = 0;

    for (int i = StartCountdown; i <= FinalCountdown; i++) 
    {
        compactado[positionNewVector] = s[i];
        positionNewVector++;
    }
    compactado[FinalCountdown+1] = '\0';
    
    return compactado;
}

int main()
{
    char sentence[100];
    scanf(" %99[^\n]",sentence);
    char *newSentence = compactar(sentence);
    printf("%s",newSentence);
    free(newSentence);
    return 0;
}