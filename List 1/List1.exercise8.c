#include <stdio.h>

int qnt_total_notas(int value)
{
    int qnt_notas;
    qnt_notas = 0;

    qnt_notas += value/100;
    value = value%100;
    qnt_notas += value/50;
    value = value%50;
    qnt_notas += value/20;
    value = value%20;
    qnt_notas += value/10;
    value = value%10;
    qnt_notas += value/5;
    value = value%5;
    qnt_notas += value/2;
    value = value%2;
    qnt_notas += value/1;
    value = value%1;

    return qnt_notas;
}

int main()
{
    int value;

    printf("Type the value: R$ ");
    scanf("%d", &value);
    printf("Total of grades = %d", qnt_total_notas(value));
}