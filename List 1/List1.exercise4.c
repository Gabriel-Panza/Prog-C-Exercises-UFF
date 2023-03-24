#include <stdio.h>

float average (float average)
{
    return average/10;
}

int main()
{
    float grade1, grade2, grade3;
    float average_with_weight, final_average;

    printf("\n The first grade is: ");
    scanf("%f", &grade1);
    while (grade1<0 || grade1>10)
    {
        printf("\n Error. Rewrite the grade in the correct format: ");
        printf("The first grade is: ");
        scanf("%f", &grade1);
    }

    printf("\n The second grade is: ");
    scanf("%f", &grade2);
    while (grade2<0 || grade2>10)
    {
        printf("\n Error. Rewrite the grade in the correct format: ");
        printf("\n The second grade is: ");
        scanf("%f", &grade2);
    }

    printf("\n The third grade is: ");
    scanf("%f", &grade3);
    while (grade3<0 || grade3>10)
    {
        printf("\n Error. Rewrite the grade in the correct format: ");
        printf("\n The third grade is: ");
        scanf("%f", &grade3);
    }

    average_with_weight = grade1*2 + grade2*3 + grade3*5;

    final_average = average(average_with_weight);

    if (final_average > 6)
    {
        printf("\n The student is approved!\n Their final average is: %.2f", final_average);
    }
    if (final_average > 4 && final_average < 6)
    {
        printf("\n The student is in VS!\n Their final average is: %.2f", final_average);
    }
    if (final_average < 4)
    {
        printf("\n The student is disapproved!\n Their final average is: %.2f", final_average);
    }

    return 0;
}
