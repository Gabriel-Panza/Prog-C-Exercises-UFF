#include<stdio.h>

int main(){
    int horasTrabalhadas, horaExtra=0;
    float valorDaHora, salarioSemanal = 0;

    printf("Type the number of hours worked this week: ");
    scanf("%d", &horasTrabalhadas);

    printf("Type the amount you gained by hour: $");
    scanf("%f", &valorDaHora);

    if(horasTrabalhadas <= 40){
        salarioSemanal += horasTrabalhadas * valorDaHora;
    } else if(horasTrabalhadas > 40 && horasTrabalhadas <= 60){
        horaExtra = horasTrabalhadas - 40;
        salarioSemanal += (40 * valorDaHora) + (horaExtra * (valorDaHora*1.5));
    } else{
        horaExtra = horasTrabalhadas - 40;
        salarioSemanal += (40 * valorDaHora) + (horaExtra * (valorDaHora*1.5));
        horaExtra = horasTrabalhadas - 60;
        salarioSemanal += (horaExtra * (valorDaHora*2));
    }

    printf("The salary of this worker is: $%.2f", salarioSemanal);

    return 0;
}
