#include <stdio.h>
#include <string.h>

int main () {
    const char str1[] = "abcde2fghi3jk4l";
    const char str2[] = "34";
    char *ret;
    char src[40];
    char dest[12];
    const char src1[50] = "Raian Pierre";

    strcpy(dest,"Ooooooi!");
    printf("Antes memcpy dest = %s\n", dest);
    memcpy(dest, src1, strlen(src1)+1);
    printf("Depois memcpy dest = %s\n", dest);

    memset(dest, '\0', sizeof(dest));
    strcpy(src, "\nRaio");
    strncpy(dest, src, 10);

    printf("\nString final copiada: %s\n", dest);
    ret = strpbrk(str1, str2);
    if(ret) {
        printf("Primeiro caractere correspondente: %c\n", *ret);
    } else {
        printf("Caractere nao encontrado");
    }

   return 0;
}
