#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct data {
    int dia;
    int mes;
    char nomeMes[12];
} Data;

main()
{
    Data aniversarios[3] = {{5,1,"JANEIRO"},{4,2,"FEVEREIRO"},{10,3,"MAIO"}};      // Preenchemos o struct Data
    int a;                                                                        //Criamos uma variavel inteira
    Data *p_dt;                                                                  // Criamos um ponteiro apontando pro struct Data
    p_dt=&aniversarios[2];                                                      // Pegamos o ultimo termo de aniversario(10,3,"MAIO") e armazenamos no p_dt
    printf("Nome do mes %d eh: %s.", p_dt->mes, p_dt->nomeMes);                // Este print vai printar que o mes 3 eh Maio, e isto está errado, pois o mes 3 eh Marco
    strcpy(p_dt->nomeMes, "MARCO");                                           // Este comando conserta o erro de cima, mudando o Maio para Marco
    printf("\nNumero de letras : %d", strlen(p_dt->nomeMes));     //Letra b  // Este print esta imprimindo a quantidade de letras do mes que será 5 (Marco)
    Data p_dt2 = (Data *) malloc(sizeof(Data));                  //Letra a  // Aloco um novo vetor para data com 1 espaço, porem, deveria ter um ponteiro antes do p_dt2
    p_dt2 = &aniversarios[0];                                              // Preencho o primeiro espaco do alocamento dinamico de p_dt2 com a primeira cadeia de termos de aniversarios.
}
