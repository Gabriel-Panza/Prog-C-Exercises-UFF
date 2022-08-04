#include <stdio.h>
#include <stdlib.h>
#define MAX 2

struct aluno
{
    int mat;
    char nome[81];
    float media;
};

void le(struct aluno *turma)
{
    for (int i=0;i<MAX;i++)
    {
        turma[i].mat = i;
        printf("Digite o nome do aluno %d: ", turma[i].mat);
        scanf("%s", &turma[i].nome);
        fflush(stdin);
        printf("Digite a media final do aluno: ");
        scanf("%f", &turma[i].media);
        fflush(stdin);
    }
}

void imprime(struct aluno *turma)
{
    for (int i=0;i<MAX;i++)
    {
        printf("\nA matricula do aluno %s eh: %d e sua media eh: %f", turma[i].nome, turma[i].mat, turma[i].media);
    }
}

void ordena_medias (struct aluno *turma)
{
    struct aluno temp;
    for (int i=0;i<MAX;i++)
    {
        for (int j=0;j<MAX-1;j++)
        {
            if(turma[j].media > turma[j+1].media)
            {
                temp = turma[j];
                turma[j] = turma[j+1];
                turma[j+1] = temp;
            }
        }
    }
}

int main (void)
{
    struct aluno turma[MAX];

    le(turma);
    puts("\nImprimindo dados lidos da turma.");
    puts("\nDigite qualquer coisa para continuar.");
    getchar();

    imprime(turma);
    ordena_medias(turma);
    puts("\nImprimindo dados ordenados da turma.");
    puts("\nDigite qualquer coisa para continuar.");
    getchar();

    imprime(turma);
    getchar();
}
