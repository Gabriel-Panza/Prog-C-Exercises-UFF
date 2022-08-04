#include <stdio.h>


float media (float media)
{
    return media/10;
}

int main()
{
    //Variáveis que representam o valor das três provas//
    float nota1, nota2, nota3;
    //Variáveis que representam a média //
    float media_com_peso, media_final;

    //Garantimos que as três notas estao no padrão certo, ou seja, entre 0 e 10//
    printf("\n A primeira nota e: ");
    scanf("%f", &nota1);
    while (nota1<0 || nota1>10)
    {
        printf("\n Padrao de nota incorreto. Reescreva a nota no padrao correto: ");
        printf("A primeira nota e: ");
        scanf("%f", &nota1);
    }

    printf("\n A segunda nota e: ");
    scanf("%f", &nota2);
    while (nota2<0 || nota2>10)
    {
        printf("\n Padrao de nota incorreto. Reescreva a nota no padrao correto: ");
        printf("\n A segunda nota e: ");
        scanf("%f", &nota2);
    }

    printf("\n A terceira nota e: ");
    scanf("%f", &nota3);
    while (nota3<0 || nota3>10)
    {
        printf("\n Padrao de nota incorreto. Reescreva a nota no padrao correto: ");
        printf("\n A terceira nota e: ");
        scanf("%f", &nota3);
    }

    //Pegamos as tres notas e multiplicamos pelos seus pesos
    media_com_peso = nota1*2 + nota2*3 + nota3*5;

    //Pegamos a média do aluno da outra função e jogamos dentro de uma variável//
    media_final = media(media_com_peso);

    //Definimos se o aluno passou ou não//
    if (media_final > 6)
    {
        printf("\n O Aluno esta aprovado!\n Sua media final foi: %.2f", media_final);
    }
    if (media_final > 4 && media_final < 6)
    {
        printf("\n O Aluno esta de VS!\n Sua media final foi: %.2f", media_final);
    }
    if (media_final < 4)
    {
        printf("\n O Aluno esta reprovado!\n Sua media final foi: %.2f", media_final);
    }

    return 0;
}
