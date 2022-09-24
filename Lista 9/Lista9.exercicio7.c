#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct aluno
{
    int mat; /* Matricula do aluno */
    char nome[81]; /* Nome do aluno */
};
typedef struct aluno Aluno;

struct prova
{
    Aluno a; /* Aluno que fez a prova */
    float q1,q2,q3,q4;  /* Nota em cada questao */
};
typedef struct prova Prova;

float calculaNota(Prova *p)
{
    float nota;
    nota = p->q1 + p->q2 + p->q3 + p->q4;
    return nota;
}

bool compara(Prova *pAtual, Prova *pSeguinte)
{
    float notaAtual, notaSeguinte;
    notaAtual = calculaNota(pAtual);
    notaSeguinte = calculaNota(pSeguinte);

    if (notaAtual>notaSeguinte)
    {
        return false;
    }
    else if (notaAtual<notaSeguinte)
    {

        return true;
    }
    else
    {
        if (strcmp(pAtual->a.nome,pSeguinte->a.nome)>0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

void troca(Prova **pAtual, Prova **pSeguinte)
{
    Prova *temp;

    temp = *pAtual;
    *pAtual = *pSeguinte;
    *pSeguinte = temp;
}

void ordena(int n, Prova** v)
{
    int fim,i;
    for(fim=n-1; fim>0; fim--)
        for(i=0; i<fim; i++)
            if(compara(v[i],v[i+1]))
                troca(&v[i],&v[i+1]);
}

void main()
{
    int n,i;
    printf("Quantos alunos fizeram prova? \n");
    scanf("%d", &n);

    Prova **vetor = (Prova**) malloc(n*sizeof(Prova*));
    if (vetor==NULL)
    {
        exit(1);
    }

    for (i=0;i<n;i++)
    {
        vetor[i] = (Prova*) malloc(sizeof(Prova));
        if (vetor[i]==NULL)
        {
            exit(1);
        }
    }

    for (i=0;i<n;i++)
    {
        vetor[i]->a.mat = i;
        printf("\nDigite o nome do aluno %d: ", vetor[i]->a.mat);
        scanf("%s", &vetor[i]->a.nome);
        printf("\nDigite a nota das 4 questoes da prova: ");
        scanf("%f %f %f %f", &vetor[i]->q1, &vetor[i]->q2, &vetor[i]->q3, &vetor[i]->q4);
    }
    ordena(n,vetor);
}
