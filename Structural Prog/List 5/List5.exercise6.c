#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int i,j=0;
    char word[100];
    char Abrev[20];
    printf("Digite seu name inteiro: ");
    scanf("%100[^\n]", word);
   if(word[0]>=97 && word[0]<=122){
        Abrev[j]=word[0]-32;
        j++;
        Abrev[j]='.';
        j++;
    }
    else{
        Abrev[j]=word[0];
        j++;
        Abrev[j]='.';
        j++;
    }
    for(i=0;i<strlen(word);i++){
        if(word[i]==' '){
            if(word[i+1]=='d'){
                if(word[i+2]=='e' || word[i+2]=='o' || word[i+2]=='a'){
                    i+2;
                }
                else{
                    if(word[i+1]==101){
                        Abrev[j]=word[i+1]-32;
                        j++;
                        Abrev[j]='.';
                        j++;
                }
                else{
                    Abrev[j]=word[i+1];
                    Abrev[j+1]='.';
                    j+2;
                }                }
            }
            else{
                if(word[i+1]>=97 && word[i+1]<=122){
                    Abrev[j]=word[i+1]-32;
                    j++;
                    Abrev[j]='.';
                    j++;
                }
                else{
                    Abrev[j]=word[i+1];
                    j++;
                    Abrev[j]='.';
                    j++;
                }
            }
        }
    }
    printf("%s", Abrev);
    return 0;
}
