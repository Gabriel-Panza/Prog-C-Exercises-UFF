#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* cifra_cesar(char* msg)
{
    int n = strlen(msg);
    char *letra, i;
    letra = (char*) malloc(n*sizeof(char));

    for(i = 0; i < n; i++)
    {
        if(msg[i] == 'z'){
            letra[i] ='c';
            continue;
        } if(msg[i] == 'y'){
            letra[i] ='b';
            continue;
        } if(msg[i] == 'x'){
            letra[i] ='a';
            continue;
        }if(msg[i] == ' '){
            letra[i] = ' ';
            continue;
        } else {
            letra[i] = msg[i] + 3;
            continue;
        }
    }
    return letra;
}

void main()
{
    char msg[20], *volta;
    int n = 0, i;
    printf("Type a sentence: ");
    scanf("%s", msg);
    n = strlen(msg);
    volta = cifra_cesar(msg);
    for(i = 0; i < n; i++){
        printf("%c ", volta[i]);
    }
}