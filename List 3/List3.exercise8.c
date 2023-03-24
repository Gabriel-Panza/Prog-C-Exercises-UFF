#include <stdio.h>
#include <locale.h>
#define N 10

float average(int n, float *v){
    float addition = 0;
    for (int i = 0; i < n; i++)
    {
        addition += v[i];
    }
    return addition/n;
}

void main()
{
    float values[N];

    for (int i = 0; i < N; i++)
    {
        printf("Type a value %d:" , i + 1);
        scanf("%f", &values[i]);
    }

    printf("The average of the values is: %.2f", average(N, values));
}

