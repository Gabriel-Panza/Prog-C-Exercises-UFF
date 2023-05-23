#include <stdio.h>

float max_vet(int n, float *vect){
    int i;
    float higher;
    higher=vect[0];

    for (i=1; i<n; i++){
        if (vect[i]>higher)
            higher=vect[i];
    }
    return higher;
}

int main() {
    int i, n;
    float *vect;

    printf("Type the size of the vector: ");
    scanf("%d",&n);
    vect = (float *) malloc(n*sizeof(float));
    if (vect==NULL) {
        printf("Error!\n");
        exit(1);
    }

    for (i=0; i<n; i++){
        printf("Type a number: ");
        scanf("%f", &vect[i]);
    }

    printf("Higher value: %.2f \n", max_vet(n, vect));

    free(vect);
    return 0;
}
