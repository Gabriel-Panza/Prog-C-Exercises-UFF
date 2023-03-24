#include <stdio.h>
#include <stdlib.h>
int main() {
    int y[10];
    int x[10];
    int i, j=0;
    printf("Type 10 integers numbers: \n");
    for (i = 0; i < 10; i++) {
        scanf("%d", &x[i] );
    }
    for (i = 9; i >= 0; i--) {
        y[j]=x[i];
        j++;
    }
    printf("Values of the vector y:\n");
    for (i = 0; i <10; i++) {

        printf("%d ", y[i]);

    }
    return 0;
}
