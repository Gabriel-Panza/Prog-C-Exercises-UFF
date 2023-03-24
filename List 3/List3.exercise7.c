#include <stdio.h>

int main() {
    int jump[]={2,3,5,7,11,13,17};
    printf("%d \n", (jump + 2));
    printf("(jump+2) is equal to the value of the index 2 (or third element) of the vector jump \n");
    return 0;
}