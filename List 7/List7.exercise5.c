#include <stdio.h>
#include <stdlib.h>
void criptografia(char *newSentence, int newSize)
{
    int i,j;

    for (i=0;i<5;i++)
    {
        for (j=i;j<newSize;j+=5)
        {
            newSentence[j] += (i+1);
        }
    }

    printf("%s", newSentence);
}
void main()
{
    int i, cont=0;
    char sentence[80];
    printf("Type a sentence of max 80 characters: ");
    gets(sentence);
    int size = strlen(sentence);
    char *sentenceWithoutSpace =(char *) malloc(size*sizeof(char));
    if (sentenceWithoutSpace == NULL)
    {
        exit(1);
    }

    for (i=0;i<size;i++)
    {
        if (sentence[i] != ' ')
        {
            sentenceWithoutSpace[cont] = sentence[i];
            cont++;
        }
    }
    sentenceWithoutSpace[cont] = '\0';
    int newSize = strlen(sentenceWithoutSpace);

    criptografia(sentenceWithoutSpace,newSize);
}
