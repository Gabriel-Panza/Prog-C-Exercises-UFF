#include <stdio.h>
#include <string.h>

int main(){
    char name[30], address[30], telephoneNumber[20], info[80]="";

    printf("Type the name: ");
    scanf(" %[^\n]", name);
    fflush(stdin);

    printf("Type the address: ");
    scanf("%[^\n]", address);
    fflush(stdin);

    printf("Type the telephoneNumber: ");
    scanf("%[^\n]", telephoneNumber);
    fflush(stdin);

    strcat(info, name);
    strcat(info, address);
    strcat(info, telephoneNumber);

    printf("%s", info);

    return 0;
}
