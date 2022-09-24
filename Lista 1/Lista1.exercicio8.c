#include <stdio.h>

//Definimos nossa função principal que irá printar a quantidade total de notas//
int main()
{
    int valor;

    printf("Digite o valor: R$ ");
    scanf("%d", &valor);
    printf("Total de notas = %d", qntd_total_notas(valor));
}

//Definimos nossa função secundária que irá somar a quantidade total de notas//
int qntd_total_notas(int valor)
{
    int qntd_notas;
    qntd_notas = 0;

    qntd_notas += valor/100;
    valor = valor%100;
    qntd_notas += valor/50;
    valor = valor%50;
    qntd_notas += valor/20;
    valor = valor%20;
    qntd_notas += valor/10;
    valor = valor%10;
    qntd_notas += valor/5;
    valor = valor%5;
    qntd_notas += valor/2;
    valor = valor%2;
    qntd_notas += valor/1;
    valor = valor%1;

    return qntd_notas;
}
