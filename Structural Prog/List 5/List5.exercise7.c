#include <stdio.h>
#include <string.h>

int main(){
    char string1[15], string2[15];
    printf("Type the first word: ");
    scanf("%s", string1);
    fflush(stdin);

    printf("Type the second word: ");
    scanf("%s", string2);
    fflush(stdin);

    if(strcmp(string1,string2)== 0){
        printf("Same Strings");
    }else if(strcmp(string1,string2)== -1){
        printf("The second word is a substring of the first");
    } else {
        printf("Different Strings");
    }

    return 0;
}
