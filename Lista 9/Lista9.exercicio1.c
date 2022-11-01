#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data {
    int dia, mes, ano;               /* dia, mes e ano do nascimento */
} Data;

typedef struct local {
    char ender[81];              /* endereco do local de provas */
    int sala;                   /* numero da sala */
} Local;

typedef struct notas {
    float geral;             /* prova de conhecimentos gerais */
    float especifica;       /* prova de conhecimentos especificos */
} Notas;

typedef struct candidato {
    int inscr;                      /* numero de inscricao */
    char nome[81];                 /* nome do candidato */
    Data nasc;                    /* data de nascimento */
    Local *loc;                   /* local de prova */
    Notas nt;                   /* notas de prova */
} Candidato;

void main()
{
    // Letra a
    int i,n,opcao;

    printf("\nQuantos candidatos estao presentes? \n");
    scanf("%d", &n);

    Candidato *curriculo = (Candidato *) malloc(n*sizeof(Candidato));
    if (curriculo==NULL)
    {
        exit(1);
    }

    Local *locAux = (Local *) malloc(n*sizeof(Local));
    if (locAux==NULL)
    {
        exit(1);
    }

    fflush(stdin);
    do
    {
        //Letra b
        printf("\nDigite qual opcao voce quer: (0)-Finaliza o programa, (1)-Leitura de dados, (2)-Impressao dos dados, (3)-Alteracao do local da prova de um candidato especifico\n");
        scanf("%d", &opcao);
        fflush(stdin);
        if(opcao==1)
        {
            for (i=0;i<n;i++)
            {
                curriculo[i].inscr = i+1;
                printf("\nNome do Candidato %d: ", curriculo[i].inscr);
                gets(curriculo[i].nome);

                printf("\nDigite a data de nascimento do candidato: ");
                scanf("%d/%d/%d", &curriculo[i].nasc.dia,&curriculo[i].nasc.mes,&curriculo[i].nasc.ano);
                fflush(stdin);

                printf("\nDigite o local da prova: ");
                gets(locAux[i].ender);
                printf("Digite a sala da prova: ");
                scanf("%d", &locAux[i].sala);
                fflush(stdin);
                curriculo[i].loc = &locAux[i];

                printf("\nDigite a nota geral do candidato: ");
                scanf("%f", &curriculo[i].nt.geral);
                fflush(stdin);
                printf("Digite a nota especifica do candidato: ");
                scanf("%f", &curriculo[i].nt.especifica);
                fflush(stdin);
            }
        }

        if (opcao==2)
        {
            if (curriculo[0].inscr==NULL)
            {
                printf("Nao possui nenhum cadastro!\n");
            }
            else
            {
                for (i=0;i<n;i++)
                {
                    //Letra a
                    printf("\nInscricao %d: %s", curriculo[i].inscr,curriculo[i].nome);
                    printf("\nNascimento: %d %d %d", curriculo[i].nasc.dia, curriculo[i].nasc.mes, curriculo[i].nasc.ano);
                    printf("\nLocal: %s %d", curriculo[i].loc->ender, curriculo[i].loc->sala);
                    printf("\nNotas: %f %f", curriculo[i].nt.geral,curriculo[i].nt.especifica);
                }
            }
        }

        // Letra c
        if(opcao==3)
        {
            int cand;
            printf("Digite a inscricao do candidato que voce quer alterar o endereco e sala da prova: ");
            scanf("%d", &cand);
            fflush(stdin);
            gets(locAux[cand-1].ender);
            scanf("%d", &locAux[cand].sala);
            fflush(stdin);
            curriculo[i].loc = &locAux[i];
        }
    }while (opcao!=0);

    free(curriculo);
    free(locAux);
}