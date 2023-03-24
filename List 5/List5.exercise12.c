#include <stdio.h>
#include <string.h>

int main () {
    const char str1[] = "abcde2fghi3jk4l";
    const char str2[] = "34";
    char *ret;
    char src[40];
    char dest[12];
    const char src1[50] = "Raian Pierre";

    strcpy(dest,"Hiiii!");
    printf("Before memcpy dest = %s\n", dest);
    memcpy(dest, src1, strlen(src1)+1);
    printf("After memcpy dest = %s\n", dest);

    memset(dest, '\0', sizeof(dest));
    strcpy(src, "\nRaio");
    strncpy(dest, src, 10);

    printf("\nFinal String copied: %s\n", dest);
    ret = strpbrk(str1, str2);
    if(ret) {
        printf("First character match: %c\n", *ret);
    } else {
        printf("Character not found");
    }

   return 0;
}
