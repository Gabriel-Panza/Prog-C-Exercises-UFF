#include<stdio.h>
#include<string.h>
int valida_mail(char *s){
    int check=0,i, contLet=0, contNum=0;

    if(((s[0]>=65 && s[0]<=90) || (s[0]>=97 && s[0]<=122)) && s[strlen(s)-1]!=46){//Primeira letra
        check = 1;
    }
    else{
        return check;
    }
    for(i=0;i<(strlen(s)-1);i++){
    	if((s[i]==45 || s[i]==46 || s[i]==95) || ((s[i]>=65 && s[i]<=90) || (s[i]>=97 && s[i]<=122)) || (s[i]>=48 && s[i]<=57)){
            if((s[i]==46) && s[i]==s[i+1]){
                check=0;
                return check;
                break;
        	}
        	else if(((s[i]>=65 && s[i]<=90) || (s[i]>=97 && s[i]<=122))){
        		contLet++;
			}
			else if((s[i]>=48 && s[i]<=57)){
				contNum++;
			}
        }
        else{
            check=0;
            return check;
            break;
        }
    }
    if(contNum<2 || contLet<2){
        check=0;
        return check;
		}
    return check;
}
int main(){
    char cadeia[64];
    int valida;
    printf("Digite seu usuario: ");
    scanf("%s",cadeia);
    valida=valida_mail(cadeia);
    printf("%d", valida);
    return 0;
}