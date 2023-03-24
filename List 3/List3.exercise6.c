#include <stdio.h>

int higherNumbers(int n, int *vect, int x){
    int i, qnt=0;
    for (i=0; i<n; i++){
        if (vect[i]>x)
            qnt+=1;
    }
    return qnt;
}

int main() {
    int i, n, *vect, x;

    printf("Type the size of the vector:");
    scanf("%d",&n);

    vect = (float *) malloc(n*sizeof(float));
    if (vect==NULL) {
        printf("\nError!");
        exit(1);
    }

    for (i=0; i<n; i++){
        printf("\nAdd a number inside the vector: ");
        scanf("%d", &vect[i]);
    }

    printf("Type a number: ");
    scanf("%d", &x);

    printf("Quantity of numbers higher than %d: %d \n",x, higherNumbers(n, vect, x));

    free(vect);

    return 0;
}

