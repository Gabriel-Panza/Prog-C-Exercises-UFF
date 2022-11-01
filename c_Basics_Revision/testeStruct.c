#include <stdio.h>
#include <stdlib.h>

typedef struct StudentList
{
    int matricula;
    float cr;
}Aluno;

typedef struct ArrayList
{
    int tamAtual; // capacidade atual da lista
    int tamMax; // capacidade maxima da lista
    Aluno *alunos; // vetor de alunos
}Lista;

Lista* Create(int tam)
{
    // Crio um struct do tipo Lista
    Lista *lt = (Lista*) malloc(sizeof(Lista));
    
    // Atribuo um valor pras suas variaveis de tamanho
    lt->tamAtual = 0;
    lt->tamMax = tam;

    // Aloco um tamanho pro meu vetor do tipo Aluno
    lt->alunos = (Aluno*) malloc(tam * sizeof(Aluno));

    return lt;
}

void Append(Lista* l, Aluno a)
{
    if (l->tamAtual<l->tamMax)
    {
        // Preencho o struct Aluno da struct Lista
        l->alunos[l->tamAtual].matricula = a.matricula;
        l->alunos[l->tamAtual].cr = a.cr;

        // Aumento o numero da capacidade atual em 1
        (l->tamAtual)+=1;
    }
}

/*
void Append(Lista* l, Aluno* a)
{
    while (l->tamAtual<l->tamMax)
    {
        // Preencho o vetor Aluno da struct Lista
        printf("Informe a matricula do aluno novo");
        scanf("%d", a->matricula);
        printf("Informe o CR do aluno novo");
        scanf("%f", a->cr);

        // Aumento o numero da capacidade atual em 1
        (l->tamAtual)++;
    }
}
*/

void Print(Lista* l)
{
    if (l)
    {
        // Print da matricula e CR dos alunos
        for (int i=0; i<l->tamAtual; i++)
        {
            printf("Matricula do aluno %d: %d\n", i+1, l->alunos[i].matricula);
            printf("CR do aluno %d: %.1f\n", i+1, l->alunos[i].cr);
        }
    }
}

Lista* Destroy(Lista* l)
{
    if (l)
    {
        free(l->alunos);
        free(l);
    }
    return NULL;
}

void main()
{
    int qntd;
    printf("Digite a quantidade de alunos: ");
    scanf("%d", &qntd);

    /* Crio uma lista vazia */
    Lista *l = Create(qntd);


    /* Adiciono um aluno novo na lista até atingir a capacidade maxima */
    Aluno alunoTemporario;
    while (l->tamAtual<l->tamMax)
    {
        printf("Informe a matricula do aluno novo: ");
        scanf("%d", &alunoTemporario.matricula);
        printf("Informe o CR do aluno novo: ");
        scanf("%f", &alunoTemporario.cr);

        Append(l,alunoTemporario);
    }

    /* Adiciono varios alunos novos até atingir a capacidade maxima */
    // Append(l, l->alunos)
    
    /* Printo a lista */
    Print(l);

    /* Destruo a lista */
    l = Destroy(l);
}