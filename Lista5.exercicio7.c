#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    int i,j=0;
    char palavra[100];
    char Abrev[20];
    printf("Digite seu nome inteiro: ");
    scanf("%100[^\n]", palavra);
   if(palavra[0]>=97 && palavra[0]<=122){
        Abrev[j]=palavra[0]-32;
        j++;
        Abrev[j]='.';
        j++;
    }
    else{
        Abrev[j]=palavra[0];
        j++;
        Abrev[j]='.';
        j++;
    }
    for(i=0;i<strlen(palavra);i++){
        if(palavra[i]==' '){
            if(palavra[i+1]=='d'){
                if(palavra[i+2]=='e' || palavra[i+2]=='o' || palavra[i+2]=='a'){
                    i+2;
                }
                else{
                    if(palavra[i+1]==101){
                        Abrev[j]=palavra[i+1]-32;
                        j++;
                        Abrev[j]='.';
                        j++;
                }
                else{
                    Abrev[j]=palavra[i+1];
                    Abrev[j+1]='.';
                    j+2;
                }                }
            }
            else{
                if(palavra[i+1]>=97 && palavra[i+1]<=122){
                    Abrev[j]=palavra[i+1]-32;
                    j++;
                    Abrev[j]='.';
                    j++;
                }
                else{
                    Abrev[j]=palavra[i+1];
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
