#include<stdio.h>

int main(){
    int horasTrabalhadas, horaExtra=0;
    float valorDaHora, salarioSemanal = 0;

    printf("Digite o numero de horas trabalhadas na semana: ");
    scanf("%d", &horasTrabalhadas);

    printf("Digite o valor ganho por hora: R$");
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
        salarioSemanal += (horaExtra * (valorDaHora*2));#include<stdio.h>

int main(){
    int horasTrabalhadas, horaExtra=0;
    float valorDaHora, salarioSemanal = 0;

    printf("Digite o numero de horas trabalhadas na semana: ");
    scanf("%d", &horasTrabalhadas);

    printf("Digite o valor ganho por hora: R$");
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

    printf("O salario semanal desse trabalhor é de: R$%.2f", salarioSemanal);

    return 0;
}
